#include <iostream>
using namespace std;

// Fungsi Sequential Search untuk mencari NIM
int cariNIM(long long data[], int n, long long key) {
    int posisi = -1;
    for (int i = 0; i < n; i++) {
        if (data[i] == key) {
            posisi = i;
            break;
        }
    }
    return posisi;
}

int main() {
    // Data NIM mahasiswa (contoh)
    long long nim[] = {
        22070230001,
        22070230005,
        22070230007,
        22070230009,
        22070230012
    };

    int n = 5; // jumlah data NIM
    long long key; // NIM yang akan dicari

    cout << "=== Algoritma Sequential Search (Mencari NIM) ===\n";
    cout << "------------------------------------------------\n";
    cout << "Data NIM: ";
    for (int i = 0; i < n; i++) {
        cout << nim[i] << " ";
    }

    cout << "\n\nMasukkan NIM yang ingin dicari: ";
    cin >> key;

    int posisi = cariNIM(nim, n, key);

    if (posisi != -1) {
        cout << "NIM " << key << " ditemukan pada indeks ke-" << posisi << endl;
    } else {
        cout << "NIM " << key << " tidak ditemukan dalam data.\n";
    }

    return 0;
}