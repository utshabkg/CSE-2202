#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "How many numbers do you want to take?: ";
    cin >> n;

    freopen("G:\Random Numbers.txt", "r", stdin);
    freopen("G:\Output for naive approach.txt", "w", stdout);

    int num[n+2];

    for(int i = 0; i < n; i++)
        scanf("%d", num+i);

    int maxi = num[0];
    int mini = num[0];
    int kount = 0;

    for(int i = 1; i < n; i++){
        if(maxi > num[i]) maxi = num[i];
        if(mini < num[i]) mini = num[i];
        kount += 2;
    }

    cout << "Maximum element: " << maxi << endl;
    cout << "Minimum element: " << mini << endl;

    cout << "Number of comparison for " << n
        << " data is: " << kount << endl;

}
