#include<iostream>
using namespace std;

int Sum(int n){
    //1+2+...+n
    if(n <= 0) return 0;
    if(n == 1) return 1;
    return Sum(n-1) + n;
}

int mySeries1(int n){
    //1+4+7+...+10
    //f(1)=1; f(4)=1+4; f(7)=1+4+7
    if(n <= 0) return 0;
    if(n==1) return 1;
    return mySeries1(n-3) + n;
}
int mySeries2(int n){
    //2+6+10+14+...
    //f(n)= compute the sum of the 1st n terms of the series
    //f(1)=2; f(2)=2+6; f(3)=2+6+10
    if(n <= 0) return 0;
    if(n == 1) return 2;
    return mySeries2(n-1) + (4*n - 2);
}
int mySeries3(int n){
    //3+5+7+...
    //f(n)= compute the sum of the 1st n terms of the series
    //f(1)=3; f(2)=3+5; f(3)=3+5+7
    if(n <= 0) return 0;
    if(n==1) return 3;
    return mySeries3(n-1) + (2*n + 1);
}

int FindNthTerm(int n){
    //1+2+5+8+11+..
    //f(n) = returns the nth term of the series
    //f(1)=1;f(2)=2;f(3)=5;f(4)=8
    if(n <= 0 ) return 0;
    if(n==1 || n==2) return n;
    return FindNthTerm(n-1) + 3;
}
int main(){
    int n = 4;
    int s = Sum(n);
    cout<<"sum from 1 to "<<n<<":"<<s<<endl;
    s = mySeries1(n);
    cout<< "sum of myseries1:" << s << endl;
    int t = FindNthTerm(4);
    cout << " nth term : " << t << endl;
}
