#include <iostream>
#include <string>

using namespace std;

// 1. Merancang struktur data untuk menampung informasi warga
struct Warga {
    string nIK; // Variabel untuk menyimpan NIK (string agar bisa diawali angka 0)
    string nama; // Variabel untuk nama lengkap
    string status; // Variabel untuk menyimpan hasil kelayakan
    long long pendapatan; // Variabel angka bulat untuk jumlah pendapatan
    int tanggungan;
};

// 2. Fungsi Sorting menggunakan algoritma Bubble Sort
// Fungsi untuk mengurutkan data warga berdasarkan NIK menggunakan algoritma Bubble Sort
void urutkanNIK(Warga data[], int n) { // data[]: array objek Warga, n: jumlah total data warga
    cout << "\n=== DESK CHECK SORTING (BUBBLE SORT) ===" << endl;

    // Loop luar: Mengatur jumlah iterasi/pass (sebanyak n-1 kali)
    for (int i = 0; i < n - 1; i++) { // i: Variabel kontrol loop luar untuk menentukan jumlah putaran (pass)
        cout << "Iterasi ke-" << i + 1 << ":" << endl;

        // Loop dalam: Melakukan perbandingan elemen berdampingan
        // n-i-1 digunakan agar elemen yang sudah "paling besar" di ujung tidak perlu dicek lagi
        for (int j = 0; j < n - i - 1; j++) {// j: Variabel kontrol loop dalam untuk membandingkan indeks yang berdampingan
            // Log Desk Check: Menampilkan elemen yang sedang dibandingkan
            cout << "  > Membandingkan NIK[" << data[j].nIK << "] dengan NIK[" << data[j+1].nIK << "]"; 
            
            // Kondisi: Jika elemen kiri lebih besar dari elemen kanan, maka tukar (Ascending)
            if (data[j].nIK > data[j + 1].nIK) { // nIK: Variabel dalam struct Warga yang menjadi acuan pengurutan
                cout << " -> (TUKAR POSISI)" << endl;
                
                // Proses pertukaran (Swapping) menggunakan variabel sementara (temp)
                Warga temp = data[j]; // temp: Variabel sementara untuk menyimpan data agar tidak hilang saat proses tukar (swap)
                data[j] = data[j + 1]; // Menggeser data yang lebih kecil ke posisi kiri
                data[j + 1] = temp; // Memindahkan data dari temp ke posisi kanan
            } else {
                // Jika elemen kiri sudah lebih kecil atau sama dengan, posisi tetap
                cout << " -> (TETAP)" << endl;
            }
        }
    }
    cout << "=== SELESAI SORTING ===\n" << endl;
}

// 3. Fungsi Searching menggunakan algoritma Linear Search (mencari satu per satu)
// Fungsi untuk mencari data warga tertentu berdasarkan input NIK menggunakan Linear Search
void cariWarga(Warga data[], int n, string target) { // target: Variabel yang menampung NIK yang ingin dicari (input dari user)
    bool ditemukan = false; // Flag untuk menandai apakah data sudah ditemukan
    
    cout << "\n=== DESK CHECK SEARCHING (LINEAR SEARCH) ===" << endl;
    cout << "Mencari NIK: " << target << endl;

    // Loop untuk menelusuri setiap indeks dalam array data warga
    for (int i = 0; i < n; i++) { // i: Indeks posisi data yang sedang diperiksa saat ini (mulai dari 0 sampai n-1)
        // Log Desk Check: Menunjukkan progres pemeriksaan pada indeks saat ini
        cout << "Langkah " << i + 1 << ": Memeriksa indeks ke-" << i << " (NIK: " << data[i].nIK << ")";
        
        // Membandingkan NIK pada indeks saat ini dengan NIK yang dicari (target)
        if (data[i].nIK == target) { // Membandingkan apakah NIK pada indeks ke-i sama dengan target
            cout << " -> Benar" << endl;
            
            // Jika ditemukan, tampilkan detail informasi warga tersebut
            cout << "\n--- HASIL VERIFIKASI DATA ---" << endl;
            cout << "NIK         : " << data[i].nIK << endl;
            cout << "Nama        : " << data[i].nama << endl;
            cout << "Pendapatan  : Rp." << data[i].pendapatan << endl;
            cout << "Tanggungan  : " << data[i].tanggungan << " Orang" << endl;
            cout << "Status      : " << data[i].status << endl;
            
            ditemukan = true; 
            break;         
        } else {
            // Jika tidak cocok, lanjut ke iterasi berikutnya
            cout << " -> Salah" << endl;
        }
    }
    
    // Validasi akhir: Jika seluruh array sudah diperiksa dan ditemukan tetap false
    if (!ditemukan) {
        cout << "\nData NIK [" << target << "] tidak terdaftar dalam sistem." << endl;
    }
    cout << "=== SELESAI SEARCHING ===\n" << endl;
}

