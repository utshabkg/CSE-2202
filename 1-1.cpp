#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "How many numbers to generate?: ";
    cin >> n;

    freopen("F:\Input.txt", "w", stdout);

    srand(time(0));
    for(int i = 0; i < n; i++)
    {
        int temp = (rand() % 10001 * 10000 + (rand() % 100));
        if (temp & 1) temp *= -1;
        cout << temp << endl;
    }
}
