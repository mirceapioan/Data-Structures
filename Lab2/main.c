#include <stdio.h>
#include <stdlib.h>

int eliminare_cifra(int n, int c){
    int cifra, tmp;

    if (n == 0)
        return n;

    cifra = n % 10;
    tmp = eliminare_cifra(n / 10, c);

    if (cifra != c)
        tmp = tmp * 10 + cifra;

    return tmp;
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int magic_index(int arr[], int l, int r) { 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == mid) 
            return mid; 
  
        if (arr[mid] > mid) 
            return magic_index(arr, l, mid - 1); 
  
        return magic_index(arr, mid + 1, r); 
    } 
  
    return -1; 
} 

void recurenta (int arr[100], int n){
    arr[0] = 0;
    arr[1] = 1;

    for( int i = 2; i <= n; i++ ){
        arr[i] = 3 * arr[i - 1] - 2 * arr[i - 2] + 3;
    }

    printf("%d\n", arr[n]);
}
int main() {
    
    //EX:1
    /*
    printf("%d\n", eliminare_cifra(24599842, 2));
    printf("%d\n", eliminare_cifra(111, 1));
    printf("%d\n", eliminare_cifra(1234, 5));
    */

    //EX2:



    //EX:3
    /*
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    mergeSort(arr, 0, arr_size - 1);

    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    */

    //EX:4
    /*
    int arr[] = { -1, 0, 1, 2, 4, 10 }; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = magic_index(arr, 0, n - 1);
    printf("%d\n", result);

    int arr1[] = { 1, 2, 3, 4, 6, 9, 11 }; 
    n = sizeof(arr1) / sizeof(arr1[0]);
    result = magic_index(arr1, 0, n - 1);
    printf("%d\n", result);
    */

    //EX:5
    
    int arr[100];
    int n = 7;
    recurenta(arr, n);
    

    return 0;
}