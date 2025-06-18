#include <stdio.h>
#include <string.h>

int main() {
    char target[100];
    int N, M;
    char combined[5000] = "";
    char temp[50];
    int count = 0;
    // printf("Combined string: %s\n", combined);
    // printf("Target: %s\n", target);
    // Membaca target angka
    scanf("%s", target);
    
    // Membaca N dan M  
    scanf("%d %d", &N, &M);
    
    // Membaca dan menggabungkan semua angka
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%s", temp);
            strcat(combined, temp);
        }
    }
    
    // Mencari kemunculan target
    int target_len = strlen(target);
    int combined_len = strlen(combined);
    
    // Loop untuk mencari pattern dengan manual comparison
    for (int i = 0; i <= combined_len - target_len; i++) {
        int match = 1;
        for (int j = 0; j < target_len; j++) {
            if (combined[i + j] != target[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            count++;
        }
    }
    
    printf("%d\n", count);
    return 0;
}