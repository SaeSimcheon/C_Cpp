#include <iostream>
#include <stdio.h>

using namespace std;


char & find(char s[100],int index){ // 
    cout << *s << endl;
    printf("%p \n",s) ;
    
    return s[index];
}


int main(){
    char name[] = "Mike";
    cout << name << endl;

    find(name,0) = 'S';
    cout << name << endl;
}