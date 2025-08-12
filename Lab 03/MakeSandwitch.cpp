#include<iostream>
using namespace std;

int makeSandwich(int n, int m){
    //you need 2 breads and 3 eggs to make a sandwich
    //how many sandwiches you can make
    //if you have n breads and m eggs
    if(n < 2 || m < 3 ) return 0;
    return 1 + makeSandwich(n-2, m-3);
}
int makeCar(int x, int y, int z){
    //you need 2 rectangle blocks, 3 circle blocks,
    //1 triangle blocks,
    //how many cars you can make using x triangle,
    //y circle and z triangle blocks
    if(x<2 || y<3 || z<1) return 0;
    return 1 + makeCar(x-2, y-3, z-1);
}
int main(){
    int breads = 10, eggs = 7;
    int s = makeSandwich(breads, eggs);
    cout << "Total sandwiches: " << s << endl;
}
