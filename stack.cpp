#include <cstdlib>
#include <iostream>

using namespace std;

// Mendefinisikan kapasitas maksimal stack
#define MAX 10 

// Struktur data Stack
struct stack {
    int items[MAX]; // Array untuk menyimpan data
    int top;        // Variabel penanda indeks data teratas
};
typedef struct stack st; // Alias agar lebih mudah memanggil 'st' daripada 'struct stack'

// Fungsi untuk inisialisasi stack kosong
void createEmptyStack(st *s) {
    s->top = -1; // Top diatur ke -1 karena array dimulai dari indeks 0
}

// Mengecek apakah stack sudah penuh
int isfull(st *s) {
    if (s->top == MAX - 1)
        return 1; // Mengembalikan 1 jika penuh
    else
        return 0; // Mengembalikan 0 jika belum penuh
}

// Mengecek apakah stack kosong
int isempty(st *s) {
    if(s->top == - 1)
        return 1; // Mengembalikan 1 jika kosong
    else
        return 0; // Mengembalikan 0 jika berisi data
}

// Fungsi untuk menambah data ke tumpukan (Push)
void push(st *s, int newitem) {
    if(isfull(s)) {
        cout << "Stack Full";
    } else {
        s->top++; // Naikkan indeks top
        s->items[s->top] = newitem; // Masukkan data baru ke posisi top
    }
}

// Fungsi untuk mengambil/menghapus data teratas (Pop)
void pop(st *s) {
    if(isempty(s)) {
        cout << "\n Stack Empty \n";
    } else {
        // Tampilkan data yang akan dihapus
        cout << "Item popped= " << s->items[s->top];
        s->top--; // Turunkan indeks top untuk "menghapus" data secara logika
    }
    cout << endl;
}

// Fungsi untuk menampilkan seluruh isi stack
void printStack(st *s) {
    cout << "Stack: ";
    for (int i = 0; i <= s->top; i++) {
        cout << s->items[i] << " "; // Cetak data dari bawah ke atas
    }
    cout << endl;
}

int main() {
    // Alokasi memori untuk struktur stack
    st *s = (st *)malloc(sizeof(st));
    
    // Inisialisasi awal
    createEmptyStack(s);
    
    // Memasukkan data ke dalam stack
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    
    // Menampilkan stack awal
    printStack(s);
    
    // Menghapus data teratas (angka 4)
    pop(s);
    
    // Menampilkan stack setelah data dihapus
    cout << "\nAfter Popping Out\n";
    printStack(s);

    // Membebaskan memori yang dialokasi (best practice)
    free(s);

    return 0;
}