#include <iostream>
#include <string>

using namespace std;

struct Warga {
    string nIK; 
    string nama; 
    string status; 
    long long pendapatan; 
    int tanggungan;
};

void urutkanNIK(Warga data[], int n) {
    cout << "\n===============================================" << endl;
    cout << "   PROSES PENGURUTAN DATA (STEP-BY-STEP) " << endl;
    cout << "===============================================" << endl;

    for (int i = 0; i < n - 1; i++) {
        cout << "\n[TAHAP KE-" << i + 1 << "]" << endl;
        bool adaPertukaran = false; // Penanda untuk optimasi

        for (int j = 0; j < n - i - 1; j++) {
            cout << "-----------------------------------------------" << endl;
            cout << "Membandingkan:" << endl;
            cout << "  A.   NIK: " << data[j].nIK << " (" << data[j].nama << ")" << endl;
            cout << "  B. NIK: " << data[j+1].nIK << " (" << data[j+1].nama << ")" << endl;

            if (data[j].nIK > data[j + 1].nIK) {
                cout << "HASIL: NIK A lebih besar dari B. Maka posisi DITUKAR." << endl;
                
                // Proses Tukar
                Warga temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                
                adaPertukaran = true;
            } else {
                cout << "HASIL: NIK A lebih kecil dari B. Posisi sudah benar (TETAP)." << endl;
            }
        }
        
        // Jika dalam satu tahap tidak ada yang ditukar sama sekali, berarti sudah urut
        if (!adaPertukaran) {
            cout << "\n(Info: Semua data sudah pada posisi yang benar.)" << endl;
            break; 
        }
    }
    cout << "\n===============================================" << endl;
    cout << "       PROSES PENGURUTAN SELESAI" << endl;
    cout << "===============================================\n" << endl;
}
// 3. Fungsi Searching dengan DESK CHECK (Linear Search)
void cariWarga(Warga data[], int n, string target) {
    bool ditemukan = false;
    cout << "\n=== MEMULAI DESK CHECK SEARCHING (LINEAR SEARCH) ===" << endl;
    cout << "Mencari NIK: " << target << endl;

    for (int i = 0; i < n; i++) {
        // Desk Check: Menampilkan proses pemeriksaan satu per satu
        cout << "Langkah " << i + 1 << ": Memeriksa indeks ke-" << i << " (NIK: " << data[i].nIK << ")";
        
        if (data[i].nIK == target) {
            cout << " -> [COCOK!]" << endl;
            cout << "\n--- HASIL VERIFIKASI DATA ---" << endl;
            cout << "NIK         : " << data[i].nIK << endl;
            cout << "Nama        : " << data[i].nama << endl;
            cout << "Pendapatan  : Rp." << data[i].pendapatan << endl;
            cout << "Tanggungan  : " << data[i].tanggungan << " Orang" << endl;
            cout << "Status      : " << data[i].status << endl;
            ditemukan = true;
            break; 
        } else {
            cout << " -> [TIDAK COCOK]" << endl;
        }
    }
    
    if (!ditemukan) {
        cout << "\nData NIK [" << target << "] tidak terdaftar dalam sistem." << endl;
    }
    cout << "=== SELESAI SEARCHING ===\n" << endl;
}

string tentukanKelayakan(long long pendapatan, int tanggungan) {
    long long perKapita = pendapatan / (tanggungan + 1);
    if (perKapita < 500000) {
        return "LAYAK (Per Kapita < 500rb)";
    } else {
        return "TIDAK LAYAK (Per Kapita > 500rb)";
    }
}

void tampilkanStatistik(Warga data[], int n) {
    int layak = 0;
    long long totalPdt = 0;
    int totalTanggungan = 0;
    
    for (int i = 0; i < n; i++) {
        long long perKapita = data[i].pendapatan / (data[i].tanggungan + 1);
        if (perKapita < 500000) layak++; 
        totalPdt += data[i].pendapatan;
        totalTanggungan += data[i].tanggungan;
    }
    
    cout << "\n--- STATISTIK ANGGARAN ---" << endl;
    cout << "Total Warga            : " << n << endl; 
    cout << "Layak Bansos           : " << layak << endl; 
    cout << "Tidak Layak            : " << n - layak << endl;
    cout << "Rata-rata Pendapatan   : Rp." << (n > 0 ? totalPdt / n : 0) << endl; 
    cout << "Total Anggaran         : Rp." << (long long)layak * 600000 << " (Estimasi)" << endl;
    cout << "Rata-rata Tanggungan   : " << (n > 0 ? (float)totalTanggungan / n : 0) << " orang/warga" << endl;
}

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
            data[i].status = tentukanKelayakan(data[i].pendapatan, data[i].tanggungan);
            cout << "\nData NIK " << target << " berhasil diperbarui!" << endl;
            ditemukan = true;
            break; 
        }
    }
    if (!ditemukan) cout << "\nNIK " << target << " tidak ditemukan." << endl;
}

