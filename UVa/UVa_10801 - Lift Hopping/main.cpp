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
#define task "10801"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define MODUL (int)(1234567890)
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
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
vi etime, dist;
int n, k, res;
vii start;
vvii adj;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    char str[1024], *num;
    int vtx, prev;

    res = MODUL;
    dist = vi(100*n, MODUL);
    adj = vvii(100*n);
    etime = vi(n, 0);
    start.clear();

    --n;

    FOR(i, 0, n) scanf("%d", &etime[i]);

    FOR(i, 0, 99)
    {
        FOR(j, 0, n)
        {
            FOR(k, j, n) if(j != k)
            {
                adj[j*100 + i].pb(ii(60, k*100 + i));
                adj[k*100 + i].pb(ii(60, j*100 + i));
            }
        }
    }

    scanf("\n");

    FOR(i, 0, n)
    {
        gets(str); num = strtok(str, " ");

        sscanf(num, "%d", &prev);
        if(prev == 0)
        {
            start.push_back(ii(0, 100*i));
            dist[i*100] = 0;
        }

        while((num = strtok(NULL, " ")) != NULL)
        {
            sscanf(num, "%d", &vtx);
            adj[i*100 + vtx].pb(ii( /*||*/ (abs(prev - vtx) * etime[i]) /*||*/ , /*||*/ (i*100 + prev) /*||*/ ));
            adj[i*100 + prev].pb(ii( /*||*/ (abs(prev - vtx) * etime[i]) /*||*/ , /*||*/ (i*100 + vtx) /*||*/ ));
            prev = vtx;
        }
    }

}

///Dijkstra's Algorithm
void Dijkstra()
{
    int u, v, du, uv;
    priority_queue<ii, vii, greater<ii>> pq(whole(start));

    while(!pq.empty())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();

        if(dist[u] != du) continue;

        FORl(i, 0, adj[u].size())
        {
            v = adj[u][i].second;
            uv = adj[u][i].first;

            if(dist[v] > du + uv)
            {
                dist[v] = du + uv;
                pq.push(ii(dist[v], v));
            }
        }
    }

    FOR(i, 0, n) res = min(res, dist[100*i + k]);
    if(res >= MODUL) printf("IMPOSSIBLE\n");
    else printf("%d\n", res);
}


//Multi-testdata processing
void Multitest()
{
    while(scanf("%d%d", &n, &k) == 2)
    {
        Enter();
        Dijkstra();
    }
}


//Main Procedure
int main()
{
    //FILEOP();

    Multitest();
    return 0;
}
