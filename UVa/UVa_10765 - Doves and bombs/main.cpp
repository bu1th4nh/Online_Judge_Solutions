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
vi num, low, del;
int m, n, cnt;
vii res;
vvi adj;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
    cnt = 0;

    res.clear();
    adj = vvi(n);
    num = vi(n, -1);
    del = low = vi(n, 0);

    int u, v;
    while(scanf("%d%d", &u, &v) == 2 && u != -1 && v != -1)
    {
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

//DFS
void DFS(int u, int p)
{
    int nChild = 0;
    low[u] = num[u] = cnt++;
    for(int v: adj[u])
    {
        if(num[v] == -1)
        {
            DFS(v, u);
            ++nChild;
            if(low[v] >= num[u])
            {
                del[u] = (u == p) ? nChild-1 : del[u]+1;
            }

            low[u] = min(low[u], low[v]);
        }
        else if(v != p)
        {
            low[u] = min(low[u], num[v]);
        }
    }
}
bool cmp(ii a, ii b)
{
    return (a.first > b.first || (a.first == b.first && a.second < b.second));
}

//Process
void Solve()
{
    FOR(u, 0, n-1)
    {
        if(num[u] == -1) DFS(u, u);
    }
    FOR(i, 0, n-1)
    {
        res.push_back(ii(del[i], i));
    }
    sort(whole(res), cmp);

    FOR(i, 0, m-1)
    {
        printf("%d %d\n", res[i].se, res[i].fi+1);
    }
}


//Output
void Multitest()
{
    while(scanf("%d%d", &n, &m) == 2 && n && m)
    {
        Enter();
        Solve();
        puts("");
    }
}

//Main Procedure
int main()
{
    Multitest();
    return 0;
}
