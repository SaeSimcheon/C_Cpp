#include <stdio.h>

struct test{
    int i ;
    char c ;
    
};


int main(){
    struct test st, st2;
    
    st.i = 1;
    st.c = 'c';
    
    st2= st;
    
    
    
    printf("&st1 : %p \n",&st);
    
    printf("st1.i : %p \n",&st.i);
    printf("st1.c : %p \n",&st.c);
    
    printf("st1.i : %d \n",st.i);
    printf("st1.c : %c \n",st.c);
    
    printf("&st2 : %p \n",&st2);
    
    printf("st2.i : %p \n",&st2.i);
    printf("st2.c : %p \n",&st2.c);
    
    printf("st2.i : %d \n",st2.i);
    printf("st2.c : %c \n",st2.c);
    
    
}