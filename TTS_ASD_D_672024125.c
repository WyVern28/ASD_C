//soal 1
#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    int NIM;
    char Nama[25];
    float IPK;
};
void bubbleSort(struct Mahasiswa data[], int n) {
    int i, j;
    struct Mahasiswa temp;
    
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(data[j].IPK < data[j+1].IPK) {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

int main() {
    struct Mahasiswa mhs[100];
    int n, i;
    
    printf("PENGURUTAN (SORTING) - METODE GELEMBUNG (BUBBLE SORT)\n");
    printf("Berapa jumlah mahasiswa: ");
    scanf("%d", &n);
    printf("\n");
    for(i = 0; i < n; i++) {
        printf("NIM Mahasiswa ke-%d : ", i+1);
        scanf("%d", &mhs[i].NIM);
        printf("Nama Mahasiswa ke-%d : ", i+1);
        scanf("%s", mhs[i].Nama);
        printf("IPK Mahasiswa ke-%d : ", i+1);
        scanf("%f", &mhs[i].IPK);
        printf("\n");
    }
    bubbleSort(mhs, n);
    
    printf("Setelah Sorting Descending (urut turun menurut IPK) :\n\n");
    for(i = 0; i < n; i++) {
        printf("No Urut %d: NIM: %d, Nama: %s, IPK: %.3f\n", 
               i+1, mhs[i].NIM, mhs[i].Nama, mhs[i].IPK);
    }
    
    return 0;
}