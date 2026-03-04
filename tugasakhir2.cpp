#include <iostream>
using namespace std;

#define max 5

// STACK
struct Stack { // variabel mengelompokkan beberapa variabel dengan tipe data berbeda menjadi satu tipe data buatan baru
    string datastack[max]; // variabel untuk menentukan jumlah maksimal data yang bisa di push
    int top;
};
Stack s = { {}, 0 };
// {} → untuk string data[max] 0 → untuk int top

bool kosong(){
    if(s.top == 0){ // jika posisi data = 0, maka benar, array sedang kosong
        return true;
    } else{
        return false;
    }
}
// Karena top adalah anggota struct Stack, maka harus diakses melalui objek (s.top). Tanpa s., compiler tidak dapat mengenali variabel top.

bool penuh(){ // untuk mendeteksi apakah array data sudah penuh atau belum
    if(s.top >= max){ // jika kondisinya lebih dari atau sama dengan max(5), maka true(penuh)
        return true;
    } else{
        return false; // jika tidak, maka false, artinya belum penuh, sehingga bisa menginput data menggunakan push
    }
}

void display(){ 
    if(!kosong()){ // jika data tidak kosong, maka tampilkan data yang tersimpan
        cout<<"Data Tersimpan"<<endl;
        for(int a = 0; a < s.top; a++){ //
            cout<<a+1<<". "<<s.datastack[a]<<endl;
        }
    } else{
        cout<<"Data Tidak tersedia"<<endl;
    }
    if(penuh()){
        cout<<"Stack penuh"<<endl;
    }
    cout<<endl;
}

void push(){
    if(!penuh()){ // jika belum full, maka bisa menambahkan data
        cout<<"Masukkan Nama Karyawan = ";
        cin >> s.datastack[s.top];
        s.top++;
    }
}

void pop(){ // jika data tidak kosong, maka data bisa dihapus
    if(!kosong()){
        s.top--;
    }
}

// QUEUE
string dataqueue[max];
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
        cout<<"antrian pengunjung = " << endl;
        for (int a = top-1;a >= 0; a--){ // top-1 agar bisa menampilkan array ke 0
            cout << a+1 << ". " << dataqueue[a] << endl; 
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
        cout<<"Masukkan Nama = ";
        cin >> dataqueue[top]; // agar data masuk kedalam array data dengan variabel top
        top++;
    }
}

// function dequeue
void dequeue(){ // bisa mengelurakan data jika antriannya ada datanya
    if(!isempty()){
        for(int a = 0; a<top;a++){  
            dataqueue[a] = dataqueue[a+1]; // untuk menggeser data kedua menjadi data kesatu
        }
        top--;
    }
}

