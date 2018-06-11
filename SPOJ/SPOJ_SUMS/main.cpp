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
typedef vector<ii> vii;
typedef long long ll;
vi a, d, dist, adj;
int n, m;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int x;
    a.push_back(-1);
    d = dist = vi(65536, MODUL);
	scanf("%d", &n);
	FOR(i, 1, n)
	{
	    scanf("%d", &x);
	    a.push_back(x);
	}
	scanf("%d", &m);
}

//Dijkstra's Algorithm
void Dijkstra()
{
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push(ii(0, 0));
    dist[0] = 0;
    int u, v, t, du, dv;

    while(!pq.empty())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();
        if(du > dist[u]) continue;

        for(int v: adj)
        {
            dv = d[v];
            t = (u + v) % a[1];
            if(dist[t] > dv + du)
            {
                dist[t] = du + dv;
                pq.push(ii(dist[t], t));
            }
        }
    }
}

//Process
void Init()
{
    FOR(i, 2, n) d[a[i] % a[1]] = min(a[i], d[a[i] % a[1]]);
    FORl(i, 0, a[1]) if(d[i] < MODUL) adj.push_back(i);
}
void Solve()
{
    Init();
    Dijkstra();
    FOR(i, 1, m)
    {
        int x;
        scanf("%d", &x);
        if(x >= dist[x%a[1]]) printf("TAK\n");
        else printf("NIE\n");
    }
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
