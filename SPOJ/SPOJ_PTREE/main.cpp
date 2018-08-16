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

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <random>
#endif // __cplusplus

using namespace std;


//=====================================
//Macroes
#define sp " "
#define el "\n"
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

const int inf = 1000000000;
//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vvi adj, trace, dp;
int n, p;
vi c;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    FILEOP_DEBUG()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
    int u, v;
    scanf("%d%d", &n, &p);

    c     = vi(n+1, 0);
    adj   = vvi(n+1, vi(n+1, 0));
    trace = vvi(n+1, vi(p+1, 0));
    dp    = vvi(n+1, vi(p+1, -inf));

    FOR(i, 1, n) scanf("%d", &c[i]), dp[i][0] = 0, dp[i][1] = c[i];  //Initial weight value
    FOR(i, 1, n-1)
    {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

//Check
void DFS(int u)
{
    dp[u][1] = c[u];
    FOR(v, 1, n) if(adj[u][v] == 1)
    {
        adj[v][u] = 0;  DFS(v);
        FORb(i, p, 1) FOR(j, 1, i-1)
        {
            if(dp[u][i] < dp[u][j] + dp[v][i-j])    //Optimization
            {
                dp[u][i]    = dp[u][j] + dp[v][i-j];
                trace[v][i] = i - j;
            }
        }
    }
}
void Trace(int u, int P)
{
    FORb(v, n, 1)
    {
        if(adj[u][v] == 1 && trace[v][P] > 0)
        {
            Trace(v, trace[v][P]);
            P -= trace[v][P];
        }
    }
    cout << u << sp;
}
void Solve()
{
    DFS(1);

    int pos = 1, res = dp[1][p];
    FOR(u, 2, n) if(dp[u][p] > dp[pos][p]) pos = u, res = dp[u][p];
    Trace(pos, p);

    //cerr << el << res << el;
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}

/*
3 2
1 2 3
1 2
2 3
*/
