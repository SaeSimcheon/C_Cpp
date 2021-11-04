#include <iostream>

using namespace std;

int main(){
    const int ci1 =2;
    int ci2 = 3;
    //ci1 =3;
    const int *pci2 =&ci2;
    cout << *pci2 <<endl;
    // *pci2 =5; error!
    ci2 = 5;
    cout << ci2 <<endl;

    pci2 = &ci1;

    //int const *pci5 =&pc;
    //cout << pci5 <<endl;
    return 0;
}