void hapusWarga(Warga data[], int &n, string target) {
    int indexHapus = -1;
    for (int i = 0; i < n; i++) {
        if (data[i].nIK == target) {
            indexHapus = i;
            break;
        }
    }
    if (indexHapus != -1) { 
        for (int i = indexHapus; i < n - 1; i++) { 
            data[i] = data[i + 1];
        }
        n--;
        cout << "\nData NIK " << target << " berhasil dihapus." << endl; 
    } else { 
        cout << "\nNIK " << target << " tidak ditemukan." << endl;
    }
}

void quitmenu() {
    string pilihan;
    while (true) {
        cout << "\n1. Kembali ke Menu Utama" << endl;
        cout << "2. Keluar Program" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;
        if (pilihan == "1") {
            return; 
        } else if (pilihan == "2") {
            cout << "Terima kasih. Program selesai." << endl;
            exit(0);    
        } else {
            cout << "Masukkan Pilihan Yang Sesuai!" << endl;
        }
    }
}

int main() {
    Warga daftarBansos[100]; 
    int jumlah = 0; 
    int pilihan;
    string cariNIK;

    while (true) {
        system("cls");
        cout << "    SISTEM VERIFIKASI BANSOS   " << endl;
        cout << "==============================" << endl;
        if (jumlah > 0) {
            cout << " Total Data Saat Ini: " << jumlah << endl;
            cout << "---------------------------------------" << endl;
        }
        cout << "1. Tambah Data Warga" << endl;
        cout << "2. Lihat Daftar Penerima (Sorting + Desk Check)" << endl;
        cout << "3. Cari Data Warga (Searching + Desk Check)" << endl;
        cout << "4. Update Data Warga (Edit)" << endl;
        cout << "5. Hapus Data Warga (Delete)" << endl;
        cout << "6. Statistik Anggaran" << endl;
        cout << "7. Keluar Program" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int dataBaru;
            cout << "\nMasukkan jumlah warga baru: ";
            cin >> dataBaru;
            for (int i = jumlah; i < (jumlah + dataBaru); i++) {
                cout << "\nData Warga ke-" << i + 1 << endl;
                cout << "NIK         : "; cin >> daftarBansos[i].nIK;
                cout << "Nama        : "; cin.ignore(); getline(cin, daftarBansos[i].nama);
                cout << "Pendapatan  : Rp."; cin >> daftarBansos[i].pendapatan;
                cout << "Tanggungan  : "; cin >> daftarBansos[i].tanggungan;
                daftarBansos[i].status = tentukanKelayakan(daftarBansos[i].pendapatan, daftarBansos[i].tanggungan);
            }
            jumlah += dataBaru;
            cout << "\nData berhasil disimpan!" << endl;
            quitmenu();
        }
        else if (pilihan == 2) { 
            if (jumlah == 0) {
                cout << "\nData masih kosong!" << endl;
            } else {
                urutkanNIK(daftarBansos, jumlah);
                cout << "--- HASIL DAFTAR PENERIMA TERURUT ---" << endl;
                for (int i = 0; i < jumlah; i++) {
                    cout << i + 1 << ". [" << daftarBansos[i].nIK << "] " << daftarBansos[i].nama << " | Status: " << daftarBansos[i].status << endl;
                }
            }
            quitmenu();
        }
        else if (pilihan == 3) {
            if (jumlah == 0) {
                cout << "\nData masih kosong!" << endl;
            } else {
                cout << "\nMasukkan NIK warga: ";
                cin >> cariNIK;
                cariWarga(daftarBansos, jumlah, cariNIK);
            }
            quitmenu();
        }
        else if (pilihan == 4) {
            if (jumlah == 0) cout << "\nData kosong!" << endl;
            else {
                cout << "\nMasukkan NIK: "; cin >> cariNIK;
                updateWarga(daftarBansos, jumlah, cariNIK);
            }
            quitmenu();
        }
        else if (pilihan == 5) {
            if (jumlah == 0) cout << "\nData kosong!" << endl;
            else {
                cout << "\nMasukkan NIK: "; cin >> cariNIK;
                char yakin;
                cout << "Yakin hapus? (y/n): "; cin >> yakin;
                if (yakin == 'y' || yakin == 'Y') hapusWarga(daftarBansos, jumlah, cariNIK);
            }
            quitmenu();
        }
        else if (pilihan == 6) {
            if (jumlah == 0) cout << "\nData kosong!" << endl;
            else tampilkanStatistik(daftarBansos, jumlah);
            quitmenu();
        }
        else if (pilihan == 7) break;
        else cout << "\nPilihan tidak valid!" << endl;
    }
    return 0; 
}