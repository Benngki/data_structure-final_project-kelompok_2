#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INF 999

/*
    Program ini memanfaatkan konsep graph dua arah dan algoritma dijkstra untuk melakukan pencarian rute terpendek

    fitur program :
        1. Buat graf 
        2. ubah data
        3. delete data
        4. tambah data
        5. lihat data
        6. pencarian rute terpendek

*/

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
        int len_baru = (int) (len - strlen(judul)) / 2, len_baru2;
        // int len_baru = (int) round((len - strlen(judul) - 1) / 2);
        // for (int j = 0; j < len_baru; j++)
        // {
        //     printf("%c", token);
        // }
        // printf("%s", judul);
        // while ((len_baru*2)+strlen(judul) < len) {
        //     len_baru++;
        // }
        // for (int k = 0; k < len_baru; k++)
        // {
        //     printf("%c", token);
        // }
        // printf("[%d]", len_baru);
        if ((int) (len - strlen(judul)) % 2 != 0) {
            len_baru2 = len_baru;
            len_baru += (int) (len - strlen(judul)) % 2;
        }
        for (int j = 0; j < len_baru; j++)
        {
            printf("%c", token);
        }
        printf("%s", judul);
        if ((int) (len - strlen(judul)) % 2 != 0) {
            len_baru = len_baru2;
        }
        // if ((int) (len - strlen(judul)) % 2 != 0) len_baru += (int) (len - strlen(judul)) % 2;
        // while ((len_baru*2)+strlen(judul) < len) {
        //     len_baru++;
        // }
        // printf("[%d]", len_baru);
        for (int k = 0; k < len_baru; k++)
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
    if (strlen(temp)%2 != 0) strcat(temp, " ");
    sprintf(temp, "Total jarak minimum adalah %d", jarak_min);
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

void penutup(){

    printf(" "); teksTengah("", '_', 60, "biasa", 1);
    printf("|"); teksTengah("      / \\          / \\      ", ' ', 60, "biasa", 0); printf("|\n"); 
    printf("|"); teksTengah(" _____/___\\________/___\\_____ ", ' ', 60, "biasa", 0); printf("|\n"); 
    printf("|"); teksTengah("|                            |", ' ', 60, "biasa", 0); printf("|\n"); 
    printf("|"); teksTengah("|     ~~ TERIMA KASIH ~~     |", ' ', 60, "biasa", 0); printf("|\n"); 
    printf("|"); teksTengah("|____________________________|", ' ', 60, "biasa", 0); printf("|\n"); 
    printf("|"); teksTengah("", ' ', 60, "biasa", 0); printf("|\n");
    printf("|"); teksTengah("", '_', 60, "biasa", 0); printf("|\n");
}

void tampilkanGraph(int *graph, int n){
    char temp[20];
    int len_num=0;
    printf("\n   Represemtasi graf dalam bentuk matriks :");

    // cari angka terbesar agar lebar tabel disesuaikan
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            sprintf(temp, "%d", *(graph + i*n + j) );
            if (strlen(temp) > len_num) len_num = strlen(temp);
        }
    }

    int lebar_node = len_num+2, lebar_nomor;
    sprintf(temp, "%d", n);
    lebar_nomor = strlen(temp)+3;
    //  cetak pembatas nomor atas
    printf("\n   ");
    teksTengah("", ' ', lebar_nomor, "biasa", 0);
    for (int i = 0; i < n; i++){
        sprintf(temp, "%d", i+1);
        teksTengah(temp, ' ', lebar_node, "biasa", 0);
        printf(" ");
    }
    printf("\n   ");
    // teksTengah("_", '|', lebar_nomor, "pembatas", 0);
    teksTengah("", '-', lebar_nomor-1, "biasa", 0);
    printf("|");
    for (int i = 0; i < n; i++){
        // sprintf(temp, "%d", i+1);
        // teksTengah("_", '|', lebar_node+1, "pembatas", 0);
        teksTengah("", '-', lebar_node, "biasa", 0);
        printf("|");
    }
    printf("\n   ");
    
    // print graf dalam bentuk matriks
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j == 0) {
                sprintf(temp, "%d", i+1);
                teksTengah(temp, ' ', lebar_nomor-1, "biasa", 0); printf("|");
            }
            sprintf(temp, "%d", *(graph + i*n + j));
            teksTengah(temp, ' ', lebar_node, "biasa", 0); 
            // if (strlen(temp) == lebar_node-4) printf("\b");
            printf("|");
        }
        printf("\n   ");
        // teksTengah("-", '|', lebar_nomor, "pembatas", 0);
        teksTengah("", '-', lebar_nomor-1, "biasa", 0);
        printf("|");
        for (int i = 0; i < n; i++){
            sprintf(temp, "%d", i+1);
            // teksTengah("-", '|', lebar_node+1, "pembatas", 0);
            teksTengah("", '-', lebar_node, "biasa", 0);
            printf("|");
        }
        printf("\n   ");
    }    
    printf("\n");
}

