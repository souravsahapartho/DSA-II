#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr= {5,1,21,6,5,16,21,5,1};
    map<int,int> numbers;

    for(int x: arr)
    {
        numbers[x]++;
    }

    cout<<"Frequency of each element: "<<endl;
    for(auto i: numbers)
    {
        cout<<i.first<<"-->" <<i.second<<endl;
    }
}





/*Question-------
You are given an array. You have to find the frequency of each element in
the array using map.
Example:
Array = {5, 1, 21, 6, 5, 16, 21, 5, 1}
Output:
1 --> 2
5 --> 3
6 --> 1
16 --> 1
21 --> 2*/
