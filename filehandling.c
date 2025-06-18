#include <stdio.h>

int main(){
    FILE *fptr = fopen("main.txt", "w");
    // FILE *another = fopen("another.txt", "w");
    if(fptr == NULL){
        printf("Error!");
        return 1;
    }
    fprintf(fptr, "Hello World!");
    fprintf(fptr, "ini baris kedua");
    fclose(fptr);
    fptr = fopen("main.txt", "r");
    if(fptr == NULL){
        printf("Error!");
        return 1;
    }
    char line[256];
    while (fgets)
    {
        /* code */
    }
    
    return 0;
}