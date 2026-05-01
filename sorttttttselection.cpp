#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = 5;

    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        cout << "\nIterasi ke-" << i+1 << endl;

        for(int j = i+1; j < n; j++) {
            cout << "Bandingkan " << arr[minIndex] << " dan " << arr[j];

            if(arr[j] < arr[minIndex]) {
                minIndex = j;
                cout << " -> min baru";
            }
            cout << endl;
        }

        swap(arr[i], arr[minIndex]);

        cout << "Setelah swap: ";
        for(int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}