 0; i--){
        if (i != 0) sprintf(temp, "%d ->", rute[i]);
        else sprintf(temp, "%d", rute[i]);
        strcat(str_rute, temp);        
    }