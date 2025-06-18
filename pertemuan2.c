#include <stdio.h>
#include <stdlib.h>

int main(){
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 1) {
            printf("%d angka ganjil\n", i);
        }
        else {
            printf("%d angka genap\n", i);
        }
    }
}