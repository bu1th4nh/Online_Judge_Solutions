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

const int inf = 2147483210;
//=====================================
class SegmentTree
{
private:

public:
    vector<int> ST;

    SegmentTree(int __n)
    {
        ST = vector<int> (4 * __n + 16, 0);
    }
    SegmentTree() {}



    void update(int id, int l_bound, int r_bound, int pos, int val)
    {
        if(pos < l_bound || pos > r_bound) return;

        ST[id] = max(ST[id], val);

        if(l_bound == r_bound) return;


        int mid = (l_bound + r_bound) / 2;

        update(id*2, l_bound, mid, pos, val);
        update(id*2+1, mid+1, r_bound, pos, val);
    }
    int query(int id, int l_bound, int r_bound, int l_query, int r_query)
    {
        if(r_query <  l_bound || l_query >  r_bound) return 0;
        if(l_query <= l_bound && r_query >= r_bound) return ST[id];

        int mid = (l_bound + r_bound) / 2;
        return max(query(id * 2, l_bound, mid, l_query, r_query)   ,    query(id * 2 + 1, mid + 1, r_bound, l_query, r_query));
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
int a[30007], F[30007], b[30007], compressed[30007];
int n, res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d", &n);
    FOR(i, 1, n)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
}


//Check
void Compressor()
{
    sort(b+1, b+n+1);

    FOR(i, 1, n)
    {
        compressed[i] = lower_bound(b+1, b+n+1, a[i]) - b;
//        cout << compressed[i] << " ";
    }
//        puts("");
}

//Process
void Solve()
{
    res = 0;
    SegmentTree st(n+1);
    Compressor();
    FOR(i, 1, n)
    {
        F[i] = st.query(1, 1, n, 1, compressed[i]-1) + 1;
        res = max(res, F[i]);
        st.update(1, 1, n, compressed[i], F[i]);


//        cout << F[i] << " ";


    }

//    puts("");
//
//    for(int x: st.ST) cout << x << " "; puts("");

    cout << res;

}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
