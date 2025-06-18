#include<stdio.h>
#include<stdlib.h>

void PROGRAM_PENENTUAN_KELULUSAN() {
    float nilai_uts, nilai_uas, nilai_tugas, persentase_kehadiran;
    int status_proyek;
    float nilai_akhir;
    char lanjut;    
    do {
        system("cls");    
        printf("================================================================\n");
        printf("|            PROGRAM PENENTUAN KELULUSAN MAHASISWA            |\n");
        printf("================================================================\n");
        printf("Masukkan nilai UTS (0-100): ");
        if (scanf("%f", &nilai_uts) != 1) {
            printf("\nInputan tidak valid! silahkan memasukan angka.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        if (nilai_uts < 0 || nilai_uts > 100) {
            printf("\nNilai UTS tidak valid! harap masukan angka 0-100.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        printf("Masukkan nilai UAS (0-100): ");
        if (scanf("%f", &nilai_uas) != 1) {
            printf("\nInputan tidak valid! silahkan memasukan angka.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        if (nilai_uas < 0 || nilai_uas > 100) {
            printf("\nNilai UAS tidak valid! harap masukan angka 0-100.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        printf("Masukkan nilai tugas (0-100): ");
        if (scanf("%f", &nilai_tugas) != 1) {
            printf("\nInputan tidak valid! silahkan memasukan angka.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        if (nilai_tugas < 0 || nilai_tugas > 100) {
            printf("\nNilai tugas tidak valid! harap masukan angka 0-100.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        printf("Masukkan persentase kehadiran (0-100): ");
        if (scanf("%f", &persentase_kehadiran) != 1) {
            printf("\nInputan tidak valid! silahkan memasukan angka.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        if (persentase_kehadiran < 0 || persentase_kehadiran > 100) {
            printf("\nPersentase kehadiran tidak valid! harap masukan angka 0-100.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        printf("Status proyek akhir (0=belum selesai, 1=selesai): ");
        if (scanf("%d", &status_proyek) != 1) {
            printf("\nInputan tidak valid! silahkan memasukan angka.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        if (status_proyek != 0 && status_proyek != 1) {
            printf("\nStatus proyek tidak valid! harap masukan angka 0 atau 1.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        nilai_akhir = (nilai_uts * 0.3) + (nilai_uas * 0.4) + (nilai_tugas * 0.2) + (persentase_kehadiran * 0.1);
        printf("\n================================================================\n");
        printf("|                       HASIL EVALUASI                         |\n");
        printf("================================================================\n");
        printf("Nilai akhir: %.2f\n", nilai_akhir);
        
        if (status_proyek == 1) {
            printf("Status proyek: Selesai\n");
        } else {
            printf("Status proyek: Belum selesai\n");
        }
        if (nilai_akhir >= 90 && status_proyek == 1) {
            printf("Status kelulusan: Lulus dengan predikat Cum Laude\n");
        } else if (nilai_akhir >= 80 && nilai_akhir < 90 && status_proyek == 1) {
            printf("Status kelulusan: Lulus dengan predikat Sangat Memuaskan\n");
        } else if (nilai_akhir >= 70 && nilai_akhir < 80 && status_proyek == 1) {
            printf("Status kelulusan: Lulus dengan predikat Memuaskan\n");
        } else if (nilai_akhir >= 60 && nilai_akhir < 70 && status_proyek == 1) {
            printf("Status kelulusan: Lulus\n");
        } else if (nilai_akhir >= 60 && status_proyek == 0) {
            printf("Status kelulusan: Lulus Bersyarat(harus menyelesaikan proyek akhir)\n");
        } else if (nilai_akhir < 60) {
            printf("Status kelulusan: Tidak Lulus\n");
            printf("Keterangan: Nilai akhir kurang dari 60\n");
            if (status_proyek == 0) {
                printf("Proyek akhir belum selesai\n");
            }
        }
        printf("\nApakah anda ingin lanjut? (y/n): ");
        while (getchar() != '\n');
        scanf("%c", &lanjut);
        
    } while (lanjut == 'y' || lanjut == 'Y');
}
void PROGRAM_EVALUASI_KARYAWAN() {
    float produktivitas, kedisiplinan, kreativitas;
    int lama_kerja;
    float nilai_total;
    char lanjut;
    do {
        system("cls");
        printf("================================================================\n");
        printf("|               PROGRAM EVALUASI KARYAWAN                      |\n");
        printf("================================================================\n");
        printf("Masukkan nilai produktivitas (0-100): ");
        if (scanf("%f", &produktivitas) != 1) {
            printf("\nInputan tidak valid! silahkan memasukan angka.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        if (produktivitas < 0 || produktivitas > 100) {
            printf("\nNilai produktivitas tidak valid! harap masukan angka 0-100.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        printf("Masukkan nilai kedisiplinan (0-100): ");
        if (scanf("%f", &kedisiplinan) != 1) {
            printf("\nInputan tidak valid! silahkan memasukan angka.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        if (kedisiplinan < 0 || kedisiplinan > 100) {
            printf("\nNilai kedisiplinan tidak valid! harap masukan angka 0-100.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        printf("Masukkan nilai kreativitas (0-100): ");
        if (scanf("%f", &kreativitas) != 1) {
            printf("\nInputan tidak valid! silahkan memasukan angka.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        if (kreativitas <.0 || kreativitas > 100) {
            printf("\nNilai kreativitas tidak valid! harap masukan angka 0-100.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        printf("Masukkan lama kerja (tahun): ");
        if (scanf("%d", &lama_kerja) != 1) {
            printf("\nInputan tidak valid! silahkan memasukan angka.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        if (lama_kerja < 0) {
            printf("\nLama kerja tidak valid! harap masukan angka positif.\n");
            printf("Tekan Enter untuk kembali...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        nilai_total = (produktivitas * 0.4) + (kedisiplinan * 0.3) + (kreativitas * 0.2);
        printf("\n================================================================\n");
        printf("|                       HASIL EVALUASI                         |\n");
        printf("================================================================\n");
        printf("Nilai Total: %.2f\n", nilai_total);
        printf("Hasil Evaluasi: ");
        if (lama_kerja < 1) {
            printf("Belum Memenuhi Syarat Evaluasi\n");
            system("pause");
        } else if (produktivitas < 50) {
            printf("Perlu Pelatihan");
            if (kreativitas >= 80) {
                printf(" + Bonus Inovasi");
            }
            printf("\n");
        } else if (kedisiplinan < 60) {
            printf("Perlu Pelatihan");
            if (kreativitas >= 80) {
                printf(" + Bonus Inovasi");
            }
            printf("\n");
        } else {
            if (nilai_total >= 85) {
                printf("Promosi Jabatan");
            } else if (nilai_total >= 75 && nilai_total < 85) {
                printf("Kenaikan Gaji 20%%");
            } else if (nilai_total >= 65 && nilai_total < 75) {
                printf("Pertahankan Kinerja");
            } else if (nilai_total >= 50 && nilai_total < 65) {
                printf("Perlu Perbaikan");
            } else {
                printf("Evaluasi Khusus");
            }
            
            if (kreativitas >= 80) {
                printf(" + Bonus Inovasi");
            }
            printf("\n");
        }
        printf("\nApakah anda ingin mengevaluasi karyawan lain? (y/n): ");
        scanf(" %c", &lanjut);
        
    } while (lanjut == 'y' || lanjut == 'Y');
}
int main(){
    int pilihan;
    do{
        system("cls");
        printf("=========================================================\n");
        printf("|\t\t\tMENU UTAMA PROGRAM\t\t|\n");
        printf("=========================================================\n");
        printf("|1. PROGRAM PENENTUAN KELULUSAN MAHASISWA (if-else)\t|\n");
        printf("|2. EVALUASI KINERJA KARYAWAN (if-else)\t\t\t|\n");
        printf("|0. KELUAR\t\t\t\t\t\t|\n");
        printf("=========================================================\n");
        printf("MASUKAN PILIHAN ANDA : ");
        if (scanf("%d", &pilihan) != 1) {
            while (getchar() != '\n'); 
            printf("Pilihan invalid! Pilihan harus berupa angka. Tekan Enter untuk mengulangi...");
            getch();
            printf("\n") ;
            main();
        }
        switch(pilihan){
            case 1:
            system("cls");
                PROGRAM_PENENTUAN_KELULUSAN();
                break;
            case 2:
                system("cls");
                PROGRAM_EVALUASI_KARYAWAN();
                break;
            case 0:
                system("cls");
                printf("TERIMA KASIH\n");
                exit(0);
                break;
            default:
                printf("Pilihan tidak ada\n");
                system("pause");
                break;
        }
    }while(1);       
}