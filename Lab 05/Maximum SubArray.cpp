#include<iostream>
#include<vector>
using namespace std;
struct Subarray
{
    int sum, low, high;
};

Subarray MaxCrossingSum(vector<int> a, int low, int mid, int high)
{
    int sum=0;
    int left_sum=INT_MIN;
    int l_idx=-1;
    for(int i=mid; i>=low; i--)
    {
        sum+=a[i];
        if(sum>left_sum)
        {
            left_sum=sum;
            l_idx=i;
        }
    }
    sum=0;
    int right_sum=INT_MIN;
    int r_idx=-1;
    for(int j=mid+1; j<=high; j++)
    {
        sum+=a[j];
        if(sum>right_sum)
        {
            right_sum=sum;
            r_idx=j;
        }
    }

    Subarray cross;
    cross.sum=left_sum+right_sum;
    cross.low=l_idx;
    cross.high=r_idx;
    return cross;
}

Subarray FindMaximumSubarray(vector<int> a, int low, int high)
{
    //returns the maximum subarray
    if(low==high)
    {
        Subarray m;
        m.low=low;
        m.high=high;
        m.sum=a[low];
        return m;
    }

    int mid=(low+high)/2;
    //conquer
    Subarray left=FindMaximumSubarray(a,low,mid);
    Subarray right=FindMaximumSubarray(a,mid+1,high);
    //combine
    Subarray cross=MaxCrossingSum(a,low,mid,high);
    if(left.sum>=right.sum && left.sum>=cross.sum)
    {
        return left;
    }
    else if(right.sum>=left.sum && right.sum>=cross.sum)
    {
        return right;
    }
    else
    {
        return cross;
    }


}

int main()
{
    vector<int> arr= {-2,5,-1,2,3,-7,5};
    int n=arr.size();
    Subarray sub= FindMaximumSubarray(arr, 0, n-1);
    int sum=sub.sum;
    int low=sub.low;
    int high=sub.high;

    cout<<"Maximum subarray sum: "<<sum<<endl;
    cout<<"Maximum subarray: ";
    for(int i=low; i<=high; i++)
    {
        cout<<arr[i]<<", ";
    }

}

