// fifo= masuk duluan keluar duluan
// enqueue = proses masuk kedalam antrian melalui pintu masuk
// dequeue = proses keluar dari antrian melalui pintu keluar
// isempty = untuk mendeteksi apakah antrian itu kosong
// isfull = untuk mendeteksi apakah antrtian itu penuh
// _view = menampilkan data antrian yang sedang terjadi

#include <iostream>
using namespace std;

// kapasitas fix
#define max 5
string data[max];

int top = 0; // variabel untuk mendeteksi posisi data 

// untuk mengecek agar bisa menambahkan data saat queue belum penuh
// menggunakan bool karena jika nilainya true, maka sedang full/tidak bisa menambahkan data, jika false baru bisa menambahkan data
bool isfull(){
    if(top >= max){ // jika top menyamai jumlah max, maka antrian penuh
        return true;
    } else{
        return false;
    }
}

// untuk mendeteksi data dalam antrian kosong atau tidak
bool isempty(){ // jika top = 0, maka datanya kosong diantrian
    if(top == 0){
        return true;
    } else {
        return false;
    }
}

// untuk menampilkan data ketika antriannya datanya
void view(){
    if(!isempty()){ //jika tidak kosong, maka akan menampilkan data
        cout<<"data antrian = " << endl;
        for (int a = top-1;a >= 0; a--){ // top-1 agar bisa menampilkan array ke 0
            cout << a+1 << ". " << data[a] << endl; 
            // a = top yang ditampilkan yang dikurangi dengan 1 agar tidak ada indeks ke 5 jika datanya ada 5
            // a+1 agar tampil data dari 1
        } 
    } else{
        cout<<"Antrian kosong"<<endl;
    }

    if(isfull()){
        cout<<"antrian penuh\n"<<endl;
    }
}

// function enqueue
void enqueue(){
    if(!isfull()){
        cout<<"Masukkan data = ";
        cin >> data[top]; // agar data masuk kedalam array data dengan variabel top
        top++;
    }
}

// function dequeue
void dequeue(){ // bisa mengelurakan data jika antriannya ada datanya
    if(!isempty()){
        for(int a = 0; a<top;a++){  
            data[a] = data[a+1]; // untuk menggeser data kedua menjadi data kesatu
        }
        top--;
    }
}
int main(){
    int pilihan;
    string isi;

    //sub program agar program kembali kesini
    queue:
        system("cls");
        view();
        cout<<"\nMenu Utama\n1. Enqueue\n2. dequeue\nMasukkan Pilihan = ";
        cin >> pilihan;
        if(pilihan == 1){
            system("cls");
            enqueue();
            goto queue;
        } else if (pilihan == 2){
            system("cls");
            dequeue();
            goto queue;
        }
}