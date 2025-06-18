#include <stdio.h>

int main() {
    // int n;
    int array[10];
    for(int i=0; i<=9; i++){
    printf("masukan angka untuk array ke-%d= ", i);
    scanf("%d", &array[i]);
    }
    printf("List array = ");
    for (int j = 0; j < 10; j++)
    {
        printf("%d ", array[j]);
    }
    
    return 0;
}