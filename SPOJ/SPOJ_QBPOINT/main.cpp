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
#define x first
#define y second
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
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
int x[2048], y[2048];
ll res;
int n;

//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    res = 0;

    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d%d", &x[i], &y[i]);

    FOR(i, 1, n)
    {
        vd rat; int cc = 0;


        FOR(j, 1, n)
        {
            if(x[j] != x[i])
            {
                rat.push_back( (double)(y[j] - y[i]) / (x[j] - x[i]) );
            }
            else ++cc;
        }

        sort(whole(rat));

        int qty = (cc - 2)*(cc - 1);

        if(rat.size())
        {
            int cnt = 1;
            FOR(j, 1, rat.size()-1)
            {
                if(rat[j] == rat[j-1]) ++cnt;
                else
                {
                    qty += cnt*(cnt-1);
                    cnt = 1;
                }
            }
            qty += cnt*(cnt-1);
        }
        res += qty;
    }
    printf("%lld", (res/6));
    return 0;
}
