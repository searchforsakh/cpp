#include<iostream>
using namespace std;

#define max 5

struct Stack { // variabel mengelompokkan beberapa variabel dengan tipe data berbeda menjadi satu tipe data buatan baru
    string datastack[max]; // variabel untuk menentukan jumlah maksimal data yang bisa di push
    int top;
};
Stack s = { {}, 0 };
// {} → untuk string data[max] 0 → untuk int top

bool isempty(){
    if(s.top == 0){ // jika posisi data = 0, maka benar, array sedang kosong
        return true;
    } else{
        return false;
    }
}
// Karena top adalah anggota struct Stack, maka harus diakses melalui objek (s.top). Tanpa s., compiler tidak dapat mengenali variabel top.

bool isfull(){ // untuk mendeteksi apakah array data sudah penuh atau belum
    if(s.top >= max){ // jika kondisinya lebih dari atau sama dengan max(5), maka true(penuh)
        return true;
    } else{
        return false; // jika tidak, maka false, artinya belum penuh, sehingga bisa menginput data menggunakan push
    }
}

void display(){ 
    if(!isempty()){ // jika data tidak kosong, maka tampilkan data yang tersimpan
        cout<<"Data Tersimpan"<<endl;
        for(int a = 0; a < s.top; a++){ //
            cout<<a+1<<". "<<s.datastack[a]<<endl;
        }
    } else{
        cout<<"Data Tidak tersedia"<<endl;
    }
    if(isfull()){
        cout<<"Stack penuh"<<endl;
    }
    cout<<endl;
}

void push(){
    if(!isfull()){ // jika belum full, maka bisa menambahkan data
        cout<<"Masukkan Nama Karyawan = ";
        cin >> s.datastack[s.top];
        s.top++;
    }
}

void pop(){ // jika data tidak kosong, maka data bisa dihapus
    if(!isempty()){
        s.top--;
    }
}

int main(){
    int pilihanstack; // pilihan untuk memilih push atau pop
    string isi; // sesuatu yang akan dipush kedalam stack

    stack:
    system("cls");
    display();
    cout<<"Menu Utama\n1. Push\n2. Pop\nMasukkan Pilihan = ";
    cin >> pilihanstack;

    if(pilihanstack==1){
        push();
        goto stack;
    } else if(pilihanstack==2){
        pop();
        goto stack;
    }
}