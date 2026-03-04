#include <iostream>
using namespace std;

int main(){
    // judul
    // deklarasi
    int banyakinput;
    int input;
    int pilihan;
    int kodebuku;
    int pilihansort;
    string lanjutorno;
    int inputbuku;
    int databaseBukuInt[4] = {121, 122, 123, 124};
    string databaseBukuStr[4] = {"C++ Dasar", "HTTYD", "HayeWay", "Python Dasar"};
    // user user
    while(true){
        cout << "PROGRAM PENDATAAN BUKU PERPUSTAKAAN\n" << endl;
        cout << "1. Masukkan Kode buku baru(sort)\n2. Cek Stok Buku (sequential search)\n----------------------\nMasukkan Pillihan = ";
        cin >> pilihan;
        cin.ignore();
        if(pilihan == 1){
            cout<<"Masukkan banyak kode buku baru  = ";
            cin>>banyakinput;
            for(int a = 1; a <= banyakinput; a++){
                cout<<"Masukkan kode buku ke- " << a << " = ";
                cin>>kodebuku;
                kodebuku++;
            }
            cout<<"\n1. Bubble sort\n2. Insertion sort\n3. quick sort\n4. selection sort\nMasukkan pilihan sorting = ";
            cin >> pilihansort;
            
            if (pilihansort == 1){
                
            }
        }
        // sequential search
        if (pilihan == 2){
            cout << "\n121 - C++ Dasar\t\t122 - HTTYD\n123 - HayeWay\t\t124 - Python Dasar\nMasukkan Kode Buku = ";
            cin >> inputbuku;
            // getline(cin, inputbuku); // untuk menampilkan string yg memiliki spasi
            bool ketemu = false;
            for(int i = 0; i<4; i++){
                if (inputbuku == databaseBukuInt[i]){
                    cout << "Buku '" << databaseBukuStr[i] << "' Tersedia" <<endl;
                    ketemu = true;
                    break;
                }
            }
            if(!ketemu){
                cout << "Maaf Buku dengan kode '" << inputbuku << "' Tidak Tersedia\n" << endl;
            }
        }
        cout<<"\nApakah ingin lanjut ? (y/n) = ";
        cin >> lanjutorno;
        if(lanjutorno == "n"){
            break;
        }
    }
    return 0;
}