#include<iostream>
using namespace std;

int main()
{
    int coin []= {1000,500,200,100,50,20,10,5,2,1};
    int M=2890;//changes amount
    int minCoins=0;
    cout<<"Selected coins:"<<endl;
    int i=0;
    while(M>0)
    {
        if(M>=coin[i])
        {
            int x=M/coin[i];
            minCoins+=x;
            M=M-x*coin[i];
            cout<<coin[i]<<"-->"<<x<<endl;
        }
        i++;

    }
    cout<<"Minimum number of coins: "<<minCoins<<endl;
}

