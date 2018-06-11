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
#define maxvalueinp (int)(1280)
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
int trace[maxvalueinp];
vii adj[maxvalueinp];
int res[maxvalueinp];
int d[maxvalueinp];
int n, m, k, resd;
int state;

//=====================================
//Functions and procedures
//Initialization
void Init()
{
}

//Input
void Input()
{
    scanf("%d%d%d", &n, &m, &k);
    FOR(i, 1, m)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        adj[x].push_back(ii(w, y));
        adj[y].push_back(ii(w, x));
    }
    //FOR(i, 1, n) adj[i].push_back(ii(0, 0));
}

//Dijkstra Algorithm
void Dijkstra(int start)
{
    priority_queue<ii, vii, greater<ii>> pq;
    int u, v, du, uv;

    FOR(i, 0, n+1)
    {
        d[i] = 1000000000;
        trace[i] = -1;
        res[i] = 0;
    }

    d[start] = 0;
    pq.push(ii(0, start));

    while(!pq.empty())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();

        if(du != d[u]) continue;

        FOR(i, 0, adj[u].size()-1)
        {
            v = adj[u][i].second;
            uv = adj[u][i].first;
            if(d[v] > du + uv)
            {
                trace[v] = u;
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

//Output
void Output()
{
    while(k--)
    {
        int st, fi;
        scanf("%d%d%d", &state, &st, &fi);
        Dijkstra(st);
        if(state == 0)
        {
            printf("%d\n", d[fi]);
        }
        else
        {
            if(trace[fi]!=-1)
            {
                while(fi!=-1)
                {
                    res[++res[0]] = fi;
                    fi = trace[fi];
                }
                printf("%d ", res[0]);
                FORb(i, res[0], 1) printf("%d ", res[i]);
                printf("\n");
            }
        }
    }
}


//Main Procedure
int main()
{
    Input();
    Output();
    return 0;
}