string tentukanKelayakan(long long pendapatan, int tanggungan) { // string = untuk menghasilkan nilai return baru
    // Logika: Pendapatan per kapita (pendapatan / orang di rumah)
    // Anggota rumah = Diri sendiri (1) + jumlah tanggungan
    long long perKapita = pendapatan / (tanggungan + 1);
    if (perKapita < 500000) {
        return "LAYAK (Per Kapita < 500rb)";
    } else {
        return "TIDAK LAYAK (Per Kapita > 500rb)";
    }
}

// fungsi menampilkan statistik 
void tampilkanStatistik(Warga data[], int n) {
    int layak = 0; // Variabel kategori layak
    long long totalPdt = 0; // Variabel penampung total pendapatan warga
    int totalTanggungan = 0; // Tambahkan penampung baru
    
    for (int i = 0; i < n; i++) {
        long long perKapita = data[i].pendapatan / (data[i].tanggungan + 1); // Cek kelayakan
        if (perKapita < 500000) layak++; 
        
        totalPdt += data[i].pendapatan;
        totalTanggungan += data[i].tanggungan; // Akumulasi tanggungan
    }
    
    cout << "\n--- STATISTIK ANGGARAN ---" << endl;
    cout << "Total Warga            : " << n << endl; 
    cout << "Layak Bansos           : " << layak << endl; 
    cout << "Tidak Layak            : " << n - layak << endl; // Menampilkan selisih warga (Total dikurangi yang layak)
    
    // Menghitung rata-rata (jika data > 0) dengan membagi total pendapatan dengan jumlah warga
    cout << "Rata-rata Pendapatan   : Rp." << (n > 0 ? totalPdt / n : 0) << endl; 
    
    // Menghitung total dengan mengalikan jumlah warga layak dengan nominal bantuan (Rp600.000)
    cout << "Total Anggaran         : Rp." << (long long)layak * 600000 << " (Estimasi)" << endl;
    // Menghitung rata-rata tanggungan per warga; (float) digunakan agar hasil pembagian memiliki angka desimal
    cout << "Rata-rata Tanggungan   : " << (n > 0 ? (float)totalTanggungan / n : 0) << " orang/warga" << endl;
}

// function update warga *deskcheck nya sama seperti linear search
void updateWarga(Warga data[], int n, string target) {
    bool ditemukan = false; 
    for (int i = 0; i < n; i++) {
        if (data[i].nIK == target) {
            cout << "\n--- DATA DITEMUKAN ---" << endl;
            cout << "Masukkan Nama Baru       : "; 
            cin.ignore(); getline(cin, data[i].nama);
            cout << "Masukkan Pendapatan Baru : Rp."; 
            cin >> data[i].pendapatan;
            cout << "Masukkan Jumlah Tanggungan Baru : "; 
            cin >> data[i].tanggungan;

            // Menghitung ulang status kelayakan secara otomatis berdasarkan data baru
            data[i].status = tentukanKelayakan(data[i].pendapatan, data[i].tanggungan);

            cout << "\nData NIK " << target << " berhasil diperbarui!" << endl;
            ditemukan = true; // Set penanda menjadi true karena data berhasil diubah
            break; 
        }
    }
    if (!ditemukan) cout << "\nNIK " << target << " tidak ditemukan." << endl;
}

// Fungsi untuk menghapus data warga fitur Desk Check 
void hapusWarga(Warga data[], int &n, string target) {
    int indexHapus = -1; // indexHapus: Menampung posisi data yang akan dibuang

    cout << "\nDESK CHECK PENGHAPUSAN" << endl;

    // 1. PROSES PENCARIAN (Linear Search)
    for (int i = 0; i < n; i++) {
        cout << "Memeriksa indeks ke-" << i << " (NIK: " << data[i].nIK << ")";
        if (data[i].nIK == target) {
            indexHapus = i; // Menemukan lokasi data
            cout << " -> [DITEMUKAN]" << endl;
            break;
        }
        cout << " -> [BUKAN]" << endl;
    }

    // 2. PROSES PERGESERAN (Shifting)
    if (indexHapus != -1) {
        cout << "\n--- Proses Pergeseran Data ---" << endl;
        cout << "Menghapus: " << data[indexHapus].nama << endl;

        // Loop untuk menggeser data di depan ke posisi belakang
        for (int i = indexHapus; i < n - 1; i++) {
            cout << "Mengambil data [" << data[i+1].nama 
                 << "] untuk menimpa posisi indeks ke-" << i << endl;
            
            data[i] = data[i + 1]; // Menimpa data saat ini dengan data di depannya
        }

        n--; // n: Mengurangi jumlah total warga karena satu data telah dibuang
    } else {
        cout << "\nStatus: NIK " << target << " tidak ditemukan, tidak ada data yang dihapus." << endl;
    }
    cout << "\nSELESAI PENGHAPUSAN" << endl;
}

