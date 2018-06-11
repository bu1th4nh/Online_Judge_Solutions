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
#include <valarray>
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
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef valarray<int> va;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<va> vva;
typedef vector<vii> vvii;
typedef map<va, int> mvai;

//=====================================
namespace std
{
    bool operator < (const va &a, const va &b)
    {
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
}

//=====================================
//Functions and procedures
//Process
va sum(const vva &a, int st)
{
    va res = {{0, 0}};
    for(auto &x: a)
    {
        if(st & 1) res += x;
        st >>= 1;
    }
    return res;
}

//Main Procedure
int main()
{
    int n, n1, n2;
    scanf("%d", &n);

    vva a((n1 = n / 2), va(2));
    for(va &x: a) scanf("%d%d", &x[0], &x[1]);

    vva b((n2 = n - n1), va(2));
    for(va &x: b) scanf("%d%d", &x[0], &x[1]);

    va S(2); scanf("%d%d", &S[0], &S[1]);

    mvai cnt;
    FORl(st, 0, (1 << n1)) cnt[sum(a, st)] += 1;

    int res = 0;
    FORl(st, 0, (1 << n2))
    {
        va s = sum(b, st);
        if(cnt.count(S - s)) res += cnt[S - s];
    }

    cout << res;

    return 0;
}
