#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMA_FILE "data_mahasiswa.txt"

struct Mahasiswa {
    char nama[50];
    int nim;
    float ipk;
    struct Mahasiswa* next;
};

struct Mahasiswa* head = NULL;

struct Mahasiswa* buatNodeBaru(char nama[], int nim, float ipk) {
    struct Mahasiswa* nodeBaru = (struct Mahasiswa*)malloc(sizeof(struct Mahasiswa));
    
    if (nodeBaru == NULL) {
        printf("Error: Gagal mengalokasi memori!\n");
        return NULL;
    }
    
    strcpy(nodeBaru->nama, nama);
    nodeBaru->nim = nim;
    nodeBaru->ipk = ipk;
    nodeBaru->next = NULL;
    
    return nodeBaru;
}

void tambahMahasiswa(char nama[], int nim, float ipk) {
    struct Mahasiswa* nodeBaru = buatNodeBaru(nama, nim, ipk);
    
    if (nodeBaru == NULL) {
        return;
    }
    
    if (head == NULL) {
        head = nodeBaru;
        return;
    }
    
    struct Mahasiswa* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = nodeBaru;
}

void simpanKeFile() {
    FILE* file = fopen(NAMA_FILE, "w");
    
    if (file == NULL) {
        printf("Error: Gagal membuka file untuk menulis!\n");
        return;
    }
    
    struct Mahasiswa* temp = head;
    
    while (temp != NULL) {
        fprintf(file, "%s|%d|%.2f\n", temp->nama, temp->nim, temp->ipk);
        temp = temp->next;
    }
    
    fclose(file);
}

void muatDariFile() {
    FILE* file = fopen(NAMA_FILE, "r");
    
    if (file == NULL) {
        return;
    }
    
    char nama[50];
    int nim;
    float ipk;

    
    while (fscanf(file, "%49[^|]|%d|%f\n", nama, &nim, &ipk) == 3) {
        tambahMahasiswa(nama, nim, ipk);
    }
    
    fclose(file);
}

void MasukkanData() {
    int jumlah;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jumlah);

    for (int i = 0; i < jumlah; i++) {
        char nama[50];
        int nim;
        float ipk;
        
        printf("\nMahasiswa %d\n", i + 1);
        printf("Nama: ");
        scanf(" %[^\n]", nama);
        printf("NIM: ");
        scanf("%d", &nim);
        printf("IPK: ");
        scanf("%f", &ipk);
        
        tambahMahasiswa(nama, nim, ipk);
    }
    
    simpanKeFile();
    printf("\nData berhasil ditambahkan dan disimpan ke file!\n");
}

void DaftarMahasiswa() {
    if (head == NULL) {
        printf("\nBelum ada data mahasiswa.\n");
        return;
    }

    printf("\nData Mahasiswa:\n");
    printf("------------------------------\n");
    
    struct Mahasiswa* temp = head;
    int counter = 1;
    
    while (temp != NULL) {
        printf("Mahasiswa %d\n", counter);
        printf("Nama: %s\n", temp->nama);
        printf("NIM: %d\n", temp->nim);
        printf("IPK: %.2f\n", temp->ipk);
        printf("------------------------------\n");
        
        temp = temp->next;
        counter++;
    }
    
    printf("Total Mahasiswa: %d\n", counter - 1);
    printf("------------------------------\n");
    
    system("pause");
    system("cls");
}

void EditDataMahasiswa() {
    if (head == NULL) {
        printf("\nTidak ada data mahasiswa yang bisa diedit.\n");
        return;
    }

    int nimEdit;
    printf("Masukkan NIM mahasiswa yang ingin diedit: ");
    scanf("%d", &nimEdit);

    struct Mahasiswa* temp = head;

    while (temp != NULL && temp->nim != nimEdit) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Mahasiswa dengan NIM %d tidak ditemukan.\n", nimEdit);
        return;
    }

    printf("\nData saat ini:\n");
    printf("Nama: %s\n", temp->nama);
    printf("NIM: %d\n", temp->nim);
    printf("IPK: %.2f\n", temp->ipk);

    printf("\nMasukkan data baru:\n");
    printf("Nama baru: ");
    scanf(" %[^\n]", temp->nama);
    printf("NIM baru: ");
    scanf("%d", &temp->nim);
    printf("IPK baru: ");
    scanf("%f", &temp->ipk);

    simpanKeFile();
    printf("\nData mahasiswa berhasil diupdate dan disimpan!\n");
}

void HapusDataMahasiswa() {
    if (head == NULL) {
        printf("\nTidak ada data mahasiswa yang bisa dihapus.\n");
        return;
    }

    int nimHapus;
    printf("Masukkan NIM mahasiswa yang ingin dihapus: ");
    scanf("%d", &nimHapus);

    struct Mahasiswa* temp = head;
    struct Mahasiswa* prev = NULL;

    if (temp != NULL && temp->nim == nimHapus) {
        head = temp->next;
        free(temp);       
        simpanKeFile();   
        printf("Data mahasiswa dengan NIM %d telah dihapus.\n", nimHapus);
        return;
    }
    while (temp != NULL && temp->nim != nimHapus) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Mahasiswa dengan NIM %d tidak ditemukan.\n", nimHapus);
        return;
    }

    prev->next = temp->next;
    free(temp);
    
    simpanKeFile();
    printf("Data mahasiswa dengan NIM %d telah dihapus.\n", nimHapus);
}

void bersihkanMemori() {
    struct Mahasiswa* temp;
    
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int pilihan;
    
    muatDariFile();

    do {
        printf("\nSistem Manajemen Data Mahasiswa\n");
        printf("===============================\n");
        printf("1. Masukkan Data Mahasiswa\n");
        printf("2. Daftar Mahasiswa\n");
        printf("3. Edit/Update Data Mahasiswa\n");
        printf("4. Hapus Data Mahasiswa\n");
        printf("5. Exit\n");
        printf("===============================\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);
        system("cls");

        switch (pilihan) {
            case 1:
                MasukkanData();
                system("pause");
                system("cls");
                break;
            case 2:
                DaftarMahasiswa();
                // system("cls");
                break;
            case 3:
                EditDataMahasiswa();
                system("pause");
                system("cls");
                break;
            case 4:
                HapusDataMahasiswa();
                system("pause");
                system("cls");
                break;
            case 5:
                bersihkanMemori();
                printf("Data telah disimpan. Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                system("pause");
                system("cls");
        }
    } while (pilihan != 5);

    return 0;
}