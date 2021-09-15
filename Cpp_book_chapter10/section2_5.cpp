#include <iostream>
#include <string>
using namespace std;

template <class T>
class MyStack{
    int tos ;
    T data [100];
public :
MyStack();
void push(T element);
T pop();
};


template <class T>
MyStack<T>::MyStack(){
    tos = -1;
}

template <class T>
    
void MyStack<T>::push(T element){
    if (tos == 99){
        cout << "stack full";
        return ;
    }
    tos ++;
    data[tos] = element ;
}

template <class T>

T MyStack<T>::pop(){
    T retData;
    if (tos == -1){
        cout << "stack empty";
        return 0 ;
    }
    retData = data[tos--];
    return retData;
}



class point{
    int x, y;
    public :
    point(int x= 0 , int y = 0){ this -> x =x ;this-> y = y ;}
    void show(){ cout << '(' << x << ',' << y << ')' <<endl;}
};

int main(){
    
    MyStack<int *> ipstack;
    int *p = new int[3];
    for(int i = 0 ; i <3 ; i ++)p[i] = i *10;
    ipstack.push(p);
    //cout << ipstack << endl;
    int *q = ipstack.pop();
    
    for(int i = 0 ; i <3 ; i ++) cout << q[i] << ' ';
    cout << endl;
    delete [] p ;
    
    
    MyStack<point> pointstack;
    point a(2,3),b;
    pointstack.push(a);
    b = pointstack.pop();
    b.show();
    
    
    MyStack<point*> pstack;
    pstack.push(new point(10,20));
    point * ppoint = pstack.pop();
    //cout << pstack << endl;
    cout << ppoint << endl;
    ppoint -> show();
    
    MyStack<string> stringstack;
    string s = "c++";
    stringstack.push(s);
    stringstack.push("java");
    cout << stringstack.pop() <<' ';
    cout << stringstack.pop() <<endl;
    
}
