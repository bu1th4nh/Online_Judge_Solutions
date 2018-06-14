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
#define whole(x) x.begin()+1, x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
//Disjoint Set
struct DisjointSet
{
    typedef vector<int> vi;
    int n;
    vi lab;

    int find(int u)
    {
        return (lab[u] == u) ? u : (lab[u] = find(lab[u]));
    }
    void union_set(int u, int v)
    {
        lab[v] = u;
    }

    DisjointSet(int __n)
    {
        lab = vi(__n+1, 0);
        FOR(i, 1, __n) lab[i] = i;
    }
    DisjointSet() {}

    ~DisjointSet() {}
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
vi val, par;
int m, n;
vii vect;


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
    string q;
    val.push_back(-999);
	scanf("%d%d", &n, &m);

	vect = vii(m+1);
	par  = vi(m+1);

	FOR(i, 1, m)
	{
	    scanf("%d%d", &vect[i].fi, &vect[i].se);
	    cin >> q;
	    par[i] = (q == "odd") ? 1 : 0;

	    val.push_back(vect[i].fi - 1);
	    val.push_back(vect[i].se);
	}
}

//Check
void Solve()
{
    int u, v, r1, r2, r3, r4;
    sort(whole(val));
    DisjointSet ds(2 * (val.size() - 1));

    FOR(i, 1, m)
    {
        u = lower_bound(whole(val), vect[i].fi - 1) - val.begin();
        v = lower_bound(whole(val), vect[i].se) - val.begin();

        r1 = ds.find(2*u - 1), r2 = ds.find(2*v - 1);
        r3 = ds.find(2*u), r4 = ds.find(2*v);

        if(par[i] == 0)
        {
            if(r1 == r4 || r2 == r3)
            {
                cout << i-1;
                return;
            }

            ds.union_set(r2, r1);
            ds.union_set(r4, r3);
        }
        else
        {
            if(r1 == r2 || r3 == r4)
            {
                cout << i-1;
                return;
            }

            ds.union_set(r4, r1);
            ds.union_set(r2, r3);
        }
    }

    cout << m;
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
