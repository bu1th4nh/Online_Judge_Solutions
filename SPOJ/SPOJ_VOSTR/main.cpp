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

/*const long long BASE = (long long)(1e15 + 37);*/
const int N = 1e6 + 10;
const int BASE = 29;
//=====================================
//Typedef
typedef unsigned ll;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;

vll PowerXXX;

//=====================================
//Hashing
class HASH
{
public:
	vll Hash;

	void InitHash(string t)
	{
		Hash = vll(t.length() + 1, 0LL);
		FORl(i, 1, t.length())
		{
			Hash[i] = Hash[i-1] * BASE + t[i];
		}
	}

	HASH(string t)
	{
		InitHash(t);
	}
	HASH() {}

	void insert(string t)
	{
		InitHash(t);
	}
	ll get(int __i, int __j)
	{
		return Hash[__j] - Hash[__i - 1] * PowerXXX[__j - __i + 1];
	}
};

//=====================================
//Variable declaration
int an, bn, u, v, nQuery;
string a, b;
HASH ha, hb;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	char st[1048576];
	scanf("%d%d", &an, &bn);
	scanf("%s", &st); a = string(st); a = ' ' + a;
	scanf("%s", &st); b = string(st); b = ' ' + b;
	scanf("%d", &nQuery);

}


//Process
void InitBase()
{
	PowerXXX = vll(N, 0LL);
	PowerXXX[0] = 1;
	FOR(i, 1, N) PowerXXX[i] = PowerXXX[i-1] * BASE;
}

void Query(int la, int ra, int lb, int rb)
{
    int lena = ra - la + 1, lenb = rb - lb + 1, pos = 0;

    for(int l = 1, r = min(lena, lenb); l <= r;)
    {
    	int mid = (l + r) >> 1;
    	if(ha.get(la, la + mid - 1) == hb.get(lb, lb + mid - 1))
    	{
    		pos = mid;
    		l = mid + 1;
    	}
    	else
    	{
    		r = mid - 1;
    	}
    }

    if(lena == lenb)
    {
    	if(pos == lena)
    	{
    		cout << '=';
    	}
    	else
    	{
    		if(a[la + pos] < b[lb + pos]) cout << '<';
    		else cout << '>';
    	}
    }
    else
    {
    	if(pos == min(lena, lenb))
    	{
    		if(lena < lenb) cout << '<';
    		else cout << '>';
    	}
    	else
    	{
    		if(a[la + pos] < b[lb + pos]) cout << '<';
    		else cout << '>';
    	}
    }

}
void Solve()
{
    InitBase();

	int ua, va, ub, vb;
    ha = HASH(a);
    hb = HASH(b);

    while(nQuery--)
    {
    	scanf("%d%d%d%d", &ua, &va, &ub, &vb);
    	Query(ua, va, ub, vb);
    }
}


//Main Procedure
int main()
{
	Enter();
	Solve();
    return 0;
}

/*
13 14
bomthichdacau
bomthichdabanh
3
1 10 1 10
1 10 1 11
1 11 1 11
*/
