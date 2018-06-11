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
#define MODUL (int)(1000000000)
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
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int n, h, res1;
vi vect;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
	int x;
	res1 = 2;
	scanf("%d%d", &n, &h);
	FOR(i, 1, n)
	{
	    scanf("%d", &x);
	    vect.push_back(x);
	}
	FORb(i, n-2, 0)
	{
	    if(vect[i] < vect[i+1]) ++res1;
	    else break;
	}
}

//Check
ll PoWeR(ll x, int _n)
{
    if(_n == 0) return 1;
    ll t = PoWeR(x, _n >> 1);
    t = t*t%MODUL;
    if(_n&1) return (t*x%MODUL);
    return t;
}
int Analyzr(int x, int p)
{
    int lres = 0;
    while(x % p == 0) ++lres, x/=p;
    return lres;
}
ll catalan(int _n)
{
    vb prime(2*_n+1, true);
    vi cnt(2*_n+1, 0);
    FOR(i, 2, _n*2)
    {
        if(prime[i])
        {
            int c = 0;
            for(int j = i; j<=2*_n; j+=i)
            {
                prime[j] = false;
                if(_n+2 <= j) c += Analyzr(j, i);
                if(j <= _n) c -= Analyzr(j, i);
            }
            cnt[i] = c;
        }
    }
    ll lres = 1;
    FOR(i, 1, 2*_n)
    {
        lres = lres * PoWeR(i, cnt[i]) % MODUL;
    }
    return lres;
}


//Process
void Solve()
{
    printf("%d\n",   res1);
    ll res2 = catalan(n+1);
    printf("%d  ",   res2);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
