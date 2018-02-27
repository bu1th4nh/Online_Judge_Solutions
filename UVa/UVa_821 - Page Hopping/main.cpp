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
int n, m, sum, TCase;
double res;
vvi d;

//=====================================
//Functions and procedures
//Enter
void Enter(int u, int v)
{
    d[u][v] = 1;
    n = max(n, max(u, v));

    while(scanf("%d%d", &u, &v) && u && v)
    {
        d[u][v] = 1;
        n = max(n, max(u, v));
    }

    FOR(i, 1, n) d[i][i] = 0;
}

//Process
void Solve()
{
    FOR(k, 1, n)
    {
        FOR(i, 1, n)
        {
            FOR(j, 1, n)
            {
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
            }
        }
    }

    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            if(i != j && d[i][j] != MODUL)
            {
                sum += d[i][j];
                ++m;
            }
        }
    }

    res = ((double)sum / (double)m);

    printf("Case %d: average length between pages = %.3f clicks\n", TCase, res);
}

//Output
void Multitest()
{
    int x, y;
    TCase = 0;

    while(scanf("%d%d", &x, &y) == 2 && x && y)
    {
        d = vvi(101, vi(101, MODUL));
        sum = 0;
        m = 0;
        n = 0;
        ++TCase;

        Enter(x, y);
        Solve();
    }

}

//Main Procedure
int main()
{
    Multitest();
    return 0;
}
