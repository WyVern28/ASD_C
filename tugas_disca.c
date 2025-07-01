#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Karyawan {
    int idKaryawan;
    char nama[50];
    char difisi[50];
};

void newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void insertionSort(struct Karyawan arr[], int n) {
    for (int i = 1; i < n; i++) {
        struct Karyawan key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].idKaryawan > key.idKaryawan) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    struct Karyawan *daftar = NULL;
    int jumlahKaryawan = 0;
    int pilihan;

    do {
        clearScreen();
        printf("\n======= MENU =======\n");
        printf("1. Tambah Karyawan\n");
        printf("2. Daftar Karyawan\n");
        printf("3. Hapus Karyawan\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda : ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                printf("\nMasukkan jumlah karyawan yang akan ditambahkan : ");
                scanf("%d", &jumlahKaryawan);
                getchar();

                daftar = (struct Karyawan*) malloc(jumlahKaryawan * sizeof(struct Karyawan));
                if (daftar == NULL) {
                    printf("Alokasi memori gagal!\n");
                    system("pause");
                    return 1;
                }

                for (int i = 0; i < jumlahKaryawan; i++) {
                    printf("\nDaftarkan Karyawan ke-%d\n", i + 1);

                    printf("Masukkan nomor ID karyawan : ");
                    scanf("%d", &daftar[i].idKaryawan);
                    getchar();

                    printf("Masukkan nama Karyawan : ");
                    fgets(daftar[i].nama, sizeof(daftar[i].nama), stdin);
                    newline(daftar[i].nama);

                    printf("Masukkan divisi yang dipegang karyawan : ");
                    fgets(daftar[i].difisi, sizeof(daftar[i].difisi), stdin);
                    newline(daftar[i].difisi);
                }
                system("pause");
                clearScreen();
                break;

            case 2:
                if (jumlahKaryawan == 0) {
                    printf("\nBelum ada data karyawan yang ditambahkan.\n");
                } else {
                    insertionSort(daftar, jumlahKaryawan);
                    printf("\n======== DAFTAR KARYAWAN ========\n");
                    for (int i = 0; i < jumlahKaryawan; i++) {
                        printf("ID : %d | Nama : %s | Divisi : %s\n", daftar[i].idKaryawan, daftar[i].nama, daftar[i].difisi);
                    }
                }
                system("pause");
                clearScreen();
                break;

            case 3:
                if (jumlahKaryawan == 0) {
                    printf("\nBelum ada data karyawan yang ditambahkan.\n");
                } else {
                    printf("\nMasukkan nomor karyawan yang ingin dihapus (1-%d): ", jumlahKaryawan);
                    int nomorHapus;
                    scanf("%d", &nomorHapus);
                    getchar();

                    int indeks = nomorHapus - 1;

                    if (indeks < 0 || indeks >= jumlahKaryawan) {
                        printf("\nNomor karyawan tidak valid!\n");
                    } else {
                        for (int i = indeks; i < jumlahKaryawan - 1; i++) {
                            daftar[i] = daftar[i + 1];
                        }
                        jumlahKaryawan--;

                        struct Karyawan *temp = realloc(daftar, jumlahKaryawan * sizeof(struct Karyawan));
                        if (temp != NULL || jumlahKaryawan == 0) {
                            daftar = temp;
                        } else {
                            printf("Gagal mengalokasikan ulang memori!\n");
                        }

                        printf("\nKaryawan ke-%d berhasil dihapus!\n", nomorHapus);
                    }
                }
                system("pause");
                clearScreen();
                break;

            case 0:
                printf("\nKeluar dari program...\n");
                break;

            default:
                printf("\nPilihan tidak valid! Silakan coba lagi.\n");
                system("pause");
                clearScreen();
        }

    } while (pilihan != 0);

    if (daftar != NULL) {
        free(daftar);
    }

    return 0;
}
