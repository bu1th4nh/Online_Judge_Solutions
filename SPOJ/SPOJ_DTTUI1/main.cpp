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
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;


//=====================================
struct pck {ll v, w;};
typedef vector<pck> vp;
void operator += (pck &a, const pck &b)
{
    a.w += b.w;
    a.v += b.v;
}
bool operator < (const pck &a, const pck &b)
{
    return a.w < b.w;
}
vi w, v;
vp a, b;
int n;
ll m;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d%lld", &n, &m);
	int n1 = n / 2, n2 = n - n1;

	a = vp(n1), b = vp(n2);

	for(pck &x: a) scanf("%lld%lld", &x.w, &x.v);
	for(pck &x: b) scanf("%lld%lld", &x.w, &x.v);
}

//Check
vp gen(const vp &x, ll y)
{
    vp re(1 << x.size());
    int n = 0;

    FORl(i, 0, re.size())
    {
        pck tmp = {0, 0};
        FORl(k, 0, x.size())
        {
            if(i&(1 << k)) tmp += x[k];
        }
        if (tmp.w <= y) re[n++] = tmp;
    }

    re.resize(n);
    sort(whole(re));
    return re;
}

//Process
void Solve()
{
    vp f = gen(a, m);
    vp g = gen(b, m);

    ll res = 0, mval = 0;

    for(int i = f.size()-1, j = 0; i>=0; i--)
    {
        while(j < (int)(g.size()) && f[i].w + g[j].w <= m)
        {
            mval = max(mval, g[j].v);
            j++;
        }
        res = max(res, mval + f[i].v);
    }


    printf("%lld\n", res);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
