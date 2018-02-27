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
#define MODUL (int)(123456789)
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
int n, m, res, nTest, src, dst, TCase;
vvi d;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;
    scanf("%d%d", &n, &m);

    d = vvi(n, vi(n, MODUL));

    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        d[u][v] = d[v][u] = 1;
    }

    FOR(i, 0, n-1) d[i][i] = 0;

    scanf("%d%d", &src, &dst);
}

//Process
void Solve()
{
    res = 0;
    FOR(k, 0, n-1)
    {
        FOR(i, 0, n-1)
        {
            FOR(j, 0, n-1)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    FOR(i, 0, n-1)
    {
        if(d[src][i] != MODUL && d[i][dst] != MODUL)
        {
            res = max(res, d[src][i] + d[dst][i]);
        }
    }

    printf("Case %d: %d\n", ++TCase, res);
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
    }
}


//Main Procedure
int main()
{
    Multitest();
    return 0;
}
