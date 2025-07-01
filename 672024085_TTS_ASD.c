#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

#define FILE_NAME "inventaris.txt"

struct inventaris {
    char namaBarang[50];
    int tahunPengadaan;
    int jumlah;
    struct inventaris *next;
};

struct inventaris *head = NULL;

struct inventaris* createNode(char *nama, int tahun, int jumlah) {
    struct inventaris *newNode = (struct inventaris*)malloc(sizeof(struct inventaris));
    if (!newNode) {
        printf("Gagal mengalokasi memori!\n");
        return NULL;
    }
    strcpy(newNode->namaBarang, nama);
    newNode->tahunPengadaan = tahun;
    newNode->jumlah = jumlah;
    newNode->next = NULL;
    return newNode;
}

void insertSorted(struct inventaris *newNode) {
    if (head == NULL || strcasecmp(newNode->namaBarang, head->namaBarang) < 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct inventaris *current = head;
    while (current->next != NULL && strcasecmp(current->next->namaBarang, newNode->namaBarang) < 0) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int countNodes() {
    int count = 0;
    struct inventaris *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// FILE HANDLING
void saveToFile() {
    FILE *fp = fopen(FILE_NAME, "w");
    if (!fp) {
        printf("Gagal membuka file untuk menyimpan!\n");
        return;
    }

    struct inventaris *temp = head;
    while (temp != NULL) {
        fprintf(fp, "%s;%d;%d\n", temp->namaBarang, temp->tahunPengadaan, temp->jumlah);
        temp = temp->next;
    }

    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        // Jika file tidak ditemukan, dianggap kosong
        return;
    }

    char baris[128];
    while (fgets(baris, sizeof(baris), fp)) {
        char *nama = strtok(baris, ";");
        char *tahunStr = strtok(NULL, ";");
        char *jumlahStr = strtok(NULL, "\n");

        if (nama && tahunStr && jumlahStr) {
            int tahun = atoi(tahunStr);
            int jumlah = atoi(jumlahStr);
            struct inventaris *node = createNode(nama, tahun, jumlah);
            if (node) insertSorted(node);
        }
    }

    fclose(fp);
}

// Fungsi input data
bool tambah() {
    char jawaban;
    printf("Apakah Anda ingin menambah barang? (y/n): ");
    scanf(" %c", &jawaban);
    while (getchar() != '\n');

    if (jawaban == 'y' || jawaban == 'Y') {
        return true;
    } else if (jawaban == 'n' || jawaban == 'N') {
        return false;
    } else {
        printf("Input tidak valid. Harap masukkan 'y' atau 'n'.\n");
        return tambah();
    }
}

void inputData() {
    do {
        char nama[50];
        int tahun, jumlah;

        printf("\nMasukkan nama barang: ");
        fgets(nama, sizeof(nama), stdin);
        strtok(nama, "\n");

        printf("Masukkan tahun pengadaan: ");
        scanf("%d", &tahun);
        while (getchar() != '\n');

        printf("Masukkan jumlah barang: ");
        scanf("%d", &jumlah);
        while (getchar() != '\n');

        struct inventaris *newNode = createNode(nama, tahun, jumlah);
        if (newNode) {
            insertSorted(newNode);
            saveToFile();
            printf("Barang berhasil ditambahkan dan disimpan!\n");
        }
    } while (tambah());
}

void tampilData() {
    printf("\n--- Daftar Inventaris ---\n");

    if (head == NULL) {
        printf("Tidak ada data inventaris.\n");
        return;
    }

    struct inventaris *temp = head;
    int no = 1;

    while (temp != NULL) {
        printf("%d. Nama Barang    : %s\n", no, temp->namaBarang);
        printf("   Tahun Pengadaan: %d\n", temp->tahunPengadaan);
        printf("   Jumlah         : %d\n\n", temp->jumlah);
        temp = temp->next;
        no++;
    }

    printf("Total barang: %d\n", countNodes());
}

void searchData() {
    char keyword[50];
    printf("\nMasukkan nama barang yang ingin dicari: ");
    fgets(keyword, sizeof(keyword), stdin);
    strtok(keyword, "\n");

    struct inventaris *temp = head;
    bool ditemukan = false;

    while (temp != NULL) {
        if (strcasecmp(temp->namaBarang, keyword) == 0) {
            printf("\n--- Data Ditemukan ---\n");
            printf("Nama Barang    : %s\n", temp->namaBarang);
            printf("Tahun Pengadaan: %d\n", temp->tahunPengadaan);
            printf("Jumlah         : %d\n", temp->jumlah);
            ditemukan = true;
            break;
        }
        temp = temp->next;
    }

    if (!ditemukan) {
        printf("Barang dengan nama '%s' tidak ditemukan.\n", keyword);
    }
}

void deleteData() {
    if (head == NULL) {
        printf("Tidak ada data untuk dihapus.\n");
        return;
    }

    char keyword[50];
    printf("\nMasukkan nama barang yang ingin dihapus: ");
    fgets(keyword, sizeof(keyword), stdin);
    strtok(keyword, "\n");

    if (strcasecmp(head->namaBarang, keyword) == 0) {
        struct inventaris *temp = head;
        head = head->next;
        printf("Barang '%s' berhasil dihapus.\n", temp->namaBarang);
        free(temp);
        saveToFile();
        return;
    }

    struct inventaris *current = head;
    while (current->next != NULL && strcasecmp(current->next->namaBarang, keyword) != 0) {
        current = current->next;
    }

    if (current->next != NULL) {
        struct inventaris *temp = current->next;
        current->next = temp->next;
        printf("Barang '%s' berhasil dihapus.\n", temp->namaBarang);
        free(temp);
        saveToFile();
    } else {
        printf("Barang dengan nama '%s' tidak ditemukan.\n", keyword);
    }
}

void editData() {
    if (head == NULL) {
        printf("Tidak ada data untuk diedit.\n");
        return;
    }

    char keyword[50];
    printf("\nMasukkan nama barang yang ingin diedit: ");
    fgets(keyword, sizeof(keyword), stdin);
    strtok(keyword, "\n");

    struct inventaris *temp = head;
    bool ditemukan = false;

    while (temp != NULL) {
        if (strcasecmp(temp->namaBarang, keyword) == 0) {
            printf("\n--- Data Ditemukan ---\n");
            printf("Nama Barang    : %s\n", temp->namaBarang);
            printf("Tahun Pengadaan: %d\n", temp->tahunPengadaan);
            printf("Jumlah         : %d\n", temp->jumlah);

            int opsi;
            printf("\nApa yang ingin Anda edit?\n");
            printf("1. Tahun Pengadaan\n");
            printf("2. Jumlah\n");
            printf("3. Keduanya\n");
            printf("Pilihan: ");
            scanf("%d", &opsi);
            while (getchar() != '\n');

            switch (opsi) {
                case 1:
                    printf("Masukkan tahun pengadaan baru: ");
                    scanf("%d", &temp->tahunPengadaan);
                    while (getchar() != '\n');
                    break;
                case 2:
                    printf("Masukkan jumlah barang baru: ");
                    scanf("%d", &temp->jumlah);
                    while (getchar() != '\n');
                    break;
                case 3:
                    printf("Masukkan tahun pengadaan baru: ");
                    scanf("%d", &temp->tahunPengadaan);
                    while (getchar() != '\n');
                    printf("Masukkan jumlah barang baru: ");
                    scanf("%d", &temp->jumlah);
                    while (getchar() != '\n');
                    break;
                default:
                    printf("Pilihan tidak valid.\n");
                    return;
            }

            printf("Data berhasil diperbarui.\n");
            saveToFile();
            ditemukan = true;
            break;
        }
        temp = temp->next;
    }

    if (!ditemukan) {
        printf("Barang dengan nama '%s' tidak ditemukan.\n", keyword);
    }
}

void cleanup() {
    struct inventaris *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int pilihan;

    loadFromFile();

    do {
        printf("\n===== MENU INVENTARIS =====\n");
        printf("1. Tambah Data Barang\n");
        printf("2. Tampilkan Data\n");
        printf("3. Cari Barang\n");
        printf("4. Hapus Barang\n");
        printf("5. Edit Data Barang\n");
        printf("0. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);
        while (getchar() != '\n');

        switch (pilihan) {
            case 1:
                inputData();
                break;
            case 2:
                tampilData();
                system("pause");
                system("cls");
                break;
            case 3:
                searchData();
                system("pause");
                system("cls");
                break;
            case 4:
                deleteData();
                system("pause");
                system("cls");
                break;
            case 5:
                editData();
                system("pause");
                break;
            case 0:
                printf("Membersihkan memori...\n");
                cleanup();
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 0);

    return 0;
}
