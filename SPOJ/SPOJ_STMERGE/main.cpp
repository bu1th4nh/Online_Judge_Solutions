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
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
int m, n, nTest;
ll res;
vvvi f;
vvi c;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d%d", &m, &n);

    c = vvi(m+1, vi(n+1, 0));
    f = vvvi(m+1, vvi(n+1, vi(2, 0)));

    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            scanf("%lld", &c[i][j]);
        }
    }
}

//Process
void Solve()
{
    f[1][1][0] = f[1][1][1] = c[1][1];

    FOR(i, 2, n) f[1][i][0] = min(f[1][i-1][0], f[1][i-1][1] + c[1][i]),  f[1][i][1] = c[1][i];

    FOR(i, 2, m) f[i][1][0] = c[i][1],  f[i][1][1] = min(f[i-1][1][1], f[i-1][1][0] + c[i][1]);

    FOR(i, 2, m)
    {
        FOR(j, 2, n)
        {
            f[i][j][0] = min(f[i][j-1][0], f[i][j-1][1] + c[i][j]);
            f[i][j][1] = min(f[i-1][j][1], f[i-1][j][0] + c[i][j]);
        }
    }

    printf("%lld\n", min(f[m][n][0], f[m][n][1]));
}

//Output
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
