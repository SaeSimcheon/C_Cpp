/*
구현 해보기 

문자 로 부터의 문자열 생성, C 문자열 (char *) 로 부터의 생성 

문자열 길이를 구하는 함수

문자열 뒤에 다른 문자열 붙이기

문자열 내에 포함되어 있는 문자열 구하기

새로운 문자열 할당하기

문자열 위치에 삽입하기

문자열 지우기

문자열 비교하기
*/
/*
1215 구현 종료 후 스스로 피드백

메모리는 만들어 놓고 막상 사용하지 않음 -> 정확히 왜 메모리를 저장하는 변수를 
따로 만드는지 생각 안 하고 그냥 습관처럼 만들었음. 

메모리를 저장하는 변수를 만든 이유는 이전 어떤 변화들에서 메모리가 넉넉하게 잡혔지만
그 것보다 작은 변수를 저장한 후에 크기가 다시 커지는 경우

재할당을 반복해서 하는 것은 시간이 오래걸리는 문제가 있기 때문에 가지고 있는 메모리를

통해서 assign 등에서 비교함으로써 효율적으로 함수를 운용할 수 있음.



- 비교에서 min(length , obj.length) 할 수 있었음.

- compare 함수 잘못 작성되어 있음. -> 대소 기준을 잘못이해하고 있음.


- find 함수에서 딱 그 위치에서 문자열이 찾이지는지만 구현했음. 
-> 기준 위치부터 그 다음 전부까지 
- 찾아지면 index 반환하게 짤 수 있음.

- 특정 문자 위치를 리턴하는 함수
- 메모리 할당 함수 및 현재 할당된 크기를 알아오는 함수

12 /16 일에 다시 이 코드 쭉 비교하면서 보완하기

*/



// 생성자 안에서 쓸 함수 미리 정의해서 사용할 수 있음.
#include <iostream>

// 문자열을 관리하는 class
// 일단 리터럴이나 문자를 받아서 관리하고 
// 문자열 자체도 받는다.
// 문자열의 길이와 확보한 메모리도 갖고 있자.
using namespace std;
class String{

    char * a;

    int length;
    int mem ;

    public:
    // character 받는 생성자
    // _a는 문자 리터럴
    int get_size(const char * given){
        int size = 0 ;

        for (;;){
            if (given[size]!='\0')
                size+=1;
            else
                break;
        }
        return size;
    }
    String(const char _a){
        length = 1;
        mem = length+1;
        a= new char[mem];
        a[0] = _a;
    }

    String(const char * _a){
        //a = _a;// 이대로면 새로 문자열을 할당하거나 뒤에 문자열을 붙이는 등의 작업을 할때 문제가 있을 것 같음. _a는 리터럴 문자열을 가리키고 a로 같은 곳을 가리킨다는 의미가 되기 때문
        length = get_size(_a);
        mem = length+1;
        a= new char[mem];
        for (int i=0 ; i < length ; i++){
            a[i] = _a[i];
        }
    }
    // 같은 클래스 안에서 private 인스턴스 변수 접근 가능한가?
    String(const String & _a){
        length = _a.length;
        mem = _a.mem;
        a= new char[mem];
        for (int i=0 ; i < length ; i++){
            a[i] = _a.a[i];
        }
    }
    void print(){

        for ( int i =0 ; i < length ; i ++)
            cout << a[i];
        cout << endl;
        
        cout << length << endl;
        cout << mem << endl;
    }
    // 모든 인자 케이스에 대해서 overloading 하게 짜는 것보다 instance를 생성해서 주는 것이 더 깔끔하다.
    // 뒤에 문자를 추가.
    void append(const char added){
        String tmp = String(added);
        append(tmp);
    }
    void append(const char * added){
        String tmp = String(added);
        append(tmp);
    }
    void append(const String & added){
        // 임시 저장소에 현재 가지고 있는 문자열을 저장해두고 새로 메모리를 할당 받아 사용하자.
        String tmp = String(this->a);
        
        
        length = tmp.length + added.length ;
        mem = length +1;
        delete[] a ;
        a = new char[mem];

        for (int i =0 ; i < tmp.length ; i ++){
            a[i] = tmp.a[i];
        }

        for (int i =0 ; i < added.length ; i ++){
            a[tmp.length+i] = added.a[i];
        }

        //delete[] a ;
    }

