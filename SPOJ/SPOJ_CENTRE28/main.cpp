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
#define maxinp (int)(32768)
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
typedef long long ll;
int d[3][maxinp];
int F[3][maxinp];
vii adj[maxinp];
int n, m;
int res1;
vi res2;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d%d", &n, &m);
	int u, v, c;
	FOR(i, 1, m)
	{
	    scanf("%d%d%d", &u, &v, &c);
	    adj[u].pb(ii(c, v));
	    adj[v].pb(ii(c, u));
	}
}

//Dijkstra's Algorithm
void Dijkstra(int type, int start)
{
    priority_queue<ii, vii, greater<ii>> pq;
    int u, v, du, uv;

    FOR(i, 1, n)
    {
        d[type][i] = 1000000000;
        F[type][i] = 0;
    }
    d[type][start] = 0;
    F[type][start] = 1;
    pq.push(ii(0, start));

    while(!pq.empty())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();
        if(du != d[type][u]) continue;

        FORl(i, 0, adj[u].size())
        {
            ii x = adj[u][i];
            v = x.second;
            uv = x.first;
            if(d[type][v] == du + uv) F[type][v] += F[type][u];
            else if(d[type][v] > du + uv)
            {
                d[type][v] = du + uv;
                F[type][v] = F[type][u];
                pq.push(ii(d[type][v], v));
            }
        }
    }
}

//Process
void Solve()
{
    res1 = 0;
    Dijkstra(1, 1);
    Dijkstra(2, n);
    FOR(i, 2, n-1) if(d[1][i] + d[2][i] != d[1][n] || (F[1][i]*F[2][i] != F[1][n]))
    {
        res2.pb(i);
        ++res1;
    }
    printf("%d\n", res1);
    FORl(i, 0, res1) printf("%d\n", res2[i]);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
