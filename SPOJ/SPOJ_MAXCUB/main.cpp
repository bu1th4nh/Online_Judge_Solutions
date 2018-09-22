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
int a[32][32][32], F[32][32][32];
int n, tc;

//=====================================
//Functions and procedures
int main()
{
    scanf("%d", &tc);
    while(tc--)
    {


        scanf("%d", &n);
        FOR(i, 1, n)
        {
            FOR(j, 1, n)
            {
                FOR(k, 1, n)
                {
                    scanf("%d", &a[i][j][k]);
                }
            }
        }

        FOR(i, 1, n)
        {
            FOR(j, 1, n)
            {
                FOR(k, 1, n)
                {
                    F[i][j][k] = F[i-1][j][k] + F[i][j-1][k] + F[i][j][k-1] + a[i][j][k] + F[i-1][j-1][k-1] - F[i-1][j-1][k] - F[i][j-1][k-1] - F[i-1][j][k-1];
                }
            }
        }

        int res = 0;

        FOR(i, 1, n)
        {
            FOR(j, 1, n)
            {
                FOR(k, 1, n)
                {
                    for(int l = 1; l <= i && l <= j && l <= k; ++l)
                    {
                        res = max(res,   F[i][j][k] - F[i-l][j][k] - F[i][j-l][k] - F[i][j][k-l] - F[i-l][j-l][k-l] + F[i-l][j-l][k] + F[i][j-l][k-l] + F[i-l][j][k-l]    );
                    }
                }
            }
        }


        printf("%d\n", res);

    }
    return 0;
}
