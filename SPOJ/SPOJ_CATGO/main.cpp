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

const int inf = 100000007;
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
vi value, length;
int m, n, res;
vvi F, G;


//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    int x, y;

    res   = -inf;
    value = length = vi(51, 0);
    F = G = vvi(101, vi(101, 0));

    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &length[i]);
    scanf("%d", &m);
    FOR(i, 1, m)
    {
        scanf("%d%d", &x, &y);
        value[x] = max(value[x], y);
    }

    FOR(i, 1, 50) G[i][0] = -inf;

    /*
            Pre-process:
                          ,-    = -inf, if j = 0
                G[i][j] = |
                          |
                          '-    = max(G[i][j], G[part][j - 1] + value[i - part], otherwise
                    (
                        With:   0 <= part <= i
                                i: Length of the bar
                                j: No. of cutting attempt
                    )
    */

    FOR(i, 1, 50)
    {
        FOR(j, 1, i)
        {
            FORl(part, 0, i)
            {
                G[i][j] = max(G[i][j], G[part][j-1] + value[i - part]);
            }
        }
    }

    /*
            DP:
                F[i][j] = max(F[i][j], F[i - 1][j - k + 1] + G[length[i]][k])

                    (
                        With:   i: The n-th wood bar
                                j: No. of cutting attempt,                  k-1 <= j <= 100
                                k: No. of part cut form the original bar    1   <= k <= length[i]
                    )
    */

    FOR(i, 1, n)
    {
        FOR(k, 1, length[i])
        {
            FOR(j, k-1, 100)
            {
                F[i][j] = max(F[i][j], F[i - 1][j - k + 1] + G[length[i]][k]);
            }
        }
    }


    FOR(i, 0, 100) res = max(res, F[n][i] - i*(i + 1)/2);

    printf("%d", res);


    return 0;
}
