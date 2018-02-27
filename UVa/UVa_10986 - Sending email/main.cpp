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
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}

//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
int nTest, m, n, s, t, Case;
vvii adj;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    adj = vvii(n+1);
    FOR(i, 1, m)
    {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u].pb(ii(c, v));
        adj[v].pb(ii(c, u));
    }
}

//Process
void Solve()
{
    priority_queue<ii, vii, greater<ii>> pq;
    int u, v, du, uv;

    vector<ll> d(n+1, 12345678987654321);
    d[s] = 0;

    pq.push(ii(0, s));
    while(!pq.empty())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();

        if(du != d[u]) continue;

        FORl(i, 0, adj[u].size())
        {
            ii k = adj[u][i];
            v = k.second;
            uv = k.first;
            if(d[v] > du + uv)
            {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }

    if(d[t] == 12345678987654321) printf("Case #%d: unreachable\n", Case);
    else printf("Case #%d: %lld\n", Case, d[t]);
}

//Output
void Multi()
{
    Case = 0;
    scanf("%d", &nTest);
    while(nTest--)
    {
        Case++;
        Enter();
        Solve();
    }
}

//Main Procedure
int main()
{
    Multi();
    return 0;
}
