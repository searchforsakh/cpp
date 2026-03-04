#include<iostream>
using namespace std;

int luaspersegi(int sisi){
    return sisi*sisi;
}

int main(){
    int luas_persegi_1 = 5;
    int luas_persegi_2 = 7;
    int luas_persegi_3 = 9;
    int luas1 = luaspersegi(luas_persegi_1);
    cout<<"hasil luas 1 = "<< luas1<<endl;
    int luas2 = luaspersegi(luas_persegi_2);
    cout<<"hasil luas 2 = "<< luas2<<endl;
    int luas3 = luaspersegi(luas_persegi_3);
    cout<<"hasil luas 3 = "<< luas3<<endl;
    return 0;
}