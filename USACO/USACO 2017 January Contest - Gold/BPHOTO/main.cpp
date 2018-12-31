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
#define task "bphoto"
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
#define FILEOP() {freopen(task".in", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
//Typedefs
template<class T, bool IS_REVERSE> struct FenwickTree
{
    #define _(x) x&(-x)
    typedef vector<T> vt;

    vt bit;
    int n;

    void update(int pos, T value)
    {
        if(IS_REVERSE)
        {
            for(; pos > 0; pos -= _(pos)) bit[pos] += value;
        }
        else
        {
            for(; pos <= n; pos += _(pos)) bit[pos] += value;
        }
    }
    T query(int pos)
    {
        T ret = T();
        if(IS_REVERSE)
        {
            for(; pos <= n; pos += _(pos)) ret += bit[pos];
        }
        else
        {
            for(; pos > 0; pos -= _(pos)) ret += bit[pos];
        }
        return ret;
    }


    FenwickTree(int __n)
    {
        n = __n;
        bit = vt(n+1, T());
    }
    FenwickTree() {}

    ~FenwickTree() {}
};



//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi a, sorted, ca, L, R;
int n, res;


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
	scanf("%d", &n);
	a = ca = L = R = vi(n+1, 0);

	FOR(i, 1, n) scanf("%d", &a[i]);
}

//Check
void Solve()
{
    sorted = a;

    sort(whole(sorted));
    FOR(i, 1, n) ca[i] = lower_bound(whole(sorted), a[i]) - sorted.begin();

    FenwickTree<int, true> ft1(n);
    FenwickTree<int, true> ft2(n);

    FOR(i, 1, n)
    {
        L[i] = ft1.query(ca[i]);
        ft1.update(ca[i], 1);
    }
    FORb(i, n, 1)
    {
        R[i] = ft2.query(ca[i]);
        ft2.update(ca[i], 1);
    }

    res = 0;

//    cerr << el;
//    FOR(i, 1, n) cerr << ca[i] << sp; cerr << el;
//    cerr << el;
//    FOR(i, 1, n) cerr << L[i] << sp; cerr << el;
//    FOR(i, 1, n) cerr << R[i] << sp; cerr << el;


    FOR(i, 1, n) if(min(L[i], R[i]) * 2 < max(L[i], R[i])) ++res;
    cout << res << el;
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
