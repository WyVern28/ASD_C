#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // untuk isdigit

struct Karyawan {
    int idKaryawan;
    char nama[50];
    char divisi[50];
    struct Karyawan *next;
};

void newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

struct Karyawan* buatNode(int id, char nama[], char divisi[]) {
    struct Karyawan* nodeBaru = (struct Karyawan*)malloc(sizeof(struct Karyawan));
    if (nodeBaru == NULL) return NULL;
    nodeBaru->idKaryawan = id;
    strcpy(nodeBaru->nama, nama);
    strcpy(nodeBaru->divisi, divisi);
    nodeBaru->next = NULL;
    return nodeBaru;
}

struct Karyawan* tambahKaryawan(struct Karyawan* head, int id, char nama[], char divisi[]) {
    struct Karyawan* nodeBaru = buatNode(id, nama, divisi);
    if (nodeBaru == NULL) return head;
    if (head == NULL || head->idKaryawan > id) {
        nodeBaru->next = head;
        return nodeBaru;
    }
    struct Karyawan* current = head;
    while (current->next != NULL && current->next->idKaryawan < id) {
        current = current->next;
    }
    nodeBaru->next = current->next;
    current->next = nodeBaru;
    return head;
}

void tampilkanKaryawan(struct Karyawan* head) {
    if (head == NULL) {
        printf("\nBelum ada data karyawan yang ditambahkan.\n");
        return;
    }
    int nomor = 1;
    struct Karyawan* current = head;
    while (current != NULL) {
        printf("%d. ID: %d | Nama: %s | Divisi: %s\n", nomor, current->idKaryawan, current->nama, current->divisi);
        current = current->next;
        nomor++;
    }
}

int hitungKaryawan(struct Karyawan* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Karyawan* cariKaryawan(struct Karyawan* head, int id) {
    while (head != NULL) {
        if (head->idKaryawan == id) return head;
        head = head->next;
    }
    return NULL;
}

struct Karyawan* hapusKaryawan(struct Karyawan* head, int nomor) {
    if (head == NULL) return head;
    int jumlah = hitungKaryawan(head);
    if (nomor < 1 || nomor > jumlah) return head;
    if (nomor == 1) {
        struct Karyawan* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Karyawan* current = head;
    for (int i = 1; i < nomor - 1; i++) current = current->next;
    struct Karyawan* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

void simpanKeFile(struct Karyawan* head, const char* namaFile) {
    FILE* file = fopen(namaFile, "w");
    if (file == NULL) return;
    while (head != NULL) {
        fprintf(file, "%d|%s|%s\n", head->idKaryawan, head->nama, head->divisi);
        head = head->next;
    }
    fclose(file);
}

struct Karyawan* muatDariFile(const char* namaFile) {
    FILE* file = fopen(namaFile, "r");
    if (file == NULL) return NULL;
    struct Karyawan* head = NULL;
    char line[200], *token;
    while (fgets(line, sizeof(line), file)) {
        newline(line);
        token = strtok(line, "|");
        if (!token) continue;
        int id = atoi(token);
        char* nama = strtok(NULL, "|");
        char* divisi = strtok(NULL, "|");
        if (nama && divisi) head = tambahKaryawan(head, id, nama, divisi);
    }
    fclose(file);
    return head;
}

void bebaskanMemori(struct Karyawan* head) {
    while (head != NULL) {
        struct Karyawan* temp = head;
        head = head->next;
        free(temp);
    }
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

struct Karyawan* editKaryawan(struct Karyawan* head, int id) {
    struct Karyawan* karyawan = cariKaryawan(head, id);
    if (karyawan == NULL) {
        printf("\nKaryawan dengan ID %d tidak ditemukan!\n", id);
        return head;
    }
    printf("\nData saat ini:\nID: %d\nNama: %s\nDivisi: %s\n", karyawan->idKaryawan, karyawan->nama, karyawan->divisi);
    printf("\n1. Edit Nama\n2. Edit Divisi\n3. Edit Nama dan Divisi\n0. Batal Edit\nPilihan: ");
    int pilihan;
    scanf("%d", &pilihan); getchar();
    if (pilihan == 1 || pilihan == 3) {
        printf("Masukkan nama baru: ");
        fgets(karyawan->nama, sizeof(karyawan->nama), stdin);
        newline(karyawan->nama);
    }
    if (pilihan == 2 || pilihan == 3) {
        printf("Masukkan divisi baru: ");
        fgets(karyawan->divisi, sizeof(karyawan->divisi), stdin);
        newline(karyawan->divisi);
    }
    return head;
}

int main() {
    struct Karyawan* daftarKaryawan = muatDariFile("data_karyawan.txt");
    int pilihan;
    do {
        clearScreen();
        printf("\n======= MENU KARYAWAN =======\n");
        printf("1. Tambah Karyawan\n2. Daftar Karyawan\n3. Hapus Karyawan\n4. Cari Karyawan\n5. Edit Data Karyawan\n0. Keluar\nPilihan Anda: ");
        scanf("%d", &pilihan); getchar();
        switch (pilihan) {
            case 1: {
                char idStr[20];
                int id;
                printf("\nMasukkan ID Karyawan: ");
                fgets(idStr, sizeof(idStr), stdin);
                newline(idStr);
                char *endptr;
                id = strtol(idStr, &endptr, 10);
                if (*endptr != '\0') {
                    printf("ID harus berupa angka!\n");
                    system("pause");
                    break;
                }
                if (cariKaryawan(daftarKaryawan, id)) {
                    printf("ID sudah ada!\n");
                    system("pause");
                    break;
                }
                char nama[50], divisi[50];
                printf("Masukkan Nama Karyawan: ");
                fgets(nama, sizeof(nama), stdin);
                newline(nama);
                printf("Masukkan Divisi: ");
                fgets(divisi, sizeof(divisi), stdin);
                newline(divisi);
                daftarKaryawan = tambahKaryawan(daftarKaryawan, id, nama, divisi);
                simpanKeFile(daftarKaryawan, "data_karyawan.txt");
                break;
            }
            case 2:
                tampilkanKaryawan(daftarKaryawan);
                system("pause");
                break;
            case 3: {
                tampilkanKaryawan(daftarKaryawan);
                int nomor;
                printf("\nMasukkan nomor karyawan yang ingin dihapus: ");
                scanf("%d", &nomor); getchar();
                daftarKaryawan = hapusKaryawan(daftarKaryawan, nomor);
                simpanKeFile(daftarKaryawan, "data_karyawan.txt");
                break;
            }
            case 4: {
                int id;
                printf("Masukkan ID Karyawan: ");
                scanf("%d", &id); getchar();
                struct Karyawan* k = cariKaryawan(daftarKaryawan, id);
                if (k)
                    printf("\nID: %d\nNama: %s\nDivisi: %s\n", k->idKaryawan, k->nama, k->divisi);
                else
                    printf("Karyawan tidak ditemukan.\n");
                system("pause");
                break;
            }
            case 5: {
                tampilkanKaryawan(daftarKaryawan);
                int id;
                printf("\nMasukkan ID Karyawan yang ingin diedit: ");
                scanf("%d", &id); getchar();
                daftarKaryawan = editKaryawan(daftarKaryawan, id);
                simpanKeFile(daftarKaryawan, "data_karyawan.txt");
                system("pause");
                break;
            }
        }
    } while (pilihan != 0);
    bebaskanMemori(daftarKaryawan);
    return 0;
}
