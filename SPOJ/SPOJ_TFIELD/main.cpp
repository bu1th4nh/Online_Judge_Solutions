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
typedef long long ll;
struct Data
{
    int col;
    ll s;

    Data(int _c, ll _s): s(_s), col(_c) {}
    Data() {col = 0, s = 0LL;}

    bool operator < (const Data &other) const
    {
        return this->s < other.s;
    }
};
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<Data> vd;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi d, sum;
int n, k;
vd vect;
vvii a;
ll res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;
    scanf("%d%d", &n, &k);

    a = vvii(n+1);
    vect = vd(n+1);
    d = sum = vi(n+10);

    FOR(i, 1, n)
    {
        vii poly;
        scanf("%d%d", &d[i], &vect[i].col);
        poly.push_back(ii(0, 0));
        FOR(j, 1, d[i])
        {
            scanf("%d%d", &u, &v);
            poly.push_back(ii(u, v));
        }
        a[i] = poly;
    }
}


//Process
void GetArea(int k)
{
    d[k]++;
    a[k].push_back(a[k][1]);
    FOR(i, 2, d[k])
    {
        vect[k].s += (1LL * (a[k][i].fi - a[k][i-1].fi) * (a[k][i].se + a[k][i-1].se));
    }
    if (vect[k].s<0) vect[k].s=-vect[k].s;


    //cout << vect[k].s << "\n";
}

void Solve()
{
    res = 0LL;
    int r;

    FOR(i, 1, n) GetArea(i);
    sort(whole(vect));

    sum[n+1] = 1000000007;
    FOR(i, 1, n)
    {
        sum[0] = 0;
        FOR(j, 1, n)
        {
            if(vect[j].col != i) sum[j] = sum[j-1] + 1;
            else sum[j] = sum[j-1];
        }

        r = 1;
        FOR(l, 1, n)
        {
            while(sum[r+1] - sum[l-1] <= k) ++r;
            res = max(res, vect[r].s - vect[l-1].s);
        }
    }

    //FOR(i, 1, n) cout << vect[i].s << " ";
    //for(Data x: vect) printf("%d %lld\n", x.col, x.s);

    printf("%lld", res/2);
    if(res % 2 == 1) printf(".5");
    else printf(".0");
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
