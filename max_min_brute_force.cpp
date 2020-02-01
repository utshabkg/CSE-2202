#include<bits/stdc++.h>
using namespace std;
int main()
{
    int number;
    cout<<"How many Data do you want to collect?"<<endl;
    cin>>number;
    int arr[number+5];
    freopen("F:\Input.txt", "r", stdin);
    int i;
    int cnt=0;

    clock_t s=clock();
    for(i=0; i<number; i++)
        cin>>arr[i];
    int minima=arr[0];
    int maxima=arr[0];

    for(i=1; i<number; i++)
    {
        if(arr[i]<minima)
        {
            minima=arr[i];
            cnt++;
        }
        if(arr[i]>maxima)
            maxima=arr[i];
    }
    clock_t e=clock();

    cout<<" minima Number : "<<minima<<endl;
    cout<<" maxima Number : "<<maxima<<endl;
    cout<<cnt<<" Comparisons"<<endl;
    cout<<" "<<(double)(e-s)/2.50e9<<endl;

    return 0;
}
