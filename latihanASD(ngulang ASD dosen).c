#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n){
    int i, j, temp;
    for ( i = 0; i < n-1; i++)
    {
        int swapped = 0;
        for ( j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
}
void selectionSort(int arr[], int n){
    int i, j, minIndex, temp;
    for(i = 0; i < n-1; i++){
        minIndex = i;
        for(j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void insertionSort(int arr[] int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main(){
    //mencari nim dengan menginput angka dengan menggunakan linear search
    // int nim[10] = {672024104, 672024105, 672024110, 672024120, 672024121, 672024122, 672024123, 672024124, 672024125, 672024126};
    // int i, cari, ketemu = 0;
    // printf("Masukkan NIM : ");
    // scanf("%d", &cari);
    // for(i = 0; i < 10; i++){
    //     if(cari == nim[i]){
    //         ketemu = 1;
    //         break;
    //     }
    // }
    // if(ketemu == 1){
    //     printf("data %d ditemukan di index ke-%d", cari, i);
    // }else{
    //     printf("data %d tidak ditemukan", cari);
    // }



    return 0;
}