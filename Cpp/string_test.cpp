#include<iostream>
#include<stdio.h>

void ftn1(const char * name){
    std::cout << name<<sizeof(name) <<std::endl;
    
}


int main(){
    
    const char * name1="SangHyuk";
    const char * name2="SangHyuk";
    //const char & name3="SangHyuk"; 안 됨
    
    //int * a = 10;
    const int & a = 10;
    
    
    
    printf("literal 주소 : %p \n",&"SangHyuk");
    //printf("literal 주소 : %p \n",&'c');
    printf("literal 주소 : %p \n",name1);
    printf("literal 주소 : %p \n",&(name1[0]));
    printf("레퍼런스 주소 : %p \n",&a ); // 
    printf("레퍼런스 주소 : %ld \n",sizeof(&a) ); // 
    //printf("literal 주소 : %p \n",name3);
    
    
    // printf("literal 주소 : %p \n",&"SangHyuk"); 이건 됨. 돌릴때마다 달라지긴 하는데, 
    //printf("literal 주소 : %p \n",&'a'); 이것도 안 됨
    //printf("literal 주소 : %p \n",&10); 이것도 안 됨
    
}