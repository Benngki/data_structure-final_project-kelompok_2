#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INF 9999999

/*
    Program ini memanfaatkan konsep undirected graph dua arah dan algoritma dijkstra untuk melakukan pencarian rute terpendek
    mencari rute terpendek berdasarkan data yang diinputkan.

    fitur program :
        1. Buat graf 
        2. ubah data
        3. delete data
        4. tambah data
        5. lihat data
        6. pencarian rute terpendek

*/

void teksTengah(char *judul, char token, float len, char* mode, int new_line){
    /* Fungsi untuk mencetak teks yang di tengah */
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
    /* Fungsi untuk mencetak header */
    printf(" "); teksTengah("", '_', 60, "biasa", 1);
    printf("|"); teksTengah("", ' ', 60, "biasa", 0); printf("|\n");
    printf("|"); teksTengah("/--------------------------------\\", ' ', 60, "biasa", 0); printf("|\n");
    printf("|"); teksTengah("| PROGRAM PENCARIAN RUTE TERPENDEK |", ' ', 60, "biasa", 0); printf("|\n");
    printf("|"); teksTengah("\\--------------------------------/", ' ', 60, "biasa", 0); printf("|\n");
    printf("|"); teksTengah("-- GRAPH IMPLEMENTATION --", ' ', 60, "biasa", 0); printf("|\n");
    printf("| "); printf("%59s", "Made by : Kelompok 2  ");printf("|\n");
    printf("|"); teksTengah("", '_', 60, "biasa", 0); printf("|\n");
}

void footer(int jarak_min, int *rute, int n){
    /* Fungsi untuk mencetak footer yang menampilkan informasi berupa jarak dan rute terpendek
    digunakan pada saat program menampilkan hasil pada menu 2
     */
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
    strcpy(str_rute, ""); // memastikan string kosong
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
    /* Fungsi untuk mencetak teks penutup "Terima Kasih" pada saat program sebelum tertutup */
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
    /* Fungsi untuk menampilkan graf */
    char temp[20];
    int len_num=0;
    printf("\n   Represemtasi graf dalam bentuk tabel :");

    // cari angka terbesar agar lebar tabel disesuaikan
    //  hal ini dilakukan agar tampilkan tabel rapi
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
    teksTengah("", '-', lebar_nomor-1, "biasa", 0);
    printf("|");
    for (int i = 0; i < n; i++){
        teksTengah("", '-', lebar_node, "biasa", 0);
        printf("|");
    }
    printf("\n   ");
    
    // print graf dalam bentuk tabel
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j == 0) {
                sprintf(temp, "%d", i+1);
                teksTengah(temp, ' ', lebar_nomor-1, "biasa", 0); printf("|");
            }
            sprintf(temp, "%d", *(graph + i*n + j));
            teksTengah(temp, ' ', lebar_node, "biasa", 0); 
            printf("|");
        }
        printf("\n   ");
        teksTengah("", '-', lebar_nomor-1, "biasa", 0);
        printf("|");
        for (int i = 0; i < n; i++){
            sprintf(temp, "%d", i+1);
            teksTengah("", '-', lebar_node, "biasa", 0);
            printf("|");
        }
        printf("\n   ");
    }    
    printf("\n");
}

void cariRuteTerpendek(int* G, int jum_node, int awal){
    /* Fungsi untuk mencari rute terpendek */
    int tempGraf[jum_node][jum_node], visit[jum_node], count, jarak[jum_node],temp[jum_node];

    // penentuan node awal dan akhir
    printf("   Masukan node awal  : ");
    scanf ("%d",&awal);
    awal--;
    int akhir;
    printf("   Masukan node akhir : ");
    scanf ("%d",&akhir);
    akhir--;

    // set nilai 0 pada node awal dan set nilai tak hingga pada node lain
    for(int i=0;i<jum_node;i++){
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
        // for (int i=0;i<akhir+1;i++)
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
        // for(int i = 0;i<akhir+1;i++)
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
        if(i==akhir)
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
            break;
        }
    }
    printf("\n");
    
    // cetak footer
    footer(jarak[akhir], rute, panjang_rute); 
}

int* buatGraph(int *jum_node) {
    /* Fungsi untuk membuat graph */
    int *G;
    // input user untuk jumlah node
    printf("   Masukan jumlah node : ");
    scanf("%d",jum_node);
    G = (int*) malloc((*jum_node)*(*jum_node)*sizeof(int));

    // user menginputkan bobot antar node
    printf("   Masukkan jarak antar node :\n");
    printf("     Note! Jika tidak ada jarak masukkan 0!\n");
    for (int i = 0; i < (*jum_node); i++){
        for (int j = 0; j < (*jum_node); j++){
            if (j == i) *(G + (*jum_node)*i + j) = 0;
            else if (j < i) *(G + (*jum_node)*i + j) = *(G + (*jum_node)*j + i);
            else {
                printf("   %d -- %d = ", i+1, j+1);
                scanf("%d", (G + (*jum_node)*i + j));
                if (j == (*jum_node)-1) teksTengah("", '-', 62, "biasa", 1);
            }
        }        
    }

    return G;
}

