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
typedef stack<int> si;
typedef long long ll;
int n, nVtx, TCase, nTest;
vi vect, deg;
bool IsEuler;
vii res;
vvi adj;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;

    adj = vvi(51, vi(51, 0));
    deg = vi(51, 0);
    IsEuler = true;
    res.clear();
    nVtx = 0;

    scanf("%d", &n);

    FOR(i, 1, n)
    {
        scanf("%d%d", &u, &v);

        nVtx = max(nVtx, max(u, v));
        adj[u][v]++, adj[v][u]++, deg[u]++, deg[v]++;
    }
}

//Check
void FindEulerTour(int u)
{
    FOR(v, 1, nVtx)
    {
        if(adj[u][v])
        {
            adj[u][v]--, adj[v][u]--;
            FindEulerTour(v);
            res.push_back(ii(u, v));
        }
    }
}


//Process
void Solve()
{
    FOR(i, 1, nVtx)
    {
        if(deg[i] & 1)
        {
            IsEuler = false;
            break;
        }
    }

    printf("Case #%d\n", ++TCase);

    if(IsEuler)
    {
        FindEulerTour(nVtx);

        if(res.size() != n || res[0].se != res[res.size()-1].fi)
        {
            printf("some beads may be lost\n");
        }

        FORb(i, res.size()-1, 0) printf("%d %d\n", res[i].first, res[i].second);
    }
    else
    {
        printf("some beads may be lost\n");
    }
}


//Output
void Multitest()
{
    TCase = 0;
    scanf("%d", &nTest);
    while(nTest--)
    {
        Enter();
        Solve();
        if(nTest) puts("");
    }
}


//Main Procedure
int main()
{
    Multitest();
    return 0;
}
