#include<bits/stdc++.h>
using namespace std;
int main(){
int a[10];
int i;
int ifind;
cout<<"The array is: ";
for(ifind=0;ifind<10;ifind++){
    a[ifind]=rand()%101;
    cout<<a[ifind]<<ends;
}


int pivot=0;
int j=10;
int temp;

///element in the first position is pivot
///set a counter greater by 1 than the last position and compare the last element of the array with the pivot.. if pivot is larger, then do nothing and go to the next element
///if pivot is smaller, then decrease j by 1 and then swap with the current element
///finally, swap the current element with the first element
for(i=j-1;i>=0;i--){
    if(a[pivot]<a[i]){
        j--;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }

    if(i==0){
        temp=a[0];
        a[0]=a[j-1];
        a[j-1]=temp;
    }
}
printf("\n\nThe correct position of the pivot is %d\n",j-1);

return 0;
}
