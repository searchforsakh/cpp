#include <iostream>

int cari(int data[], int n, int k){
    int posisi, i, ketemu;

    if(n<=0)
    posisi = -1;

    else
    {
        ketemu = 0;
        i = 1;
        while((i<=n-1)&& (!ketemu))
            if(data[i] == k)
            {
                posisi = i;
                ketemu = 1;
            }
            else{
                i++;
            }
            if(!ketemu)
                posisi =- 1;
    }
    return posisi;
}

int main(){
    int data[8]={8,10,6,-2,11,7,1,100};
    int dicari=6;

    printf("\tAlgoritma Sequential Search\n\n");
    printf("Data = 8,10,6,-2,11,7,1,100\n\n");
    printf("Posisi %d berada pada index ke-n = %d \n", dicari, cari(data,8,dicari));

    return 0;

}