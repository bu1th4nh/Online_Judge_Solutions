/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
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
typedef pair<ll, ll> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
const ll MAX = 1000000000;
int n, m, tc;
vvii adj;
vll d;
ll c;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v, w;
    scanf("%d%d%lld", &n, &m, &c);

    adj = vvii(n);
    d = vll(n, MAX);

    FOR(i, 1, m)
    {
        scanf("%d%d%d", &u, &v, &w);
        adj[--u].pb(ii(w, --v));
        adj[v].pb(ii(w, u));
    }
}

//Check
inline ll ceil(int a, int b)
{
    return b <= 0 ? MAX : a / b + (a % b != 0);
}

//Process
void Dijkstra()
{
    int u, v;
    ll du, uv;
    priority_queue<ii, vii, greater<ii>> pq;

    pq.push(ii(0, n-1));
    d[n-1] = 0;

    while(!pq.empty())
    {
        du = pq.top().first;
        u = pq.top().second;
        pq.pop();

        if(du > d[u]) continue;

        for(ii x: adj[u])
        {
            uv = x.first;
            v = x.second;

            if(du + uv <= c)
            {
                if(du + uv < d[v]) pq.push(ii( (d[v] = du + uv) , v ));
            }
            else
            {
                ll k = ceil(du - c + uv, c - uv - uv);
                if(k != MAX && (k+k+1)*uv + du < d[v]) pq.push(ii( (d[v] = (k+k+1)*uv + du) , v ));
            }
        }
    }

//    puts("========================");
//    for(ll i: d) cout << i << " ";
//    puts("========================");
//    FORl(i, 0, n)
//    {
//        cout << i << ": ";
//        for(ii x: adj[i]) cout << x.second << "-" << x.first << " ";
//        puts("");
//    }
//    puts("========================");

    printf("%lld\n", d.front());
}

//Output
void Multitest()
{
    scanf("%d", &tc);
    while(tc--)
    {
        Enter();
        Dijkstra();
    }
}

//Main Procedure
int main()
{
    Multitest();
    return 0;
}
