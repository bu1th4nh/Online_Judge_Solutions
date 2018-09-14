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
    typedef vector<int> vi;
    typedef vector<ld> vld;
    typedef vector<ll> vll;
    typedef vector<vld> vvld;
    typedef vector<vll> vvll;


    vi head, tail;
    vvll a, b;
    vvld x;


    ll query(int id, ll x_query)
    {
        int& he = head[id];
        int& ta = tail[id];

        if(he > ta) return 0LL;

        while(he < ta && x[id][he+1] <= x_query) he++;
        x[id][he] = x_query;


        //cerr << "Returned: " << 1LL * a[id][he] * x_query + b[id][he] << el;

        return 1LL * a[id][he] * x_query + b[id][he];
    }
    void update(int id, ll new_a, ll new_b)
    {
        int& he = head[id];
        int& ta = tail[id];


        ld new_x = -1e18;
        while(he <= ta)
        {
            if( new_a == a[id][ta] ) return;

            new_x = 1.0 * (b[id][ta] - new_b) / (new_a - a[id][ta]);
            if(he == ta || new_x >= x[id][ta]) break;

            ta--;
        }

        a[id][++ta] = new_a;
        b[id][ ta ] = new_b;
        x[id][ ta ] = new_x;

        //cerr << "Added: " << new_a << sp << new_b << sp << new_x << el;
    }


    ConvexHullDS()
    {
        head = vi(16, 1);
        tail = vi(16, 0);
        a = b = vvll(16, vll(131073, 0LL));
        x = vvld(16, vld(131073, 0.00000));
    }
};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, nPiles;
vi a, ps, lc;
vvi dp;

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
	scanf("%d%d", &n, &nPiles);

	ps = lc = a = vi(n+1, 0LL);
	dp = vvi(n+1, vi(nPiles+1, 0LL));

	FOR(i, 1, n) scanf("%lld", &a[i]);

	reverse(whole(a));
	FOR(i, 1, n)
	{
	    ps[i] = ps[i-1] + a[i];
	    lc[i] = ps[i-1] + lc[i-1];
	}
	lc.push_back(lc.back());
}


//Process
void Solve()
{
    ConvexHullDS tml;

    tml.update(0, 0, 0);


    FOR(i, 1, n)
    {
        FOR(j, 1, nPiles)
        {
            if(j > i) break;

            dp[i][j] = lc[i] + tml.query(j-1, i);
            tml.update(j, -ps[i],  dp[i][j] - lc[i+1] + ps[i]*(i+1) );

            //cerr << i << sp << j << sp << dp[i][j] << sp << tml.query(j-1, i) << el;
        }
    }


    //FOR(i, 1, n) {FOR(j, 1, nPiles) cerr << dp[i][j] << sp; cerr << el;} cerr << el;

    cout << dp[n][nPiles];
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}



/*
5 2
1
2
3
4
5
*/
