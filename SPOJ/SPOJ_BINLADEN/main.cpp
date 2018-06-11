//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(65536)
#define MODUL (int)(1e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef pair<int, int> ii;
typedef vector<ii> vii;
vii adj[maxvalueinp];
int d[maxvalueinp];
int m, n;

//=====================================
//Functions and procedures
//Enter
void AddEdge(int u, int v, int w)
{
    adj[u].push_back(ii(w, v));
    adj[v].push_back(ii(w, u));
}
void Enter()
{
    int c;
    scanf("%d%d", &m, &n);
    FORl(i, 0, m)
    {
        FOR(j, 1, n)
        {
            scanf("%d", &c);
            if(i == 0) AddEdge(0, j, c);
            else AddEdge((i-1)*n + j, i*n+j, c);
        }
        FORl(j, 1, n)
        {
            scanf("%d", &c);
            AddEdge(i*n+j, i*n+j+1, c);
        }
    }
}

//Dijkstra's Algorithm
void Dijkstra()
{
    priority_queue<ii, vii, greater<ii>> pq;
    FOR(i, 0, m*n+5) d[i] = 100000000;
    pq.push(ii(0, 0));
    d[0] = 0;

    int u, v, du, uv;

    while(!pq.empty())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();

        if(du != d[u]) continue;

        FORl(i, 0, adj[u].size())
        {
            v = adj[u][i].second;
            uv = adj[u][i].first;
            if(du + uv < d[v])
            {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }

    printf("%d", d[m*n]);
}


//Main Procedure
int main()
{
    Enter();
    Dijkstra();
    return 0;
}
