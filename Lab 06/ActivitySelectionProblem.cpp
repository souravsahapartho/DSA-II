#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Activity
{
public:
    int start_time, finish_time;
    Activity(int s, int f): start_time(s), finish_time(f) {}
    void display()
    {
        cout<<"Start time: "<<start_time<<" Finish time: "<<finish_time<<endl;
    }
};

bool Compare(Activity a1, Activity a2)
{
    return a1.finish_time<a2.finish_time;
}

void ActivitySelection(vector<Activity> activityList)
{
//find the maximum number of activities
    sort(activityList.begin(), activityList.end(), Compare);
    for(Activity a: activityList) a.display();

    vector<Activity> selected; //to store the selected activities
    int l=0;// last chosen activity
    selected.push_back(activityList[0]);
    int count=1;
    for(int m=1; m<activityList.size(); m++)
    {
        if(activityList[m].start_time >= activityList[l].finish_time)
        {
            selected.push_back(activityList[m]);
            l=m;
            count++;
        }
    }
    cout<<"maximum no of activities:"<<count<<endl;
    cout<<"\nSelected activities: "<<endl;
    for(Activity a: selected) a.display();
}


int main()
{
    vector<Activity> activities= {Activity(8,12),Activity(9,10),Activity(14,16),Activity(11,13),Activity(9,11),Activity(10,12)};

    ActivitySelection(activities);

}
