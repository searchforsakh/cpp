#include <iostream>

using namespace std;

int main(){
    int a,b,x,y;
    //increment (ditambah), decrement(dikurang)
    cout << "increment" << endl;
    //post increment = memberikan operator setelah variabel, mencetak nilai variabel dahulu, kemudian ditambah
    x = 1;
    cout << "Nilai increment = " << x << endl;
    cout << "Nilai x post increment = " << ++x <<endl;
    cout << "Nilai x post increment = " << ++x <<endl;
    cout << "Nilai x post increment = " << ++x <<endl;
    
    //pre increment = memberikan operator sebelum variabel, menambah nilai variabel dahulu, kemudian di cetak
    y = 1;
    cout << "Nilai y pre increment = " << ++y <<endl;
    cout << "Nilai y pre increment = " << ++y <<endl;
    
    
    //decrement
    cout << "decrement" << endl;
    //post decrement = memberikan operator setelah variabel, mencetak nilai variabel dahulu, kemudian dikurang
    a = 5;
    cout << "Nilai decrement = " << 5 << endl;
    cout << "Nilai a post decrement = " << a--<<endl;
    cout << "Nilai a post decrement = " << a--<<endl;
    cout << "Nilai a post decrement = " << a--<<endl;

    //pre decrement = memberikan operator sebelum variabel, mengurangi nilai variabel dahulu, kemudian di cetak
    b = 5;
    cout << "Nilai b pre decrement = " << --b << endl;
    cout << "Nilai b pre decrement = " << --b << endl;
    
    return 0;
}