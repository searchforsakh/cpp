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

string main(){
    string data[2]=
    ("""
        Nama = Ferry Santoso
        NIM = 22070230007
        IPK 3,57
    """)
    ("""
        Nama = Sakha Pratama
        NIM = 20250801037
        IPK 4,00
    """)
    };
    
    string dicari="1";

    printf("\tAlgoritma Mencari Data Mahasaiswa\n\n");
    printf("""
        Nama = Ferry Santoso
        NIM = 22070230007
        IPK 3,57
        """);
    // printf("Posisi %d berada pada index ke-n = %d \n", dicari, cari(data,2,dicari));

    return 0;

    }