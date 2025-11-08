#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    int nim;
    char nama[30];
    float ipk;
} Mahasiswa;

int main() {
    int n, i, idx_max = 0, idx_min = 0;
    Mahasiswa mhs[MAX];
    float total = 0, rata2;
    printf("MENCARI IPK TERBESAR, TERKECIL, MENGHITUNG RATA-RATA\n");
    printf("Berapa jumlah mahasiswa : ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("\nNIM Mahasiswa ke-%d : ", i+1);
        scanf("%d", &mhs[i].nim);
        printf("Nama Mahasiswa ke-%d : ", i+1);
        scanf("%s", mhs[i].nama);
        printf("IPK Mahasiswa ke-%d : ", i+1);
        scanf("%f", &mhs[i].ipk);
        total += mhs[i].ipk;
        if(mhs[i].ipk > mhs[idx_max].ipk) idx_max = i;
        if(mhs[i].ipk < mhs[idx_min].ipk) idx_min = i;
    }
    rata2 = total / n;
    printf("\nIPK terbesar adalah : %.3f atas nama %s\n", mhs[idx_max].ipk, mhs[idx_max].nama);
    printf("IPK terkecil adalah : %.3f atas nama %s\n", mhs[idx_min].ipk, mhs[idx_min].nama);
    printf("IPK rata-rata adalah : %.3f\n", rata2);
    return 0;
}