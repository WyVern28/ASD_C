#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<unistd.h>

#define MAX_USERS 5
#define MAX_LENGTH 50
#define MAX_BOOKS 100

struct User {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

struct Book {
    int id;
    char judul[MAX_LENGTH];
    char penulis[MAX_LENGTH];
    int tahunTerbit;
};

struct User users[MAX_USERS] = {
    {"admin", "123"},
};

struct Book books[MAX_BOOKS];
int totalUsers = 1;
int totalBooks = 0;

void loadingawal() {
    system("cls");
    printf("\033[0;32m");

    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t\t SELAMAT DATANG\n");
    printf("\t\t\t\t\t\t    Loading:\n\n");

    for (int i = 0; i <= 50; i++) {
        int percentage = (i * 2);
        printf("\r\t\t\t%3d%% [", percentage);
        for (int j = 0; j < i; j++) {
            printf("=");
        }
        for (int k = i; k < 50; k++) {
            printf(" ");
        }
        printf("]");
        fflush(stdout);
        usleep(100000);
    }
    printf("\n\n\t\t\t\t\t\tLoading Selesai!\n");
    printf("\033[0m");
}

void inputString(char *str, int maxLength) {
    if (fgets(str, maxLength, stdin) != NULL) {
        size_t len = strlen(str);
        if (len > 0 && str[len-1] == '\n') {
            str[len-1] = '\0';
        }
    }
}

int loginUser(struct User users[], int totalUsers, char *inputUsername, char *inputPassword) {
    for (int i = 0; i < totalUsers; i++) {
        if (strcmp(users[i].username, inputUsername) == 0 && 
            strcmp(users[i].password, inputPassword) == 0) {
            return 1;
        }
    }
    return 0;
}

void displayMainMenu() {
    system("cls");
    printf("\t\t\t============= LOGIN =============\n");
    printf("\t\t\t= 1. Login                      =\n");
    printf("\t\t\t= 2. Keluar                     =\n");
    printf("\t\t\t=================================\n");
}

void tambahSemuaBuku() {
    int jumlahBuku;
    int validInput = 0;
    
    system("cls");
    printf("\t\t\t======== TAMBAH BUKU ========\n");
    while (!validInput) {
        printf("\t\t\tBerapa buku yang ingin ditambahkan? ");
        
        if (scanf("%d", &jumlahBuku) != 1) {
            printf("\n\t\t\tERROR: Input harus berupa angka!\n");
            while (getchar() != '\n');
            continue;
        }
        
        if (jumlahBuku < 0) {
            printf("\n\t\t\tERROR: Jumlah buku tidak boleh negatif!\n");
            getchar();
            continue;
        }
        
        if (jumlahBuku == 0) {
            printf("\n\t\t\tJumlah buku harus lebih dari 0!\n");
            getchar();
            continue;
        }
        
        if ((totalBooks + jumlahBuku) > MAX_BOOKS) {
            printf("\n\t\t\tERROR: Jumlah buku melebihi kapasitas maksimum (%d)!\n", MAX_BOOKS);
            printf("\t\t\tKapasitas tersisa: %d buku\n", MAX_BOOKS - totalBooks);
            getchar();
            continue;
        }
        validInput = 1;
        getchar();
    }
    for (int i = 0; i < jumlahBuku; i++) {
        books[totalBooks].id = totalBooks + 1;
        
        printf("\n\t\t\t--- Buku ke-%d ---\n", i + 1);
        printf("\t\t\tJudul Buku: ");
        inputString(books[totalBooks].judul, MAX_LENGTH);
        
        printf("\t\t\tPenulis: ");
        inputString(books[totalBooks].penulis, MAX_LENGTH);
        int validYear = 0;
        while (!validYear) {
            printf("\t\t\tTahun Terbit: ");
            if (scanf("%d", &books[totalBooks].tahunTerbit) != 1) {
                printf("\t\t\tERROR: Tahun harus berupa angka!\n");
                while (getchar() != '\n');
                continue;
            }
            if (books[totalBooks].tahunTerbit < 0) {
                printf("\t\t\tERROR: Tahun tidak boleh negatif!\n");
                getchar();
                continue;
            }   
            if (books[totalBooks].tahunTerbit > 2025) {
                printf("\t\t\tERROR: Tahun tidak boleh lebih dari 2025!\n");
                getchar();
                continue;
            }
            validYear = 1;
            getchar();
        }
        totalBooks++;
    }
    printf("\n\t\t\t%d buku berhasil ditambahkan!\n", jumlahBuku);
    printf("\t\t\tTekan Enter untuk melihat daftar buku...");
    getchar();
}

void lihatSemuaBuku() {
    system("cls");
    printf("\t\t\t========== DAFTAR BUKU ==========\n");
    
    if (totalBooks == 0) {
        printf("\t\t\tTidak ada buku yang tersedia.\n");
    } else {
        printf("\n\t\t\t%-3s %-25s %-20s %-6s\n", "ID", "Judul", "Penulis", "Tahun");
        printf("\t\t\t================================================================\n");
        for (int i = 0; i < totalBooks; i++) {
            printf("\t\t\t%-3d %-25s %-20s %-6d\n", 
                   books[i].id, 
                   books[i].judul, 
                   books[i].penulis, 
                   books[i].tahunTerbit);
        }
        printf("\t\t\t================================================================\n");
    }
    
    printf("\n\t\t\tTotal buku: %d\n", totalBooks);
    printf("\t\t\tTekan Enter untuk kembali ke menu utama...");
    getchar();
}

void displayBookMenu() {
    system("cls");
    printf("\t\t\t======== MANAJEMEN BUKU ========\n");
    printf("\t\t\t= 1. Tambah Buku                =\n");
    printf("\t\t\t= 2. Lihat Daftar Buku          =\n");
    printf("\t\t\t= 3. Logout                     =\n");
    printf("\t\t\t=================================\n");
}

void bookManagement() {
    int choice;
    
    while (1) {
        displayBookMenu();
        printf("\t\t\tPilih menu: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                tambahSemuaBuku();
                lihatSemuaBuku();
                break;
            case 2:
                lihatSemuaBuku();
                break;
            case 3:
                printf("\n\t\t\tLogout berhasil!\n");
                printf("\t\t\tTekan Enter untuk kembali ke menu login...");
                getchar();
                return;
            default:
                system("cls");
                printf("\t\t\tPilihan tidak valid. Silakan coba lagi.\n");
                printf("\t\t\tTekan Enter untuk melanjutkan...");
                getchar();
                break;
        }
    }
}

void loginForm() {
    char inputUsername[MAX_LENGTH];
    char inputPassword[MAX_LENGTH];
    
    system("cls");
    printf("\t\t\t========== FORM LOGIN ==========\n");
    printf("\t\t\tUsername: ");
    inputString(inputUsername, MAX_LENGTH);
    
    printf("\t\t\tPassword: ");
    inputString(inputPassword, MAX_LENGTH);
    
    if (loginUser(users, totalUsers, inputUsername, inputPassword)) {
        system("cls");
        printf("\t\t\t============================\n");
        printf("\t\t\t    LOGIN BERHASIL!  \n");
        printf("\t\t\t    Selamat datang, %s!\n", inputUsername);
        printf("\t\t\t============================\n");
        printf("\t\t\tTekan Enter untuk melanjutkan...");
        getchar();
        bookManagement();
    } else {
        system("cls");
        printf("\t\t\t============================\n");
        printf("\t\t\t     LOGIN GAGAL!    \n");
        printf("\t\t\t Username atau password salah\n");
        printf("\t\t\t============================\n");
        printf("\t\t\tTekan Enter untuk kembali...");
        getchar();
    }
}

int main() {
    int choice;
    loadingawal();
    while (1) {
        system("color d");
        displayMainMenu();
        printf("\t\t\tPilih menu: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                loginForm();
                break;
            case 2:
                system("cls");
                printf("\t\t\tTerima kasih! Sampai Jumpa.\n");
                exit(0);
                break;
            default:
                system("cls");
                printf("\t\t\tPilihan tidak valid. Silakan coba lagi.\n");
                printf("\t\t\tTekan Enter untuk melanjutkan...");
                getchar();
                break;
        }
    }
    return 0;
}