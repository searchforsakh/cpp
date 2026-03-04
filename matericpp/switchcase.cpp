#include <iostream>
using namespace std;

int main(){
    int angka;
    cout<<"Masukkan Angka = ";
    cin >> angka;
    switch(angka == 1){
        case true:
        cout<<"angka = 1"<<endl;
        break;
        case false:
        cout<<"angka tidak terdefinisi"<<endl;
    }
    switch(angka){ // menjalankan perintah jika input user memenuhi case
        case 1:
        cout<<"angka = 1"<<endl;
        case 2:
        cout<<"angka = 2"<<endl;
        case 3:
        cout<<"angka = 3"<<endl;
        break;
        case 4:
        cout<<"angka = 4"<<endl;
        default: // nilai default
        cout<<"default"<<endl;
    }
    return 0;
}