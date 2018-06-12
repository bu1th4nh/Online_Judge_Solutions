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
#define sp ' '
#define el '\n'
#define task ""
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin()+1, x.end()
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

class PROBLEM
{
    vb avail;
    vvi adj;
    vi inv;
    int n;

    void Enter()
    {
        int x, y;
        while(scanf("%d", &x) && x)
        {
            while(scanf("%d", &y) && y)
            {
                adj[x].pb(y);
            }
        }

        scanf("%d", &x);
        FOR(i, 1, x)
        {
            scanf("%d", &y);
            inv.push_back(y);
        }
    }

    void DFS(int u)
    {
        avail[u] = false;
        for(int v: adj[u])
        {
            if(avail[v])
            {
                DFS(v);
            }
        }
    }

    void Solve()
    {
        for(int vtx: inv)
        {
            avail = vb(n+1, true);
            DFS(vtx);

            vi res;
            int nr = 0;
            FOR(i, 1, n) if(avail[i]) res.push_back(i), ++nr;

            cout << nr;
            for(int xxxx: res) cout << sp << xxxx;

            puts("");
        }
    }


    void debug()
    {
        FOR(i, 1, n)
        {
            cout << i << " : ";
            for(int x: adj[i]) cout << x << sp;
            cout << el;
        }
    }


public:

    PROBLEM(int __n)
    {
        n = __n;
        adj = vvi(n+1);
    }
    void SLV()
    {
        Enter();
        //debug();
        Solve();
    }


};


//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    freopen("x.txt", "w", stdout);

    int n;
    while(scanf("%d", &n) && n)
    {
        PROBLEM pb(n);
        pb.SLV();
    }
    return 0;
}
