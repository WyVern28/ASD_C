#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_BOOKS 100
#define MAX_STRING 100
#define MENU_COUNT 6
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

typedef struct {
    int id;
    char judul[MAX_STRING];
    char pengarang[MAX_STRING];
    char penerbit[MAX_STRING];
    int tahun;
    int tersedia;
} Buku;

Buku perpustakaan[MAX_BOOKS];
int jumlah_buku = 0;

// Array menu items
char menu_items[MENU_COUNT][50] = {
    "Tambah Buku",
    "Hapus Buku", 
    "Edit Buku",
    "Tampilkan Daftar Buku",
    "Urutkan Buku (Judul)",
    "Exit"
};

// Deklarasi fungsi
void simpanKeFile();
void muatDariFile();
void clearScreen();
int login();
void tampilkanMenu(int selected);
int navigasiMenu();
int generateID();
void tambahBuku();
void tampilkanBuku();
void hapusBuku();
void editBuku();
void urutkanBuku();

void clearScreen() {
    system("cls");
}

int login() {
    char username[50], password[50];
    printf("\n");
    printf("=================================\n");
    printf("              LOGIN              \n");
    printf("=================================\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    
    // Login username: admin
    // login password: admin123
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        printf("\nLogin berhasil! Selamat datang, %s\n", username);
        printf("Tekan enter untuk melanjutkan...");
        getch();
        return 1;
    } else {
        printf("\nLogin gagal! Username atau password salah.\n");
        printf("Tekan enter untuk mencoba lagi...");
        getch();
        return 0;
    }
}

void tampilkanMenu(int selected) {
    clearScreen();
    printf("\n=================================\n");
    printf("         MENU PERPUSTAKAAN       \n");
    printf("=================================\n");
    printf("Gunakan arrow untuk memilih menu\n");
    printf("=================================\n");
    
    for (int i = 0; i < MENU_COUNT; i++) {
        if (i == selected) {
            printf("[x] %s\n", menu_items[i]);
        } else {
            printf("[ ] %s\n", menu_items[i]);
        }
    }
    printf("=================================\n");
    printf("Gunakan panah atas/bawah untuk navigasi, Enter untuk memilih, ESC untuk keluar\n");
}

int navigasiMenu() {
    int selected = 0; // Index menu yang dipilih (mulai dari 0)
    int key;
    
    while (1) {
        tampilkanMenu(selected);
        
        key = getch();
        
        if (key == 224) { // Arrow key prefix
            key = getch(); // Baca karakter kedua
            
            switch (key) {
                case KEY_UP:
                    selected--;
                    if (selected < 0) {
                        selected = MENU_COUNT - 1; // Wrap ke menu terakhir
                    }
                    break;
                    
                case KEY_DOWN:
                    selected++;
                    if (selected >= MENU_COUNT) {
                        selected = 0; // Wrap ke menu pertama
                    }
                    break;
            }
        }
        else if (key == KEY_ENTER) {
            return selected + 1; // Return 1-based index untuk kompatibilitas
        }
        else if (key == 27) { // ESC key untuk keluar
            return -1; // Return -1 untuk exit
        }
    }
}

int generateID() {
    int id = 1;
    int found;
    
    while (1) {
        found = 0;
        for (int i = 0; i < jumlah_buku; i++) {
            if (perpustakaan[i].id == id) {
                found = 1;
                break;
            }
        }
        if (!found) return id;
        id++;
    }
}

// Fungsi untuk menambah buku
void tambahBuku() {
    if (jumlah_buku >= MAX_BOOKS) {
        printf("\nPerpustakaan sudah penuh!\n");
        return;
    }
    
    printf("\n=== TAMBAH BUKU BARU ===\n");
    
    perpustakaan[jumlah_buku].id = generateID();
    printf("ID Buku: %d (otomatis)\n", perpustakaan[jumlah_buku].id);
    
    printf("Judul Buku: ");
    getchar();
    fgets(perpustakaan[jumlah_buku].judul, MAX_STRING, stdin);
    perpustakaan[jumlah_buku].judul[strcspn(perpustakaan[jumlah_buku].judul, "\n")] = 0;
    
    printf("Pengarang: ");
    fgets(perpustakaan[jumlah_buku].pengarang, MAX_STRING, stdin);
    perpustakaan[jumlah_buku].pengarang[strcspn(perpustakaan[jumlah_buku].pengarang, "\n")] = 0;
    
    printf("Penerbit: ");
    fgets(perpustakaan[jumlah_buku].penerbit, MAX_STRING, stdin);
    perpustakaan[jumlah_buku].penerbit[strcspn(perpustakaan[jumlah_buku].penerbit, "\n")] = 0;
    
    printf("Tahun Terbit: ");
    scanf("%d", &perpustakaan[jumlah_buku].tahun);
    
    perpustakaan[jumlah_buku].tersedia = 1;
    
    jumlah_buku++;
    simpanKeFile();
    printf("\nBuku berhasil ditambahkan dan disimpan ke file!\n");
}