void cariRuteTerpendek(int* G, int jum_node, int awal){
    int tempGraf[jum_node][jum_node], visit[jum_node], count, jarak[jum_node],temp[jum_node];

    printf("   Masukan node awal : ");
    scanf ("%d",&awal);
    awal--;

    int akhir;
    printf("   Masukan node akhir : ");
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
    int jarakmin, nextnode;
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
    //nenampilkan jalur dan jarak untuk setiap node
    for (int i = 0, k, j, z=0; i < jum_node ;i++)
    {
        panjang_rute = 0;
        z = 0;
        if(i!=awal)
        {
            printf ("\n   Hasil jarak untuk node ke-%d adalah %d\n",i+1,jarak[i]);

            j=i;
            printf ("   %d <- ", i+1);
            rute[z] = i+1;
            z++;
            panjang_rute+=1;
            while(j!=awal)
            {
                j=temp[j];
                printf ("%d",j+1);
                rute[z] = j+1;
                z++;
                panjang_rute+=1;
                if(j!=awal)
                {
                    printf (" <- ");
                }
            }
        }
    }
    printf("\n");
    
    // cetak footer
    footer(jarak[jum_node-1], rute, panjang_rute); 
}

int* buatGraph(int *jum_node) {
    int *G;
    // char *jenis_graph[] = {"Satu arah", "Dua arah"};

    // cetak header
    // system("cls");
    // header();
    // teksTengah(" Buat Graph ", '=', 62, "biasa", 1);

    // for (int i = 0; i < 2; i++){
    //     printf("-> %d. %s\n", i+1, jenis_graph[i]);
    // }
    // printf("-? Masukkan pilihan anda : ");
    // scanf("%d", &mode_graph);
    // printf("\n");
    
    // input user untuk jumlah node
    printf("   Masukan jumlah node : ");
    scanf("%d",jum_node);
    G = (int*) malloc((*jum_node)*(*jum_node)*sizeof(int));

    printf("   Masukkan jarak antar node :\n");
    printf("     Note! Jika tidak ada jarak masukkan 0!\n");
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
                printf("   %d <-> %d = ", i+1, j+1);
                scanf("%d", (G + (*jum_node)*i + j));
                if (j == (*jum_node)-1) teksTengah("", '-', 62, "biasa", 1);
            }
        }        
    }

    return G;
}

void ubahData(int *G, int jum_node){
    // deklarasi variabel
    int lokasi_data[2], data_baru;
    // menampilkan graph sekarang
    tampilkanGraph(G, jum_node);
    // input user
    printf("   Data yang ingin diubah [X Y]: ");
    scanf("%d %d", &lokasi_data[0], &lokasi_data[1]);
    lokasi_data[0]--; lokasi_data[1]--; // ubah inputan menjadi index
    printf("   Ubah data menjadi : ");
    scanf("%d", &data_baru);
    // mengubah data 
    *(G + lokasi_data[0]*jum_node + lokasi_data[1]) = data_baru;
    *(G + lokasi_data[1]*jum_node + lokasi_data[0]) = data_baru;
}

int* tambahData(int *G, int *jum_node){
    int jum_node_baru, *G_baru;

    // temp_graph = (int*) malloc(temp_count*sizeof(int));

    printf("   Masukkan jumlah data : ");
    scanf("%d", &jum_node_baru);

    // tampilkanGraph(G, *jum_node);

    jum_node_baru += *jum_node;
    
    // tampilkanGraph(G, *jum_node);

    G_baru = (int*) malloc(jum_node_baru*jum_node_baru*sizeof(int));
    // realloc(G, (*jum_node)*(*jum_node)*sizeof(int));
    
    // tampilkanGraph(G_baru, jum_node_baru);
    

    for (int i = 0; i < jum_node_baru; i++){
        for (int j = 0; j < jum_node_baru; j++){
            *(G_baru + (jum_node_baru)*i + j) = -1;
            // *(G_baru + j) = -1;
        }
    }

    // tampilkanGraph(G_baru, jum_node_baru);

    for (int i = 0; i < jum_node_baru; i++){
        for (int j = 0; j < jum_node_baru; j++){
            // printf("{test}");
            if (j < *jum_node && i < *jum_node) *(G_baru + jum_node_baru*i + j) = *(G + (*jum_node)*i + j);
            else if (j < i) *(G_baru + jum_node_baru*i + j) = *(G_baru + jum_node_baru*j + i);
            else if (i == j) *(G_baru + jum_node_baru*i + j) = 0;
            else{
                printf("   %d <-> %d = ", i+1, j+1);
                scanf("%d", (G_baru + (jum_node_baru)*i + j));
                if (j == jum_node_baru-1) teksTengah("", '-', 62, "biasa", 1);
            }
        }
            // if (j == (*jum_node)-1) teksTengah("", '-', 62, "biasa", 1);
    }

    // for (int i = 0; i < *jum_node; i++){
    //     for (int j = 0; j < *jum_node; j++){
    //         *(G_baru + (jum_node_baru)*i + j) = *(G + (*jum_node)*i + j);
    //     }
    // }

    tampilkanGraph(G, *jum_node);
    tampilkanGraph(G_baru, jum_node_baru);
    free(G);


    G = G_baru;
    *jum_node = jum_node_baru;

    // free(G);

    teksTengah(" Berhasil menambahkan data! ", '-', 62, "biasa", 1);

    tampilkanGraph(G, *jum_node);

    return G;

    // ubahData(G, *jum_node);


    // tempGraph = (int*) malloc(sizeof)
}

