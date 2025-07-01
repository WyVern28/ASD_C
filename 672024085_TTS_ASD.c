#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

// Struktur untuk node linked list
struct inventaris {
    char namaBarang[50];
    int tahunPengadaan;
    int jumlah;
    struct inventaris *next;
};

// Head pointer untuk linked list
struct inventaris *head = NULL;

// Fungsi untuk membuat node baru
struct inventaris* createNode(char *nama, int tahun, int jumlah) {
    struct inventaris *newNode = (struct inventaris*)malloc(sizeof(struct inventaris));
    if (newNode == NULL) {
        printf("Gagal mengalokasi memori!\n");
        return NULL;
    }
    
    strcpy(newNode->namaBarang, nama);
    newNode->tahunPengadaan = tahun;
    newNode->jumlah = jumlah;
    newNode->next = NULL;
    
    return newNode;
}

// Fungsi untuk menghitung jumlah node dalam linked list
int countNodes() {
    int count = 0;
    struct inventaris *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi untuk insert node secara terurut berdasarkan nama barang
void insertSorted(struct inventaris *newNode) {
    // Jika list kosong atau nama baru lebih kecil dari head
    if (head == NULL || strcasecmp(newNode->namaBarang, head->namaBarang) < 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    
    // Cari posisi yang tepat untuk insert
    struct inventaris *current = head;
    while (current->next != NULL && 
           strcasecmp(current->next->namaBarang, newNode->namaBarang) < 0) {
        current = current->next;
    }
    
    // Insert node di posisi yang tepat
    newNode->next = current->next;
    current->next = newNode;
}

// Fungsi untuk menambah barang
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

// Fungsi untuk input data barang
void inputData() {
    do {
        char nama[50];
        int tahun, jumlah;
        
        printf("\nMasukkan nama barang: ");
        fgets(nama, sizeof(nama), stdin);
        strtok(nama, "\n"); // Hapus newline
        
        printf("Masukkan tahun pengadaan: ");
        scanf("%d", &tahun);
        while (getchar() != '\n');
        
        printf("Masukkan jumlah barang: ");
        scanf("%d", &jumlah);
        while (getchar() != '\n');
        
        // Buat node baru dan insert ke linked list
        struct inventaris *newNode = createNode(nama, tahun, jumlah);
        if (newNode != NULL) {
            insertSorted(newNode);
            printf("Barang berhasil ditambahkan!\n");
        }
        
    } while (tambah());
}

// Fungsi untuk membuat dummy data
void createDummyData() {
    struct {
        char nama[50];
        int tahun;
        int jumlah;
    } dummy[] = {
        {"Laptop", 2020, 5},
        {"Printer", 2018, 3},
        {"Proyektor", 2019, 2},
        {"Scanner", 2021, 4},
        {"AC", 2017, 1}
    };

    int dummySize = sizeof(dummy) / sizeof(dummy[0]);
    
    for (int i = 0; i < dummySize; i++) {
        struct inventaris *newNode = createNode(dummy[i].nama, dummy[i].tahun, dummy[i].jumlah);
        if (newNode != NULL) {
            insertSorted(newNode);
        }
    }
    
    printf("Dummy data berhasil dimuat!\n");
}

// Fungsi untuk menampilkan semua data
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

// Fungsi untuk mencari data barang
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

// Fungsi untuk menghapus semua node (cleanup memory)
void cleanup() {
    struct inventaris *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Fungsi untuk menghapus barang berdasarkan nama
void deleteData() {
    if (head == NULL) {
        printf("Tidak ada data untuk dihapus.\n");
        return;
    }
    
    char keyword[50];
    printf("\nMasukkan nama barang yang ingin dihapus: ");
    fgets(keyword, sizeof(keyword), stdin);
    strtok(keyword, "\n");
    
    // Jika yang akan dihapus adalah head
    if (strcasecmp(head->namaBarang, keyword) == 0) {
        struct inventaris *temp = head;
        head = head->next;
        printf("Barang '%s' berhasil dihapus.\n", temp->namaBarang);
        free(temp);
        return;
    }
    
    // Cari node yang akan dihapus
    struct inventaris *current = head;
    while (current->next != NULL && 
           strcasecmp(current->next->namaBarang, keyword) != 0) {
        current = current->next;
    }
    
    if (current->next != NULL) {
        struct inventaris *temp = current->next;
        current->next = temp->next;
        printf("Barang '%s' berhasil dihapus.\n", temp->namaBarang);
        free(temp);
    } else {
        printf("Barang dengan nama '%s' tidak ditemukan.\n", keyword);
    }
}

int main() {
    int pilihan;

    createDummyData();

    do {
        printf("\n===== MENU INVENTARIS (Linked List) =====\n");
        printf("1. Tambah Data Barang\n");
        printf("2. Tampilkan Data\n");
        printf("3. Cari Barang\n");
        printf("4. Hapus Barang\n");
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
                break;
            case 3:
                searchData();
                system("pause");
                break;
            case 4:
                deleteData();
                system("pause");
                break;
            case 0:
                printf("Membersihkan memori...\n");
                cleanup();
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Tidak ada dalam pilihan.\n");
                break;
        }
    } while (pilihan != 0);

    return 0;
}