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


#define id second
#define x first.first
#define y first.second

//=====================================
//Fenwick Tree
struct FenwickTree
{
    typedef vector<int> vi;

    int n;
    vi T;

    void update(int pos)
    {
        for(; pos <= n; pos += pos & (-pos)) ++T[pos];
    }
    int query(int pos)
    {
        int ret = 0;
        for(; pos > 0; pos -= pos & (-pos)) ret += T[pos];
        return ret;
    }


    ~FenwickTree() {T.clear();}

    FenwickTree() {}
    FenwickTree(int __n, int __val = 0)
    {
        T = vi(__n + 1, __val);
        n = __n;
    }
};


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<iii> viii;
viii vect;
vi res;
int n;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d", &n);

    res = vi(n+1);
    vect = viii(n+1);

    FOR(i, 1, n)
    {
        scanf("%d%d", &vect[i].x, &vect[i].y);
        vect[i].id = i;
    }
}

//Process
void Solve()
{
    FenwickTree ft(131072);
    sort(whole(vect));

    ft.update(vect[1].y);
    ll ce = 1;

    FOR(i, 2, n)
    {
        if(vect[i].x != vect[i-1].x || vect[i].y != vect[i-1].y) ce = 0;
        ft.update(vect[i].y);
        ++ce;
        res[vect[i].id] = ft.query(vect[i].y) - ce;
    }

    FOR(i, 1, n) cout << res[i] << "\n";
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
