#include <iostream>

using namespace std;

int main() {
    int input;

    cout << "Masukan banyak input : ";
    cin >> input;

    // FIX 1: Deklarasi array HARUS SETELAH kita tahu nilai 'input'
    int data[input]; 

    // Input Data
    for(int a = 0; a < input; a++) {
        cout << "data ke " << a + 1 << " : "; // a+1 agar lebih rapi dilihat user (1, 2, 3...)
        cin >> data[a];
    }
    
    // Proses Bubble Sort (Descending/Besar ke Kecil)
    for (int b = 0; b < input - 1; b++) {
        // FIX 2: Batas loop harus 'input - 1' agar 'c+1' tidak keluar batas
        // Optimasi: Kurangi dengan 'b' karena angka paling bawah sudah pasti terurut
        for (int c = 0; c < input - 1 - b; c++) { 
            if(data[c] < data[c+1]) { 
                int temp = data[c];
                data[c] = data[c+1];
                data[c+1] = temp;
            }
        }
    }   
    
    cout << "\nHasil setelah diurutkan (Descending): " << endl;
    for (int z = 0; z < input; z++) {
        cout << data[z] << " ";
    }
    cout << endl;
    
    return 0;
}