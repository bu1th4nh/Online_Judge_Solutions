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

const int inf = 1000000007;
//=====================================
//Fenwick Tree
struct FenwickTree              //1-based
{
    typedef pair<int, int> ii;    //Value - Quantity
    typedef vector<ii> vii;
    int n;

    vii T;


    void add(int &a, int b)
    {
        a += b;
        if(a >= inf) a -= inf;
    }
    ii query(int i)
    {
        ii ret = ii(0, 0);
        for(; i > 0; i -= i & (-i))
        {
            if(ret.fi < T[i].fi) ret = T[i];
            else if(ret.fi == T[i].fi) add(ret.se, T[i].se);
        }
        return ret;
    }
    void update(int i, int val, int qty)
    {
        for(; i <= n + 1; i += i & (-i))
        {
            if(val > T[i].fi) T[i] = ii(val, qty);
            else if(val == T[i].fi) add(T[i].se, qty);
        }
    }

    ~FenwickTree() {T.clear();}

    FenwickTree(int __n) {T = vii(__n + 3); n = __n;}
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
int a[512000], b[512000], F[512000];
int n, max_val;


//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]), b[i] = a[i];

    sort(b+1, b+n+1);
    FOR(i, 1, n) a[i] = lower_bound(b+1, b+n+1, a[i]) - b;
    max_val = *max_element(a+1, a+n+1); a[n+1] = max_val + 1;

    FenwickTree ft(max_val);
    ii tmp;

    FOR(i, 1, n+1)
    {
        tmp = ft.query(a[i] - 1);
        F[i] = tmp.first + 1;
        if(tmp.second == 0) tmp.second++;
        if(i == n + 1) printf("%d\n", tmp.second);
        ft.update(a[i], F[i], tmp.second);
    }
    return 0;
}
