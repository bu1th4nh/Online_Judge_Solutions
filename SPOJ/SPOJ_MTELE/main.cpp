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
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
const int INF = -1234567890;
int n, m, res;
vvii adj;
vi pay;
vvi f;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int k, v, w;

    scanf("%d%d", &n, &m);

    adj = vvii(n);
    f = vvi(n+5, vi(n+5, INF));
    pay = vi(n);

    FORl(i, 0, n - m)
    {
        scanf("%d", &k);
        while(k--)
        {
            scanf("%d%d", &v, &w); --v;
            adj[i].pb(ii(w, v));
        }
    }

    FORl(i, n - m, n)
    {
        scanf("%d", &pay[i]);
    }

}

//DFS
int DFS(int u)
{
    f[u][0] = 0;
    if(u >= n - m)
    {
        f[u][1] = pay[u];
        return 1;
    }

    int mx = 0;

    int tmp[4096];

    for(ii vtx: adj[u])
    {
        int x = DFS(vtx.second);
        mx += x;

        FOR(j, 0, mx) tmp[j] = INF;

        FOR(j, 0, mx)
        {
            FOR(k, 0, j)
            {
                int cur = f[vtx.second][k] - vtx.first;
                tmp[j] = max( tmp[j] , max( f[u][j] , f[u][j - k] + cur ) );
            }
        }

        FOR(j, 0, mx) f[u][j] = max(f[u][j], tmp[j]);

    }

    return mx;
}

//Process
void Solve()
{
    DFS(0);
    res = n;
    while(f[0][res] < 0) res--;

    printf("%d", res);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