    void insert(int loc ,const char inserted){
        String tmp = String(inserted);
        insert(loc,tmp);
    }
    void insert(int loc ,const char * inserted){
        String tmp = String(inserted);
        insert(loc,tmp);
    }
    void insert(int loc ,const String & inserted){
        // insert도 마찬가지로 임시 저장소에 현재 가지고 있는 문자열을 저장해두고 새로 메모리를 할당 받아 사용하자.
        if (loc > length || loc < 0) {
            cout << " Wrong input loc !! " << endl;
            return ;}
        String tmp = String(this->a);
        
        
        length = tmp.length + inserted.length ;
        mem = length +1;
        delete[] a ;
        a = new char[mem];

        for (int i =0 ; i < loc ; i ++){
            a[i] = tmp.a[i];
        }

        for (int i =0 ; i < inserted.length ; i ++){
            a[loc+i] = inserted.a[i];
        }

        int remain = length - loc - inserted.length;
        for (int i =0 ; i < remain ; i ++){
            a[loc + inserted.length +i] = tmp.a[loc + i];
        }
        //delete[] a ;
    }
    // 문자열 탐색 find 함수

    bool find(int loc , const char obj){
        String tmp = String(obj);
        return find(loc, tmp);
    }

    bool find(int loc , const char * obj){
        String tmp = String(obj);
        return find(loc, tmp);
    }

    bool find(int loc , const String & obj){
        if ( length-obj.length < loc || loc < 0 ) {
            return false;
        }
        for (int i = 0 ; i < obj.length ; i ++){
            if (a[i+loc] == obj.a[i]) continue ;
            else return false;
        }
        return true;
    }
    void assign(const char assigned){
        String tmp(assigned);
        assign(assigned);
    }

    void assign(const char * assigned){
        String tmp(assigned);
        assign(assigned);
    }

    void assign(const String & assigned){
        if (mem >= assigned.mem){
            for (int i = 0 ; i < assigned.length ; i ++)
                a[i] = assigned.a[i];
            length = assigned.length;
        }else{
            delete[] a;
            length = assigned.length;
            mem = length +1; // 메모리 이렇게 저장할 필요 없음
            a = new char[mem]; 

            for (int i = 0 ; i < length ; i ++){
                a[i] = assigned.a[i];
            }
        }
    }

    bool cmp(const char obj){
        String tmp(obj);
        return cmp(tmp);
    }

    bool cmp(const char * obj){
        String tmp(obj);
        return cmp(tmp);
    }

    bool cmp(const String & obj){
        int cmp_len ;
        if (length >= obj.length) cmp_len = obj.length;
        else cmp_len = length;

        for (int i =0 ; i < cmp_len ; i ++){
                if (a[i] == obj.a[i]) 
                    continue;
                else return a[i] > obj.a[i];
            }

        return length < obj.length ;
    }

    void erase(int loc ){
        if (loc > length || loc < 0) {
            cout << " Wrong input loc !! " << endl;
            return ;}
        
        length = loc;
        mem = length +1;
        a[loc] = '\0';
    }

    ~String(){
        delete[] a;
    }

    
};


int main(){
    
    char a = 'a';
    const char * aa = &a;
    
    String str1('a');
    String str2("abs");
    String str3(str2);
    str1.print();
    str2.print();
    str3.print();
    str1.append(str3);
    str1.print();
    str1.insert(100,str3);
    str1.print();
    cout << str1.find(3,"c") << endl;
    cout << str1.find(3,"s") << endl;
    str1.assign(str3);
    str1.print();
    

    str1.erase(2);
    str1.print();

    return 0 ;
}

// 인자로 문자배열을 받을때 char * a <- char a[] , char a[10] 같게됨
// 문자배열을 받을때 const char * a 나 char *a나 변화만 시키지 않는다면 
// 문자열 리터럴을 인자로 받을때 const char * a 이렇게 받아야함.(문자열 리터럴의 주소를 저장) const char & (주소의 별명은 불가) 이건 가능한가? 이건 불가능함.



// const char * 이렇게 된 경우에 이 포인터 변수로 접근해서 바꾸지 못한다.
// const * char 이렇게 된 경우에 이 포인터 변수의 내용을 바꾸지 못한다. (https://stackoverflow.com/questions/890535/what-is-the-difference-between-char-const-and-const-char) 참고
// The difference is that const char * is a pointer to a const char(엄연히 따지면 const char로 취급하는거지 const char은 아닐 수도 있는거 아닌가 ?), while char * const is a constant pointer to a char.
//     char a = 'a';
//    const char * aa = &a; 이 코드가 가능하고 aa로는 a의 내용을 바꿀 수 없지만 a는 바꿀 수 있음.

// 
