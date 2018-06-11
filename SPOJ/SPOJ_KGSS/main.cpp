//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
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
#define MODUL (int)(1e9+57)
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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int n, q;
vi vect;
vii st;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d", &n);
    st = vii(4*n, ii(0, 0));
    vect.push_back(-98766543);
    FOR(i, 1, n)
    {
        int x;
        scanf("%d", &x);
        vect.push_back(x);
    }
    scanf("%d", &q);
}

//Segment Tree
void Build(int id, int l, int r)
{
    if(l == r)
    {
        st[id] = ii(vect[l], 0);
        return;
    }
    int mid = (l+r)/2;
    Build(id*2, l, mid);
    Build(id*2+1, mid+1, r);
    int x1 = st[id*2].fi;
    int x2 = st[id*2].se;
    int y1 = st[id*2+1].fi;
    int y2 = st[id*2+1].se;
    st[id] = (x1 > y1) ? ii(x1, max(y1, max(x2, y2) ) ) : ii(y1, max(x1, max(x2, y2) ) );
}
void Update(int id, int l, int r, int i, int x)
{
    if(l > i || r < i) return;
    if(l==i && r==i)
    {
        st[id].fi = x;
        return;
    }
    int mid = (l+r)/2;
    Update(id*2, l, mid, i, x);
    Update(id*2+1, mid+1, r, i, x);
    int x1 = st[id*2].fi;
    int x2 = st[id*2].se;
    int y1 = st[id*2+1].fi;
    int y2 = st[id*2+1].se;
    st[id] = (x1 > y1) ? ii(x1, max(y1, max(x2, y2) ) ) : ii(y1, max(x1, max(x2, y2) ) );
}
ii Query(int id, int l, int r, int ql, int qr)
{
    if(l > qr || r < ql)
    {
        return ii(0, 0);
    }
    if(l >= ql && r <= qr)
    {
        return st[id];
    }
    int mid = (l+r)/2;
    ii t1 = Query(id*2, l, mid, ql, qr);
    ii t2 = Query(id*2+1, mid+1, r, ql, qr);
    int x1 = t1.fi;
    int x2 = t1.se;
    int y1 = t2.fi;
    int y2 = t2.se;
    ii lres = (x1 > y1) ? ii(x1, max(y1, max(x2, y2) ) ) : ii(y1, max(x1, max(x2, y2) ) );
    return lres;
}

//Process
void Solve()
{
    Build(1, 1, n);
    FOR(iquery, 1, q)
    {
        char t;
        cin >> t;
        if(t == 'U')
        {
            int i, k;
            scanf("%d%d", &i, &k);
            Update(1, 1, n, i, k);
        }
        else if(t == 'Q')
        {
            int u, v;
            scanf("%d%d", &u, &v);
            ii res = Query(1, 1, n, u, v);
            printf("%d\n", (res.first+res.second));
        }
    }
}



//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
