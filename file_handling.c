#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("data.txt", "w");  // w = write (tulis baru)
    if (fp == NULL) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    fprintf(fp, "Halo, ini ditulis dari C!\n");
    fprintf(fp, "Angka favorit saya: %d\n", 42);

    fclose(fp);
    printf("Data berhasil ditulis ke file.\n");

    return 0;
}



// #include <stdio.h>

// int main() {
//     FILE *fp;
//     char buffer[100];

//     fp = fopen("data.txt", "r");  // r = read (baca)
//     if (fp == NULL) {
//         printf("File tidak ditemukan.\n");
//         return 1;
//     }

//     printf("Isi file:\n");
//     while (fgets(buffer, sizeof(buffer), fp) != NULL) {
//         printf("%s", buffer);
//     }

//     fclose(fp);
//     return 0;
// }