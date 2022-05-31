// #include <stdio.h>

// struct kota {
//     int nilai;
//     int jarak;
// };

// void cariRuteTerpendek(){
//     for (int i = 0; i < jum_kota; i++){
//         for (int j = 0; j < jum_kota; j++){
//             if (data_kota[i][j] == 1){
                
//             }
//         }
//     }
// }

// int main(){
//     // masukkan jumlah kota yang dapat terhubung
//     int jum_kota;
//     printf("Masukkan jumlah kota yang akan dilewati : ");
//     scanf("%d", &jum_kota);

//     // meminta input user untuk memasukkan penghubung antarkota
//     struct kota data_kota[jum_kota][jum_kota];
//     for (int i = 1; i <= jum_kota; i++){
//         for (int j = 1; j <= jum_kota; j++){
//             if (j <= i) {
//                 data_kota[i-1][j-1].nilai = 0;
//             }
//             else {
//                 printf("kota %d -> kota %d [1/0]?  ", i, j);
//                 // printf("apakah ada jarak antara kota %d ke kota %d ")
//                 scanf("%d", &data_kota[i-1][j-1].nilai);

//                 // jika ada jarak input jarak kota 
//                 if (data_kota[i-1][j-1].nilai == 1){
//                     printf("Masukkan jarak kota %d ke %d : ", i, j);
//                     scanf("%d", &data_kota[i-1][j-1].jarak);
//                 }
//             }
//         }
//     }

//     // masukkan jarak untuk setiap kota

//     for (int i = 0; i < jum_kota; i++){
//         // if (i == 0) {
//         //     for (int k = 0; k < jum_kota; k++){
//         //         printf("\t%d", k+1);
//         //     }
//         // }
//         for (int j = 0; j < jum_kota; j++){
//             // if (j == 0) printf("%d| ", i);
//             printf("%d ", data_kota[i][j].nilai);

//             // if (data_kota[i][j].nilai == 1){
//             //     printf("|%d", data_kota[i][j].jarak);
//             // }
//             // printf("\t");
//         }
//         printf("\n");
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#define INF 999
int main()
{
    int n,i,j,start;
    printf("Masukan jumlah node : ");
    scanf("%d",&n);
    int G[n][n],tempGraf[n][n],jarak[n],visit[n],temp[n],count;

    printf("Masukkan jarak antar node :\n");
    printf("  Note! Jika tidak ada jarak masukkan 0!\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            // if (i == j) G[i][j] = 0;
            if (i == j){
                printf("  %d -> %d = %d\n", i+1, j+1, 0);                
                G[i][j] = 0;
                continue;
            }
            printf("  %d -> %d = ", i+1, j+1);
            scanf("%d", &G[i][j]);
        }
    }

    printf("Masukan node Asal : ");
    scanf ("%d",&start);
    start--;

    for(i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (G[i][j] == 0)
            {
                tempGraf[i][j] = INF;
            }
            else{
                tempGraf[i][j] = G[i][j];
            }
        }
    }
    for (i = 0;i<n;i++)
    {
        jarak[i] = tempGraf[start][i];
        temp[i] = start;
        visit[i] = 0;
    }
    jarak[start] = 0;
    visit[start] = 1;

    count =1; //dimulai dari 1 karena kita tidak akan menghitung node asal lagi

    //proses untuk menghitung node yang dikunjungi
    int jarakmin,nextnode;
    while (count < n-1)
    {
        jarakmin = INF;
        for (i=0;i<n;i++)
        {
            //jika jarak lebih kecil dari jarak minimum dan node belum dikunjungi
            // maka jarak minimum adalah jarak yang sudah dibandingkan sebelumnya dengan jarakmin
                if(jarak[i] < jarakmin && visit[i]!=1)
                {
                    jarakmin = jarak[i];
                    nextnode = i; //untuk memberikan node pada jarak minimum
                }
        }

        // untuk mengecek node selanjutnya yang terhubung dengan node lain yang memiliki jarak minimum
        visit[nextnode] = 1;
        for(i = 0;i<n;i++)
        {
            if(visit[i]!=1)
            {
                if(jarakmin+tempGraf[nextnode][i]<jarak[i])
                {
                    jarak[i] = jarakmin+tempGraf[nextnode][i];
                    temp[i] = nextnode;
                }
            }
        }
    count++;
    }
    //nenampilkan jalur dan jarak untuk setiap node
    int a[n+1],k;
    for (i = 0; i < n ;i++)
    {
        if(i!=start)
        {
            printf ("\nHasil jarak untuk node ke-%d adalah %d\n",i+1,jarak[i]);

            j=i;
             printf ("%d<-",i+1);
            while(j!=start)
            {
                j=temp[j];
                printf ("%d",j+1);
                if(j!=start)
                {
                    printf ("<-");
                }

            }

        }
    }
    printf ("\nTotal Jaraknya adalah %d\n",jarak[n-1]);
    return 0;
}















