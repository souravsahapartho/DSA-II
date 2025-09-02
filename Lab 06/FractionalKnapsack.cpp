#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Item
{
public:
    string name;
    double weight, value, unit_value;
    Item(string n, double w, double v): name(n), weight(w), value(v), unit_value(v/w) {}

    void display()
    {
        cout<<"name: "<<name<<", w: "<<weight<<", v:"<<value<<", Unit Value:"<<unit_value<<endl;
    }
};

bool Compare(Item i1, Item i2)
{
    return i1.unit_value > i2.unit_value;
}


void FractionalKnapsack(vector<Item> itemList, int n, int W)
{
    //find the maximum profit
    sort(itemList.begin(), itemList.end(), Compare);
    for(Item i: itemList) i.display();
    int i=0;
    cout<<"\nSelected Item: "<<endl;
    double profit=0;
    while(W>0 && i<n)
    {
        if(itemList[i].weight<=W){
            //we can take entire item
            profit+=itemList[i].value;
            W=W-itemList[i].weight;
            itemList[i].display();
        }
        else{
            //we can't take the entire item
            double weight_taken=W;
            double p=weight_taken*itemList[i].unit_value;
            profit+=p;
            W=0;
            string name=itemList[i].name;
            double unit_value=itemList[i].unit_value;
            cout<<"Name: "<<name<<", W:"<<weight_taken<<", v:"<<p<<", Unit Value:"<<unit_value<<endl;
        }

        i++;
    }
    cout<<"\nMaximum Profit: "<<profit<<endl;
}
int main()
{
    vector<Item> items= {Item("Rice",5,300), Item("Saffron",2,8000), Item("Salt",10,200),Item("Sugar",4,400)};

    int n=items.size();//number of items
    int W=24; //knapsack capacity
    FractionalKnapsack(items,n,W);
}
