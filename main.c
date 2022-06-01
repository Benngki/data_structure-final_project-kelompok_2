#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INF 999

void teksTengah(char *judul, char token, float len, char* mode, int new_line){
    if (mode == "parent" || mode == "run"){
        int len = (int) (len - strlen(judul) - 1) / 2;
        if (mode != "run"){
            for (int j = 0; j < len*2+strlen(judul); j++)
            {
                printf("%c", token);
            }
            printf("\n");
        }
        for (int k = 0; k < len; k++)
        {
            printf(" ");
        }
        printf("%s", judul);
        for (int k = 0; k < len; k++)
        {
            printf(" ");
        }        
        printf("\n");
        if (mode != "run"){
            for (int j = 0; j < len*2+strlen(judul); j++)
            {
                printf("%c", token);
            }
            printf("\n");      
        }
    }
    else if (mode == "pembatas"){
         len = (int) len;
        for (int j = 0; j < len-1; j++)
        {
            printf("%s", judul);
        }
        printf("%c", token);
        if (new_line){
            printf("\n");
        }
    }
    else{
        len = (int) round((len - strlen(judul) - 1) / 2);
        for (int j = 0; j < len; j++)
        {
            printf("%c", token);
        }
        printf("%s", judul);
        for (int k = 0; k < len; k++)
        {
            printf("%c", token);
        }
        if (new_line){
            printf("\n");
        }
    }
    
}

void header(){
    printf(" "); teksTengah("", '_', 60, "biasa", 1);
    printf("|"); teksTengah("", ' ', 60, "biasa", 0); printf("|\n");
    printf("|"); teksTengah("/--------------------------------\\", ' ', 60, "biasa", 0); printf("|\n");
    printf("|"); teksTengah("| PROGRAM PENCARIAN RUTE TERPENDEK |", ' ', 60, "biasa", 0); printf("|\n");
    printf("|"); teksTengah("\\--------------------------------/", ' ', 60, "biasa", 0); printf("|\n");
    printf("|"); teksTengah("-- GRAPH IMPLEMENTATION --", ' ', 60, "biasa", 0); printf("|\n");
    printf("|"); teksTengah("", '_', 60, "biasa", 0); printf("|\n");
}

void footer(int jarak_min, int *rute, int n){
    char temp[20];
    printf(" "); teksTengah("", '_', 60, "biasa", 1);
    printf("|"); teksTengah("", ' ', 60, "biasa", 0); printf("|\n");
    
    // cetak total jarak minimum
    sprintf(temp, "Total jarak minimum adalah %d", jarak_min);
    if (strlen(temp)%2 != 0) strcat(temp, " ");
    printf("|"); teksTengah(temp, ' ', 60, "biasa", 0); printf("|\n");

    printf("|"); teksTengah("Dengan rute terpendek : ", ' ', 60, "biasa", 0); printf("|\n");

    // cetak rute terpendek
    char str_rute[50];
    strcpy(str_rute, "");
    // printf("%d", rute[n-1]);
    for (int i = n-1; i >= 0; i--){        
        if (i != 0) sprintf(temp, "%d -> ", rute[i]);
        else sprintf(temp, "%d", rute[i]);
        strcat(str_rute, temp);        
    }
    if (strlen(str_rute)%2 != 0) strcat(str_rute, " ");
    printf("|"); teksTengah(str_rute, ' ', 60, "biasa", 0); printf("|\n");
    printf("|"); teksTengah("", '_', 60, "biasa", 0); printf("|\n");
}

void tampilkanGraph(int *graph, int n){
    char temp[20];
    int len_num=0;
    printf(" Represemtasi graf dalam bentuk matriks :\n");

    // cari angka terbesar agar lebar tabel disesuaikan
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            sprintf(temp, "%d", *(graph + i*n + j) );
            if (strlen(temp) > len_num) len_num = strlen(temp);
        }
    }

    int lebar_node = len_num+4, lebar_nomor;
    sprintf(temp, "%d", n);
    lebar_nomor = strlen(temp)+3;
    //  cetak pembatas nomor atas
    printf("\n ");
    teksTengah("", ' ', lebar_nomor, "biasa", 0);
    for (int i = 0; i < n; i++){
        sprintf(temp, "%d", i+1);
        printf("");
        teksTengah(temp, ' ', lebar_node, "biasa", 0);
    }
    printf("\n ");
    teksTengah("_", '|', lebar_nomor, "pembatas", 0);
    for (int i = 0; i < n; i++){
        sprintf(temp, "%d", i+1);
        teksTengah("_", '|', lebar_node, "pembatas", 0);
    }
    printf("\n ");
    
    // print graf dalam bentuk matriks
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j == 0) {
                sprintf(temp, "%d", i+1);
                teksTengah(temp, ' ', lebar_nomor-1, "biasa", 0); printf("|");
            }
            sprintf(temp, "%d", *(graph + i*n + j));
            teksTengah(temp, ' ', lebar_node, "biasa", 0); 
            if (strlen(temp) == lebar_node-4) printf("\b");
            printf("|");
        }
        printf("\n ");
        teksTengah("-", '|', lebar_nomor, "pembatas", 0);
        for (int i = 0; i < n; i++){
            sprintf(temp, "%d", i+1);
            teksTengah("-", '|', lebar_node, "pembatas", 0);
        }
        printf("\n ");
    }    
}

