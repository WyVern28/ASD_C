#include <stdio.h>
#include <stdlib.h>

int main() {
    int baris, kolom;
    printf("Masukkan panjang Matriks : ");
    scanf("%d", &baris);
    printf("Masukkan lebar Matriks  : ");
    scanf("%d", &kolom);
    int matriks[baris][kolom];
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            printf("Isi Matriks [%d,%d] : ", i+1, j+1);
            scanf("%d", &matriks[i][j]);
        }
    }
    printf("\nMatriks yang diinput adalah : \n");
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            printf("%-5d", matriks[i][j]);
        }
        printf("\n");
    }
    int jumlah = 0;
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            jumlah += matriks[i][j];
        }
    }
    printf("\nJumlah semua bilangan dalam matriks adalah %d\n", jumlah);
    float rata2 = (float)jumlah / (baris * kolom);
    printf("Rata - rata dari matriks adalah %d/%d = %.2f\n", jumlah, baris*kolom, rata2);
    printf("\nMatriks dengan angka Genap '0' : \n");
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            if (matriks[i][j] % 2 == 0) {
                printf("%-8d", 0);
            } else {
                printf("%-8d", matriks[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nMatriks dengan angka kelipatan 5 'L' : \n");
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            if (matriks[i][j] % 5 == 0) {
                printf("%-8c", 'L');
            } else {
                printf("%-8d", matriks[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nMatriks Tranpose : \n");
    for (int j = 0; j < kolom; j++) {
        for (int i = 0; i < baris; i++) {
            printf("%-8d", matriks[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}