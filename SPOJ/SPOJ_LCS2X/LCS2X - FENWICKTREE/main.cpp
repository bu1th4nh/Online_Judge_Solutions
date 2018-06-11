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

    FenwickTree(int __n) {T = vi(__n + 6, 0); n = __n;}
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
vi a, b, X, Y, sorted, comp, P;
FenwickTree ft, pre_ft;
int tc;


//=====================================
//Functions and procedures
//Process
void Solve_2()
{
    int m, n, res;
	int prev_max = 0, cur_max = 0;

	scanf("%d%d", &m, &n);

    a = vi(m+1);
    X = Y = P = b = comp = vi(n+1);

	FOR(i, 1, m) scanf("%d", &a[i]);
	FOR(i, 1, n) scanf("%d", &b[i]);
	sorted = b; sort(whole(sorted));
    FOR(i, 1, n) comp[i] = lower_bound(whole(sorted), b[i]) - sorted.begin();

	res = 0;

	int id = 0;
    FOR(i, 1, n)
    {
        id = 0;
        FOR(j, 1, i-1) if(b[j]*2 <= b[i] && b[j] > b[id]) id = j;
        P[i] = comp[id];
    }

    ft = pre_ft = FenwickTree(n);

    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            if(a[i] == b[j])
            {
                X[j] = max(1, pre_ft.query(P[j]) + 1);
                ft.update(comp[j], X[j]);
            }
            res = max(res, X[j]);
        }
        pre_ft = ft;
    }

    printf("%d\n", res);
}

//Main Procedure
int main()
{
	scanf("%d", &tc);
	while(tc--)
	{
		Solve_2();
	}
    return 0;
}
