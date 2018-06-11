//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
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
#define MODUL (int)(1e9+57)
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
struct edge
{
    int v, l, c;
    edge(int v, int l, int c): v(v), l(l), c(c) {}
    bool operator < (const edge &a) const
    {
        return l > a.l;
    }
};
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<edge> ve;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<ve> vve;
typedef vector<vii> vvii;
typedef long long ll;
int n, k, m, tc;
vve adj;
vvi d;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v, c, l;
    scanf("%d%d%d", &k, &n, &m);

    adj = vve(n);
    d = vvi(128, vi(4096, 0xfff));

    FOR(i, 1, m)
    {
        scanf("%d%d%d%d", &u, &v, &l, &c);
        adj[--u].pb(edge(--v, l, c));
    }
}

//Dijkstra's Algorithm
void Dijkstra()
{
    priority_queue<edge> q; q.push(edge(0, 0, k));
    while(!q.empty())
    {
        int u = q.top().v, du = q.top().l, cu = q.top().c; q.pop();
        if(du > d[u][cu]) continue;
        if(u == n-1)
        {
            printf("%d\n", du);
            return;
        }
        for(edge i: adj[u])
        {
            int v = i.v, uv = i.l, c = i.c;
            if(cu >= c && d[v][cu - c] > du + uv)
            {
                q.push(edge(v, d[v][cu - c] = du + uv, cu - c));
            }
        }
    }
    printf("-1\n");
}


//Output
void Multitest()
{
    scanf("%d", &tc);
    while(tc--)
    {
        Enter();
        Dijkstra();
    }
}

//Main Procedure
int main()
{
    Multitest();
    return 0;
}