void tampilkanBuku() {
    if (jumlah_buku == 0) {
        printf("\nTidak ada buku dalam perpustakaan.\n");
        return;
    }
    
    printf("\n=== DAFTAR BUKU PERPUSTAKAAN ===\n");
    printf("%-5s %-25s %-20s %-15s %-6s %-10s\n", "ID", "Judul", "Pengarang", "Penerbit", "Tahun", "Status");
    printf("================================================================================\n");
    
    for (int i = 0; i < jumlah_buku; i++) {
        printf("%-5d %-25s %-20s %-15s %-6d %-10s\n",
               perpustakaan[i].id,
               perpustakaan[i].judul,
               perpustakaan[i].pengarang,
               perpustakaan[i].penerbit,
               perpustakaan[i].tahun,
               perpustakaan[i].tersedia ? "Tersedia" : "Dipinjam");
    }
}

void hapusBuku() {
    if (jumlah_buku == 0) {
        printf("\nTidak ada buku untuk dihapus.\n");
        return;
    }
    
    int id, found = -1;
    printf("\n=== HAPUS BUKU ===\n");
    tampilkanBuku();
    printf("\nMasukkan ID buku yang akan dihapus: ");
    scanf("%d", &id);
    for (int i = 0; i < jumlah_buku; i++) {
        if (perpustakaan[i].id == id) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        printf("Buku dengan ID %d tidak ditemukan!\n", id);
        return;
    }
    
    printf("\nBuku yang akan dihapus:\n");
    printf("Judul: %s\n", perpustakaan[found].judul);
    printf("Pengarang: %s\n", perpustakaan[found].pengarang);
    char konfirmasi;
    printf("\nApakah Anda yakin ingin menghapus buku ini? (y/n): ");
    scanf(" %c", &konfirmasi);
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        for (int i = found; i < jumlah_buku - 1; i++) {
            perpustakaan[i] = perpustakaan[i + 1];
        }
        jumlah_buku--;
        simpanKeFile();
        printf("Buku berhasil dihapus dan disimpan ke file!\n");
    } else {
        printf("Penghapusan dibatalkan.\n");
    }
}

void editBuku() {
    if (jumlah_buku == 0) {
        printf("\nTidak ada buku untuk diedit.\n");
        return;
    }
    
    int id, found = -1;
    printf("\n=== EDIT BUKU ===\n");
    tampilkanBuku();
    printf("\nMasukkan ID buku yang akan diedit: ");
    scanf("%d", &id);
    for (int i = 0; i < jumlah_buku; i++) {
        if (perpustakaan[i].id == id) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        printf("Buku dengan ID %d tidak ditemukan!\n", id);
        return;
    }
    
    printf("\nData buku saat ini:\n");
    printf("1. Judul: %s\n", perpustakaan[found].judul);
    printf("2. Pengarang: %s\n", perpustakaan[found].pengarang);
    printf("3. Penerbit: %s\n", perpustakaan[found].penerbit);
    printf("4. Tahun: %d\n", perpustakaan[found].tahun);
    printf("5. Status: %s\n", perpustakaan[found].tersedia ? "Tersedia" : "Dipinjam");
    
    int pilihan;
    printf("\nPilih data yang ingin diedit (1-5): ");
    scanf("%d", &pilihan);
    
    switch (pilihan) {
        case 1:
            printf("Judul baru: ");
            getchar();
            fgets(perpustakaan[found].judul, MAX_STRING, stdin);
            perpustakaan[found].judul[strcspn(perpustakaan[found].judul, "\n")] = 0;
            break;
        case 2:
            printf("Pengarang baru: ");
            getchar();
            fgets(perpustakaan[found].pengarang, MAX_STRING, stdin);
            perpustakaan[found].pengarang[strcspn(perpustakaan[found].pengarang, "\n")] = 0;
            break;
        case 3:
            printf("Penerbit baru: ");
            getchar();
            fgets(perpustakaan[found].penerbit, MAX_STRING, stdin);
            perpustakaan[found].penerbit[strcspn(perpustakaan[found].penerbit, "\n")] = 0;
            break;
        case 4:
            printf("Tahun baru: ");
            scanf("%d", &perpustakaan[found].tahun);
            break;
        case 5:
            printf("Status baru (1=Tersedia, 0=Dipinjam): ");
            scanf("%d", &perpustakaan[found].tersedia);
            break;
        default:
            printf("Pilihan tidak valid!\n");
            return;
    }
    
    simpanKeFile();
    printf("Data buku berhasil diupdate dan disimpan ke file!\n");
}

