#include <bits/stdc++.h>
using namespace std;

struct edges
{
    int u, v, weight;
    edges(int u1, int v1, int weight1)
    {
        u = u1;
        v = v1;
        weight = weight1;
    }
    bool operator< (const edges &e2) const
    {
        return weight < e2.weight;
    }
};

int nodes;
int edgess;
vector<edges> e;
int parent[100000];

vector<edges> taken;

void edges_connect(int u, int v, int w)
{
    e.push_back(edges(u, v, w));
}

int representative(int nd)
{
    if(parent[nd] == nd) return nd;
    return parent[nd] = representative(parent[nd]);
}

void min_spanning_tree()
{
    sort(e.begin(), e.end());

    int length = e.size();

    for(int i = 0; i < nodes; i++)
    {
        parent[i] = i;
    }

    int cnt = 0;
    int ans = 0;

    for(int i = 0; i < length; i++)
    {
        int uu = representative(e[i].u);
        int vv = representative(e[i].v);
        if(uu != vv)
        {
            parent[uu] = vv;
            ans += e[i].weight;
            cnt++;
            taken.push_back(e[i]);

            printf("\n\n");
            int given_length = taken.size();
            set <int> givens_Parent;

            for(int i = 0; i < given_length; i++)
            {
                printf("%d -> %d\n", taken[i].u, taken[i].v);
                givens_Parent.insert(representative(taken[i].u));
                givens_Parent.insert(representative(taken[i].v));

            }

            cout << "Latest Representatives: ";
            set <int>::iterator it;
            for( it = givens_Parent.begin(); it != givens_Parent.end(); it++ )
            {
                cout << *it << " ";
            }
            cout << endl;
            printf("Current Number of Tree: %d\n", givens_Parent.size());
            givens_Parent.clear();

            if(cnt == edgess-1) break;
        }
    }

    printf("\nMinimum weight = %d\n\n", ans);

    printf("Minimum Spanning Tree:\n");

    for(int i = 1; i < nodes; i++)
    {
        printf("Parent of %d-th Node: %d\n", i, parent[i]);
    }
}

int main()
{
    edges_connect(1, 2, 5);
    edges_connect(1, 3, 4);
    edges_connect(2, 4, 1);
    edges_connect(3, 5, 3);
    edges_connect(4, 5, 5);
    edges_connect(2, 5, 5);

    edgess = 6;
    nodes = 5; ///Number of Nodes

    min_spanning_tree();
}

