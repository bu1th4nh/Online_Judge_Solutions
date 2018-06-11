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
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
int n, m, src, dst, nTest, nQuery, res;
vvii adj, revadj;

//=====================================
//Functions and procedures
//Enter
inline void Enter()
{
	int u, v, c;
	scanf("%d%d%d%d%d", &n, &m, &nQuery, &src, &dst);

	adj.resize(n+1); FOR(i, 0, n) adj[i].clear();
	revadj.resize(n+1); FOR(i, 0, n) revadj[i].clear();

	FOR(i, 1, m)
	{
	    scanf("%d%d%d", &u, &v, &c);
	    revadj[v].pb(ii(c, u));
	    adj[u].pb(ii(c, v));
	}
}

//Dijkstra's Algorithm
vi Dijkstra(int start, const vvii & adjl)
{
    vi d(adj.size(), 1000000007);
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

        for(ii x: adjl[u])
        {
            v = x.second;
            uv = x.first;
            if(d[v] > du + uv)
            {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }

    return d;

}

//Process
inline void Solve()
{
    int u, v, c;
    vi ds = Dijkstra(src, adj);
    vi dt = Dijkstra(dst, revadj);

    res = ds[dst];

    FOR(i, 1, nQuery)
    {
        scanf("%d%d%d", &u, &v, &c);
        if(ds[u] != 1000000007 && dt[v] != 1000000007)
        {
            res = min(res, ds[u] + c + dt[v]);
        }
        if(ds[v] != 1000000007 && dt[u] != 1000000007)
        {
            res = min(res, ds[v] + c + dt[u]);
        }
    }
    if(res >= 1000000007) res = -1;
    printf("%d\n", res);
}


//Output
void Multitest()
{
    Enter();
    Solve();
}


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
