#include <stdio.h>
#include <math.h>
#include <string.h>

int zeros( int n ){
    int k = 0;
    if (n == 0){
        return 1;

    }else if (n < 10){
        return 0;

    }else if (n % 10 == 0){
        k = 1 + zeros (n /10);

    }else{
        k = zeros (n/10);
    }
    return k;
}

int recurenta (int n){
    int k = 0;
    if (n == 0){
        return 0;

    } else if ( n==1 ){
        return 1;
    } else {
        k = 3 * recurenta(n-1) - 2 * recurenta(n-2) + 3;
    }
    return k;
}

void putere(int i, int n, int *v){
    //printf("%d\n",*(v+2)+1); //test pointer
    if (i % 2 == 0){
        *(v+i) = pow(*(v+i), 2);
    } else {
        *(v+i) = pow(*(v+i), 3);
    }
    if ( i <= n - 1){
        i++;
        putere(i, n, v);
    }
    
}

int diferenta(int *tablou){
    int k = 0;
    if (*tablou == NULL)
        return k;
    
    if (*tablou % 2 == 0){
        k = diferenta(tablou + 1);

    } else if(*tablou % 2 != 0){
        k = diferenta(tablou + 1);
        
    }
    return k;
}

int distanta(char *s1, char *s2){
    if (strlen(s1) != strlen(s2)){
        return -1;
    }
    if (strlen(s1) == 0 || strlen(s2) == 0){
        return 0;
    }
    if (s1[0] != s2[0]) {
        return 1 + distanta(++s1, ++s2);
    }
    return distanta(++s1, ++s2);
}
int main(){

    //EX1
    //printf("%d \n", zeros(0));

    //EX2
    printf("%d \n", recurenta(7));

    //EX3
    /*
    int v[7] = {1, -1, 0, 2, 3, 2, 4};
    putere(0, 7, v);
    for(int i = 0; i < 7; i++) 
        printf("%d \n", *(v+i));
    */

    //EX4
    /*
    int tablou[8] = {1, 2, 2, 3, 4, 1, 3, 2};
    //printf("%d\n", *tablou+2); // test pointer
    printf("%d\n", diferenta(tablou));
    */
   
    //EX5
    /*
    char *s1 = "MARTHA";
    char *s2 = "MARHTA";
    printf("%d\n", distanta(s1, s2));
    */

    return 0;
}
