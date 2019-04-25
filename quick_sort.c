#include<stdio.h>
#include<stdlib.h>

int partition(int A[], int p, int r){
    int temp;
    int j;
    int x = A[r];
    int i =(p - 1);
    
    for(j=p; j<r; j++){
        if (A[j] <= x){
            i++;
            //swap(&A[i],&A[j]);
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }//end of if
        
    }//end of for
    
    //swap( &A[i+1], &A[r]);
    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;
    return i+1;
    
}

void quickSort(int A[], int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quickSort( A, p, q-1);
        quickSort( A, q+1, r);
    }
}


int main(){
    int sizeofArray = 20;
    int A[sizeofArray];
    
    
    printf("\n\n");
    int n = sizeof(A)/sizeof(A[0]);
    for(int i = 0 ; i < sizeofArray ; i++ ) {
        A[i] = rand() % 50;
        //printf("%d ", A[i]);
    }

    
    quickSort(A, 0, n-1);
    for (int i=0; i < sizeofArray; i++){
        printf("%d ", A[i]);
    }
    

    return 0;
}
