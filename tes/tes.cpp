// Sakha Pratama 20250801037
#include <iostream> // Library untuk fitur standar input/output

using namespace std; // sintaks untuk meringkas code (tanpa perlu std::)

int main(){  // tempat program dijalankan
    // Menampilkan Judul Program di terminal
    cout << "\nProgram C++ diskon 10%, setiap pembelian 2 barang" << endl;
    cout << "=================================================" << endl;
    cout << endl;

    // deklarasi tipe data (int) dan variabel (arang1, barang2, diskon, hasil, hargadidiskon)
    float barang1, barang2, diskon, hasil, hargadidiskon;
    
    // Input User (User Memasukkan Harga Barang)
    cout << "Masukkan Harga barang 1 \t= Rp.";
    cin >> barang1;
    cout << "Masukkan Harga barang 2 \t= Rp.";
    cin >> barang2;
    
    // proses / rumus menghitung Total Harga
    hasil = barang1 + barang2;
    cout << "------------------------------------------" << endl;
    cout << "Total Harga \t\t\t= Rp." << hasil << endl;
    
    // proses / rumus menghitung diskon
    diskon = hasil * 0.10;
    cout << "Diskon 10% \t\t\t= Rp." << diskon << endl;

    // proses / rumus menghitung Harga setelah mendapat diskon
    hargadidiskon = hasil - diskon;
    cout << "Harga Setelah Di diskon 10% \t= Rp." << hargadidiskon << endl;
    cout << endl;

    return 0; // program berhasil dijalankan tanpa masalah.
}