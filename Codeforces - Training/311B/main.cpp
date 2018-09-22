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
#define task ""
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
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
//DS Classes
struct ConvexHullDS
{
    typedef double ld;
    typedef long long ll;
    typedef vector<ll> vll;
    typedef vector<ld> vld;

    int head, tail;
    vll a, b;
    vld x;

    ll query(ll x_query)        //Get the optimal value from constructed set of lines with x = a[i]
    {
        if(head > tail) return 0LL;
        while(head < tail && x[head + 1] <= x_query) head++;

        x[head] = x_query;
        return (1LL * a[head] * x_query + b[head]);
    }

    void update(ll new_a, ll new_b)     //Add a line to the set
    {
        ld new_x = -1e18;
        while(head <= tail)
        {
            if(new_a == a[tail]) return;
            new_x = 1.0 * (b[tail] - new_b) / (new_a - a[tail]);

            if(head == tail || new_x >= x[tail]) break;
            tail--;
        }

        a[++tail] = new_a;
        b[tail]   = new_b;
        x[tail]   = new_x;
    }

    ConvexHullDS()
    {
        head = 1, tail = 0;
        x = vld(131073, 0.0);
        a = b = vll(131073, 0LL);
    }

    ~ConvexHullDS() {}
};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<vii> vvii;
vll ps, dist, wait_time;
int m, n, p;
vii cats;
vvll dp;
ll res;


//=====================================
//Functions and procedures
//Initialization and preparation
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

//Enter
void Enter()
{
	scanf("%d%d%d", &n, &m, &p);    //m cats, n hills, p feeders


	ps = wait_time = vll(m+1, 0LL);
	dp = vvll(m+1, vll(p+1, 0LL));
	dist = vll(n+1, 0LL);
	cats = vii(m+1);


	FOR(i, 2, n) scanf("%I64d", &dist[i]), dist[i] += dist[i-1];
	FOR(i, 1, m) scanf("%d%d", &cats[i].fi, &cats[i].se);
}

//Process
void Preps()
{
    FOR(i, 1, m) wait_time[i] = cats[i].se - dist[cats[i].fi];
    sort(whole(wait_time));
    FOR(i, 1, m) ps[i] = ps[i-1] + wait_time[i];
}
void Solve()
{
    FOR(j, 1, p)
    {
        ConvexHullDS planaxis;
        FOR(i, 1, m)
        {
            dp[i][j] = planaxis.query(wait_time[i]) + wait_time[i] * i - ps[i];
            if(j > 1) planaxis.update(-i, dp[i][j-1] + ps[i]);
        }
    }

    cout << *min_element(whole(dp[m]));
}



//Main Procedure
int main()
{
    Enter();
    Preps();
    Solve();
    return 0;
}
