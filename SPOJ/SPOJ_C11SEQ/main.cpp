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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
ll res, L, R, a[131072];
int n, F[131072];
vll X;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int x;
	scanf("%d%lld%lld", &n, &L, &R);

	X.push_back(0);
	FOR(i, 1, n)
	{
	    scanf("%d", &x);
	    a[i] = a[i-1] + x;
	    X.push_back(a[i]);
	}
}

//Binary Indexed Tree
void Add(int x)
{
    x++;
    while(x <= int(X.size())) F[x]++, x += x & -x;
}
int Get(int x)
{
    int r = 0;
    x++;
    while(x) r += F[x], x -= x&-x;
    return r;
}

//Process
void Solve()
{
    int x;
    res = 0;
    sort(whole(X));
    X.resize(unique(whole(X)) - X.begin());
    FOR(i, 0, n)
    {
        if(i)
        {
            int low = lower_bound(whole(X), a[i] - R) - X.begin();
            int hig = upper_bound(whole(X), a[i] - L) - X.begin();
            if(low < hig) res += Get(hig - 1) - Get(low - 1);
        }
        x = lower_bound(whole(X), a[i]) - X.begin();
        Add(x);
    }
    printf("%lld\n", res);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
