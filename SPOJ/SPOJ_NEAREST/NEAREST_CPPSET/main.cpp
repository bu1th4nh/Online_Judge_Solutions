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
#define whole(x) x.begin()+1, x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".ans", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


const double inf = 1e20;
const int FP_ROUNDING = 3;
//=====================================
//Typedefs
typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ld, ld> dd;
typedef vector<dd> vdd;
ld res;
vdd a;
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
	a = vdd(n+1);
	FOR(i, 1, n) a[i].fi = readDouble(), a[i].se = readDouble();
}

//Check
struct cmp
{
    bool operator() (const dd &a, const dd &b) const
    {
        return (a.se == b.se ? a.fi < b.fi : a.se < b.se);
    }
};
ld dist(const dd &a, const dd &b)
{
    return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}

//Process
void Solve()
{
    set<dd, cmp> st;
    int j = 1;

    res = inf;
    sort(whole(a));

    FOR(i, 1, n)
    {
        while(j < i && a[j].fi <= a[i].fi - res)
        {
            st.erase(a[j]);
            j++;
        }

        set<dd, cmp>::iterator ptr = st.upper_bound(dd(inf, a[i].se - res));
        while(ptr != st.end())
        {
            if(ptr->se >= a[i].se + res) break;
            res = min(res, dist(a[i], *ptr));
            ptr++;
        }

        st.insert(a[i]);
    }

    printf("%.3lf", res);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
