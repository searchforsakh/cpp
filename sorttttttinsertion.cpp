////FATHURRIZKY-20250803093
#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = 5;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        cout << "\nSisipkan " << key << endl;

        while (j >= 0 && arr[j] > key) {
            cout << "Geser " << arr[j] << " ke kanan" << endl;
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        cout << "Hasil: ";
        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;
    }

    return 0;
}