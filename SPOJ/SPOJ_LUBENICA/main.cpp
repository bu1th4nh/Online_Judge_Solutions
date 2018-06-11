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
#include <climits>
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
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


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
vvi P, Wmin, Wmax;
vvii adj;
vi depth;
int n, k;


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileDebug()
{
    FILEOP_DEBUG();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
    int u, v, c;
	scanf("%d", &n);

	P = Wmin = Wmax = vvi(20, vi(n+1, 0));
	adj = vvii(n+1);
	depth = vi(n+1);

	FOR(i, 1, n-1)
	{
	    scanf("%d%d%d", &u, &v, &c);
	    adj[u].pb(ii(v, c));
	    adj[v].pb(ii(u, c));
	}
	scanf("%d", &k);
}

//Check
void DFS(int u)
{
    for(ii x: adj[u])
    {
        int v = x.first, w = x.second;
        if(v != P[0][u])
        {
            P[0][v] = u;
            depth[v] = depth[u] + 1;
            Wmin[0][v] = Wmax[0][v] = w;
            DFS(v);
        }
    }
}
void Init()
{
    DFS(1);

    FOR(k, 1, 19)
    {
        FOR(i, 1, n) if(P[k][i] == 0)
        {
            P[k][i] = P[k-1][P[k-1][i]];
            Wmin[k][i] = min(Wmin[k-1][i], Wmin[k-1][P[k-1][i]]);
            Wmax[k][i] = max(Wmax[k-1][i], Wmax[k-1][P[k-1][i]]);
        }
    }
}

//Process
void Query(int u, int v)
{
    if(depth[u] < depth[v]) swap(u, v);
    int wmax = INT_MIN;
    int wmin = INT_MAX;

    FORb(i, 19, 0)
    {
        if(depth[u] - (1 << i) >= depth[v])
        {
            wmin = min(wmin, Wmin[i][u]);
            wmax = max(wmax, Wmax[i][u]);
            u = P[i][u];
        }
    }
    if(u != v)
    {
        FORb(i, 19, 0) if(P[i][u] != P[i][v])
        {
            wmin = min(wmin, min(Wmin[i][u], Wmin[i][v]));
            wmax = max(wmax, max(Wmax[i][u], Wmax[i][v]));
            u = P[i][u], v = P[i][v];
        }
        wmin = min(wmin, min(Wmin[0][u], Wmin[0][v]));
        wmax = max(wmax, max(Wmax[0][u], Wmax[0][v]));
    }


    printf("%d %d\n", wmin, wmax);
}

//Output
void Solve()
{
    int u, v;
    Init();
    while(k--)
    {
        scanf("%d%d", &u, &v);
        Query(u, v);
    }
}



//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
