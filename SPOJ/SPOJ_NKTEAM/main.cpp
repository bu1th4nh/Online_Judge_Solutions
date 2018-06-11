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
//Fenwick Tree
struct FenwickTree
{
    typedef vector<int> vi;

    int n;
    vi T;

    void update(int pos, int x)
    {
        for(; pos <= n; pos += pos & (-pos)) T[pos] = min(T[pos], x);
    }
    int query(int pos)
    {
        int ret = n + 1;
        for(; pos >= 1; pos -= pos & (-pos)) ret = min(T[pos], ret);
        return ret;
    }
    void reset() {T.assign(n+1, 0);}



    ~FenwickTree() {T.clear();}

    FenwickTree(int __n, int __val) {T = vi(__n + 1, __val); n = __n;}
    FenwickTree(int __n) {T = vi(__n + 1, 0); n = __n;}
    FenwickTree() {}
};

//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<iii> viii;
typedef vector<vii> vvii;
int n, res;
viii a;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u;
    scanf("%d", &n);

    a = viii(n+1);
    a[0] = (iii(-1, ii(-1, -1)));

    FOR(i, 1, n) scanf("%d", &u), a[u].fi    = i;
    FOR(i, 1, n) scanf("%d", &u), a[u].se.fi = i;
    FOR(i, 1, n) scanf("%d", &u), a[u].se.se = i;

}

//Process
void Solve()
{
    FenwickTree ft(n+1, n+1);
    sort(whole(a));
    res = 0;

    FOR(i, 1, n)
    {
        int v = ft.query(a[i].se.se);
        if(v > a[i].se.fi) ++res;
        ft.update(a[i].se.se, a[i].se.fi);
    }

    cout << res;
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
