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
vi STMax, STMin;
int n, q, res;
vi vect;


//=====================================
//Functions and procedures
//Segment Tree
int GetMaxVal(int l, int r, int si)
{
    if(l == r)
    {
        STMax[si] = vect[l];
        return vect[l];
    }

    int mid = (l + r) >> 1;
    STMax[si] = max(GetMaxVal(l, mid, si*2+1), GetMaxVal(mid + 1, r, si*2+2));
    return STMax[si];
}
int GetMinVal(int l, int r, int si)
{
    if(l == r)
    {
        STMin[si] = vect[l];
        return vect[l];
    }

    int mid = (l + r) >> 1;
    STMin[si] = min(GetMinVal(l, mid, si*2+1), GetMinVal(mid + 1, r, si*2+2));
    return STMin[si];
}


int QueMinU(int l, int r, int ql, int qr, int index)
{
    if(ql <= l && qr >= r) return STMin[index];
    if(r < ql || l > qr) return 1234567890;

    int mid = (l + r) >> 1;

    return min(QueMinU(l, mid, ql, qr, index*2+1), QueMinU(mid+1, r, ql, qr, index*2+2));
}
int QueMaxU(int l, int r, int ql, int qr, int index)
{
    if(ql <= l && qr >= r) return STMax[index];
    if(r < ql || l > qr) return -1234567890;

    int mid = (l + r) >> 1;

    return max(QueMaxU(l, mid, ql, qr, index*2+1), QueMaxU(mid+1, r, ql, qr, index*2+2));
}


void Build()
{
    STMax = vi(4*n+16);
    STMin = vi(4*n+16);
    GetMaxVal(1, n, 0);
    GetMinVal(1, n, 0);
}

int QMin(int l, int r)
{
    return QueMinU(1, n, l, r, 0);
}
int QMax(int l, int r)
{
    return QueMaxU(1, n, l, r, 0);
}

//Enter
void Enter()
{
	scanf("%d%d", &n, &q);
	vect.push_back(-1);
	FOR(i, 1, n)
	{
	    int x;
	    scanf("%d", &x);
	    vect.push_back(x);
	}
}

//Process
void Query()
{
    int l, r;
    FOR(k, 1, q)
    {
        scanf("%d%d", &l, &r);
        res = QMax(l, r) - QMin(l, r);
        printf("%d\n", res);
    }
}



//Main Procedure
int main()
{
    Enter();
    Build();
    Query();
    return 0;
}
