#include <iostream>
#include <string>

using namespace std;

// 1. Merancang struktur data untuk menampung informasi warga
struct Warga {
    string nIK;         // Variabel untuk menyimpan NIK (string agar bisa diawali angka 0)
    string nama;        // Variabel untuk nama lengkap
    int pendapatan;     // Variabel angka bulat untuk jumlah pendapatan
    string status;      // Variabel untuk menyimpan hasil kelayakan
};

// 2. Fungsi Sorting menggunakan algoritma Bubble Sort
void urutkanNIK(Warga data[], int n) {
    for (int i = 0; i < n - 1; i++) { // Loop untuk tahap pengurutan
        for (int j = 0; j < n - i - 1; j++) { // Loop untuk membandingkan data bertetangga
            if (data[j].nIK > data[j + 1].nIK) { // Jika NIK kiri lebih besar dari kanan, maka tukar
                Warga temp = data[j]; // Simpan data sementara
                data[j] = data[j + 1]; // Geser data terkecil ke kiri
                data[j + 1] = temp; // Pindahkan data terbesar ke kanan
            }
        }
    }
}

// 3. Fungsi Searching menggunakan algoritma Linear Search (mencari satu per satu)
void cariWarga(Warga data[], int n, string target) {
    bool ditemukan = false; // Penanda apakah data ditemukan atau tidak
    for (int i = 0; i < n; i++) { // Loop menelusuri seluruh data di array
        if (data[i].nIK == target) { // Jika NIK yang dicari cocok dengan data di sistem
            cout << "\n--- HASIL VERIFIKASI DATA ---" << endl;
            cout << "NIK         : " << data[i].nIK << endl;
            cout << "Nama        : " << data[i].nama << endl;
            cout << "Pendapatan  : Rp." << data[i].pendapatan << endl;
            cout << "Status      : " << data[i].status << endl;
            ditemukan = true; // Set penanda menjadi benar
            break; // Hentikan pencarian karena data sudah didapat
        }
    }
    if (!ditemukan) { // Jika sampai akhir loop data tidak ada yang cocok
        cout << "\nData NIK [" << target << "] tidak terdaftar dalam sistem." << endl;
    }
}

int main() {
    Warga daftarBansos[100]; // Menyiapkan wadah untuk maksimal 100 data warga
    int jumlah = 0; // Menyimpan total warga yang sudah terdaftar
    int pilihan, quit; // Variabel untuk menampung pilihan menu user
    string cariNIK; // Variabel untuk menampung input NIK yang dicari

    while (true) { // Loop utama agar program terus berjalan
        utama: // Label untuk melompat kembali ke menu utama
        system("cls"); // Membersihkan tampilan terminal
        cout << "   SISTEM VERIFIKASI BANSOS   " << endl;
        cout << "==============================" << endl;
        cout << "1. Tambah Data Warga" << endl;
        cout << "2. Lihat Daftar Penerima (Sorting NIK)" << endl;
        cout << "3. Cari Data Warga (Verifikasi / Search NIK)" << endl;
        cout << "4. Keluar Program" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) { // Menu Input Data
            int dataBaru;
            cout << "\nMasukkan jumlah warga baru yang ingin ditambah: ";
            cin >> dataBaru;

            // Memulai input dari indeks terakhir (jumlah) agar data lama tidak tertimpa
            for (int i = jumlah; i < (jumlah + dataBaru); i++) {
                cout << "\nData Warga ke-" << i + 1 << endl;
                cout << "NIK         : "; cin >> daftarBansos[i].nIK;
                cout << "Nama        : "; cin.ignore(); getline(cin, daftarBansos[i].nama); // Mengambil nama lengkap dengan spasi
                cout << "Pendapatan  : Rp."; cin >> daftarBansos[i].pendapatan;

                // Logika penentuan kelayakan berdasarkan angka pendapatan
                if (daftarBansos[i].pendapatan < 2000000) {
                    daftarBansos[i].status = "LAYAK MENERIMA ( <2.000.000 )";
                } else {
                    daftarBansos[i].status = "TIDAK LAYAK ( >2.000.000 )";
                }
            }
            jumlah += dataBaru; // Menambah angka total data yang tersimpan di sistem
            urutkanNIK(daftarBansos, jumlah); // Memanggil fungsi urutkan agar daftar NIK rapi

            cout << "\nData berhasil disimpan!" << endl;
            cout << "\n1. Kembali ke Menu Utama\n2. Keluar Program\nPilihan: ";
            cin >> quit;
            if (quit == 1) { 
                goto utama; 
            } // Lompat ke label utama
            else {
                break; 
            } // Keluar dari loop while(true)
        }

        else if (pilihan == 2) { // Menu Tampil Data
            if (jumlah == 0) { // Validasi jika belum ada data yang diinput
                cout << "\nData masih kosong!" << endl;
            } else {
                cout << "\n--- DAFTAR PENERIMA (TERURUT NIK) ---" << endl;
                for (int i = 0; i < jumlah; i++) { // Loop menampilkan isi array satu per satu
                    cout << i + 1 << ". [" << daftarBansos[i].nIK << "] " 
                         << daftarBansos[i].nama << " - Status: " << daftarBansos[i].status << endl;
                }
            }
            cout << "\n1. Kembali ke Menu Utama\n2. Keluar Program\nPilihan: ";
            cin >> quit;
            if (quit == 1) { 
                goto utama; 
            } // Lompat ke label utama
            else {
                break; 
            } // Keluar dari loop while(true)
        }

        else if (pilihan == 3) { // Menu Pencarian Data
            cari_lagi: // Label jika ingin mencari NIK lain
            if (jumlah == 0) {
                cout << "\nData masih kosong!" << endl;
            } else {
                cout << "\nMasukkan NIK warga untuk verifikasi: ";
                cin >> cariNIK;
                cariWarga(daftarBansos, jumlah, cariNIK); // Memanggil fungsi search
            }
            cout << "\n1. Kembali ke Menu Utama\n2. Keluar Program\nPilihan: ";
            cin >> quit;
            if (quit == 1) { 
                goto utama; 
            } // Lompat ke label utama
            else {
                break; 
            } // Keluar dari loop while(true)
        }

        else if (pilihan == 4) { // Menu Keluar
            break; // Menghentikan perulangan while
        }

        else { // Jika user memasukkan angka selain 1-4
            cout << "\nPilihan tidak valid!" << endl;
            system("pause");
            break; // Menahan layar agar user bisa membaca pesan error
        }
    }

    cout << "\nTerima kasih. Program selesai." << endl;
    return 0; // Menandakan program berakhir dengan sukses
}