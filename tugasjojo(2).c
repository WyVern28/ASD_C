#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa {
    char nama[100];
    char nim[20];
    struct Mahasiswa* next;
};

struct Mahasiswa* buatNodeBaru(char nama[], char nim[]) {
    struct Mahasiswa* nodeBaru = (struct Mahasiswa*)malloc(sizeof(struct Mahasiswa));
    strcpy(nodeBaru->nama, nama);
    strcpy(nodeBaru->nim, nim);
    nodeBaru->next = NULL;
    return nodeBaru;
}

void tambahMahasiswa(struct Mahasiswa** head, char nama[], char nim[]) {
    struct Mahasiswa* nodeBaru = buatNodeBaru(nama, nim);
    if (*head == NULL) {
        *head = nodeBaru;
    } else {
        struct Mahasiswa* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
}

void tampilkanMahasiswa(struct Mahasiswa* head) {
    if (head == NULL) {
        printf("Belum ada data mahasiswa.\n");
        return;
    }

    printf("\nDaftar Mahasiswa:\n");
    while (head != NULL) {
        printf("Nama: %s\n", head->nama);
        printf("NIM : %s\n\n", head->nim);
        head = head->next;
    }
}

int main() {
    struct Mahasiswa* head = NULL;
    int pilihan;
    char nama[100], nim[20];

    do {
        printf("Menu:\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Tampilkan Data Mahasiswa\n");
        printf("3. Keluar\n");
        printf("Pilih: ");
        if (scanf("%d", &pilihan) != 1) {
            printf("Input tidak valid. Silakan masukkan angka.\n");
            while (getchar() != '\n');
            pilihan = 0; 
        }

        switch (pilihan) {
            case 1:
                printf("Masukkan Nama Mahasiswa: ");
                scanf(" %[^\n]", nama);
                printf("Masukkan NIM Mahasiswa: ");
                scanf(" %[^\n]", nim); 

                tambahMahasiswa(&head, nama, nim);
                printf("Data mahasiswa ditambahkan.\n\n");
                break;

            case 2:
                tampilkanMahasiswa(head);
                break;

            case 3:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 3);

    struct Mahasiswa* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}