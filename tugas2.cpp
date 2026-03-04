#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int A[n];
    cout << "Masukkan elemen array:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    cout << "Nilai terbesar dalam array adalah: " << max << endl;
    return 0;
}