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

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <random>
#endif // __cplusplus

using namespace std;


//=====================================
//Macroes
#define sp " "
#define el "\n"
#define task "NEAREST"
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
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".ans", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


const int FP_ROUNDING = 3;
const long double EPS = 1e-3;
//=====================================
//Typedefs
typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ld, ld> dd;
typedef vector<dd> vdd;
dd a[131072];
ld res;
int n;

//=====================================
//Functions and procedures
//I/O Utilities
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    FILEOP_DEBUG()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
inline ld readDouble()
{
    char c = 0;
    bool neg = 0;
    ld ret = 0.0, after_the_dot = 0.10;
    while((!isdigit(c)) && c != '-' && c != '.') c = getchar();

    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) == 1; c = getchar()) ret = ret * 10 + (c - '0');
    if(c == '.')
    {
        c = getchar();
        for(; isdigit(c) == 1; c = getchar())
        {
            ret += after_the_dot * (c - '0');
            after_the_dot /= 10;
        }
    }

    //cerr << fixed << setprecision(10) << ret << el;
    return (neg) ? -ret : ret;
}


//Enter
void Enter()
{
	cin >> n;
	FORl(i, 0, n) a[i].fi = readDouble(), a[i].se = readDouble();
}

//Check
bool cmp_x(dd a, dd b)
{
    return a.fi < b.fi;
}
bool cmp_y(dd a, dd b)
{
    return a.se < b.se;
}
inline void upd_dist(dd &x, dd &y)
{
    ld dst = sqrt((x.fi - y.fi)*(x.fi - y.fi) + (x.se - y.se)*(x.se - y.se));
    if(dst < res) res = dst;
}

//Process
void find(int l, int r)
{
    if(r <= l) return;

    if(r == l + 1)
    {
        upd_dist(a[l], a[r]);
        if(!cmp_y(a[l], a[r])) swap(a[l], a[r]);
        return;
    }

    int m = (l + r) / 2;
    int midx = a[m].fi;

    find(l, m);
    find(m+1, r);

    static dd t[131072];
    merge(a+l, a+m+1, a+m+1, a+r+1, t, cmp_y);
    copy(t, t+r-l+1, a+l);

    int tmp = 0;
    FOR(i, l, r) if(abs(a[i].fi - midx) < res)
    {
        for(int j = tmp-1; j >= 0 && t[j].se > a[i].se - res; j--) upd_dist(a[i], t[j]);
        t[tmp++] = a[i];
    }
}

//Output
void Solve()
{
    sort(a, a+n, cmp_x);

    res = 1e20;
    find(0, n-1);
    printf("%.3lf", res);


    //FOR(i, 1, n) cerr << a[i].fi << sp << a[i].se << el;
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
