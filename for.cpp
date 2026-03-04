#include <iostream>

using namespace std;

int main(){
    double awal, akhir;
    cout<<"Masukkan angka pertama = ";
    cin >> awal;
    cout<<"Masukkan angka kedua = ";
    cin >> akhir;
    for(int a = awal; a <= akhir; a++){  // masukkan 3 parameter didalam kurung for  
        cout<<a<<". sakha"<<endl;
    }
    return 0;
}

// sintaks for = masukkan 3 parameter didalam kurung for (harus sesuai urutan)
// 1. deklarasi tipe data, variabel (loop), dan value, bisa 
// 2. parameter range contoh = a <= 10
// 3. parameter increment/decrement
