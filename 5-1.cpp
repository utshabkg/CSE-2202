#include <bits/stdc++.h>
using namespace std;

int adjacent[6][6];
int visit[6];;

void makematrix()
{
    adjacent[0][1] = 1;
    adjacent[1][2] = 1;
    adjacent[2][3] = 1;
    adjacent[2][4] = 1;
    adjacent[2][5] = 1;
    adjacent[3][0] = 1;
    adjacent[5][0] = 1;
}

void printmatrix()
{
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
        {
            if(j==5)
                cout<<adjacent[i][j]<<endl;
            else
                cout<<adjacent[i][j]<<ends;
        }
}

void checkfrom(int source)
{
    stack <int> s;
    s.push(source);
    visit[source] = 1;
    while(!s.empty())
    {
        int u = s.top();
        s.pop();

        for(int i = 0; i < 6; i++)
        {
            if(adjacent[u][i] == 1)
            {
                cout << u << " is connected to " << i << "\n";
                visit[i]++;
                if(visit[i] <= 1)
                    s.push(i);
            }
        }
    }
    cout << endl;
}

int main()
{
    makematrix();
    printmatrix();

    int n;

    cout << "Enter source: ";
    cin >> n;

    checkfrom(n);

    cout << "Visit status:\n";
    for(int i = 0; i < 6; i++)
        printf(i == 5 ? "%d\n" : "%d ", visit[i]);

    if(visit[n] > 1)
        printf("Possible to get back\n");
    else
        printf("Not Possible to get back\n");

}

