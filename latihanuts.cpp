#include <iostream>
using namespace std;

int main(){
    // int a = 20;
    // int b = 6;
    // cout << (a/b) << " dan " << (a%b);

    // const int SISI = 10;
    // SISI = 12;
    // cout << SISI;

    // int x = 5;
    // if(x=0){
    //     cout<<"A"<<endl;
    // } else {
    //     cout<<"B"<<endl;
    // }

    // int a = 7;
    // bool b = false;
    // if ((a>5 && a<10) || (b=true)){
    //     cout << "OK";
    // } else{
    //     cout << "NOT OK";
    // }

    // int hitung = 0;
    // for(int i = 0; i < 10; i++){
    //     cout << hitung;
    // }

    // for(int i = 1; i<=5;i++){
    //     if(i==2){
    //         continue;
    //     }
    //     if(i==4){
    //         break;
    //     }
    //     cout << i << " ";
    // }

    // for(int i = 1; i <= 3; i++){
    //     for(int j = 1; j <= i; j++){
    //         cout<< "*";
    //     }
    //     cout << endl;
    // }

    // int arr[4] = {10,20,30,40};
    // cout << arr[0] << " dan " << arr[4];

    // int angka[] = {4,1,5,3};
    // int jumlahangka = 4;
    // int temp;
    // for(int a = 1;a < jumlahangka; a++){
    //     for(int b = 0; b < jumlahangka-1; b++){
    //         if (angka[b] > angka[b+1]){
    //             temp = angka[b];
    //             angka[b] = angka[b+1];
    //             angka[b+1] = temp;
    //         }
    //     }
    // }
    // for(int x = 0; x<jumlahangka; x++){
    //     cout<<angka[x]<<endl;
    // }

    // int data[] = {5,2,8,1,9};
    // int N = 5;
    // int temp;
    // for (int i = 0; i < N; i++){
    //     for(int j = 0; j < N-1; j++){
    //         if(data[j] > data[j+1]){
    //             temp = data[j];
    //             data[j] = data[j+1];
    //             data[j+1] = temp;
    //         }
    //     }
    // }
    // for(int a = 0; a<N; a++){
    //     cout<<data[a]<<endl;
    // }

    int angka[] = {2,4,7,10,9,20};
    int jumlahangka = 6;
    int temp;

    for(int a = 1; a < jumlahangka; a++){
        for(int b = 0; b < jumlahangka-1; b++){
            if(angka[b] > angka[b+1]){
                temp = angka[b];
                angka[b] = angka[b+1];
                angka[b+1] = temp;
            }
        }
    }
    for(int x = 0; x < jumlahangka; x++){
        cout<<angka[x]<<endl;
    }
    return 0;
}

