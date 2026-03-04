#include <iostream>
using namespace std;

int main(){
    int angka;
    cout<<"Masukkan Angka = ";
    cin >> angka;
    while(angka <= 10){
        cout<<angka<<". halo"<<endl;
        angka++;
    }
    return 0;
}