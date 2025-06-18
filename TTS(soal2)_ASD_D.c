//soal2
#include <stdio.h>

int hitung = 0;
int Konsonan(char nama[]) {
    int i;
    
    for(i = 0; nama[i] != '\0'; i++) {
        char huruf = nama[i];
        
        if((huruf >= 'A' && huruf <= 'Z') || (huruf >= 'a' && huruf <= 'z')) {
            if(huruf >= 'A' && huruf <= 'Z') {
                huruf = huruf + 32;
            }
            
            if(huruf != 'a' && huruf != 'i' && huruf != 'u' && 
               huruf != 'e' && huruf != 'o') {
                hitung++;
            }
        }
    }
    return hitung;
}

int main() {
    char nama[100];
    printf("Nama Anda? ");
    scanf("%s", nama);
    hitung = Konsonan(nama);
    printf("\n\nJumlah konsonan = %i", hitung);
    
    return 0;
}