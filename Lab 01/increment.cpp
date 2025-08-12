#include<iostream>
using namespace std;

void increment(int &x){
    x++;
}

void Max(int a, int b, int &m){
    if(a > b) m = a;
    else m = b;
}

int main(){
    int y = 10;
    cout << "before increment : " << y << endl;
    increment(y);
    cout<< "after increment : " << y << endl;
    int a = 3, b = 7, m;
    Max(a, b, m);
    cout << "maximum : " << m << endl;
}
