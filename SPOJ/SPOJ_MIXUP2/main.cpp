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
#define maxinp (int)(17)
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
typedef long long ll;
ll F[1 << 16][maxinp];
int n, k;
vi vect;
ll res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	int x;
	scanf("%d%d", &n, &k);
	FOR(i, 1, n)
	{
	    scanf("%d", &x);
	    vect.push_back(x);
	}
}

//Bit Manipulation
int GetBit(int _k, ll _x)
{
    return (( _x >> (_k))&1);
}
ll OffBit(int _k, ll _x)
{
    return (_x ^ (1 << _k));
}

//Process
void Solve()
{
    sort(whole(vect));
    int lim = (1 << n) - 1;
    FOR(i, 0, n) F[1<<i][i] = 1;
    FOR(i, 1, lim)
    {
        FORl(j, 0, n)
        {
            if(GetBit(j, i) == 0) continue;
            FORl(__k, 0, n)
            {
                if(GetBit(__k, i) == 1 && (int)(abs(vect[j] - vect[__k])) > k) F[i][j] += 1LL*F[OffBit(j, i)][__k];
            }
        }
    }
    res = 0LL;
    FORl(i, 0, n) res += 1LL*F[lim][i];
    printf("%lld", res);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
