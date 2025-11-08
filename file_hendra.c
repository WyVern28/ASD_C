#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MHS 100

typedef struct Mahasiswa {
    char nama[50];
    float tugas, uts, uas, akhir;
    const char* predikat;
    struct Mahasiswa* next;
} Mahasiswa;

Mahasiswa* head = NULL; 

int validasi_nama(const char* nama) {
    for (int i = 0; nama[i]; i++) {
        if (!isalpha(nama[i]) && !isspace(nama[i])) return 0;
    }
    return 1;
}

float input_nilai(const char* label) {
    float nilai;
    int valid;
    do {
        printf("%s (0 - 100): ", label);
        valid = scanf("%f", &nilai);
        getchar();
        if (valid != 1 || nilai < 0 || nilai > 100) {
            printf("Input tidak valid. Harap ulangi!\n");
            while (getchar() != '\n');
            valid = 0;
        }
    } while (!valid);
    return nilai;
}

void hitung_nilai(Mahasiswa* mhs) {
    mhs->akhir = mhs->tugas * 0.25f + mhs->uts * 0.35f + mhs->uas * 0.40f;
    if (mhs->akhir >= 85)
        mhs->predikat = "A (Sangat Baik)";
    else if (mhs->akhir >= 75)
        mhs->predikat = "B (Baik)";
    else if (mhs->akhir >= 65)
        mhs->predikat = "C (Cukup)";
    else if (mhs->akhir >= 55)
        mhs->predikat = "D (Kurang)";
    else
        mhs->predikat = "E (Sangat Kurang)";
}

void tambah_mahasiswa() {
    Mahasiswa* baru = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    if (!baru) {
        printf("Gagal mengalokasikan memori.\n");
        return;
    }

    do {
        printf("Nama Mahasiswa: ");
        fgets(baru->nama, sizeof(baru->nama), stdin);
        baru->nama[strcspn(baru->nama, "\n")] = '\0';
    } while (strlen(baru->nama) == 0 || !validasi_nama(baru->nama));

    baru->tugas = input_nilai("Nilai Tugas");
    baru->uts = input_nilai("Nilai UTS");
    baru->uas = input_nilai("Nilai UAS");

    hitung_nilai(baru);
    baru->next = head;
    head = baru;

    printf("Mahasiswa berhasil ditambahkan!\n");
}


void insertion_sort(Mahasiswa* arr[], int n) {
    for (int i = 1; i < n; i++) {
        Mahasiswa* key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j]->akhir < key->akhir) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int tampilkan_mahasiswa_dan_kembalikan_array(Mahasiswa* arr[]) {
    Mahasiswa* current = head;
    int count = 0;
    while (current && count < MAX_MHS) {
        arr[count++] = current;
        current = current->next;
    }

    insertion_sort(arr, count);

    printf("\n==== Daftar Nilai Mahasiswa) ====\n");
    for (int i = 0; i < count; i++) {
        printf("\nMahasiswa ke-%d\n", i + 1);
        printf("Nama           : %s\n", arr[i]->nama);
        printf("Nilai Tugas    : %.0f\n", arr[i]->tugas);
        printf("Nilai UTS      : %.0f\n", arr[i]->uts);
        printf("Nilai UAS      : %.0f\n", arr[i]->uas);
        printf("Nilai Akhir    : %.2f\n", arr[i]->akhir);
        printf("Predikat       : %s\n", arr[i]->predikat);
    }
    if (count == 0)  
    {
        printf("belum ada data mahasiswa.\n");
    }
    
    return count;
}

void update_mahasiswa() {
    if (!head) {
        printf("Belum ada data.\n");
        return;
    }

    Mahasiswa* arr[MAX_MHS];
    int count = tampilkan_mahasiswa_dan_kembalikan_array(arr);

    int index;
    printf("\nMasukkan nomor mahasiswa yang ingin diupdate (1-%d): ", count);
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > count) {
        printf("Nomor tidak valid.\n");
        return;
    }

    Mahasiswa* mhs = arr[index - 1];
    printf("Update data untuk %s\n", mhs->nama);
    mhs->tugas = input_nilai("Nilai Tugas");
    mhs->uts = input_nilai("Nilai UTS");
    mhs->uas = input_nilai("Nilai UAS");
    hitung_nilai(mhs);
    printf("Data berhasil diupdate.\n");
}

void hapus_mahasiswa() {
    if (!head) {
        printf("Belum ada data untuk dihapus.\n");
        return;
    }

    Mahasiswa* arr[MAX_MHS];
    int count = tampilkan_mahasiswa_dan_kembalikan_array(arr);

    int index;
    printf("\nMasukkan nomor mahasiswa yang ingin dihapus (1-%d): ", count);
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > count) {
        printf("Nomor tidak valid.\n");
        return;
    }

    Mahasiswa* target = arr[index - 1];
    Mahasiswa* current = head;
    Mahasiswa* prev = NULL;

    while (current) {
        if (current == target) {
            if (prev)
                prev->next = current->next;
            else
                head = current->next;

            free(current);
            printf("Data berhasil dihapus.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
}

void bersihkan_data() {
    Mahasiswa* current = head;
    while (current) {
        Mahasiswa* hapus = current;
        current = current->next;
        free(hapus);
    }
}

int main() {
    int pilihan;

    do {
        printf("\n=== MENU NILAI MAHASISWA ===\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Tampilkan Mahasiswa\n");
        printf("3. Update Mahasiswa\n");
        printf("4. Hapus Mahasiswa\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1: 
                tambah_mahasiswa(); 
                system("pause");
                system("cls");
            break;
            case 2: {
                Mahasiswa* dummy[MAX_MHS];
                tampilkan_mahasiswa_dan_kembalikan_array(dummy);
                system("pause");
                system("cls");
                break;
            }
            case 3: 
                update_mahasiswa(); 
                system("pause");
                system("cls");
            break;
            case 4: 
                hapus_mahasiswa();
                system("pause");
                system("cls");
                break;
            case 0: 
                bersihkan_data(); 
                // system("pause");
                printf("Terima kasih.\n"); 
                break;
            default: 
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    return 0;
}