void urutkanBuku() {
    if (jumlah_buku <= 1) {
        printf("\nTidak cukup buku untuk diurutkan.\n");
        return;
    }
    printf("\n=== MENGURUTKAN BUKU BERDASARKAN JUDUL ===\n");
    for (int i = 0; i < jumlah_buku - 1; i++) {
        for (int j = 0; j < jumlah_buku - i - 1; j++) {
            if (strcmp(perpustakaan[j].judul, perpustakaan[j + 1].judul) > 0) {
                Buku temp = perpustakaan[j];
                perpustakaan[j] = perpustakaan[j + 1];
                perpustakaan[j + 1] = temp;
            }
        }
    }
    
    simpanKeFile();
    printf("Buku berhasil diurutkan berdasarkan judul (A-Z) dan disimpan ke file!\n");
    tampilkanBuku();
}

void simpanKeFile() {
    FILE *file = fopen("perpustakaan.txt", "w");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file untuk menulis!\n");
        return;
    }
    
    fprintf(file, "%d\n", jumlah_buku);
    for (int i = 0; i < jumlah_buku; i++) {
        fprintf(file, "%d|%s|%s|%s|%d|%d\n",
                perpustakaan[i].id,
                perpustakaan[i].judul,
                perpustakaan[i].pengarang,
                perpustakaan[i].penerbit,
                perpustakaan[i].tahun,
                perpustakaan[i].tersedia);
    }
    
    fclose(file);
    printf("Data berhasil disimpan ke file perpustakaan.txt\n");
}

void muatDariFile() {
    FILE *file = fopen("perpustakaan.txt", "r");
    if (file == NULL) {
        printf("File perpustakaan.txt tidak ditemukan. Memulai dengan data kosong...\n");
        jumlah_buku = 0;
        simpanKeFile();
        return;
    }
    
    if (fscanf(file, "%d", &jumlah_buku) != 1) {
        printf("File kosong atau error membaca. Memulai dengan data kosong...\n");
        fclose(file);
        jumlah_buku = 0;
        return;
    }
    fgetc(file);
    
    for (int i = 0; i < jumlah_buku; i++) {
        char line[500];
        if (fgets(line, sizeof(line), file) == NULL) {
            printf("Error membaca data buku ke-%d\n", i+1);
            break;
        }
        char *token = strtok(line, "|");
        if (token != NULL) perpustakaan[i].id = atoi(token);
        
        token = strtok(NULL, "|");
        if (token != NULL) strcpy(perpustakaan[i].judul, token);
        
        token = strtok(NULL, "|");
        if (token != NULL) strcpy(perpustakaan[i].pengarang, token);
        
        token = strtok(NULL, "|");
        if (token != NULL) strcpy(perpustakaan[i].penerbit, token);
        
        token = strtok(NULL, "|");
        if (token != NULL) perpustakaan[i].tahun = atoi(token);
        
        token = strtok(NULL, "|");
        if (token != NULL) perpustakaan[i].tersedia = atoi(token);
    }
    
    fclose(file);
    if (jumlah_buku > 0) {
        printf("Data berhasil dimuat dari file perpustakaan.txt (%d buku)\n", jumlah_buku);
    } else {
        printf("File kosong. Memulai dengan database kosong.\n");
    }
}

int main() {
    int pilihan;
    printf("Memuat data dari file...\n");
    muatDariFile();
    printf("Tekan enter untuk melanjutkan...");
    getch();
    
    while (!login()) {
        clearScreen();
    }
    
    do {
        pilihan = navigasiMenu(); // Menggunakan navigasi arrow key
        
        if (pilihan == -1) { // ESC ditekan
            printf("\nMenyimpan data terakhir ke file...\n");
            simpanKeFile();
            printf("Terima kasih telah menggunakan Sistem Perpustakaan!\n");
            break;
        }
        
        switch (pilihan) {
            case 1:
                clearScreen();
                tambahBuku();
                printf("\nTekan enter untuk kembali ke menu...");
                getch();
                break;
            case 2:
                clearScreen();
                hapusBuku();
                printf("\nTekan enter untuk kembali ke menu...");
                getch();
                break;
            case 3:
                clearScreen();
                editBuku();
                printf("\nTekan enter untuk kembali ke menu...");
                getch();
                break;
            case 4:
                clearScreen();
                tampilkanBuku();
                printf("\nTekan enter untuk kembali ke menu...");
                getch();
                break;
            case 5:
                clearScreen();
                urutkanBuku();
                printf("\nTekan enter untuk kembali ke menu...");
                getch();
                break;
            case 6:
                printf("\nMenyimpan data terakhir ke file...\n");
                simpanKeFile();
                printf("Terima kasih telah menggunakan Sistem Perpustakaan!\n");
                break;
            default:
                printf("\nPilihan tidak valid! Silakan coba lagi.\n");
                printf("Tekan enter untuk melanjutkan...");
                getch();
        }
    } while (pilihan != 6 && pilihan != -1);
    
    return 0;
}