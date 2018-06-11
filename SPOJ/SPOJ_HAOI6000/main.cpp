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


const int inf = 1e9 + 7;
const int nextx[4] = {-1, 0, 1, 0};
const int nexty[4] = {0, 1, 0, -1};
const int mve[4][2] = {{2, 1}, {2, 3}, {0, 3}, {0, 1}};
//=====================================
//Typedef
struct Point
{
	int x, y, z;
	Point(int __x, int __y, int __z)
	{
		x = __x, y = __y, z = __z;
	}
};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef queue<Point> qp;
typedef vector<vii> vvii;
int F[1024][1024][4] = {0};
int n, m, a[1024][1024];
qp que;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d%d", &m, &n);
	FORl(i, 0, m)
	{
		FORl(j, 0, n)
		{
			scanf("%d", &a[i][j]);
		}
	}

	FORl(i, 0, n)
	{
		if(a[0][i] == 0)
		{
			F[0][i][0] = 1;
			que.push(Point(0, i, 0));
		}
		else
		{
			F[0][i][3] = 1;
			que.push(Point(0, i, 3));
		}
	}
}

//Check
bool Check(int __i, int __j)
{
	return (__i >= 0 && __j >= 0 && __i < m && __j < n);
}

//Process
void FloodFill()
{
    int curx, cury, curid, x, y, id;
	while(!que.empty())
	{
		curx = que.front().x, cury = que.front().y, curid = que.front().z;
		que.pop();

		FOR(i, curid, curid + 1)
		{
		    x = curx + nextx[i % 4];
		    y = cury + nexty[i % 4];

		    if(Check(x, y))
            {
                id = mve[i % 4][a[x][y]];

                if(!F[x][y][id])
                {
                    F[x][y][id] = F[curx][cury][curid] + 1;
                    que.push(Point(x, y, id));
                }
            }
		}
	}
}

void Solve()
{
    FloodFill();
    int res = inf, num = 0;
    FORl(j, 0, n)
    {
        FOR(t, 1, 2)
        {
            if(F[m-1][j][t] && F[m-1][j][t] < res)
            {
                res = F[m-1][j][t];
                num = 1;
            }
            else if(F[m-1][j][t] == res) ++num;
        }
    }

    if(res < inf) printf("%d %d", res, num);
    else printf("0 0");
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
