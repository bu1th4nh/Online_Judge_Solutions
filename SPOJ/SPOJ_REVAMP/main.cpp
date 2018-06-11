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
#define maxinp (int)(16384)
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
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> lii;                          ///<Distance, <Numbers of amp used, Source vertex>>
typedef vector<lii> vlii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll d[maxinp][24];
vii adj[maxinp];
int n, m, k;
ll res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	int u, v, c;
	scanf("%d%d%d", &n, &m, &k);
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
    priority_queue<lii, vlii, greater<lii>> pq;    ///<Distance, <Numbers of amp used, Source vertex>>
    ll du, uv;
    int u, v, amp;

    FOR(i, 1, n)
    {
        FOR(j, 0, k) d[i][j] = 1000000007;
    }

    FOR(i, 0, k) d[1][i] = 0;

    pq.push(lii(0, ii(0, 1)));

    while(true)
    {
        u   = pq.top().se.se;
        amp = pq.top().se.fi;
        du  = pq.top().first;
        pq.pop();

        if(u == n) break;
        if(du != d[u][amp]) continue;

        FORl(i, 0, adj[u].size())
        {
            ii x = adj[u][i];
            uv = x.first;
            v = x.second;
            if(amp < k)
            {
                if(d[v][amp + 1] > d[u][amp])
                {
                    d[v][amp + 1] = d[u][amp];
                    pq.push(lii(d[v][amp + 1], ii(amp + 1, v)));
                }
            }
            if(d[v][amp] > du + uv)
            {
                d[v][amp] = du + uv;
                pq.push(lii(d[v][amp], ii(amp, v)));
            }
        }
    }
}


//Process
void Solve()
{
    Dijkstra();
    res = d[n][0];
    FOR(i, 1, k) res = min(res, d[n][i]);
    printf("%lld", res);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
