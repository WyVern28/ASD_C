#include<iostream>
#include<string>
using namespace std;

int main(){
    //membuat program menghitung nilai total dari 40% TTS dan 60% TAS dari seorang mahasiswa(menggunakan struct), lalu menghitung nilai rata2 kelasnya setelah menginput nilai nya
    const int jumlah_mhs = 3;
    struct mahasiswa{
        int no_urut;    
        string nama;
        float TTS, TAS;
        double total;
    };
    mahasiswa daftar_mhs[jumlah_mhs];
    double total_nilai_kelas = 0;
    for(int i = 0; i < jumlah_mhs; i++){
        cout << "\nMahasiswa ke-" << (i+1) << endl;
        cout << "Masukkan nomor urut: "; 
        cin >> daftar_mhs[i].no_urut;
        cout << "Masukkan nama: "; 
        cin >> daftar_mhs[i].nama;
        cout << "Masukkan nilai TTS: "; 
        cin >> daftar_mhs[i].TTS;
        cout << "Masukkan nilai TAS: "; 
        cin >> daftar_mhs[i].TAS;
        daftar_mhs[i].total = (daftar_mhs[i].TTS * 0.4) + (daftar_mhs[i].TAS * 0.6);
        total_nilai_kelas += daftar_mhs[i].total;
    }
    double nilai_rata2_kelas = total_nilai_kelas / jumlah_mhs;
    for(int i = 0; i < jumlah_mhs; i++){
        cout << "\nNomor urut: " << daftar_mhs[i].no_urut << endl;
        cout << "Nama: " << daftar_mhs[i].nama << endl;
        cout << "Nilai total: " << daftar_mhs[i].total << endl;
    }
    cout << "\nNilai rata-rata kelas: " << nilai_rata2_kelas << endl;
    
    return 0;
}