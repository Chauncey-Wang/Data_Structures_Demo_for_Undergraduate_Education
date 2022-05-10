#include<iostream>
using namespace std;

long Fact(long n){
    if (n==0)
        return 1;
    else
        return n*Fact(n-1);
}

long Fib(long n){
    if(n==1||n==2)
        return 1;
    else
        return Fib(n-1)+Fib(n-2);
}

int main(){
    cout << Fact(5) << endl;
    cout << Fib(5)  << endl;  // 1、1、2、3、5、8

    return 0;
}
