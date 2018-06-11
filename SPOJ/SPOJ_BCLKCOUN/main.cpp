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
#define maxinp (int)(128)
#define MODUL (int)(1e9+57)
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef queue<ii> qii;
typedef long long ll;
const int nextx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int nexty[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool mark[maxinp][maxinp];
string a[maxinp];
int n, m, res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	MEMS(mark, false);
	scanf("%d%d", &n, &m);
	FOR(i, 1, n)
	{
        cin >> a[i];
        a[i] = '0' + a[i];
	    FOR(j, 1, m)
	    {
	        mark[i][j] = (a[i][j] == 'W');
	    }
	}
}

//Flood Fill
void FloodFill(int _x, int _y)
{
    qii dir;
    mark[_x][_y] = false;
    dir.push(ii(_x, _y));

    while(!dir.empty())
    {
        ii cur = dir.front();
        dir.pop();

        int curx = cur.first;
        int cury = cur.second;

        FOR(k, 0, 7)
        {
            int u = curx + nextx[k];
            int v = cury + nexty[k];
            if((u >= 1) && (u <= n) && (v >= 1) && (v <= m) && mark[u][v])
            {
                mark[u][v] = false;
                dir.push(ii(u, v));
            }
        }
    }
}


//Process
void Solve()
{
    res = 0;
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            if(mark[i][j])
            {
                ++res;
                FloodFill(i, j);
            }
        }
    }
    printf("%d", res);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
