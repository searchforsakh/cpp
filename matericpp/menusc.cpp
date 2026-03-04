#include <iostream>
#include <string>
using namespace std;

int main(){
	int jumlah;
	
	cout << "masukan banyak data : ";
	cin >> jumlah;
	
	string arr[jumlah];
	
	for (int i = 0; i < jumlah; i++){
		cout << "masukan kata : ";
		cin >> arr[i];
	}
	
	for (int i = 0; i < jumlah - 1; i++){
		for (int j = 0; j < jumlah - i - 1; j++){
			if (arr[j] > arr[j+1]){
				string temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	for (int i = 0; i < jumlah; i++){
		cout << i+1 << ". " << arr[i] << endl;
	}
	return 0;
}