#include <bits/stdc++.h>
using namespace std;

int kount = 0;

typedef struct{
    int maxi;
    int mini;
} dataset;

dataset findmaxmin(int* num, int lo, int hi){
    dataset ret;
    if(lo == hi){
        ret.maxi = ret.mini = num[lo];
        return ret;
    }

    if(lo+1 == hi){
        if(num[lo] > num[hi]){ret.maxi = num[lo]; ret.mini = num[hi];}
        else {ret.maxi = num[hi]; ret.mini = num[lo];}
        kount += 1;
        return ret;
    }

    int mid = lo + (hi - lo) / 2;

    dataset ret1;
    dataset ret2;

    ret1 = findmaxmin(num, lo, mid);
    ret2 = findmaxmin(num, mid+1, hi);

    ret.maxi = max(ret1.maxi, ret2.maxi);
    ret.mini = min(ret1.mini, ret2.mini);

    kount += 2;

    return ret;
}

int main(){
    int n;
    cout << "How many numbers do you want to take?: ";
    cin >> n;

    freopen("G:\Random Numbers.txt", "r", stdin);
    freopen("G:\Output for two leaf approach.txt", "w", stdout);

    int num[n+2];

    for(int i = 0; i < n; i++)
        scanf("%d", num+i);

    dataset ans = findmaxmin(num, 0, n-1);

    cout << "Maximum element: " << ans.maxi << endl;
    cout << "Minimum element: " << ans.mini << endl;

    cout << "Number of comparison for " << n
        << " data is: " << kount << endl;

}

