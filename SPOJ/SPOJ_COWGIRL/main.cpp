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
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
int id[3][31];
int F[32][32];
int m, n, res;
int nTest;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d%d", &m, &n);
	if(m < n) swap(m, n);
	MEMS(F, 0);
	MEMS(id, 0);
}

//Check
int GetBit(int _k, int _x)
{
    return ((_x >> (_k - 1)) & 1);
}
bool Check(int x, int y)
{
    FOR(i, 1, n) id[1][i] = GetBit(i, x);
    FOR(i, 1, n) id[2][i] = GetBit(i, y);
    FORl(i, 1, n)
    {
        int tmp = id[1][i] + id[1][i+1] + id[2][i] + id[2][i+1];
        if(tmp == 0 || tmp == 4) return false;
    }
    return true;
}

//Process
void Solve()
{
    int lim = (1 << n) - 1;
    FOR(i, 0, lim) F[1][i] = 1;
    FOR(i, 2, m)
    {
        FOR(j, 0, lim)
        {
            FOR(k, 0, lim)
            {
                if(Check(j, k)) F[i][j] += F[i-1][k];
            }
        }
    }
    res = 0;
    FOR(i, 0, lim) res += F[m][i];
    printf("%d\n", res);
}


//Output
void Multitest()
{
    Enter();
    Solve();
}

//Main Procedure
int main()
{
    scanf("%d", &nTest);
    while(nTest--)
    {
        Multitest();
    }
    return 0;
}
