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
#define task "test"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define MODUL (int)(1e9+7)
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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
int n, m, e, t, res, nTest;
vvii adj;
vi d;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v, c;

    scanf("%d\n%d\n%d\n%d\n", &n, &e, &t, &m);

    adj = vvii(n+1);
    d = vi(n+1, MODUL);

    FOR(i, 1, m)
    {
        scanf("%d%d%d", &u, &v, &c);
        adj[v].pb(ii(c, u));
    }
}

//Dijkstra's Algorithm
void Dijkstra()
{
    priority_queue<ii, vii, greater<ii>> pq;
    int u, v, du, uv;

    pq.push(ii(0, e));
    d[e] = 0;

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
            if(d[v] > du + uv)
            {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

//Process
void Solve()
{
    res = 0;
    Dijkstra();
    FOR(i, 1, n) if(d[i] <= t) ++res;
    printf("%d\n", res);
}

//Output
void Multitest()
{
    scanf("%d", &nTest);
    while(nTest--)
    {
        Enter();
        Solve();
        if(nTest) puts("");
    }
}

//Main Procedure
int main()
{
    //FILEOP();

    Multitest();
    return 0;
}
