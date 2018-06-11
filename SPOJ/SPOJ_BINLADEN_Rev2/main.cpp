/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
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
#include <tuple>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define sp ' '
#define el '\n'
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
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


const long long inf = 1234567890987699;
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int m, n;
vvii adj;
vi d;


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileDebug()
{
    FILEOP_DEBUG();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
	scanf("%d%d", &m, &n);
	adj = vvii(m*n+2);
	d = vi(m*n+2, inf);
	ll x;

    FOR(i, 1, n)
    {
        scanf("%lld", &x);
        adj[0].pb(ii(x, i));
        adj[i].pb(ii(x, 0));
    }
    FOR(i, 2, n)
    {
        scanf("%lld", &x);
        adj[i-1].pb(ii(x, i));
        adj[i].pb(ii(x, i-1));
    }


    FOR(i, 0, m-2)
    {
        FOR(j, 1, n)
        {
            scanf("%lld", &x);
            adj[i*n+j].pb(ii(x, (i+1)*n+j));
            adj[(i+1)*n+j].pb(ii(x, i*n+j));
        }
        FOR(j, 2, n)
        {
            scanf("%lld", &x);
            adj[(i+1)*n+j].pb(ii(x, (i+1)*n+j-1));
            adj[(i+1)*n+j-1].pb(ii(x, (i+1)*n+j));
        }
    }
}

//Check
void Dijkstra(int start)
{
    ll du, uv;
    int u, v;

    priority_queue<ii, vii, greater<ii>> pq;
    pq.push(ii(0LL, start));
    d[start] = 0LL;

    while(!pq.empty())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();

        if(du != d[u]) continue;

        for(ii x: adj[u])
        {
            v = x.second;
            uv = x.first;

            if(du + uv < d[v]) pq.push(ii((d[v] = du + uv), v));
        }
    }


}



//Process
void Solve()
{
    Dijkstra(0);
    printf("%lld\n", d[m*n]);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
