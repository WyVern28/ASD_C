#include <stdio.h>
#include <string.h>

int main() {
    int jumlahKelas;
    float jumlahMahasiswa[50];
    float nilaiMahasiswa[50][50];
    do{
    printf("Masukkan banyak kelas: ");
    scanf("%d", &jumlahKelas);
        if(jumlahKelas < 0) {
            printf("Jumlah kelas tidak boleh negatif\n");
        }else if(jumlahKelas > 50) {
            printf("Jumlah kelas tidak boleh lebih dari 50\n");
        }
    }while (jumlahKelas < 0 || jumlahKelas > 50);
    for(int i = 0; i < jumlahKelas; i++) {
        do{
        printf("Masukkan banyak mahasiswa di kelas - %d : ", i + 1);
        scanf("%f", &jumlahMahasiswa[i]);
        if(jumlahMahasiswa[i] < 0) {
            printf("Jumlah mahasiswa tidak boleh negatif\n");
        }else if(jumlahMahasiswa[i] > 50) {
            printf("Jumlah mahasiswa tidak boleh lebih dari 50\n");
        }
        }while (jumlahMahasiswa[i] < 0 || jumlahMahasiswa[i] > 50);
        for(int j = 0; j < jumlahMahasiswa[i]; j++) {
            printf("Masukkan nilai - %d dari kelas %d :", j + 1, i + 1);
            scanf("%f", &nilaiMahasiswa[i][j]);
        }
    }
    printf("\n");
    for(int i = 0; i < jumlahKelas; i++) {
        float totalNilai = 0;
        for(int j = 0; j < jumlahMahasiswa[i]; j++) {
            totalNilai += nilaiMahasiswa[i][j];
        }
        float rataRata = totalNilai / jumlahMahasiswa[i];
        int jumlahLulus = 0;
        for(int j = 0; j < jumlahMahasiswa[i]; j++) {
            if(nilaiMahasiswa[i][j] >= rataRata) {
                jumlahLulus++;
            }
        }
        float persentaseLulus = (float)jumlahLulus / jumlahMahasiswa[i] * 100;
        printf("yg lulus di kelas %d = %.2f%%\n", i + 1, persentaseLulus);
    }
    return 0;
}