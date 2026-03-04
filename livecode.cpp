#include <iostream>
using namespace std;

int main(){
    int inputangka;
    int angka[8] = {2,5,7,1,2,8,9,7};
    cout << "Masukkan angka 2,5,7,1,2,8,9,7 = ";
    cin >> inputangka;
    bool ketemu = false;
    for (int i= 0; i<8; i++){
        if(inputangka == angka[i]){
            cout<<"angka ditemukan"<<endl;
            cout<<"indeks ke - "<<i<<endl;
            ketemu = true;
            break;
        } 
    }
    if (!ketemu){
        cout<< "data tidak ditemukan" << endl;
    }
    return 0;
}