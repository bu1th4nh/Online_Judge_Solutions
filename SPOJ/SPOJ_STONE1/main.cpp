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
typedef long long ll;
vb avail;
vvi adj;
int n;
vi F;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, m, v;
	scanf("%d", &n);

	avail = vb(n+1, true);
	adj = vvi(n+1);
	F = vi(n+1);

	while(scanf("%d", &u) == 1)
    {
        scanf("%d", &m);
        FOR(i, 1, m)
        {
            scanf("%d", &v);
            adj[u].pb(v);
            //adj[v].pb(u);
        }
    }
}

//DSF + DP
bool cmp(int a, int b)
{
    return a > b;
}
void DFS(int u)
{
    avail[u] = false;
    int sz = adj[u].size();
    if(sz == 0)
    {
        F[u] = 1;
        return;
    }
    else
    {
        vi tmp;
        int now = 0, lres = 0;
        for(int v: adj[u]) if(avail[v])
        {
            DFS(v);
            tmp.push_back(F[v]);
        }

        sort(whole(tmp), cmp);
        FORl(i, 0, sz)
        {
            if(now < tmp[i])
            {
                lres += tmp[i] - now;
                now = tmp[i] - 1;
            }
            else --now;
        }

        F[u] = lres;
    }
}

//Process
void Solve()
{
    DFS(1);
    printf("%d", F[1]);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