int main(){
    // judul
    // deklarasi
    int quit;
    int pilihsortataulihatdaftar;
    int temp;
    int banyakinput;
    int pilihan;
    int pilihansort;
    // string lanjutorno;
    int inputbuku;
    int databaseBukuInt[4] = {121, 122, 123, 124};
    string databaseBukuStr[4] = {"C++ Dasar", "HTTYD", "HayeWay", "Python Dasar"};

    // user user
    while(true){
        utama:
        system("cls");
        cout << "\nPROGRAM PENDATAAN BUKU PERPUSTAKAAN\n" << endl;
        cout << "1. Masukkan Kode Buku Baru\t(Sort)\n2. Cek Stok Buku\t\t(Sequential Search)\n3. Antrian Pengunjung Perpus\t(Queue)\n4. Daftar Absen Karyawan Perpus\t(Stack)\n5. Keluar Program\n---------------------\nMasukkan Pillihan = ";
        cin >> pilihan;
        cin.ignore();
        
        if(pilihan == 1){
            system("cls");
            cout<<"\nMasukkan banyak kode buku baru  = ";
            cin>>banyakinput;
            int data[banyakinput]; // agar variabel data bisa membaca array dari input user
            
            // input data
            for(int a = 0; a < banyakinput; a++){
                cout<<"Masukkan kode buku ke- " << a+1 << " = ";
                cin>>data[a]; // -1 karena indeks array dimulai dari angka 0
            }
            cout << "\n1. Lihat Daftar Kode Buku\n2. Sorting Buku\nMasukkan pilihan = ";
            cin>>pilihsortataulihatdaftar;
            
            if (pilihsortataulihatdaftar == 1){
                daftarbuku:
                system("cls");
                cout<<"\nBerikut Daftar Buku Baru"<<endl;
                for(int i = 0; i<banyakinput; i++){
                    cout<<"- "<<data[i]<<endl;
                }
                cout<<"\n1. Kembali ke menu utama\n2. Lanjut Sort\n3. Akhiri Program\nMasukkan Pilihan = ";
                cin>>quit;
                if(quit==1){
                    goto utama;
                } else if(quit==2){
                    goto sort;
                } else{
                    break;
                }
            } 

            if (pilihsortataulihatdaftar == 2){
                sort:
                system("cls");
                cout<<"\n1. Bubble sort\n2. Insertion sort\n3. quick sort\n4. selection sort\nMasukkan pilihan sorting = ";
                cin >> pilihansort;
            } 

            // proses bubble sort
            // Membandingkan dua elemen bersebelahan Jika urutannya salah, keduanya ditukar Proses diulang sampai tidak ada pertukaran lagi
            if (pilihansort == 1){
                for (int b = 0; b < banyakinput - 1; b++){
                    for(int c = 0; c < banyakinput - 1 - b; c++){
                        if(data[c] > data[c+1]){
                            temp = data[c];
                            data[c] = data[c+1];
                            data[c+1] = temp;
                        }
                    }
                }
                cout<<"\nHasil Sorting (bubble sort)"<<endl;
                for(int x = 0; x < banyakinput; x++){
                    cout<<"- "<<data[x]<<endl;
                }
                cout<<"\n1. Kembali ke menu utama\n2. Kembali ke Daftar Buku\n3. Akhiri Program\nMasukkan Pilihan = ";
                cin>>quit;
                if(quit==1){
                    goto utama;
                } else if(quit==2){
                    goto daftarbuku;
                } else{
                    break;
                }
            }

            // proses insertion sort - kurang cout 
            // seperti bubble sort, tetapi tidak membandingkan satu persatu melainkan langsung membandingkan dengan semua elemen sebelumnya
            else if(pilihansort == 2){
                for(int i = 1; i < banyakinput; i++){
                    int key = data[i];
                    int j = i - 1;

                    while(j >= 0 && data[j] > key){
                        data[j + 1] = data[j];
                        j--;
                    }
                    data[j + 1] = key;
                }
                cout << "\nHasil Sorting (Insertion Sort)"<<endl;
                for(int i = 0; i < banyakinput; i++){
                    cout << "- " << data[i] << endl;
                }
                cout<<"\n1. Kembali ke menu utama\n2. Kembali ke Daftar Buku\n3. Akhiri Program\nMasukkan Pilihan = ";
                cin>>quit;
                if(quit==1){
                    goto utama;
                } else if(quit==2){
                    goto daftarbuku;
                } else{
                    break;
                }
            }

            // proses quick sort + cout
            // Memilih pivot (nilai tengah),  Memisahkan data menjadi: Kecil dari pivot, Besar dari pivot, Mengurutkan bagian tersebut secara rekursif
            else if(pilihansort == 3){
                for(int step = 0; step < banyakinput; step++){
                    int pivot = data[step];

                    int left = 0;
                    int right = banyakinput - 1;

                while(left < right){
                    while(data[left] < pivot) left++;
                    while(data[right] > pivot) right--;

                    if(left <= right){
                        swap(data[left], data[right]);
                        left++;
                        right--;
                        }
                    }
                }   
                cout << "\nHasil Sorting (Quick Sort)" << endl;
                for(int i = 0; i < banyakinput; i++){
                    cout << "- " << data[i] << endl;
                }
                cout<<"\n1. Kembali ke menu utama\n2. Kembali ke Daftar Buku\n3. Akhiri Program\nMasukkan Pilihan = ";
                cin>>quit;
                if(quit==1){
                    goto utama;
                } else if(quit==2){
                    goto daftarbuku;
                } else{
                    break;
                }
            }

            // proses selesction sort - kurang cout
            // Mencari nilai terkecil Menukarnya dengan elemen di posisi awal Ulangi untuk posisi berikutnya
            // mencari nilai terkecil dari data lalu memindahkannya ke paling depan
            else if(pilihansort == 4){
                for(int i = 0; i < banyakinput - 1; i++){
                    int minIndex = i;
                    for(int j = i + 1; j < banyakinput; j++){
                        if(data[j] < data[minIndex]){
                            minIndex = j;
                        }
                    }
                    swap(data[i], data[minIndex]);
                }
                cout << "\nHasil Sorting (Selection Sort)"<<endl;
                for(int i = 0; i < banyakinput; i++){
                    cout << "- " << data[i] << endl;
                }
                cout<<"\n1. Kembali ke menu utama\n2. Kembali ke Daftar Buku\n3. Akhiri Program\nMasukkan Pilihan = ";
                cin>>quit;
                if(quit==1){
                    goto utama;
                } else if(quit==2){
                    goto daftarbuku;
                } else{
                    break;
                }
            }
        }

        // sequential search
        else if (pilihan == 2){
            sequential:
            system("cls");
            cout << "\n121 - C++ Dasar\t\t122 - HTTYD\n123 - HayeWay\t\t124 - Python Dasar\nMasukkan Kode Buku = ";
            cin >> inputbuku;

            bool ketemu = false;

            for(int i = 0; i < 4; i++){
                if (inputbuku == databaseBukuInt[i]){
                    cout << "Buku '" << databaseBukuStr[i] << "' Tersedia" << endl;
                    ketemu = true;
                    cout<<"\n1. Kembali ke menu utama\n2. Kembali ke Stok Buku\n3. Akhiri program\nMasukkan Pilihan = ";
                    cin>>quit;
                    if(quit==1){
                        goto utama;
                    } else if(quit==2){
                        goto sequential;
                    } else{
                        break;
                    }
                }
            }
            if(!ketemu){
                cout << "Maaf Buku dengan kode '" << inputbuku << "' Tidak Tersedia" << endl;
                cout<<"\n1. Kembali ke menu utama\n2. Kembali ke Stok Buku\n3. Akhiri program\nMasukkan Pilihan = ";
                cin>>quit;
                if(quit==1){
                    goto utama;
                } else if(quit==2){
                    goto sequential;
                } else{
                    break;
                }
            }
        }

        // algoritma queue
        else if (pilihan == 3){
            int pilihanqueue;
            string isi;

            //sub program agar program kembali kesini
            queue:
                system("cls");
                view();
                cout<<"\nData kehadiran Pengunjung (FIFO)\n1. Masukkan Nama Pengunjung\n2. Hapus Nama\n3. Kembali ke Menu Utama\n4. Akhiri Program\nMasukkan Pilihan = ";
                cin >> pilihanqueue;
                if(pilihanqueue == 1){
                    // system("cls");
                    enqueue();
                    goto queue;
                } else if (pilihanqueue == 2){
                    // system("cls");
                    dequeue();
                    goto queue;
                } else if(pilihanqueue == 3){
                    goto utama;
                } else if(pilihanqueue == 4){
                    break;
                }
        }

        // algoritma stack
        else if(pilihan == 4){
            int pilihanstack; // pilihan untuk memilih push atau pop
            string isi; // sesuatu yang akan dipush kedalam stack

            stack:
                system("cls");
                display();
                cout<<"Data Kehadiran Karyawan (LIFO)\n1. Input Nama Karyawan\n2. Hapus Nama Karyawan\n3. Kembali ke menu\n4. Akhiri Program\nMasukkan Pilihan = ";
                cin >> pilihanstack;

                if(pilihanstack==1){
                    push();
                    goto stack;
                } else if(pilihanstack==2){
                    pop();
                    goto stack;
                } else if(pilihanstack == 3){
                    goto utama;
                } else if(pilihanstack == 4){
                    break;
                }
        }

        else if(pilihan == 5){
            break;
        } else{
            cout<<"Out of range!";
            break;
        }
    }
    return 0;
}