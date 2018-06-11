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
struct FenwickTree              //1-based
{
    typedef vector<int> vi;
    int n;

    vi T;

    void update(int pos, int val)
    {
        while(pos <= n)
        {
            T[pos] = max(T[pos], val);
            pos += pos & (-pos);
        }
    }
    int query(int pos)
    {
        int ret = 0;
        if(pos == 0) return 0;
        while(pos > 0)
        {
            ret = max(ret, T[pos]);
            pos -= pos & (-pos);
        }
        return ret;
    }

    ~FenwickTree() {T.clear();}

    FenwickTree(int __n) {T = vi(__n + 6); n = __n;}
    FenwickTree() {}

};


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi a, sorted, comp, F;
int n, res;


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
	scanf("%d", &n);
	a = comp = F = vi(n+1); a[0] = -1234567;

	FOR(i, 1, n) scanf("%d", &a[i]);
}

//Check
void Compress()
{
    sorted = a;
    sort(whole(sorted));

    FOR(i, 1, n) comp[i] = lower_bound(whole(sorted), a[i]) - sorted.begin();
}

//Process
void Solve()
{
    res = 0;
    Compress();
    FenwickTree ft(n);

    FOR(i, 1, n)
    {
        F[i] = ft.query(comp[i] - 1) + 1;
        res = max(res, F[i]);
        ft.update(comp[i], F[i]);
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
