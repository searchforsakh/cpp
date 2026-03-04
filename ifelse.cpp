#include <iostream>

using namespace std;

int main(){
    int pilihan;
    cout<<R"(
    1. rendang
    2. bakso
    3. mie ayam)"<<endl;
    cout<<"Masukkan pilihan Menu = ";
    cin >> pilihan;

    if (pilihan == 1){
        cout<<"Menu yang anda pilih adalah rendang";
    } else if (pilihan == 2){
        cout<<"Menu yang anda pilih adalah bakso";
    } else if (pilihan == 3){
        cout<<"Menu yang anda pilih adalah Mie ayam";
    } else {
        cout<<"Pilihan tidak tersedia";
    }
    return 0;
}