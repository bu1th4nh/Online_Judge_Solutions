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
int nUpdate, nQuery, n;
vi SegTree, vect;


//=====================================
//Functions and procedures
//Segment Tree
void Update(int id, int l, int r)
{
    if(l == r)
    {
        SegTree[id] = vect[l];
        return;
    }
    int mid = (l+r)/2;
    Update(id*2, l, mid);
    Update(id*2+1, mid+1, r);
    SegTree[id] = max(SegTree[id*2], SegTree[id*2+1]);
}
int Query(int id, int l, int r, int ql, int qr)
{
    if((qr < l) || (r < ql)) return -INFINITY;
    if((ql <= l) && (r <= qr)) return SegTree[id];
    int mid = (l + r)/2;
    return max(Query(id*2, l, mid, ql, qr), Query(id*2+1, mid+1, r, ql, qr));
}

//Enter
void Enter()
{
	scanf("%d%d", &n, &nUpdate);
	SegTree = vi(4*n+3, 0);
	vect = vi(n+3, 0);
	FOR(i, 1, nUpdate)
	{
	    int u, v, k;
	    scanf("%d%d%d", &u, &v, &k);
	    vect[u] += k;
	    vect[v+1] -= k;
	}
	scanf("%d", &nQuery);
	FOR(i, 1, n) vect[i] += vect[i-1];
}


//Process
void Solve()
{
    Update(1, 1, n);
    FOR(ifdgfhjh, 1, nQuery)
    {
        int u, v, res;
        scanf("%d%d", &u, &v);
        res = Query(1, 1, n, u, v);
        printf("%d\n", res);
    }
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
