#include <stdio.h>

// fungsi untuk membatasi diskon
// bertujuan untuk menghindari diskon besar yang disebabkan oleh harga barang yang besar, kelipatannya pun besar. jadi jika diskon lebih dari 50% maka diskon akan tetap disetting menjadi 50%.
int batasDiskon(int diskon)
{
  if (diskon > 50)
  {
    // kembalikan nilai 50 sebagai batas maksismum
    return 50;
  }
  // jika diskon tidak lebih dari 50% kembalikan nilai asli
  return diskon;
}

int main()
{
  // deklarasi array dan variabel
  int hargaAwal[100], persenDiskon[100], potongan[100], totalBayar[100], tanggal, diskon[100], kelipatan, jumlahBarang;
  char member, ulang;

  // looping pertama untuk melakukan transaksi lagi jika diinginkan
  do
  {
    printf("=== SELAMAT DATANG DI SISTEM PERHITUNGAN DISKON LUAR BIASA ===\n");

    // menanyakan apakah sudah menjadi member atau tidak
    printf(" Apakah kamu member (Y/T)?\n");
    scanf(" %c", &member);

    // menanyakan tanggal untuk kebutuhan diskon tambahan
    printf("Tanggal berapa hari ini?\n");
    scanf("%d", &tanggal);

    // validasi tanggal
    if (tanggal >= 1 && tanggal <= 30)
    {

      //  tanggal yang dapat diinput hanya 1-30
    }
    else
    {
      printf("Tanggal tidak valid. Masukkan tanggal antara 1 sampai 30.\n");
    }

    // input jumlah barang yang ingin dihitung
    printf("Berapa jumlah barang yang ingin kamu hitung? ");
    scanf("%d", &jumlahBarang);

    // looping kedua untuk setiap barang
    for (int i = 0; i < jumlahBarang; i++)
    {

      // input harga barang ke-i
      printf("Harga barang ke-%d: Rp. ", i + 1);
      scanf("%d", &hargaAwal[i]);

      //  jika harga barang lebih dari sama dengan Rp. 100.000 maka akan mendapatkan diskon
      if (hargaAwal[i] >= 100000)
      {
        kelipatan = hargaAwal[i] / 100000;

        // kondisi diskon untuk tanggal genap dan ganjil
        if (tanggal % 2 == 0)
        {
          diskon[i] = kelipatan * 5;
          printf("Hari ini tanggal GENAP\n" );
        }
        else
        {
          diskon[i] = kelipatan * 2;
          printf("Hari ini tanggal GANJIL\n");
        }

        // jika member diskon akan ditambahkan
        if (member == 'Y')
        {
          diskon[i] += 2;
          printf("kamu adalah member maka mendapatkan tambahan diskon 2%%\n");
        }
        else
        {
          printf("**yuk gabung member untuk dapat diskon lebih**\n");
        }

        // pembatasan diskon 50% dengan memanggil fungsi
        diskon[i] = batasDiskon(diskon[i]);
        printf("Total diskon yang didapat: %d%%\n", diskon[i]);

        // perhitungan potongan harga berdasarkan diskon yang diperoleh
        potongan[i] = (hargaAwal[i] * diskon[i]) / 100;

        // total akhir harga yang harus dibayar setelah dipotong dengan diskon
        totalBayar[i] = hargaAwal[i] - potongan[i];

        // jika harga kurang dari Rp. 100.000 maka tidak mendapatkan diskon
      }
      else
      {
        diskon[i] = 0;
        potongan[i] = 0;
        totalBayar[i] = hargaAwal[i];
        printf("Maaf,tidak ada diskon untuk pembelian di bawah Rp.100.000\n");
      }
    }

    // rincian diskon
    printf("\n===========================================\n");
    printf("           >> RINCIAN DISKON <<\n");
    printf("===========================================\n");

    //   looping ketiga untuk rincian diskon dan semua barang yang diinput
    for (int i = 0; i < jumlahBarang; i++)
    {
      printf("           Barang ke-%d \n", i + 1);
      printf("Harga Awal          : Rp. %d\n", hargaAwal[i]);
      printf("Total Diskon        : %d%%\n", diskon[i]);
      printf("Potongan Harga      : Rp. %d\n", potongan[i]);
      printf("Total Bayar         : Rp. %d\n", totalBayar[i]);
    }

    // bertanya apakah ingin transaksi lagi
    printf("Apakah ingin transaksi lagi? (Y/T):\n");
    scanf("  %c", &ulang);
    printf("\n");

  } while (ulang == 'Y' || ulang == 'y');
  printf("\n=== TERIMAKASIH TELAH BERBELANJA DAN MENGGUNAKAN SISTEM DISKON LUAR BIASA ===\n");

  return 0;
}
