// #include <iostream>
// using namespace std;

// int main(){
//     // Data Mahasiswa
//     string nama[2] = {"Ferry Santoso","Sakha Pratama"};
//     string nim[2] = {"20211234567","20250801037"};
//     float ipk[2] = {3.37,4.00};

//     // input dari user
//     string keynim;
//     cout<<"\nMasukkan NIM yang ingin dicari = ";
//     cin >> keynim;

//     cout<<"\n===HASIL PENCARIAN===\n";

//     // proses
//     bool ketemu = false;
//     for(int a = 0; a < 2; a++){
//         if(keynim == nim[a]){
//             cout<<"Data Ditemukan\n";
//             cout<<"NIM = "<<nim[a]<<endl;
//             cout<<"Nama = "<<nama[a]<<endl;
//             cout<<"IPK = "<<ipk[a]<<endl;
//             ketemu = true;
//             break;
//         }
//     }
//     if (!ketemu){
//         cout<<"Data tidak ditemukan";
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

int main(){
    int jumlah;

    cout << "Masukkan jumlah mahasiswa = ";
    cin >> jumlah;

    // database mahasiswa
    string nama[jumlah];
    string nim[jumlah];
    float ipk[jumlah];

    // input data mahasiswa
    cout << "\n=== INPUT DATA MAHASISWA ===\n";
    for(int i = 0; i < jumlah; i++){
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "NIM  : ";
        cin >> nim[i];
        cin.ignore();
        cout << "Nama : ";
        getline(cin, nama[i]);
        cout << "IPK  : ";
        cin >> ipk[i];
    }

    // input pencarian
    string keynim;
    cout << "\nMasukkan NIM yang ingin dicari = ";
    cin >> keynim;

    cout << "\n=== HASIL PENCARIAN ===\n";

    // proses pencarian
    bool ketemu = false;
    for(int i = 0; i < jumlah; i++){
        if(keynim == nim[i]){
            cout << "Data Ditemukan\n";
            cout << "NIM  = " << nim[i] << endl;
            cout << "Nama = " << nama[i] << endl;
            cout << "IPK  = " << ipk[i] << endl;
            ketemu = true;
            break;
        }
    }

    if(!ketemu){
        cout << "Data tidak ditemukan";
    }

    return 0;
}
