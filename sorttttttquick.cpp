//FATHURRIZKY-20250803093
#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    cout << "\nPivot: " << pivot << endl;

    int i = low - 1;

    for(int j = low; j < high; j++) {
        cout << "Bandingkan " << arr[j] << " dengan pivot";

        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            cout << " -> pindah ke kiri";
        }
        cout << endl;
    }

    swap(arr[i+1], arr[high]);

    cout << "Setelah partisi: ";
    printArray(arr, n);

    return i + 1;
}

void quickSort(int arr[], int low, int high, int n) {
    if(low < high) {
        int pi = partition(arr, low, high, n);
        quickSort(arr, low, pi-1, n);
        quickSort(arr, pi+1, high, n);
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = 5;

    quickSort(arr, 0, n-1, n);
}