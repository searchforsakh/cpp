#include <iostream>

using namespace std;

int main(){
    // fungsi input auto
    string nama;

    cout << "Masukkan nama anda: ";
    getline(cin, nama);

    cout << "Nama anda adalah = " << nama;

    return 0;
}

