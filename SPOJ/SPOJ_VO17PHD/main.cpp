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
typedef pair<ll, ll> ii;
typedef pair<ii, int> iii;
typedef pair<int, int> p2i;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<p2i> vp2i;
typedef vector<iii> viii;
typedef vector<vp2i> DSK;
const ll MODUL = (long long)(12345678909876543);

//=====================================
//Variables Declaration
vll dist, take;
int n, m;
DSK adj;
vi cake;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v, c;
    scanf("%d", &n);

    adj = DSK(n+4);
    cake = vi(n+1);
    take = vll(n+1);
    dist = vll(n+1, MODUL);

    FOR(i, 1, n) scanf("%d", &cake[i]);
    scanf("%d", &m);

    FOR(i, 1, m)
    {
        scanf("%d%d%d", &u, &v, &c);
        adj[u].pb(p2i(c, v));
        adj[v].pb(p2i(c, u));
    }
}

//Dijkstra's Algorithm
void Dijkstra()
{
    int u, v;
    ll du, cu;
    priority_queue<iii, viii, greater<iii>> pq;

    pq.push( iii( ii( 0 , cake[1] ) , 1 ) );
    take[1] = cake[1];
    dist[1] = 0;

    while(!pq.empty())
    {
        u = pq.top().se, du = pq.top().fi.fi, cu = pq.top().fi.se;
        pq.pop();

        for(p2i x: adj[u])
        {
            if(dist[x.se] > du + x.fi)
            {
                pq.push( iii( ii( dist[x.se] = du + x.fi , take[x.se] = cu + cake[x.se] ) , x.se ) );
            }
            else
            {
                if(dist[x.se] == du + x.fi && take[x.se] < cu + cake[x.se])
                {
                    pq.push( iii( ii( dist[x.se] , take[x.se] = cu + cake[x.se] ) , x.se ) );
                }
            }
        }
    }


//    puts("");
//    FOR(i, 1, n) printf("%lld %lld\n", dist[i].fi, dist[i].se);
//    puts("");
//
//    puts("");
//    FOR(i, 1, n)
//    {
//        cout << i << ": ";
//        for(ii x: adj[i]) cout << x.second << "-" << x.first << "  ";
//        puts("");
//    }
//    puts("");



}

//Process
void Solve()
{
    Dijkstra();
    if(dist[n] == MODUL)
    {
        printf("impossible");
    }
    else
    {
        printf("%lld %lld\n", dist[n], take[n]);
    }
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
