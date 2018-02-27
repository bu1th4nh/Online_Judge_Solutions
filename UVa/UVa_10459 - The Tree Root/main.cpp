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
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
vi res1, res2, height;
int n, ds, fn;
vvi adj;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    height = vi(n+1, 0);
    adj = vvi(n+1);
    res1.clear();
    res2.clear();
    fn = 0;

    int link, v;

    FOR(i, 1, n)
    {
        scanf("%d", &link);
        FOR(jjj, 1, link)
        {
            scanf("%d", &v);
            adj[i].pb(v);
        }
    }
}

//DFS
void DFS(int u, int par, int h)
{
    height[u] = max(height[u], h);

    if(h > ds)
    {
        ds = h;
        fn = u;
    }

    for(int v: adj[u])
    {
        if(v == par) continue;
        DFS(v, u, h+1);
    }

}


//Process
void Solve()
{
    int mx = 0, mn = 123456789;

    ds = 0;
    DFS(1, -1, 1);
    ds = 0;
    DFS(fn, -1, 1);
    ds = 0;
    DFS(fn, -1, 1);

    height[0] = -1234567890;
    mx = *max_element(whole(height));
    height[0] = 1234567890;
    mn = *min_element(whole(height));

    printf("Best Roots  :");
    FOR(i, 1, n) if(height[i] == mn) printf(" %d", i);
    puts("");

    printf("Worst Roots :");
    FOR(i, 1, n) if(height[i] == mx) printf(" %d", i);
    puts("");
}


//Output
void Multitest()
{
    while(scanf("%d", &n) != EOF)
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
