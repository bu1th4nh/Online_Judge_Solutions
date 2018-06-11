/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}


//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
const int INF = 1234567890;
int n, m, src, sink, DTime;
vvi cap, flow, adj;
vi dist, Dfs;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v, x;

    scanf("%d%d%d%d", &n, &m, &src, &sink);

    DTime = 0;

    adj = vvi(n+1);
    Dfs = dist = vi(n+1, 0);
    cap = flow = vvi(n+1, vi(n+1, 0));

    FOR(i, 1, m)
    {
        scanf("%d%d%d", &u, &v, &x);
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += x;
    }
}

///Dinitz's Algorithm
bool BFS(int s, int t)
{
    queue<int> q;
    dist = vi(n+1, 0);

    dist[s] = 1;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        if(u == t) return true;
        for(int v: adj[u])
        {
            if(!dist[v] && flow[u][v] < cap[u][v])
            {
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    return false;
}

int DFS(int u, int Min)
{
    if(u == sink) return Min;
    if(Dfs[u] != DTime) Dfs[u] = DTime;
    else return 0;

    for(int v: adj[u])
    {
        if(flow[u][v] < cap[u][v])
        {
            if(Dfs[v] != DTime && dist[v] == dist[u] + 1)
            {
                if(int x = DFS(v, min(Min, cap[u][v] - flow[u][v])))
                {
                    flow[u][v] += x;
                    flow[v][u] -= x;
                    return x;
                }
            }
        }
    }
    return 0;
}

int DINITZ()
{
    int MAXFLOW = 0;
    while(BFS(src, sink))
    {
        while(int x = (DTime++, DFS(src, INF)))
        {
            MAXFLOW += x;
        }
    }
    return MAXFLOW;
}

//Process
void Solve()
{
    cout << DINITZ() << endl;
}



//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
