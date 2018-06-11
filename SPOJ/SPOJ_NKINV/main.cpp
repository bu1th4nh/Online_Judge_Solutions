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

#define _(x) ((x) & (-x))
//=====================================
//Fenwick Tree
struct FenwickTree
{
    int T[65536];

    void update(int k)
    {
        while(k <= 60007)
        {
            T[k]++;
            k += k & (-k);
        }
    }
    int get(int x)
    {
        int ret = 0;
        while(x > 0)
        {
            ret += T[x];
            x -= x & (-x);
        }
        return ret;
    }

    ~FenwickTree() {}
    FenwickTree() {}

};

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
int a[65536];
int n, res;

//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    res = 0;
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);

    FenwickTree FT;
    FORb(i, n, 1)
    {
        res += FT.get(a[i] - 1);
        FT.update(a[i]);
    }
    printf("%d\n", res);
    return 0;
}
