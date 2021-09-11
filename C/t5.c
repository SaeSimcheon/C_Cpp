#include <stdio.h>

int main(){
    char a ;
    a= 'a';
    
    printf("%d , %c \n",a,a);
    
    
    
    char ch ;
    
    short sh ;
    int i ; 
    long lo;
    
    float fl ;
    double du ; 
    
    double celsius ;
    
    //printf("프로그램 \n");
    //printf("온도 입력 \n");
    //scanf("%lf",&celsius);
    
    
    //printf("섭씨 %f 도는 화씨로 %f 도 \n", celsius, 9* celsius / 5 + 32);
    
    
    printf("char 형 변수 ");
    scanf("%c",&ch);
    
    printf("short 형 변수 ");
    scanf("%hd",&sh);
    
    printf("int 형 변수 ");
    scanf("%d",&i);
    
    printf("long 형 변수 ");
    scanf("%ld",&lo);
    
    printf("float 형 변수 ");
    scanf("%f",&fl);
    
    printf("double 형 변수 ");
    scanf("%lf",&du);
    
    
    
    
    printf("char : %c , short : %d , int : %d \n",ch,sh,i);
    printf("long : %ld , float : %f , double : %f ",lo,fl,du);
    
    
    
    
    
    
    
    return 0 ;
    
}