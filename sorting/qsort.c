void quickSort(int* v, int ini, int fim){
    if(fim>ini){                        
        int indexPivo = partition(v,ini,fim);
        quickSort(v,ini,indexPivo-1);
        quickSort(v,indexPivo+1,fim); 
    }
}

void swap(int* v, int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int partition(int* v, int ini, int fim){
    int pIndex = ini;
    int pivo = v[fim];
    for(int i = ini; i < fim; i++){
        if(v[i] <= pivo){
            swap(v,i,pIndex);
            pIndex++;
        }
    }
    swap(v,pIndex,fim);
    return pIndex;
}
