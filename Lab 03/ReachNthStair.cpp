#include<iostream>
using namespace std;

int DistinctWays(int n){
    //you can climb 1 or 2 steps at a time.
    //Find the number of distinct ways to reach
    //from 0 th nth stair
    if(n <= 0 ) return 0;
    if(n==1 || n==2) return n;
    return DistinctWays(n-1) + DistinctWays(n-2);
}
int main(){
    int n = 3;
    int d = DistinctWays(n);
    cout << "No of distinct ways: " << d << endl;
}
