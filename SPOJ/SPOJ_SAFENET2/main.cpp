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
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
//Biconnected Component
struct BiconnectedComponent
{
    typedef long long ll;
    typedef unsigned long long ull;
    typedef pair<int, int> ii;
    typedef vector<bool> vb;
    typedef vector<int> vi;
    typedef vector<ii> vii;
    typedef vector<vi> vvi;
    typedef vector<vii> vvii;
    typedef stack<ii> sii;

    int n, nBCC, nTime, maxBCC;
    vi num, low, idx;
    vvii BCC;
    vvi adj;
    sii st;


    void addEdge(int u, int v)
    {
        adj[--u].pb(--v);
        adj[v].pb(u);
    }
    void DFS(int u, int p)
    {
        num[u] = low[u] = ++nTime;

        for(int v: adj[u])
        {
            if(num[v] == -1)
            {
                st.push(ii(u, v)); DFS(v, u);
                low[u] = min(low[u], low[v]);


                if(low[v] >= num[u])
                {
                    int c = 0;
                    while(1)
                    {
                        ii e = st.top(); st.pop();

                        if(idx[e.fi] != nBCC) ++c, idx[e.fi] = nBCC;
                        if(idx[e.se] != nBCC) ++c, idx[e.se] = nBCC;

                        if(e == ii(u, v)) break;
                    }
                    ++nBCC;
                    maxBCC = max(maxBCC, c);
                }
            }
            else if(v != p && num[v] < num[u])
            {
                st.push(ii(u, v));
                low[u] = min(low[u], num[v]);
            }
        }
    }
    void InitDFS()
    {
        FORl(i, 0, n) if(num[i] == -1) DFS(i, -1);
    }
    int ExtractMaxBCC()
    {
        return max(maxBCC, 1);
    }

    BiconnectedComponent() {}
    BiconnectedComponent(int __n)
    {
        n = __n;

        nBCC =  nTime = 0;
        maxBCC = 0;             //Initialize Everything!

        num = low = idx = vi(n, -1);
        adj = vvi(n);
    }

    ~BiconnectedComponent() {}
};


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

//=====================================
//Functions and procedures
//Driver Program 1: SPOJ - SAFENET2
void SAFENET2()
{
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    BiconnectedComponent bc(n);

    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        bc.addEdge(u, v);
    }

    bc.InitDFS();
    cout << bc.ExtractMaxBCC();
}



//Main Procedure
int main()
{
    SAFENET2();
    return 0;
}
