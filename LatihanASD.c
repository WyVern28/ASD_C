#include <stdio.h>
void bubbleSort(int arr[], int jumlahData){
    int i, j, temp;
    for ( i = 0; i < jumlahData-1; i++)
    {
        for ( j = 0; j < jumlahData-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int data[] = {20, 21, 5, 7, 8, 1, 3, 19};
    int jumlahData = sizeof(data)/sizeof(data[0]);
    printf("Sebelum : \n");
    for(int i = 0; i<jumlahData;i++){
        printf("%d, ", data[i]);
    }
    printf("\n");
    bubbleSort(data, jumlahData);
    printf("Setelah : \n");
    for(int i = 0; i<jumlahData;i++){
        printf("%d, ", data[i]);
    }
    printf("\n");
    return 0;
}