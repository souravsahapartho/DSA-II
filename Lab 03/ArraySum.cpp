#include<iostream>
#include<vector>
using namespace std;

int ArraySum(vector<int> a, int idx){
    //compute the sum of the elements of the array
    //from index 0 to idx
    if(idx < 0) return 0;
    return ArraySum(a, idx-1 ) + a[idx];
}
int main(){
    vector<int> arr = {5, 2, 3, 1};
    int n = arr.size();
    int s = ArraySum(arr, n-1);
    cout << " sum : " << s << endl;
}
