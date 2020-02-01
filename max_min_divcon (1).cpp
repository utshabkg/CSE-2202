#include<bits/stdc++.h>
using namespace std;
int N=10000;
int arr[10000+5];
int maxi(int l,int r)
{
    if(l==r)
        return arr[l];
    int mid=(l+r)/2;
    int mx1=maxi(l,mid);
    int mx2=maxi(mid+1,r);
    if(mx1>mx2)
        return mx1;
    else
        return mx2;
}
int mini(int l,int r)
{
    if(l==r)
        return arr[l];
    int mid=(l+r)/2;
    int mn1=mini(l,mid);
    int mn2=mini(mid+1,r);
    if(mn1<mn2)
        return mn1;
    else
        return mn2;
}

int main()
{
    clock_t s=clock();
    ifstream myfile("lab2.txt");
    int i;
    for(i=0;i<N;i++)
        myfile>>arr[i];
    cout<<" Minimum Number : "<<mini(0,N-1)<<endl;
    cout<<" Maximum Number : "<<maxi(0,N-1)<<endl;
    clock_t e=clock();
    cout<<" "<<(double)(e-s)/2.50e9<<endl;

    return 0;
}
