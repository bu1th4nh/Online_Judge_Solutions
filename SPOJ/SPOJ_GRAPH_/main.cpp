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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
int n, m, res1, res2, Time;
vi num, low, CVtx;
vvi adj;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;
    scanf("%d%d", &n, &m);
    CVtx = vi(n+1, 0);
    num = vi(n+1, 0);
    low = vi(n+1, 0);
    adj = vvi(n+1);

    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

//DFS
void DFS(int u, int p)
{
    int nChild = 0;
    low[u] = num[u] = ++Time;
    for(int v: adj[u])
    {
        if(v != p)
        {
            if(num[v] != 0) low[u] = min(low[u], num[v]);
            else
            {
                DFS(v, u);
                nChild++;

                low[u] = min(low[u], low[v]);
                if(low[v] >= num[v]) ++res1;

                if (u==p)
                {
                    if (nChild >= 2)
                    CVtx[u] = true;
                }
                else
                {
                    if (low[v] >= num[u])
                    CVtx[u] = true;
                }
            }
        }
    }
}

//Process
void Solve()
{
    res1 = 0;
    res2 = 0;
    FOR(i, 1, n) if(!num[i]) DFS(i, i);
    FOR(i, 1, n) if(CVtx[i]) ++res2;

    printf("%d %d\n", res2, res1);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
