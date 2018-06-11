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
int n;
vvi g;
vi my;
vb vy;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d", &n);

	g = vvi(n, vi(n));

	FORl(i, 0, n) {
        FORl(j, 0, n) {
            scanf("%d", &g[i][j]);
        }
	}
}

//Check
bool DFS(int s, int lim) {
    FORl(u, 0, n) if(!vy[u] && g[s][u] <= lim) {
        vy[u] = true;
        if(my[u] == -1 || DFS(my[u], lim)) return my[u] = s, true;
    }
    return false;
}


//Process
void Solve() {
    int l = 0, h = 1000000000;
    while(l < h) {
        my = vi(n, -1);
        bool ok = true;
        int mid = (l + h) / 2;

        for(int i = 0; i < n && ok; ++i) {vy = vb(n, false); ok &= DFS(i, mid);}
        if(ok) h = mid;
        else l = mid + 1;
    }

    printf("%d", l);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