//function quit
void quitmenu() {
    string pilihan;
    while (true) {
        cout << "\n1. Kembali ke Menu Utama" << endl;
        cout << "2. Keluar Program" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        if (pilihan == "1") {
            system("cls"); // Bersihkan layar sebelum kembali
            return; // Keluar dari fungsi dan lanjut ke kode setelah pemanggilan fungsi
        } 
        else if (pilihan == "2") {
            cout << "Terima kasih. Program selesai." << endl;
            exit(0);    
        } 
        else {
            cout << "Masukkan Pilihan Yang Sesuai!" << endl;
        }
    }
}

int main() {
    Warga daftarBansos[100]; // struct of array / Menyiapkan wadah untuk maksimal 100 data warga 
    int jumlah = 0; // Menyimpan total warga yang sudah terdaftar
    int pilihan, quit; // Variabel untuk menampung pilihan menu user
    string cariNIK; // Variabel untuk menampung input NIK yang dicari

    while (true) { // Loop utama agar program terus berjalan
        utama: // Label untuk melompat kembali ke menu utama
        system("cls"); // Membersihkan tampilan terminal
        cout << "   SISTEM VERIFIKASI BANSOS   " << endl;
        cout << "==============================" << endl;
        // "Total Data" hanya muncul jika sudah ada data terinput
        if (jumlah > 0) {
            cout << " Total Data Saat Ini: " << jumlah << endl;
            cout << "---------------------------------------" << endl;
        }
        cout << "1. Tambah Data Warga" << endl;
        cout << "2. Lihat Daftar Penerima (Sorting NIK)" << endl;
        cout << "3. Cari Data Warga (Verifikasi / Search NIK)" << endl;
        cout << "4. Update Data Warga (Edit)" << endl;
        cout << "5. Hapus Data Warga (Delete)" << endl;
        cout << "6. Statistik Anggaran" << endl;
        cout << "7. Keluar Program" << endl;
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
            cout << "Nama        : "; cin.ignore(); getline(cin, daftarBansos[i].nama);
            cout << "Pendapatan  : Rp."; cin >> daftarBansos[i].pendapatan;
            cout << "Tanggungan  : "; cin >> daftarBansos[i].tanggungan;

            // Memanggil fungsi logika baru
            daftarBansos[i].status = tentukanKelayakan(daftarBansos[i].pendapatan, daftarBansos[i].tanggungan);
        }
            jumlah += dataBaru; // Menambah angka total data yang tersimpan di sistem
            cout << "\nData berhasil disimpan!" << endl;
            quitmenu();
        }
        
        else if (pilihan == 2) { 
            if (jumlah == 0) {
                cout << "\nData masih kosong!" << endl;
            } else {
                urutkanNIK(daftarBansos, jumlah); // Memanggil fungsi urutkan agar daftar NIK rapi
                cout << "\n--- DAFTAR PENERIMA (TERURUT NIK) ---" << endl;
                for (int i = 0; i < jumlah; i++) {
                    cout << i + 1 << ". [" << daftarBansos[i].nIK << "] " 
                        << daftarBansos[i].nama 
                        << " | Tanggungan: " << daftarBansos[i].tanggungan // Tambahkan ini
                        << " | Status: " << daftarBansos[i].status << endl;
                }
            }
            quitmenu();
        }

        else if (pilihan == 3) { // Menu Pencarian Data
            if (jumlah == 0) {
                cout << "\nData masih kosong!" << endl;
            } else {
                cout << "\nMasukkan NIK warga untuk verifikasi: ";
                cin >> cariNIK;
                cariWarga(daftarBansos, jumlah, cariNIK); // Memanggil fungsi search
            }
            quitmenu();
        }

        else if (pilihan == 4) {
            if (jumlah == 0) {
                cout << "\n[Peringatan] Belum ada data untuk diedit!" << endl;
            } else {
                cout << "\nMasukkan NIK yang ingin diubah: "; cin >> cariNIK;
                updateWarga(daftarBansos, jumlah, cariNIK);
            }
            quitmenu();
        }
        
        else if (pilihan == 5) { 
            if (jumlah == 0) {
                cout << "\n[Peringatan] Belum ada data untuk dihapus!" << endl;
            } else {
                cout << "\nMasukkan NIK yang ingin dihapus: "; cin >> cariNIK;
                // Konfirmasi penghapusan agar lebih aman
                char yakin;
                cout << "Yakin ingin menghapus data ini? (y/n): "; cin >> yakin;
                if (yakin == 'y' || yakin == 'Y') {
                    hapusWarga(daftarBansos, jumlah, cariNIK);
                }  
            }
            quitmenu();
        }

        else if (pilihan == 6) { // Menu Statistik
            if (jumlah == 0) {
                cout << "\n[Peringatan] Belum ada data untuk dihitung!" << endl;
            } else {
                tampilkanStatistik(daftarBansos, jumlah); // Memanggil fungsi rekapitulasi
            }
            quitmenu();
        }

        else if (pilihan == 7) { 
            break; 
        }

        else { // Jika user memasukkan angka selain 1-4
            cout << "\nPilihan tidak valid!" << endl;
            system("pause");
            break; // Menahan layar agar user bisa membaca pesan error
        }
    }

    cout << "\nTerima kasih. Program selesai." << endl;
    return 0; 
}