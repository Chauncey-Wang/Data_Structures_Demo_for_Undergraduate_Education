#include<iostream>
#include<fstream>
using namespace std;

int a=2, b=4;

void swap_reference(int &c, int &d){
    int temp; 
    temp=c; 
    c=d; 
    d=temp;
}

void swap_test(int c, int d){
    int temp; 
    temp=c; 
    c=d; 
    d=temp;
}

int main(){
    swap_reference(a,b);
    // swap_test(a,b);
    cout << a << endl;
    cout << b << endl;
    return 0;
}