int* hapusData(int *G, int *jum_node){
    // deklarasi variabel
    int lokasi_data, *G_baru, jum_node_baru;
    // menampilkan graph sekarang
    tampilkanGraph(G, *jum_node);
    // input user
    printf("   Data yang ingin dihapus [X/Y]: ");
    scanf("%d", &lokasi_data);
    lokasi_data--; // ubah inputan menjadi index
    // mengapus data
    jum_node_baru = *jum_node - 1;
    G_baru = (int*) malloc(jum_node_baru*jum_node_baru*sizeof(int));
    for (int i = 0, k = 0; i < *jum_node; i++){
        if (i == lokasi_data) continue;
        for (int j = 0, l = 0; j < *jum_node; j++){
            // if ((i == lokasi_data[0] && j == lokasi_data[1]) || (j == lokasi_data[0] && i == lokasi_data[1])) continue;
            if (j == lokasi_data) continue;
            else{
                *(G_baru + jum_node_baru*k + l) = *(G + (*jum_node)*i + j);
                l++;
            }
        }
        k++;
    }
    *jum_node = jum_node_baru;
    teksTengah(" Berhasil menghapus data! ", '-', 62, "biasa", 1);

    return G_baru;
}

void menu(){

    int jum_node,awal;
    int *G = NULL;

    char list_menu_utama[][20] = {"Buat graph", "Cari rute terpendek", "Tampilkan graph", "Tambah data", "Hapus data", "Ubah data"}, lagi, inp_hapus_graph;
    int pilihan;
    
    do{
        // back_menu:
        system("cls");
        // cetak header
        header();

        teksTengah(" Menu Utama ", '=', 62, "biasa", 1);
        for (int i = 0; i < sizeof(list_menu_utama)/sizeof(char)/20; i++){
            printf("-> %d. %s\n", i+1, list_menu_utama[i]);
        }
        printf("-? Masukkan pilihan anda [1-%d]: ", sizeof(list_menu_utama)/sizeof(char)/20);
        scanf("%d", &pilihan);

        switch (pilihan){
            case 1:
                // buat graph
                if (G != NULL) {
                    printf(".? Apakah anda yakin ingin membuat graph baru [y/t]: ");
                    scanf("\n%c", &inp_hapus_graph);
                    if (inp_hapus_graph == 'y') G = (int*) buatGraph(&jum_node);
                }
                else G = (int*) buatGraph(&jum_node);
                break;
            case 2:
                if (G == NULL) teksTengah(" Anda harus membuat graph terlebih dahulu! -", '-', 62, "biasa", 1);
                else cariRuteTerpendek(G, jum_node, awal);
                // if (G == NULL) teksTengah(strGanjil(" Anda harus membuat graph terlebih dahulu! "), '-', 62, "biasa", 1);
                break;
            case 3:
                // tampilkan graph
                if (G == NULL) teksTengah(" Anda harus membuat graph terlebih dahulu! -", '-', 62, "biasa", 1);
                else tampilkanGraph(G, jum_node);
                break;
            case 4:
                if (G == NULL) teksTengah(" Anda harus membuat graph terlebih dahulu! -", '-', 62, "biasa", 1);
                else G = tambahData(G, &jum_node);
                break;
            case 5:
                if (G == NULL) teksTengah(" Anda harus membuat graph terlebih dahulu! -", '-', 62, "biasa", 1);
                else G = hapusData(G, &jum_node);
                break;
            case 6:
                if (G == NULL) teksTengah(" Anda harus membuat graph terlebih dahulu! -", '-', 62, "biasa", 1);
                // else teksTengah(" Sedang dalam pengembangan -", '-', 62, "biasa", 1);
                else ubahData(G, jum_node);
                break;
            default:
                printf("--- Input salah! ---\n");
        }

        printf("-? Kembali ke menu utama [y/t]? ");
        scanf("\n%c", &lagi);
    } while (lagi == 'y');

    // cetak kalimat penutup
    penutup();
    
    

}

int main()
{

    // panggil fungsi menu
    menu();

    return 0;
}