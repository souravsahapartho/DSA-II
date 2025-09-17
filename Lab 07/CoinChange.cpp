#include<iostream>
using namespace std;

void DPCoinChange(int coin[], int d, int M){
    //return the minimum number of coins to change M amount
    int P[M+1];
    int b[M+1];
    P[0] = 0;
    b[0] = 0;
    for(int m = 1; m <= M ; m++){
        P[m] = INT_MAX;
        for(int i = 0; i <d ; i++){
            if( m >= coin[i] ){
                if( 1 + P[ m- coin[i] ] < P[m] ){
                    P[m] = 1 + P[ m- coin[i] ];
                    b[m] = coin[i];
                }
            }
        }
    }
    cout<<"Min number of coins:"<<P[M]<<endl;
    int i = M;
    cout<<"chosen coins:";
    while(i>0){
        cout<<b[i]<<", ";
        i = i - b[i];
    }
}

int main(){
    int coin[] = {1, 2, 6};
    int d = 3; //no of denominations
    int M = 11; // changed amount
    DPCoinChange(coin, d, M);
}
