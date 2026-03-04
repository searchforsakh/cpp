#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---------------------- Struktur Buku ----------------------
struct Buku {
    string judul, pengarang, tahun;
};

vector<Buku> buku;

// ---------------------- Fungsi Pembanding -------------------
bool lebihKecil(Buku a, Buku b, string key) {
    if (key == "judul") return a.judul < b.judul;
    if (key == "pengarang") return a.pengarang < b.pengarang;
    return a.tahun < b.tahun;
}

// -------------------------- Bubble Sort ---------------------
vector<Buku> bubbleSort(vector<Buku> arr, string key) {
    for (int i = 0; i < arr.size() - 1; i++)
        for (int j = 0; j < arr.size() - i - 1; j++)
            if (!lebihKecil(arr[j], arr[j + 1], key))
                swap(arr[j], arr[j + 1]);
    return arr;
}

// ----------------------- Insertion Sort ---------------------
vector<Buku> insertionSort(vector<Buku> arr, string key) {
    for (int i = 1; i < arr.size(); i++) {
        Buku temp = arr[i];
        int j = i - 1;
        while (j >= 0 && !lebihKecil(arr[j], temp, key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    return arr;
}

// ----------------------- Selection Sort ---------------------
vector<Buku> selectionSort(vector<Buku> arr, string key) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < arr.size(); j++)
            if (lebihKecil(arr[j], arr[minIdx], key))
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
    return arr;
}

// ---------------------------- Quick Sort ---------------------
void quickSort(vector<Buku> &arr, int left, int right, string key) {
    if (left >= right) return;

    Buku pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (lebihKecil(arr[i], pivot, key)) i++;
        while (lebihKecil(pivot, arr[j], key)) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }

    quickSort(arr, left, j, key);
    quickSort(arr, i, right, key);
}

// ----------------------- Input Buku -------------------------
void inputBuku() {
    Buku b;
    cin.ignore();
    cout << "\nJudul Buku     : "; getline(cin, b.judul);
    cout << "Pengarang      : "; getline(cin, b.pengarang);
    cout << "Tahun Terbit   : "; getline(cin, b.tahun);
    buku.push_back(b);
    cout << "Buku berhasil ditambah!\n";
}

// ----------------------- Lihat Buku --------------------------
void lihatBuku() {
    if (buku.empty()) {
        cout << "\nData buku kosong.\n";
        return;
    }

    cout << "\n===== DATA BUKU =====\n";
    for (int i = 0; i < buku.size(); i++) {
        cout << i + 1 << ". " << buku[i].judul 
             << " | " << buku[i].pengarang
             << " | " << buku[i].tahun << endl;
    }
}

// ---------------------- Sorting ------------------------------
void menuSorting() {
    if (buku.empty()) {
        cout << "\nTidak ada data untuk di-sort!\n";
        return;
    }

    int pilihData, pilihAlgoritma;
    string key;

    cout << "\nSort berdasarkan:\n1. Judul\n2. Pengarang\n3. Tahun\nPilih: ";
    cin >> pilihData;

    if (pilihData == 1) key = "judul";
    else if (pilihData == 2) key = "pengarang";
    else key = "tahun";

    cout << "\nMetode Sorting:\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Quick Sort\nPilih: ";
    cin >> pilihAlgoritma;

    vector<Buku> hasil = buku;

    switch (pilihAlgoritma) {
        case 1: hasil = bubbleSort(hasil, key); break;
        case 2: hasil = insertionSort(hasil, key); break;
        case 3: hasil = selectionSort(hasil, key); break;
        case 4: quickSort(hasil, 0, hasil.size()-1, key); break;
        default: cout << "Pilihan tidak valid!\n"; return;
    }

    cout << "\n===== HASIL SORTING =====\n";
    for (auto &b : hasil) {
        cout << b.judul << " | " << b.pengarang << " | " << b.tahun << endl;
    }
}

// ----------------------- Menu Utama --------------------------
void menu() {
    int pilih;
    do {
        cout << "\n\n===== MENU UTAMA =====\n";
        cout << "1. Input Buku\n";
        cout << "2. Lihat Buku\n";
        cout << "3. Sorting Buku\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: inputBuku(); break;
            case 2: lihatBuku(); break;
            case 3: menuSorting(); break;
            case 4: cout << "Program selesai.\n"; break;
            default: cout << "Menu tidak valid!\n";
        }
    } while (pilih != 4);
}

// ---------------------------- MAIN ---------------------------
int main() {
    menu();
    return 0;
}
