//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(10101)
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
int m, n, src, dst;
int nTest;

//=====================================
//Functions and procedures
//Initialization
void Init()
{
    FOR(i, 0, n+1)
    {
        adj[i].clear();
        d[i] = 2147483647;
    }
}

//Input
void Input()
{
    scanf("%d%d", &n, &m);
    Init();
    FOR(i, 1, m)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        adj[x].push_back(ii(w, y));
    }
    scanf("%d%d", &src, &dst);
}

//Dijkstra's Algorithm
void Dijkstra(int start)
{
    priority_queue<ii, vii, greater<ii>> pq;
    int u, v, du, uv;

    d[start] = 0;
    pq.push(ii(0, start));

    while(!pq.empty())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();
        if(du != d[u]) continue;

        FORl(i, 0, siz(adj[u]))
        {
            v = adj[u][i].second;
            uv = adj[u][i].first;
            if(d[v] > du + uv)
            {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}


//Process
void Multitest()
{
    Input();
    Dijkstra(src);
    if(d[dst] == 2147483647) printf("NO\n");
    else printf("%d\n", d[dst]);
}


//Output





//Main Procedure
int main()
{
    scanf("%d", &nTest);
    while(nTest--)
    {
        Multitest();
    }
    return 0;
}
