#include<iostream>
using namespace std;

#define up 1
#define diagonal 2

void Knapsack01(string name[], int w[], int v[], int n, int W){
    int P[n+1][W+1];//for storing profit
    int b[n+1][W+1];//for backtracking
    //initialize 1st row
    for(int i = 0; i <= W; i++) P[0][i] = 0;
    //initialize 1st column
    for(int i = 0; i <= n; i++) P[i][0] = 0;

    for(int i = 1; i <= n; i++){ // for each row --> indicates items
        for(int j = 1; j <= W; j++){ // for each column --> current capacity
            if( j < w[i] ){
                //we can't take the item at all
                P[i][j] = P[i-1][j];
                b[i][j] = up;
            }else{
                //we take the item but choose that will
                //give us maximum profit
                if( v[i]+P[i-1][ j-w[i] ] > P[i-1][j] ){
                    //taking the item maximizes the profit
                    P[i][j] = v[i]+P[i-1][ j-w[i] ];
                    b[i][j] = diagonal;
                }else{
                    //skipping the item maximizes the profit
                    P[i][j] = P[i-1][j];
                    b[i][j] = up;
                }
            }
        }
    }
    cout << "Maximum profit: " << P[n][W] << endl;
    cout << "Selected items:" << endl;
    //backtracking
    int i = n, j = W;
    while(i>0 && j>0){
        if(b[i][j] == diagonal ){
            //we have taken the item
            cout<<"name:"<<name[i]<<" w:"<<w[i]<<" v:"<<v[i]<<endl;
            j = j - w[i];
        }
        i--;
    }

}

int main(){
    string name[] = {"", "Rice", "Sugar", "salt", "lentil"};
    int w[] = {0, 2, 1, 3, 2};
    int v[] = {0, 12, 10, 20, 15};
    int n = 4;//no of items
    int W = 5; //knapsack capacity
    Knapsack01(name, w, v, n, W);
}
