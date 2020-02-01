#include <bits/stdc++.h>
using namespace std;

int main()
{

    freopen("F:\Input.txt", "r", stdin);
    freopen("F:\Output.txt", "w", stdout);

    long long ara[50000];
    long long index = 0, temp;

    while(scanf("%d", &temp) == 1)
    {
        ara[index++] = temp;
    }

    clock_t start = clock();
    for(long long i = 0; i < index; i++)
    {
        for(long long j = 0; j < index; j++)
        {
            for(long long k = 0; k < index; k++)
            {
                if(ara[i] + ara[j] + ara[k] == 0)
                    cout << ara[i] << " " << ara[j] << " " << ara[k]
                         << " Sum = " << ara[i] + ara[j] + ara[k] << endl;

            }
        }
    }
    clock_t stop = clock();

    double duration = (double)(stop - start);
    duration /= CLOCKS_PER_SEC;

    printf( "Total time taken : %.4lf seconds.\n", duration);
}

