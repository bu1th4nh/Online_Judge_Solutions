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
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define sp ' '
#define el '\n'
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


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef unordered_map<string, int> msi;
typedef pair<int, int> ii;
typedef pair<int , ii> iii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<iii> viii;
int nTest;


//=====================================
//Functions and procedumst
struct MinSpanningTree
{
    struct DisjointSet
    {
        vi lab;
        int n;

        DisjointSet() {}
        DisjointSet(int __n)
        {
            n = __n;
            lab = vi(__n+12, -1);
        }

        int find(int u)
        {
            return (lab[u] < 0) ? u : (lab[u] = find(lab[u]));
        }
        bool unify(int u, int v)
        {
            int r = find(u);
            int s = find(v);

            if(r != s)
            {
                if(lab[s] < lab[r]) swap(r, s);
                lab[r] += lab[s];
                lab[s] = r;

                return true;
            }
            return false;
        }
    };

    viii EdgeList;
    int n, mst;

    void addEdge(int u, int v, int c)
    {
        EdgeList.push_back(iii(c, ii(u, v)));
    }
    void initKruskal()
    {
        DisjointSet ds(n);

        mst = 0;
        sort(whole(EdgeList));
        for(auto x: EdgeList)
        {
            if(ds.unify(x.se.fi, x.se.se)) mst += x.fi;
        }
    }
    int extract() {return mst;}


    MinSpanningTree() {}
    MinSpanningTree(int __n)
    {
        n = __n;
        EdgeList.clear();
    }

};


//Process
void Solve()
{
    int m, n, x, u, v, cur_vtx = 0;
    msi mp;

    scanf("%d%d", &n, &m);
    MinSpanningTree mstt(n);
    FOR(i, 1, m)
    {
        string a, b; cin >> a >> b >> x;
        if(mp[(a)] == 0) u = mp[(a)] = ++cur_vtx;
        else u = mp[(a)];
        if(mp[(b)] == 0) v = mp[(b)] = ++cur_vtx;
        else v = mp[(b)];

        mstt.addEdge(u, v, x);

        //cout << u << sp << v << el;
    }

    mstt.initKruskal();
    cout << mstt.extract() << el;
}

//Main Procedure
int main()
{
    cin >> nTest;
    FOR(iTest, 1, nTest)
    {
        if(iTest > 1) puts("");
        Solve();
    }
    return 0;
}
