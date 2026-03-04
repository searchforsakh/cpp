#include <iostream>
using namespace std;
int main() {
    //deklarasi variabel dan tipe data
    int jumlahData;
    int input;
    int totalGanjil = 0;
    int totalGenap = 0;
    int semua[5]; // array untuk menyimpan semua input
    int simpaninput = 0; // jumlah input yang tersimpan
    int temp;
    //input user
    cout << "Masukkan jumlah data (maksimal 5): ";
    cin >> jumlahData;
    //proses total genap dan ganjil
    for(int i = 1; i <= jumlahData; i++) {
        cout << "Data ke-" << i << ": ";
        cin >> input;
        semua[simpaninput] = input;  // simpan input ke array
        simpaninput++;
        if(i % 2 == 0) {
            totalGenap += input;
        } else {
            totalGanjil += input;
        }
    }
    // proses quicksort
    for(int i = 0; i < simpaninput - 1; i++) {
        for(int j = i + 1; j < simpaninput; j++) {
            if(semua[i] > semua[j]) {
                temp = semua[i];
                semua[i] = semua[j];
                semua[j] = temp;
            }
        }
    }
    // tampilkan output
    cout << "\nHasil Akhir:\n";
    cout << "Jumlah posisi ganjil = " << totalGanjil << endl;
    cout << "Jumlah posisi genap  = " << totalGenap << endl;

    cout << "\nSemua angka setelah diurutkan:\n";
    for(int i = 0; i < simpaninput; i++) {
        cout << semua[i] << " ";
    }
    cout << endl;
    return 0;
}