



#include<stdio.h>
#include<stdlib.h>
#include<time.h>



void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int A[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }

}

void max_heapify(int A[], int n, int i){

    int temp;
    int largest = i;
    int left_child = 2*i +1 ;
	int right_child = 2*i + 2;
 

	if( left_child <= n && A[i] < A[left_child]) {
		largest = left_child;
	}
    else{
        largest = i;
    }
	if( right_child <= n && A[largest] < A[right_child] ){
		largest = right_child;
	}
	if(largest != i){
		//swap(&A[largest], &A[i]);
        temp = A[largest];
        A[largest] = A[i];
        A[i] = temp;
        max_heapify(A, n, largest);
	}
	
}

void build_max_heap(int A[], int n){
	int m = (n-1) /2;
	int i;
	for(i= m; i>-1; i--){
		max_heapify(A, n-1, i);
	}
}


void heapSort(int A[], int n){
    build_max_heap(A, n);
    int temp;
    int size =n;
    int i;
    for(i=n-1; i>-1; i--){
		//swap(&A[0], &A[i]);
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        n--;
		max_heapify(A, n-1, 0);

	}
	
}

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

void merge(int A[], int low, int mid, int high){
	int i;
	int j;
	int k;

    int sizeofB = mid - low + 1;
    int sizeofC = high - mid;
    int B[sizeofB]; int C[sizeofC];
    
    /*help from internet to figure out how to "slice" in C */
    
	for(i=0; i<sizeofB; i++)
	{
		B[i] = A[i + low];
	}
    
	
	for(j=0; j<sizeofC; j++)
	{
		C[j] = A[mid + 1 + j];
	}
	
    i=0;
    j=0;
    k=low;
    
    while(i < sizeofB && j < sizeofC)
	{
		if(B[i] <= C[j]){
            A[k] = B[i];
			i++;
		}
		else
		{
			A[k] = C[j];
			j++;
		}
        k++;
	}

	while(i<sizeofB)
	{
		A[k] = B[i];
		i++;
		k++;
	}	

	while( j < sizeofC)
	{
		A[k] = C[j];
		j++;
		k++;
	}
}

void mergeSort(int A[], int low, int high){
    if(low<high)
    {
        int mid = (low + high) / 2;

        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}


int main(){
    clock_t begin = clock();
    int sizeofArray;
    int choice;
    time_t t;
    printf("What will the size of the array be? ");
    scanf("%d", &sizeofArray);
    int A[sizeofArray];
    
    srand((unsigned) time(&t));
    printf("Unsorted Array: ");
    for(int i = 0 ; i < sizeofArray ; i++ ) {
        A[i] = rand() % 1000000000001;
        //printf("%d ", A[i]);
    }
    printf("\n\n");
    int n = sizeof(A)/sizeof(A[0]);
    printf("1. HeapSort\n2. QuickSort\n3. MergeSort\n\nSelect which Sorting Algorithm you would like to use: ");
    scanf("%d",&choice);

    
    if(choice == 1){
        clock_t begin = clock();
        heapSort(A, n);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        //printf("\nSorted Array: ");
        //printArray(A, n);
        printf("\n");
        printf("Here is the execution time --> %f seconds\n", time_spent);
        printf("\n");
        
    }
    else if(choice==2){
        clock_t begin = clock();
        quickSort(A, 0, n-1);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        //printf("\nSorted Array: ");
        //printArray(A, n);
        printf("\n");
        printf("Here is the execution time --> %f seconds\n", time_spent);
        printf("\n");
    }
    else if(choice==3){
        clock_t begin = clock();
        mergeSort(A, 0, n-1);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        //printf("\nSorted Array: ");
        //printArray(A, n);
        printf("\n");
        printf("Here is the execution time --> %f seconds\n", time_spent);
        printf("\n");
    }
    else{
        printf("\nInvalid Option. Please Try Again!\n");
    }
	
    



return 0;
}


/* RESULTS FROM RUNNING TIME
 
 Heapsort:
 -25000 -->  0.007893 seconds
 -100000 --> 0.028161 seconds
 -500000 --> 0.149854 seconds
 -1000000 --> 0.318057 seconds
 
 
 QuickSort:
 -25000 --> 0.005261 seconds
 -100000 -->0.017336 seconds
 -500000 --> 0.078926 seconds
 -1000000 --> 0.165451 seconds
 
 MergeSort:
 -25000 -->  0.007129 seconds
 -100000 -->  0.023596 seconds
 -500000 --> 0.114847 seconds
 -1000000 --> 0.239632 seconds
 
 */
