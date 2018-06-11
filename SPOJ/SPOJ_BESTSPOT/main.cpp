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
#define maxvalueinp (int)(512)
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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
vii adj[maxvalueinp];
int best[maxvalueinp];
int d[maxvalueinp];
int f, n, m, res;
vi fav;

//=====================================
//Functions and procedure
//Input
void Input()
{
    scanf("%d%d%d", &n, &f, &m);
    fav.push_back(0);
    FOR(i, 1, f)
    {
        int x;
        scanf("%d", &x);
        fav.push_back(x);
    }
    FOR(i, 1, m)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(ii(w, v));
        adj[v].push_back(ii(w, u));
    }
}


//Dijkstra's Algorithm
void Dijkstra(int start)
{
    priority_queue<ii, vii, greater<ii>> pq;
    int u, v, du, uv;

    //FOR(i, 0, n+2) d[i] = 1000000057;
    MEMS(d, 1000000057);
    d[start] = 0;
    pq.push(ii(0, start));

    while(!pq.empty())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();

        if(du != d[u]) continue;

        FORl(i, 0, (int)(adj[u].size()))
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

    FOR(i, 1, f) best[start] += d[fav[i]];

}

//Process
void Process()
{
    MEMS(best, 0);
    res = n;
    FOR(i, 1, n)
    {
        Dijkstra(i);
    }
    FORb(i, n-1, 1)
    {
        if(best[i] <= best[res]) res = i;
    }
    printf("%d", res);
}

//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
