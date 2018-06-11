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
typedef long long ll;
int n, m, nTest, nQuery;
vi lab, w;
vii edge;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;
    scanf("%d%d%d", &n, &m, &nQuery);

    edge = vii(m+1);
    w = vi(m+1);

    FOR(i, 1, m)
    {
        scanf("%d%d%d", &u, &v, &w[i]);
        edge[i] = ii(u, v);
    }
}

//Disjoint Sets DS
int FSet(int u)
{
    return (lab[u] < 0) ? u : (lab[u] = FSet(lab[u]));
}
void Union(int r, int s)
{
    if(lab[s] < lab[r]) swap(r, s);
    lab[r] += lab[s];
    lab[s] = r;
}

//Process
void Solve()
{
    FOR(iiiiiii, 1, nQuery)
    {
        int id, s, vtx, wei;
        vi chg = w;

        scanf("%d%d", &id, &s);

        FOR(i, 1, s)
        {
            scanf("%d%d", &vtx, &wei);
            chg[vtx] = wei;
        }

        lab = vi(n+1, -1);

        FOR(i, 1, m)
        {
            if(chg[i] < chg[id])
            {
                int u = FSet(edge[i].fi);
                int v = FSet(edge[i].se);
                if(u!=v) Union(u, v);
            }
        }

        int u = FSet(edge[id].fi);
        int v = FSet(edge[id].se);
        if(u!=v) printf("NO\n");
        else printf("YES\n");
    }
}

//Multi-test processing
void Multitest()
{
    scanf("%d", &nTest);
    while(nTest--)
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
