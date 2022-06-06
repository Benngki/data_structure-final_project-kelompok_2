#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        int len_baru = (int) (len - strlen(judul)) / 2;
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
        for (int j = 0; j < len_baru; j++)
        {
            printf("%c", token);
        }
        printf("%s", judul);
        if ((int) (len - strlen(judul)) % 2 != 0) len_baru += (int) (len - strlen(judul)) % 2;
        // while ((len_baru*2)+strlen(judul) < len) {
        //     len_baru++;
        // }
        // printf("[%d]", len_baru);
        for (int k = 0; k <= len_baru; k++)
        {
            printf("%c", token);
        }
        if (new_line){
            printf("\n");
        }
    }
    
}

int main(){
    int temp[] = {1546793837, 778333539}, len = 13;
    char *str_temp;
    
    sprintf(str_temp, "%d", temp[0]);
    printf("|");
    teksTengah(str_temp, '-', len, "biasa", 1);
    // printf("|");
    sprintf(str_temp, "%d", temp[1]);
    printf("|");
    teksTengah(str_temp, '-', len, "biasa", 0);
    printf("|");

    return 0;
}