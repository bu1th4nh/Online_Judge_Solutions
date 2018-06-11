//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(5050)
#define MODUL (int)(1e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
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
typedef pair<ll, int> ii;
typedef vector<ii> vii;
vii adj[maxvalueinp];
ll cnt[maxvalueinp];
ll d[maxvalueinp];
int m, n;

//=====================================
//Functions and procedures
//Input
void Input()
{
    scanf("%d%d", &n, &m);
    FOR(i, 1, m)
    {
        int u, v, w, state;
        cin >> state >> u >> v >> w;
        adj[u].push_back(ii(w, v));
        if(state == 2) adj[v].push_back(ii(w, u));
    }
}


//Dijkstra's Algorithm
void Dijkstra()
{
    priority_queue<ii, vii, greater<ii>> pq;
    FOR(i, 1, n) d[i] = 10000000000;
    int u, v;
    ll uv, du;
    cnt[1] = 1;
    d[1] = 0;

    pq.push(ii(0, 1));

    while(pq.size())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();

        if(du != d[u]) continue;
        //if(u==n) break;

        FORl(i, 0, siz(adj[u]))
        {
            v = adj[u][i].second;
            uv = adj[u][i].first;
            if(d[v] == du + uv) cnt[v] += cnt[u];
            if(d[v] > du + uv)
            {
                d[v] = du + uv;
                cnt[v] = cnt[u];
                pq.push(ii(d[v], v));
            }
        }
    }

}


//Output
void Process()
{
    Dijkstra();
    cout << d[n] << ' ' << cnt[n];
}



//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
