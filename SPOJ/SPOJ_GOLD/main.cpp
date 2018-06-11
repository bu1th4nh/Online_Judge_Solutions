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


const int Abs = 30000;
const int m_X = 100000;
//=====================================
//Segment Tree
struct SegmentTree
{
    #define lc id*2+1
    #define rc id*2+2
    typedef vector<int> vi;

    vi ST, com;

    void update(int id, int l, int r, int x, int y, int delta)
    {
        if(r <= x || r <= l || y <= l) return;
        if(x <= l && r <= y)
        {
            ST[id] += delta;
            com[id] += delta;
            return;
        }

        int mid = (l + r) / 2;
        update(lc, l, mid, x, y, delta);
        update(rc, mid, r, x, y, delta);

        ST[id] = max(ST[lc], ST[rc]) + com[id];
    }

    SegmentTree()
    {
        ST = com = vi(262144, 0);
    }

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
int n, s, w, res;
ii gold[16384];


//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d%d%d", &s, &w, &n);
    FORl(i, 0, n) scanf("%d%d", &gold[i].first, &gold[i].second), gold[i].second += Abs;
}

//Process
void Solve()
{
    res = 0;
    SegmentTree st;
    sort(gold, gold + n);

    for(int l = 0, r = 0; r < n; ++r)
    {
        while(gold[l].first + s < gold[r].first)
        {
            st.update(0, 0, m_X, gold[l].se, gold[l].se + w + 1, -1), ++l;
        }
        st.update(0, 0, m_X, gold[r].se, gold[r].se + w + 1, 1);
        res = max(res, st.ST[0]);
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
