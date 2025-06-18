#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void Program_Segitiga_Terbalik(){
    int tinggi, i, j, spasi;
    system("cls");    
    printf("================================================================\n");
    printf("|                  PROGRAM SEGITIGA TERBALIK                   |\n");
    printf("================================================================\n");
    printf("Jika input genap maka akan ditambah 1\n\n");
    printf("Masukkan tinggi segitiga: ");
    scanf("%d", &tinggi);
    if (tinggi % 2 == 0) {
        tinggi = tinggi + 1;
    }
    for (i = tinggi; i >= 1; i--) {
        for (spasi = tinggi - i; spasi > 0; spasi--) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }

        printf("\n");
    }

    printf("\nTekan Enter untuk melanjutkan...");
    getchar();
    getchar();
}
void Program_Belanjaan(){
    int jumlahBarang;
    float harga[10], totalHarga = 0;
    char pilihan;
    int c;
    
    do {
        totalHarga = 0;
        printf("================================================================\n");
        printf("|               PROGRAM HITUNG TOTAL BELANJAAN                 |\n");
        printf("================================================================\n");
        do {
            printf("Masukkan banyak barang belanjaan (maksimal 10): ");
            if (scanf("%d", &jumlahBarang) != 1) {
                printf("Error: Input harus berupa angka!\n");
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            }
            while ((c = getchar()) != '\n' && c != EOF);
            
            if (jumlahBarang < 1 || jumlahBarang > 10) {
                printf("Error: Jumlah barang harus antara 1-10!\n\n");
            }
        } while (jumlahBarang < 1 || jumlahBarang > 10);
        for (int i = 0; i < jumlahBarang; i++) {
            do {
                printf("Masukkan harga ke-%d: Rp", i+1);
                if (scanf("%f", &harga[i]) != 1) {
                    printf("Error: Input harus berupa angka!\n");
                    while ((c = getchar()) != '\n' && c != EOF);
                    continue;
                }
                while ((c = getchar()) != '\n' && c != EOF);
                
                if (harga[i] <= 0) {
                    printf("Error: Harga harus lebih dari 0!\n");
                }
            } while (harga[i] <= 0);
        }
        printf("\nDaftar Harga:\n");
        for (int i = 0; i < jumlahBarang; i++) {
            printf("Harga ke-%d: Rp%.2f\n", i+1, harga[i]);
            totalHarga += harga[i];
        }
        printf("\nTotal harga: Rp%.2f\n", totalHarga);
        printf("\nIngin menghitung belanjaan lagi? (y/n): ");
        scanf(" %c", &pilihan);
        while ((c = getchar()) != '\n' && c != EOF);
    } while (pilihan == 'y' || pilihan == 'Y');
    printf("\nTerima kasih telah menggunakan program ini!\n");
    system("pause");
}
void Matriks_2x2(){
    int A[2][2], B[2][2], C[2][2];
    char pilihan;
    do{
    system("cls");
    printf("===========================================================================\n");
    printf("|                       PROGRAM PENJUMLAHAN MATRIKS 2x2                   |\n");
    printf("===========================================================================\n");
    printf("Masukkan elemen matriks A (2x2):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Matriks A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n");
    printf("Masukkan elemen matriks B (2x2):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Matriks B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("\nHasil Penjumlahan Matriks A + B:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("\nApakah ingin mengulang lagi? (y/n): ");
    scanf(" %c", &pilihan);
    }while(pilihan == 'y' || pilihan == 'Y');
}

int main(){
    int pilihan;
    do{
        system("cls");
        printf("=========================================================\n");
        printf("|                   MENU UTAMA PROGRAM                  |\n");
        printf("=========================================================\n");
        printf("|1. Program Segitiga Terbalik                           |\n");
        printf("|2. Program Hitung Total Belanjaan                      |\n");
        printf("|3. Penjumlahan Matriks 2x2                             |\n");
        printf("|0. KELUAR                                              |\n");
        printf("=========================================================\n");
        printf("MASUKAN PILIHAN ANDA : ");
        if (scanf("%d", &pilihan) != 1) {
            while (getchar() != '\n'); 
            printf("Pilihan invalid! Pilihan harus berupa angka. Tekan Enter untuk mengulangi...");
            getch();
            printf("\n") ;
            main();
        }
        switch(pilihan){
            case 1:
            system("cls");
            Program_Segitiga_Terbalik();
                break;
            case 2:
                system("cls");
                Program_Belanjaan();
                break;
            case 3:
                system("cls");
                Matriks_2x2();
                break;
            case 0:
                system("cls");
                printf("TERIMA KASIH\n");
                exit(0);
                break;
            default:
                printf("Pilihan tidak ada\n");
                system("pause");
                break;
        }
    }while(1);
    return 0;
}