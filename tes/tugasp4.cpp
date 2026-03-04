#include <iostream>     // Library untuk input-output (cout, cin)
#include <string>       // Library untuk tipe data string
using namespace std;    // Supaya tidak perlu nulis std:: di depan cout/cin

// Struktur data untuk menyimpan info mahasiswa
struct Mahasiswa {
    long long nim;      // NIM mahasiswa (angka besar, jadi pakai long long)
    string nama;        // Nama mahasiswa
    float ipk;          // Nilai IPK mahasiswa
};

int main() {
    // Membuat 1 data mahasiswa bernama Ferry Santoso
    Mahasiswa ferry = {22070230007, "Ferry Santoso", 3.37};

    string input;       // Variabel untuk menampung input dari user

    // Teks pembuka program
    cout << "=== Pencarian Data Mahasiswa (Nama / NIM) ===\n";
    cout << "---------------------------------------------\n";

    // Meminta user memasukkan NIM atau Nama yang ingin dicari
    cout << "Masukkan NIM atau Nama yang ingin dicari: ";
    getline(cin, input);   // Pakai getline supaya bisa membaca spasi (contoh: Ferry Santoso)

    bool ditemukan = false;   // Variabel penanda apakah data ditemukan atau tidak

    // Mengecek apakah input sama dengan NIM Ferry (diubah jadi string dulu)
    // ATAU sama dengan nama Ferry langsung
    if (input == to_string(ferry.nim) || input == ferry.nama) {
        ditemukan = true;     // Kalau cocok, ubah jadi true
    }

    // Menampilkan hasil pencarian
    cout << "\nHasil Pencarian:\n";
    cout << "----------------\n";

    // Jika data ditemukan
    if (ditemukan) {
        cout << "Data ditemukan!\n";
        cout << "NIM  : " << ferry.nim << endl;    // Tampilkan NIM Ferry
        cout << "Nama : " << ferry.nama << endl;   // Tampilkan Nama Ferry
        cout << "IPK  : " << ferry.ipk << endl;    // Tampilkan IPK Ferry
    } else {
        // Jika data tidak cocok
        cout << "Data tidak ditemukan.\n";
    }

    return 0;   // Program selesai
}