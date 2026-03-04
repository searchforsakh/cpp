#include <iostream>
using namespace std;

int main(){
    // deklarasi tipe data dan variabel
    int angka[] = {9,5,1,4,3};
    int jumlahangka = 5;
    int temp; // variabel penampung
    int j; // variabel pembanding
    
    // proses menaruh indeks 1 ke temp dan menghitung variabel pembanding (j)
    for(int a = 1; a < jumlahangka; a++){
        temp = angka[a];
        j = a-1;
        // proses mwmbandingkan
        while(j >= 0 && angka[j] > temp){
            angka[j+1] = angka[j];
            j = j-1;
        }
        // jika tidak memenuhi syarat while, maka angka[j+1] dimasukkan ke temp
        angka[j+1] = temp;
    }
    // mengeluarkan output hasil
    cout << "Hasilnya adalah = ";
    for(int x = 0; x < jumlahangka; x++){
        cout << angka[x] << " " ;
    }
    return 0;
}
    // int angka[] = {9,5,1,4,3};
    // int jumlahangka = 5;
    // int temp;
    
    // for(int a = 1; a < jumlahangka; a++){
    //     for(int b = a; b > 0; b--){
    //         if(angka[b] < angka[b-1]){
    //             temp = angka[b];
    //             angka[b] = angka[b-1];
    //             angka[b-1] = temp;
    //         } else{
    //         break;
    //         }
    //     }
    // }
    // for(int x = 0; x < jumlahangka; x++){
    //     cout<<"angka urut = "<< angka[x]<< endl;
    // }