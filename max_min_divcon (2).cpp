#include<bits/stdc++.h>
using namespace std;
int number=10000;
int arr[10000+5];
int cnt=0;
int maxima(int lo,int hi)
{
    if(lo==hi)
    {
        return arr[lo];
        cnt++;
    }
    int mid=lo+(hi-lo)/2;
    int max1=maxima(lo,mid);
    int max2=maxima(mid+1,hi);

    if(lo+1 == hi)
    {
        if(arr[lo] > arr[hi])
        {
            cnt++;
            return max1;
        }
        else
        {
            cnt++;
            return max2;
        }

    }

    if(max1>max2)
    {
        return max1;
        cnt++;
    }
    else
    {
        cnt++;
        return max2;
    }
}
int minima(int lo,int hi)
{
    if(lo==hi)
        return arr[lo];
    int mid=(lo+hi)/2;
    int min1=minima(lo,mid);
    int min2=minima(mid+1,hi);
    if(lo+1 == hi)
    {
        if(arr[lo] > arr[hi])
        {
            cnt++;
            return min1;
        }
        else
        {
            cnt++;
            return min2;
        }

    }
    if(min1<min2)
        return min1;
    else
        return min2;
}

int main()
{
    clock_t s=clock();
    freopen("F:\Input.txt", "r", stdin);
    int i;
    for(i=0; i<number; i++)
        cin>>arr[i];
    cout<<" Minimum Number : "<<minima(0,number-1)<<endl;
    cout<<" Maximum Number : "<<maxima(0,number-1)<<endl;
    cout<<cnt<<" Comparisons"<<endl;
    clock_t e=clock();
    cout<<" "<<(double)(e-s)/2.50e9<<endl;

    return 0;
}
