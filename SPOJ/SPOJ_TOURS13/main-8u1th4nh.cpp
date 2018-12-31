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
#define MODUL (int)(1234567887654321)
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
typedef pair<ll, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
int n, m, nTest;
vvll dist;
vvii adj;

//=====================================
//Functions and procedures
template<class T> inline void scan(T &ret)
{
    bool neg = 0;
    char c = 0;
    ret = T();

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        c = getchar();
        neg = 1;
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret = neg ? -ret : ret;
}
template<class T> void print(T x)
{
    if(x < 0)
    {
        putchar('-');
        x *= -1;
    }

    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

//Enter
void Enter()
{
    int u, v, c;

    scan(n);
    scan(m);

	dist = vvll(n+1, vll(n+1, MODUL));
	adj = vvii(n+1);

	FOR(i, 1, m)
	{
	    scan(u);
	    scan(v);
	    scan(c);
	    adj[u].pb(ii(c, v));
	}
}

//Dijkstra's Algorithm
void Dijkstra(int st)
{
    priority_queue<ii, vii, greater<ii>> pq;
    int u, v, du, uv;

    dist[st][st] = 0;
    pq.push(ii(0, st));

    while(!pq.empty())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();

        if(du != dist[st][u]) continue;

        for(ii x: adj[u])
        {
            v = x.second;
            uv = x.first;

            if(du + uv < dist[st][v])
            {
                dist[st][v] = du + uv;
                pq.push(ii(dist[st][v], v));
            }
        }
    }

}


//Process
void Solve()
{
    FOR(i, 1, n) Dijkstra(i);

    FOR(i, 1, n)
    {
        ll res = -1;
        FOR(j, 1, n) if(j != i)
        {
            if(dist[i][j] != MODUL && dist[j][i] != MODUL)
            {
                if(res < 0) res = dist[i][j] + dist[j][i];
                else res = min(res, dist[i][j] + dist[j][i]);
            }
        }
        print(res);
        putchar('\n');
    }
}


//Output
void Multitest()
{
    scan(nTest);
    while(nTest--)
    {
        Enter();
        Solve();
    }
}

//Main Procedure
int main()
{
    Multitest();
    return 0;
}
