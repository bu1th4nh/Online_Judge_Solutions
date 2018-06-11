/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
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
#include <tuple>
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
#define whole(x) x+1, x+n+1
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
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi F, TopoOrder, IdOrder;
int n, res, idx, a[1024];
vb avail;
vvi adj;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d", &n);

    F = IdOrder = TopoOrder = vi(n+1);
    avail = vb(n+1, true);
    adj = vvi(n+1);

    a[0] = F[0] = -1;
    idx = n;

    FOR(i, 1, n) scanf("%d", &a[i]);
    sort(whole(a));
}

//Check
void BuildGraph()
{
    int last;
    FOR(i, 1, n-2)
    {
        FOR(j, i+1, n-1)
        {
            int k1 = lower_bound(a+j+1, a+n+1, a[i] + a[j]) - a;
            if(a[k1] != a[i] + a[j]) continue;
            int k2 = upper_bound(a+j+1, a+n+1, a[i] + a[j]) - a;

            FORl(k, k1, k2)
            {
                adj[i].pb(k);
                adj[j].pb(k);
            }
        }
    }
}
void DFS(int u)                                 //Topological sorting
{
    avail[u] = false;
    for(int v: adj[u]) if(avail[v]) DFS(v);

    TopoOrder[u] = idx;
    IdOrder[idx] = u;
    --idx;
}
void TopoDP()
{
    FOR(i, 1, n) if(avail[i]) DFS(i);
    FORb(i, n-1, 1)
    {
        int u = IdOrder[i];
        for(int v: adj[u]) F[i] = max(F[i], F[TopoOrder[v]]+1);
    }
    printf("%d\n", *max_element(F.begin(), F.end()) + 1);       //Count the starting vertex
}

//Process
void Solve()
{
    BuildGraph();
    TopoDP();
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