void ubahData(int *G, int jum_node){
    /* Fungsi untuk mengubah data */
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
    /* Fungsi untuk menambahkan data/node pada graf */
    int jum_node_baru, *G_baru;

    // input user
    printf("   Masukkan jumlah data : ");
    scanf("%d", &jum_node_baru);
    jum_node_baru += *jum_node;

    G_baru = (int*) malloc(jum_node_baru*jum_node_baru*sizeof(int)); // alokasi memori untuk G_baru

    // memberikan nilai -1 untuk setiap node pada G_baru
    for (int i = 0; i < jum_node_baru; i++){
        for (int j = 0; j < jum_node_baru; j++){
            *(G_baru + (jum_node_baru)*i + j) = -1;
        }
    }

    // memindahkan graph lama ke graph baru
    //  kemudian meminta input user jika ada node yang belum ada bobotnya
    for (int i = 0; i < jum_node_baru; i++){
        for (int j = 0; j < jum_node_baru; j++){
            if (j < *jum_node && i < *jum_node) *(G_baru + jum_node_baru*i + j) = *(G + (*jum_node)*i + j);
            else if (j < i) *(G_baru + jum_node_baru*i + j) = *(G_baru + jum_node_baru*j + i);
            else if (i == j) *(G_baru + jum_node_baru*i + j) = 0;
            else{
                printf("   %d <-> %d = ", i+1, j+1);
                scanf("%d", (G_baru + (jum_node_baru)*i + j));
                if (j == jum_node_baru-1) teksTengah("", '-', 62, "biasa", 1);
            }
        }
    }
    
    // mengupdate data graph lama dan jumlah node
    free(G); // menghapus G dari memori
    G = G_baru;
    *jum_node = jum_node_baru;

    // menampilkan info bahwa data berhasil ditambahkan
    teksTengah(" Berhasil menambahkan data! ", '-', 62, "biasa", 1);

    return G;
}

int* hapusData(int *G, int *jum_node){
    /* Fungsi untuk menghapus data */
    // deklarasi variabel
    int lokasi_data, *G_baru, jum_node_baru;

    // menampilkan graph sekarang
    tampilkanGraph(G, *jum_node);

    // input user
    printf("   Data yang ingin dihapus [X/Y]: ");
    scanf("%d", &lokasi_data);
    lokasi_data--; // ubah inputan menjadi index

    // proses menghapus data
    jum_node_baru = *jum_node - 1; // inisialisasi jumlah node baru
    G_baru = (int*) malloc(jum_node_baru*jum_node_baru*sizeof(int)); // alokasi memori untuk variabel G_baru
    for (int i = 0, k = 0; i < *jum_node; i++){
        if (i == lokasi_data) continue;
        for (int j = 0, l = 0; j < *jum_node; j++){
            if (j == lokasi_data) continue;
            else{
                *(G_baru + jum_node_baru*k + l) = *(G + (*jum_node)*i + j);
                l++;
            }
        }
        k++;
    }
    *jum_node = jum_node_baru; // mengupdate jumlah node

    // menampilkan informasi bahwa data berhasil dihapus
    teksTengah(" Berhasil menghapus data! ", '-', 62, "biasa", 1);

    return G_baru;
}

void menu(){
    /* Fungsi menu utama */

    int jum_node, awal, *G = NULL, pilihan;
    char list_menu_utama[][20] = {"Buat graph", "Cari rute terpendek", "Tampilkan graph", "Tambah data", "Hapus data", "Ubah data"}, lagi, inp_hapus_graph;
    
    do{
        // menampilkan tampilan menu
        system("cls");
        header(); // cetak header
        teksTengah(" Menu Utama ", '=', 62, "biasa", 1);
        for (int i = 0; i < sizeof(list_menu_utama)/sizeof(char)/20; i++){
            printf("-> %d. %s\n", i+1, list_menu_utama[i]);
        }
        //  meminta input user terkait menu yang ingin diakses
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
                // pencarian rute terpendek
                if (G == NULL) teksTengah(" Anda harus membuat graph terlebih dahulu! -", '-', 62, "biasa", 1);
                else cariRuteTerpendek(G, jum_node, awal);
                break;
            case 3:
                // tampilkan graph
                if (G == NULL) teksTengah(" Anda harus membuat graph terlebih dahulu! -", '-', 62, "biasa", 1);
                else tampilkanGraph(G, jum_node);
                break;
            case 4:
                // tambah data
                if (G == NULL) teksTengah(" Anda harus membuat graph terlebih dahulu! -", '-', 62, "biasa", 1);
                else G = tambahData(G, &jum_node);
                break;
            case 5:
                // hapus data
                if (G == NULL) teksTengah(" Anda harus membuat graph terlebih dahulu! -", '-', 62, "biasa", 1);
                else G = hapusData(G, &jum_node);
                break;
            case 6:
                // ubah data
                if (G == NULL) teksTengah(" Anda harus membuat graph terlebih dahulu! -", '-', 62, "biasa", 1);
                else ubahData(G, jum_node);
                break;
            default:
                teksTengah(" Input Salah! ", '-', 62, "biasa", 1);
        }

        // menanyakan user apakah ingin kembali ke menu utama
        printf("-? Kembali ke menu utama [y/t]? ");
        scanf("\n%c", &lagi);
    } while (lagi == 'y');

    // cetak kalimat penutup
    penutup();
    system("pause");
}

int main()
{

    // panggil fungsi menu
    menu();

    return 0;
}