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
#define maxinp (int)(1024)
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
typedef pair<double, ii> dii;     /// dii: <cost, <number of accelerator used , vertex>>
typedef vector<dii> vdii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
bool Free[maxinp][16];
double d[maxinp][16];
vii adj[maxinp];
int m, n, k;
double res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d%d%d", &n, &m, &k);
	MEMS(Free, true);
	int u, v, c;
	FOR(i, 1, m)
	{
	    scanf("%d%d%d", &u, &v, &c);
	    adj[u].pb(ii(c, v));
	    adj[v].pb(ii(c, u));
	}
}

//Dijkstra's Algorithm
void Dijkstra()
{
    priority_queue<dii, vdii, greater<dii>> pq;    /// dii: <cost, <number of accelerator used , vertex>>
    double du, uv;
    int u, v, nac;

    FOR(i, 2, n)
    {
        FOR(j, 0, k)
        {
            d[i][j] = 1e9;
        }
    }
    FOR(i, 0, k)
    {
        pq.push(dii(d[1][i], ii(i, 1)));
    }


    while(true)
    {
        du = pq.top().first;
        nac = pq.top().se.fi;
        u = pq.top().se.se;
        pq.pop();
        Free[u][nac] = false;

        if(d[u][nac] != du) continue;
        if(u == n && nac == k) break;

        for(ii lnk: adj[u])
        {
            int mul = 1;
            uv = lnk.first;
            v = lnk.second;
            FOR(i, nac, k)
            {
                if(Free[v][i] && d[v][i] > d[u][nac] + (uv / mul))
                {
                    d[v][i] = d[u][nac] + (uv / mul);
                    pq.push(dii(d[v][i], ii(i, v)));
                }
                mul *= 2;
            }
        }
    }

}

//Process
void Solve()
{
    Dijkstra();
    printf("%.2lf", d[n][k]);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
