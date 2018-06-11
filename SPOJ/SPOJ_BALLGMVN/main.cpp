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
struct Point
{
	int x, y, id;
	Point(int __x, int __y, int __id)
	{
		x = __x, y = __y, id = __id + 1;
	}
	Point()
	{}

	bool operator < (const Point &other) const
	{
		return tie(this->x, this->y) < tie(other.x, other.y);
	}
	bool operator == (const Point &other) const
	{
		return (this->x == other.x && this->y == other.y);
	}

};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<Point> vp;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vp a, b;
int n;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
	int u, v;
	scanf("%d", &n);

	FORl(i, 0, n)
	{
		scanf("%d%d", &u, &v);
		a.pb(Point(u, v, i));
	}
	FORl(i, 0, n)
	{
		scanf("%d%d", &u, &v);
		b.pb(Point(u, v, i+n));
	}

}

//Check
int gcd(int _a, int _b)
{
	int r;
	if(_a < 0) _a = -_a;
	if(_b < 0) _b = -_b;

	while(_b > 0) r = _a % _b, _a = _b, _b = r;
	return _a;
}
void Normalize(Point &t)
{
	if(t.y == 0) t.x = 1;
	else if(t.x == 0) t.y = 1;
	else
	{
		if(t.y < 0) t.y = -t.y, t.x = -t.x;
		int g = gcd(t.x, t.y);
		t.x /= g;
		t.y /= g;
	}
}
bool Find(const Point a, const vp &_b)
{
	vp c(n);
	FORl(i, 0, n)
	{
		c[i].x = _b[i].x - a.x;
		c[i].y = _b[i].y - a.y;
		c[i].id = _b[i].id;
		Normalize(c[i]);
	}

	sort(whole(c));
	FORl(i, 1, n)
	{
		if(c[i] == c[i-1])
		{
			printf("%d %d %d\n", c[i].id, c[i-1].id, a.id);
			return true;
		}
	}
	return false;
}

//Process
void Solve()
{
	for(Point p: b) if(Find(p, a)) return;
	for(Point p: a) if(Find(p, b)) return;
	printf("-1");
}

//Main Procedure
int main()
{
	Enter();
	Solve();
    return 0;
}
