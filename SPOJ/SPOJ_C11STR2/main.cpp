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
#define MODUL (int)(1000000009)
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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
ll ha[134072], hb[134072], p[134072];
ll MM = 1LL*MODUL*MODUL;
int m, n, mn, k;
ll base = 101;
string a, b;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	getline(cin, a);
	getline(cin, b);
	m = a.length(), n = b.length();
	a = ' ' + a, b = ' ' + b;
	mn = max(m, n);
	k  = min(m, n);
}

//Process
void Solve()
{
    p[0] = 1;

    FOR(i, 1, mn) p[i] = (p[i-1]*base)%MODUL;
    FOR(i, 1, m) ha[i] = (ha[i-1]*base + a[i]) % MODUL;
    FOR(i, 1, n) hb[i] = (hb[i-1]*base + b[i]) % MODUL;

    int pos = 0;
    FORb(i, k, 1)
    {
        ll sb = hb[i];
        ll sa = (ha[m] - ha[m-i]*p[i] + MM) % MODUL;

        if(sa == sb)
        {
            pos = i;
            break;
        }
    }
    a.erase(0, 1);
    printf("%s", a.c_str());
    FOR(i, pos+1, n) printf("%c", b[i]);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
