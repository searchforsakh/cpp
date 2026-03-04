#include <iostream>
#define SIZE 5
using namespace std;

class Queue {
	private:
		int items[SIZE], front, rear;
		
	public:
		Queue() {
			front = -1;
			rear = -1;
		}

		int isFull(){
			return (rear == SIZE - 1);
		}

		int isEmpty(){
			return (front == -1);
		}

		void enQueue(int element){
			if (isFull()) {
				cout << "Antrian sudah penuh" << endl;
			} else {
				if (front == -1) front = 0;
				rear++;
				items[rear] = element;
			}
		}

		int deQueue(){
			if (isEmpty()) {
				cout << "Antrian masih kosong" << endl;
				return -1;
			} else {
				int element = items[front];
				if (front >= rear) {
					front = -1;
					rear = -1;
				} else {
					front++;
				}
				cout << "Hapus -> " << element << endl;
				return element;
			}
		}

		void display(){
			if (isEmpty()) {
				cout << "Antrian kosong" << endl;
			} else {
			    cout << endl << "Index depan -> " << front;
				cout << endl << "Items-> ";
				for (int i = front; i <= rear; i++)
					cout << items[i] << " ";
				cout << endl;
			}
		}
};

int main() {
	Queue q;
	int x;
	
	cout << "Masukkan 5 elemen" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << "Input elemen " << i + 1 << ": ";
		cin >> x;
		q.enQueue(x);
	}
	
	cout << "\n == Isi antrian sekarang == \n";
	q.display();
	
	cout << "\n == Proses deQueue 1 elemen == \n";
	q.deQueue();
	
	cout << "\n == Isi antrian setelah deQueue == \n";
	q.display();
	
	return 0;
}