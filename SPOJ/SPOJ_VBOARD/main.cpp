/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
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
int f[512][512], g[512][512], a[512][512];
int n, q, x, y, u, v;

//=====================================
//Functions and procedures
int main()
{
    scanf("%d", &n);

    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {

            scanf("%d", &a[i][j]);

            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];

            g[i][j] = g[i-1][j] + g[i][j-1] - g[i-1][j-1] +  (   (  ( i + j ) % 2 == 0  )   ?  0  :  a[i][j]  );

        }
    }

    scanf("%d", &q);

    FOR(i, 1, q)
    {
        scanf("%d%d%d%d", &x, &y, &u, &v);

        printf("%d\n",  abs(  f[u][v] - f[x-1][v] - f[u][y-1] + f[x-1][y-1] - 2   * ( g[u][v] - g[x-1][v] - g[u][y-1] + g[x-1][y-1]   )  )    );
    }

    return 0;
}
