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

const long long MODUL = 1000000000;
//=====================================
//Fenwick Tree
struct FenwickTree              //1-based
{
    typedef vector<long long> vi;

    int n;
    vi T;

    void update(int pos, long long x)
    {
        for(; pos <= n; pos += pos & (-pos)) (T[pos] += x) % MODUL;
    }
    long long query(int pos)
    {
        long long ret = 0;
        for(; pos >= 1; pos -= pos & (-pos)) ret += T[pos];
        return (ret % MODUL);
    }
    void reset() {T.assign(n+1, 0);}



    ~FenwickTree() {T.clear();}

    FenwickTree(int __n) {T = vi(__n + 1, 0); n = __n;}
    FenwickTree() {}

};


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi F, G, a;
int n, k;
ll res;

//=====================================
//Functions and procedures
//Sequence Compression
void Compress(vi &vect)
{
    set<ll> s(whole(vect));
    vi b(whole(s));
    for(ll &x: vect) x = b.end() - lower_bound(whole(b), x);
}


//Main Procedure
int main()
{
    scanf("%d%d", &n, &k); a = vi(n);
    for(ll &x: a) scanf("%lld", &x);

    Compress(a);

    FenwickTree ft(n);

    F = vi(n, 1);
    G = vi(n);


    while(--k)
    {
        G.assign(n, 0);
        ft.reset();

        FORl(i, 0, n)
        {
            G[i] = ft.query(a[i] - 1);
            ft.update(a[i], F[i]);
        }
        swap(F, G);
    }

    res = 0;
    for(int x: F) res += x;
    res = res % MODUL;
    printf("%lld\n", res);

    return 0;
}