void cariRuteTerpendek(int jum_node, int awal, int *rute, int *jarak, int *temp, int *panjang_rute){
    //nenampilkan jalur dan jarak untuk setiap node
    for (int i = 0, k, j, z=0; i < jum_node ;i++)
    {
        *panjang_rute = 0;
        z = 0;
        if(i!=awal)
        {
            printf ("\n Hasil jarak untuk node ke-%d adalah %d\n",i+1,jarak[i]);

            j=i;
            printf (" %d <- ", i+1);
            rute[z] = i+1;
            z++;
            *panjang_rute+=1;
            while(j!=awal)
            {
                j=temp[j];
                printf ("%d",j+1);
                rute[z] = j+1;
                z++;
                *panjang_rute+=1;
                if(j!=awal)
                {
                    printf (" <- ");
                }
            }
        }
    }
    printf("\n");
}

int* buatGraph(int *jum_node) {
    int *G;
    
    // input user untuk jumlah node
    printf("\n Masukan jumlah node : ");
    scanf("%d",jum_node);
    G = (int*) malloc((*jum_node)*(*jum_node)*sizeof(int));

    printf(" Masukkan jarak antar node :\n");
    printf("   Note! Jika tidak ada jarak masukkan 0!\n");
    for (int i = 0; i < (*jum_node); i++){
        for (int j = 0; j < (*jum_node); j++){
            // opsi 1
            // if (i == j) G[i][j] = 0;

            // opsi 2
            // if (i == j){
            //     printf("   %d -> %d = %d\n", i+1, j+1, 0);                
            //     G[i][j] = 0;
            //     continue;
            // }

            if (j == i) *(G + (*jum_node)*i + j) = 0;
            else if (j < i) *(G + (*jum_node)*i + j) = *(G + (*jum_node)*j + i);
            else {
                printf("   %d -> %d = ", i+1, j+1);
                scanf("%d", (G + (*jum_node)*i + j));
                if (j == (*jum_node)-1) printf(" ------------------------------------------------\n");
            }
        }        
    }

    return G;
}

void menu(){

    int jum_node,awal;
    int *G, tempGraf[jum_node][jum_node],jarak[jum_node],visit[jum_node],temp[jum_node],count;

    char list_menu_utama[][20] = {"Buat graph", "Cari rute terpendek", "Tambah data", "Update"};
    int pilihan;
    
    // cetak header
    header();

    teksTengah(" Menu Utama ", '=', 62, "biasa", 1);
    for (int i = 0; i < sizeof(list_menu_utama)/sizeof(char)/20; i++){
        printf("-> %d. %s\n", i+1, list_menu_utama[i]);
    }
    printf("-> Masukkan pilihan anda [1-%d]: ", sizeof(list_menu_utama)/sizeof(char)/20);
    scanf("%d", &pilihan);
    switch (pilihan)
    {
    case 1:
        break;
    
    default:
        break;
    }
    // 1. Buat graf
    // 2. update data 
    // 2. delete data
    // 3. add data
    // 4. lihat data

    // buat graph
    G = (int*) buatGraph(&jum_node);

    tampilkanGraph(G, jum_node);
    

    printf("\n Masukan node awal : ");
    scanf ("%d",&awal);
    awal--;

    int akhir;
    printf(" Masukan node akhir : ");
    scanf ("%d",&akhir);
    akhir--;

    for(int i=0;i<jum_node;i++)
    {
        for (int j=0;j<jum_node;j++)
        {
            if (*(G + jum_node*i + j) == 0)
            {
                tempGraf[i][j] = INF;
            }
            else{
                tempGraf[i][j] = *(G + jum_node*i + j);
            }
        }
    }
    for (int i = 0;i<jum_node;i++)
    {
        jarak[i] = tempGraf[awal][i];
        temp[i] = awal;
        visit[i] = 0;
    }
    jarak[awal] = 0;
    visit[awal] = 1;

    count =1; //dimulai dari 1 karena kita tidak akan menghitung node asal lagi

    //proses untuk menghitung node yang dikunjungi
    int jarakmin,nextnode;
    // while (count < jum_node-1)
    while (count < jum_node-1)
    {
        jarakmin = INF;
        for (int i=0;i<jum_node;i++)
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
        for(int i = 0;i<jum_node;i++)
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

    // proses pencarian rute terpendek
    int rute[jum_node], panjang_rute;
    cariRuteTerpendek(jum_node, awal, rute, jarak, temp, &panjang_rute);
    
    // cetak footer
    footer(jarak[jum_node-1], rute, panjang_rute); 

}

int main()
{

    // panggil fungsi menu
    menu();

    return 0;
}