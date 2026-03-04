#include <iostream>
using namespace std;

int main(){
    int angka[] = {8, 10, 7, 9, 6}; // database angka 
    int jumlahangka = 5; // variabel jumlah angka, supaya tidak perlu mengganti angka diloopingan saat ingin mengubah database 
    int temp; // untuk menyimpan angka yg sedang ditukar agar tidak hilang
    for(int a = 0; a < jumlahangka; a++){ // outer loop dimulai dari 1 karena tidak melibatkan perbandingan indeks
        for(int b = 0; b < jumlahangka-1; b++){ // inner loop dimulai dari 0 karena indeks dalam c++ selalu dimulai dari 0 untuk membandingkan angka[0] dengan angka[1], bisa jadi -1 tidak mempengaruhi hasil, akan tetapi suatu saat akan menyebabkan crash 
            if(angka[b] > angka[b+1]){ 
                temp = angka[b];
                angka[b] = angka[b+1];
                angka[b+1] = temp;
            }
        }
    }
    for(int i = 0; i < jumlahangka; i++){
        cout<<" "<<angka[i];
    }
    return 0;
}