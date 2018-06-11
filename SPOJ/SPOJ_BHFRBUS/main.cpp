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
#define maxinp (int)(131072)
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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ii> lii;
typedef vector<int> vi;
typedef vector<lii> vlii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
int n, m, kk, s, t;
ll dist[maxinp][10];
vii adj[maxinp];
int res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v, c;
	scanf("%d%d%d%d%d", &n, &m, &kk, &s, &t);
	FOR(i, 1, m)
	{
	    scanf("%d%d%d", &u, &v, &c);
	    adj[u].pb(ii(c, v));
	    adj[v].pb(ii(c, u));
	}
}

//Dijkstra's Algorithm
void Dijkstra(int start)
{
    priority_queue<lii, vlii, greater<lii>> pq;
    int u, v, amp;
    ll du, uv;

    FOR(i, 1, n)
    {
        FOR(j, 0, kk)
        {
            dist[i][j] = 1234567890;
        }
    }

    pq.push(lii(0, ii(0, start)));
    FOR(i, 0, kk) dist[start][i] = 0;

    while(true)
    {
        u   = pq.top().se.se;
        amp = pq.top().se.fi;
        du  = pq.top().first;
        pq.pop();

        if(u == t) break;
        if(du != dist[u][amp]) continue;

        for(ii nxt: adj[u])
        {
            uv = nxt.first;
            v = nxt.second;
            if(amp < kk)
            {
                if(dist[v][amp + 1] > dist[u][amp])
                {
                    dist[v][amp + 1] = dist[u][amp];
                    pq.push(lii(dist[v][amp + 1], ii(amp + 1, v)));
                }
            }
            if(dist[v][amp] > du + uv)
            {
                dist[v][amp] = du + uv;
                pq.push(lii(dist[v][amp], ii(amp, v)));
            }
        }
    }

}

//Process
void Solve()
{
    Dijkstra(s);


    /*
    ll res = 1234567890;
    FOR(i, 0, kk) res = min(res, dist[t][i]);
    */


    printf("%lld", dist[t][kk]);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
