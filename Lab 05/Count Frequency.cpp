#include<iostream>
#include<vector>
using namespace std;

int countFrequency(vector<int> a, int low, int high, int target){
    if(low == high){
        if(a[low] == target) return 1;
        else return 0;
    }
    int mid = (low + high)/2;
    int l = countFrequency(a, low, mid, target);
    int r = countFrequency(a, mid+1, high, target);
    return l + r;
}

int main(){
    vector<int> v = {21, 8, 9, 8, 31, 7, 8};
    int n = v.size();
    int t = 8;
    int c = countFrequency(v, 0, n-1, t);
    cout << " frequency : " << c << endl;
}
