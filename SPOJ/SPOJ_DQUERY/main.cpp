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
//Fenwick Tree
struct Query
{
    int l, r, id;

    Query(int __l, int __r, int __id): l(__l), r(__r), id(__id) {}
    Query() {}

    ~Query() {}

    bool operator < (const Query &other) const
    {
        return this->l < other.l;
    }
};
struct FenwickTree
{
    typedef vector<int> vi;

    int n;
    vi T;

    void update(int v)
    {
        for(; v <= n; v += v & (-v)) ++T[v];
    }
    int query(int v)
    {
        int ret = 0;
        for(; v > 0; v -= v & (-v)) ret += T[v];
        return ret;
    }

    FenwickTree(int __n)
    {
        n = __n;
        T = vi(__n + 6, 0);
    }
    FenwickTree() {}

    ~FenwickTree() {}
};

//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<Query> vq;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi last(1000007), res;
int n, nQuery;
vii vect;
vq q;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
    int u, v;

    scanf("%d", &n);

    vect.push_back(ii(-9999, -9999));
    q.push_back(Query(-99999, 0, 0));

    FOR(i, 1, n)
    {
        scanf("%d", &u);
        vect.push_back(ii(last[u], i));
        last[u] = i;
    }

    scanf("%d", &nQuery);
    res = vi(nQuery + 1);
    FOR(i, 1, nQuery)
    {
        scanf("%d%d", &u, &v);
        q.push_back(Query(u, v, i));
    }
}

//Process
void Solve()
{
    FenwickTree ft(n);

    sort(whole(q));
    sort(whole(vect));

    int pos = n;
    FORb(i, nQuery, 1)
    {
        Query x = q[i];
        while(vect[pos].fi >= x.l) ft.update(vect[pos--].se);
        res[x.id] = (x.r - x.l + 1) - (ft.query(x.r) - ft.query(x.l));
    }

    FOR(i, 1, nQuery) printf("%d\n", res[i]);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
