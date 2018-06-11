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
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}

const int inf = 1e9;
//=====================================
//Typedefs
struct FenwickTree
{
    typedef vector<int> vi;
    vi minT, maxT;
    int n;

    #define _(x) ((x) & (-(x)))

    void update(bool type, int pos, int val)   //0 - min, 1 - max
    {
        for (; pos > 0; pos -= _(pos))
        {
            if (type) maxT[pos] = max(maxT[pos], val);
            else minT[pos] = min(minT[pos], val);
        }
    }
    int query(bool type, int pos)
    {
        int ret = (type) ? -inf : +inf;     //0 - min, 1 - max

        for (; pos < n; pos += _(pos))
        {
            if (type) ret = max(ret, maxT[pos]);
            else ret = min(ret, minT[pos]);
        }

        return ret;
    }


    ~FenwickTree() {}

    FenwickTree()
    {
        int __n = 100000;
        n = __n + 10;
        maxT = vi(__n + 10, -inf);
        minT = vi(__n + 10, +inf);
    }

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
int n, k, res, L, R;
vi a, val;
vii b;

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
	scanf("%d%d", &n, &k);

	int cnt = 0;

	b = vii(n+1);
	a = val = vi(n+1, 0);
	FOR(i, 1, n) scanf("%d", &a[i]), a[i] += a[i-1], b[i] = (ii(a[i], i));

    sort(whole(b));
    FOR(i, 0, n)
    {
        if(!i || b[i].fi != b[i-1].fi) cnt++;
        val[cnt] = b[i].fi;
        a[b[i].se] = cnt;
    }

}

//Check
bool check(int lim)
{
    int pos, mi, ma;
    FenwickTree ft;

    ft.update(0, a[0], 0);                  //0 - min, 1 - max
    ft.update(1, a[0], 0);

    FOR(i, 1, n)
    {
        pos = lower_bound(val.begin()+1, val.end(), val[a[i]] - lim) - val.begin();
        mi  = ft.query(0, pos) + 1;
        ma  = ft.query(1, pos) + 1;

        //cerr << i << sp << mi << sp << ma << el;

        ft.update(0, a[i], mi);
        ft.update(1, a[i], ma);
    }

    return mi <= k && k <= ma;
}

//Process
void Solve()
{
    L = -1e9;
    R = +1e9;

    while(L <= R)
    {
        int mid = (L + R) / 2;
        if(check(mid))
        {
            res = mid;
            R   = mid - 1;
        }
        else L  = mid + 1;

        //cerr << mid << el;
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
