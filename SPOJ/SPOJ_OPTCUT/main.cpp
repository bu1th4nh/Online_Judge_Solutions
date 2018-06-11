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

const int inf = 1234567890;
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
vi a, ps;
vvi F, P;
int n;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d", &n);

    F = P = vvi(n+2, (a = ps = vi(n+2, 0)));

    FOR(i, 1, n) scanf("%d", &a[i]), ps[i] = ps[i-1] + a[i];
}

//Process
void Solve()
{
    FOR(i, 1, n) P[i][i] = i, F[i][i] = 0;
    FOR(l, 2, n)
    {
        for(int i = 1, j = i + l - 1; j <= n; ++i, ++j)
        {
            F[i][j] = inf;
            FORb(t, P[i+1][j], P[i][j-1])
            {
                if(ps[j] - ps[i-1] + F[i][t-1] + F[t][j] < F[i][j])
                {
                    F[i][j] = ps[j] - ps[i-1] + F[i][t-1] + F[t][j];
                    P[i][j] = t;
                }
            }
        }
    }
    cout << F[1][n];
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
