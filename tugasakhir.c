#include <stdio.h>
#include <string.h>

#define MAKS_MAHASISWA 100

// Struktur data untuk menyimpan data mahasiswa
typedef struct {
  char nim[10];
  char nama[50];
  char prodi[10];
  char angkatan[10];
  float ipk;
} Mahasiswa;


// Fungsi untuk menambah data mahasiswa
void tambahData(Mahasiswa *mhs, int *jumlahMhs) {
  printf("Masukkan NIM: ");
  scanf("%s", mhs[*jumlahMhs].nim);
  printf("\nMasukkan nama: ");
  fflush(stdin); gets(mhs[*jumlahMhs].nama);
  printf("Masukkan PRODI: ");
  scanf("%s", mhs[*jumlahMhs].prodi);
  printf("Masukkan angkatan: ");
  scanf("%s", mhs[*jumlahMhs].angkatan);
  printf("Masukkan IPK: ");
  scanf("%f", &mhs[*jumlahMhs].ipk);
  (*jumlahMhs)++;
}


// Fungsi untuk mencetak data mahasiswa
void cetakData(Mahasiswa mhs) {
  printf("NIM: %s\n", mhs.nim);
  printf("Nama: %s\n", mhs.nama);
  printf("PRODI: %s\n", mhs.prodi);
  printf("angkatan: %s\n", mhs.angkatan);
  printf("IPK: %.2f\n", mhs.ipk);
  printf("\n");
}

// Fungsi untuk Mengurutkan
void pengurutan(Mahasiswa *mhs,int *jumlahMhs)
{
    for (int i = 0; i < jumlahMhs; i++) {
        for (int j = i + 1; j < jumlahMhs; j++) {
            if (strcmp(mhs[i].nama, mhs[j].nama) > 0) {
                Mahasiswa temp = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = temp;
        }
        }
    }
}

// Fungsi utama
int main() {
  Mahasiswa mhs[MAKS_MAHASISWA];
  int jumlahMhs = 0;

  int pilihan;
  do {
    printf("Menu:\n");
    printf("1. Tambah data\n");
    printf("2. Cetak data\n");
    printf("3. Pengurutan\n");
    printf("4. Selesai\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
      tambahData(mhs, &jumlahMhs);
        FILE *file;
        file = fopen("output.txt", "w");
        for (int i = 0; i < jumlahMhs; i++) {
            fprintf(file, "Mahasiswa %d\n", i+1);
            fprintf(file, "NIM: %s\n", mhs[i].nim);
            fprintf(file, "Nama: %s\n", mhs[i].nama);
            fprintf(file, "PRODI: %s\n", mhs[i].prodi);
            fprintf(file, "angkatan: %s\n", mhs[i].angkatan);
            fprintf(file, "IPK: %.2f\n", mhs[i].ipk);
            fprintf(file, "\n");
        }
        fclose(file);
    } else if (pilihan == 2) {
      for (int i = 0; i < jumlahMhs; i++) {
        cetakData(mhs[i]);
      }
    }
    else if (pilihan == 3)
    {
        pengurutan(mhs, jumlahMhs);
      for (int i = 0; i < jumlahMhs; i++) {
        cetakData(mhs[i]);
      }
    }
    
  } while (pilihan != 4);

  return 0;
}