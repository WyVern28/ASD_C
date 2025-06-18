#include <stdio.h>
#include <stdlib.h>

void soal1() {
    int a, b, c, d, f;
    printf("SOAL 1\n");
    printf("program yang melakukan operasi aritmatika campuran dengan empat variabel input Program ini meminta pengguna memasukkan nilai a, b, c, dan d, kemudian menghitung hasil dari ekspresi (a * b) + (c / d) - (a mod b).\n");
    printf("Operasi modulus (a b) digunakan untuk mendapatkan sisa pembagian, sementara operasi pembagian (c / d) menghasilkan hasil bagi.\n");
    printf("Program ini membantu memahami urutan operasi aritmatika dalam bahasa C dan cara kerja operator dasar\n");

    printf("Masukkan nilai a: "); 
    scanf("%d", &a);
    printf("Masukkan nilai b: "); 
    scanf("%d", &b);
    printf("Masukkan nilai c: "); 
    scanf("%d", &c);
    printf("Masukkan nilai d: "); 
    scanf("%d", &d);

    f = (a * b) + (c / d) - (a % b);

    printf("hasil: (%d * %d) + (%d / %d) - (%d %% %d) = %d\n", a, b, c, d, a, b, f);
}
void soal2() {
    float luas, keliling , r;
    float phi = 3.14;
    printf("SOAL 2\n");
    printf("Program meminta input berupa jari-jari lingkaran dalam satuan centimeter, kemudian menghitung luas dan keliling lingkaran menggunakan nilai phi yang telah ditetapkan.\n");
    printf("Rumus yang di gunakan adalah: \n");
    printf("Luas = phi * r * r\n");
    printf("Keliling = 2 * phi * r\n");
    printf("Masukan Jari -jari lingkaran(cm): ");
    scanf("%f", &r);
    luas = (float)phi * r * r;
    keliling = (float)2 * phi * r;
    printf("Luas Lingkaran = %.2f\n", luas);
    printf("Keliling Lingkaran = %.2f cm\n", keliling);
    
}
void soal3() {
    int x, y;
    float hasil;
    printf("SOAL 3\n");
    printf("Program meminta nilai x dan y dari pengguna, kemudian menghitung hasil dari ekspresi (x + y) * (x - y) / (x * y).");
    printf("Operasi ini menggabungkan penjumlahan, pengurangan, perkalian, dan pembagian dalam satu ekspresi matematika.\n");
    printf("Masukkan nilai x: "); 
    scanf("%d", &x);
    printf("Masukkan nilai y: "); 
    scanf("%d", &y);
    hasil = (float)(x + y) * (x - y) / (x * y);
    printf("Hasil dari (%d + %d) * (%d - %d) / (%d * %d) = %.2f\n", x, y, x, y, x, y, hasil);
}
void soal4() {
    int jam, menit, detik, totaldetik;
    printf("SOAL 4\n");
    printf("Pengguna dimasukkan waktu dalam format tiga bilangan yang di pisahkan menjadi titik dua, kemudian program menghitung total detik dengan mengkonversi jam menjadi 3600 detik dan menit menjadi 60 detik.\n");
    printf("masukan waktu(jj:mm:dd): ");
    scanf("%d:%d:%d", &jam, &menit, &detik);
    totaldetik = (jam * 3600) + (menit * 60) + detik;
    printf("%02d:%02d:%02d = %d detik\n", jam, menit, detik, totaldetik);
}
void soal5() {
    int jamMasuk, menitMasuk, jamKeluar, menitKeluar, totalMasuk, totalKeluar, durasiMenit;
    float durasiJam, tarifperjam = 3000, biaya;
    printf("SOAL 5\n");
    printf("Program membandingkan waktu masuk dan keluar dalam format jam:menit, menghitung total durasi parkir dalam menit, kemudian mengkonversinya ke jam (termasuk pecahan) untuk menghitung biaya dengan tarif tetap Rp3000 per jam.\n");
    printf("Masukkan waktu masuk (jj:mm): ");
    scanf("%d:%d", &jamMasuk, &menitMasuk);
    printf("Masukkan waktu keluar (jj:mm): ");
    scanf("%d:%d", &jamKeluar, &menitKeluar);
    totalMasuk = jamMasuk * 60 + menitMasuk;
    totalKeluar = jamKeluar * 60 + menitKeluar;
    durasiMenit = totalKeluar - totalMasuk;
    durasiJam = durasiMenit / 60.0;
    biaya = durasiJam * tarifperjam;
    printf("Durasi parkir: %d menit (%.2f jam)\n", durasiMenit, durasiJam);
    printf("Biaya parkir: Rp%.0f\n", biaya);
}
int main() {    
    soal1();
    system("pause");
    system("cls");
    soal2();
    system("pause");
    system("cls");
    soal3();
    system("pause");
    system("cls");
    soal4();
    system("pause");
    system("cls");
    soal5();
    
    return 0;
}
