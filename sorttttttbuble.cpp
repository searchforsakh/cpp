#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = 5;

    for(int i = 0; i < n-1; i++) {
        cout << "\nIterasi ke-" << i+1 << endl;
        for(int j = 0; j < n-i-1; j++) {
            cout << "Bandingkan " << arr[j] << " dan " << arr[j+1];

            if(arr[j] > arr[j+1]) {
                cout << " -> swap" << endl;
                swap(arr[j], arr[j+1]);
            } else {
                cout << " -> tidak swap" << endl;
            }
        }

        cout << "Hasil: ";
        for(int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;
    }

    return 0;
}