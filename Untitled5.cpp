#include <bits/stdc++.h>
using namespace std;

int main()
{
    int number;
    cout << "How many numbers to generate?: ";
    cin >> number;

    freopen("F:\r.txt", "w", stdout);

    srand(time(0));
    for(int i = 0; i < number; i++)
    {
        int temporary = (rand() % 10001 * 10000 + (rand() % 100));
        if (temporary & 1) temporary *= -1;
        cout << temporary << endl;
    }
}
