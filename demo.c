#include <stdio.h>

int main (){
    // int angka = 5;
    // printf("angka = %d\n", angka);

    // char huruf = 'a';
    // printf("huruf = %c\n", huruf);

    // float decimal = 3.8;
    // printf("decimal = %.2f\n", decimal);

    // int a, b;
    // char nama[20];
    
    // printf("masukan angka 1 :");
    // scanf("%d", &a);
    // printf("masukan angka 2 :");
    // scanf("%d", &b);
    // printf("masukan nama :");
    // scanf("%s", &nama);
    // // scanf(" %[^\n]", &nama);

    // printf("nama = %s\n", nama);
    // printf("hasil penjumlahan = %d\n", a + b);

    // int nomer1 = 9;
    // int nomer2 = 12;
    
    // int penjumlahan = nomer1 + nomer2;
    // int pengurangan = nomer1 - nomer2;
    // int perkalian = nomer1 * nomer2;
    // float pembagian = (float)nomer1 / nomer2;

    // printf("hasil penjumlahan dari %d + %d = %d\n", nomer1, nomer2, penjumlahan);
    // printf("hasil pengurangan dari %d - %d = %d\n", nomer1, nomer2, pengurangan);
    // printf("hasil perkalian dari %d * %d = %d\n", nomer1, nomer2, perkalian);
    // printf("hasil pembagian dari %d / %.d = %.2f\n", nomer1, nomer2, pembagian);

    float celsius, fahrenheit, reamur, kelvin;

    printf("Masukkan suhu dalam Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9/5) + 32;
    reamur = (celsius * 4/5);
    kelvin = (celsius + 273.15);

    printf("Suhu dalam Fahrenheit: %.2f\n", fahrenheit);
    printf("Suhu dalam Reamur: %.2f\n", reamur);
    printf("Suhu dalam Kelvin: %.2f\n", kelvin);
    return 0;
}