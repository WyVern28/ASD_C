#include<stdio.h>
#include<stdlib.h>
int main(){
    int angka[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("Isi Matriks [%d][%d]: ", i, j);
            scanf("%d", &angka[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("[%d][%d]: %d\n", i, j, angka[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}