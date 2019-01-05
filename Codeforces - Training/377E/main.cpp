/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//=====================================
//Solution Briefing - Foreword



//=====================================
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#include <chrono>
#endif // __cplusplus

using namespace std;

//#define DEBUG
#define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task ""
#define maxinp ()
#define fi first
#define se second
#define pb push_back
#define whole(x) x.begin(),x.end()
#define whole_1(x) x.begin()+1,x.end()
#define r_whole(x) x.rbegin(),x.rend()
#define FOR(i, x, y) for(auto i=x; i<=y; ++i)
#define FORl(i, x, y) for(auto i=x; i<y; ++i)
#define FORb(i, x, y) for(auto i=x; i>=y; --i)
#define FORlb(i, x, y) for(auto i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define what_is(x) cerr << #x << " is " << x << endl;
#define FILEOP()                        \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
}
#define FILEOP_DEBUG()                  \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
    freopen(task".err", "w", stderr);   \
}

//Macroes - Optional
#ifdef OPTIONAL_FEATURE
    #define pc(x) putchar(x)
    #define gc() getchar()
#endif



//=====================================
//Auxilary Functions and Fast I/O
#ifdef OPTIONAL_FEATURE
    template<class T, class R> T max(const T &__X, const R &__Y)
    {
        return __X > __Y ? __X : __Y;
    }
    template<class T, class R> T min(const T &__X, const R &__Y)
    {
        return __X < __Y ? __X : __Y;
    }
    template<class T, class R> void maximize(T &__X, R __Y)
    {
        __X = __X > __Y ? __X : __Y;
    }
    template<class T, class R> void minimize(T &__X, R __Y)
    {
        __X = __X < __Y ? __X : __Y;
    }
    template<class T> int getBit(T &__X, int __i)
    {
        return ((__X >> __i) & 1) == 1;
    }
    template<class T> bool inRange(T __L, T __R, T __X)
    {
        return __L <= __X && __X <= __R;
    }
    template<class T> T __abs(T __X)
    {
        return (__X < 0) ? -__X : __X;
    }
    template<class T> T __sqr(T __X)
    {
        return __X * __X;
    }
#endif
//Fast I/O
template<class T> inline void scan(T &__ret)
{
    __ret = T();
    char c = 0;
    bool neg = 0;

    while(isdigit(c) == 0 && c != '-') c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) __ret = __ret * 10 + c - '0';
    __ret = (neg) ? -__ret : __ret;
}
template<class T> void print(T __X)
{
    if(__X < 0)
    {
        putchar('-');
        __X *= -1;
    }

    if(__X > 9) print(__X / 10);
    putchar(__X % 10 + '0');
}

//=====================================
//Constants
const long long inf = 1e18+7;



//=====================================
//Typedefs
class ConvexHull
{
private:
    typedef long long ll;
    typedef pair<ll, ll> ii;

    struct Segment
    {
        ll x, a, b;
        Segment(): x(0LL), a(0LL), b(0LL) {}
        Segment(ll x, ll a, ll b): x(x), a(a), b(b) {}

        ll val() const
        {
            return (inf / a < x) ? inf : a * x + b;
        }
        bool operator< (const Segment &other) const
        {
            return this->val() <  other.val();
        }
        bool operator<= (const Segment &other) const
        {
            return this->val() <= other.val();
        }
    };
    deque<Segment> dq;

    inline ll div(ll a, ll b)
    {
        assert(b != 0);
        if(b < 0) a = -a, b = -b;
        assert(a >= 0);
        return (a / b + (a % b > 0));
    }

public:
    void insert(ll a, ll b)
    {
        if(dq.empty())
        {
            dq.push_back(Segment(0LL,   a, b));
            dq.push_back(Segment(inf/a, a, b));
            return;
        }

        int cur_sz = dq.size();
        while(!dq.empty() && dq.back() <= Segment(dq.back().x, a, b)) dq.pop_back();
        if(dq.size() == cur_sz) return;

        if(dq.empty())
        {
            dq.push_back(Segment(0LL,   a, b));
            dq.push_back(Segment(inf/a, a, b));
            return;
        }

        ll x = div(dq.back().b - b, a - dq.back().a);
        dq.push_back(Segment(x, a, b));
        dq.push_back(Segment(inf/a, a, b));
    }
    ii query(ll req, ll prev)
    {
        while(dq.size() > 1 && dq[1].x <= prev) dq.pop_front();
        int p = upper_bound(whole(dq), Segment(req, 1, 0)) - dq.begin();

        if(!p)
        {
            ll a = dq[p].a, b = dq[p].b;
            return ii(prev, a * prev + b);
        }

        ll a = dq[p-1].a;
        ll b = dq[p-1].b;
        ll x = div(req - b, a);
        return (x < dq[p].x ? ii(x, a * x + b)
                            : ii(dq[p].x, dq[p].val()));
    }


    ConvexHull() {}
};

//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef map<ll, ll> mii;
typedef pair<ll, ll> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vii a;
int n;
ll s;

//=====================================
//Functions and procedures
//File I/O and utilities
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    #ifdef DEBUG
        FILEOP_DEBUG()
    #else
        FILEOP()
    #endif
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}


//Enter
void Enter()
{
    vii tmp;

	cin >> n >> s;
	a = vii(n+1);
	FOR(i, 1, n)
	{
	    cin >> a[i].fi >> a[i].se;
	}


	sort(whole_1(a));
	FOR(i, 1, n) if(i == 1 || a[i].fi > a[i-1].fi) tmp.push_back(a[i]);
    n = tmp.size();
    FORl(i, 0, n) a[i+1] = tmp[i];

    tmp.clear();
	ll minv = inf;
	FORb(i, n, 1) if(a[i].se < minv)
	{
	    tmp.push_back(a[i]);
	    minv = a[i].se;
	}
	n = tmp.size();
	reverse(whole(tmp));
    FORl(i, 0, n) a[i+1] = tmp[i];
}

//Process
void Solve()
{
    ConvexHull cht;
    ii previ(0, 0);
    ll res = inf;

    FOR(i, 1, n)
    {
        cht.insert(a[i].fi, previ.se - a[i].fi * previ.fi - a[i].se);
        minimize(res, cht.query(s, previ.fi).fi);
        if(i < n) previ = cht.query(a[i+1].se, previ.fi);
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

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
