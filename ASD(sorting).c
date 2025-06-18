#include<stdio.h>

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
void selectionSort(int arr[], int jumlahData){
    int i, j, temp, minIndex;
    for ( i = 0; i < jumlahData - 1; i++)
    {
        minIndex = i;
        for ( j = i+1; j < jumlahData; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    if (minIndex != i)
    {
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
int binarySearch(int arr[], int jumlahData, int target){
    int left = 0;
    int right = jumlahData - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int linearSearch(int arr[], int jumlahData, int target){
    for (int i = 0; i < jumlahData; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int main(){
    int data[] = {2, 1, 5, 4, 3, 8, 9, 10};
    int n = sizeof(data)/sizeof(data[0]);
    printf("Sebelum : \n");
    for(int i = 0; i<n;i++){
        printf("%d, ", data[i]);
    }
    printf("\n");
    bubbleSort(data, n);

    printf("Setelah : \n");
    for(int i = 0; i<n;i++){
        printf("%d, ", data[i]);
    }
    printf("\n");
    printf("Sesudah Selection : \n");
    selectionSort(data, n);
    for(int i = 0; i<n;i++){
        printf("%d, ", data[i]);
    }
    printf("\n");
    printf("Target ditemukan di index : %d", binarySearch(data, n, 5));
    return 0;
}