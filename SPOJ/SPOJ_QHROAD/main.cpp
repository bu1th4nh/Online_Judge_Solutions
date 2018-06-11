//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
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
int p[131072], res[131072], u[131072], v[131072], d[131072];
int n, q, m, nSet;
vb del;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d%d%d", &n, &m, &q);

    del = vb(131072, false);

    nSet = n;

    FORl(i, 0, m)
    {
        scanf("%d%d", &u[i], &v[i]);
        --u[i], --v[i];
    }
    FORl(i, 0, q)
    {
        scanf("%d", &d[i]);
        del[--d[i]] = true;
    }
}

//Disjoint Set DS
void reset(int n) {for(int i = 0; i < n; ++i) p[i] = i; nSet = n;}
int getset(int u) {return u == p[u] ? u : p[u] = getset(p[u]);}
void Union(int u, int v) {if(getset(u) != getset(v)) p[p[u]]=p[v], --nSet;}

//Process
void Solve()
{
    reset(n);
    FORl(i, 0, m) if(!del[i]) Union(u[i], v[i]);
    FORb(i, q-1, 0) res[i] = nSet, Union(u[d[i]], v[d[i]]);
    FOR(i, 0, q-1) printf("%d\n", res[i]);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
