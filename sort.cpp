#include <iostream> // Mengimpor pustaka untuk input dan output standar
using namespace std; // Menggunakan namespace std agar tidak perlu menulis std:: di depan cout, endl, dll

int main() { // Fungsi utama program
    int A[] = {10, 8, 7, 9, 6}; // Mendeklarasikan array A berisi 5 elemen
    int n = 5; // Menyimpan jumlah elemen array
    int i, j, max, temp; // Mendeklarasikan variabel yang digunakan untuk iterasi dan pertukaran nilai
    // Loop untuk selection sort menurun (descending)
    for (i = 0; i < n - 1; i++) {
        max = i; // Asumsikan elemen ke-i adalah yang terbesar
        // Mencari elemen terbesar di sisa array
        for (j = i + 1; j < n; j++) {
            if (A[j] > A[max]) { // Jika A[j] lebih besar dari A[max]
                max = j; // Simpan indeks elemen terbesar baru
            }
        }
        // Menukar elemen ke-i dengan elemen terbesar yang ditemukan
        temp = A[i];
        A[i] = A[max];
        A[max] = temp;
    }
    // Menampilkan hasil pengurutan
    cout << "Hasil urut (dari besar ke kecil): ";
    for (i = 0; i < n; i++) {
        cout << A[i] << " "; // Menampilkan elemen array yang sudah diurutkan
    }
    cout << endl; // Baris baru setelah output
    return 0; // Mengembalikan nilai 0 untuk menunjukkan program selesai dengan sukses
}
