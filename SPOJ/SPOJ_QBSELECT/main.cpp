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
#define maxinp (int)(10240)
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
int F[16][maxinp];
int a[5][maxinp];
int fr[9][9];
int n, inMax;
int res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	res = -200000000;
	inMax = -200000000;
	scanf("%d", &n);
	FOR(i, 1, 4)
	{
	    FOR(j, 1, n)
	    {
	        scanf("%d", &a[i][j]);
	        inMax = max(inMax, a[i][j]);
	    }
	}
}

//Check
int getBit(int k, int x)
{
    return (x >> (k-1))&1;
}
int ok(int x, int y)
{
    if((x&y) != 0) return 0;
    return 1;
}
int getVal(int x, int y)
{
    int tmp = 0;
    FOR(i, 1, 4)
    {
        if(getBit(i, x) == 1) tmp += a[i][y];
    }
    return tmp;
}

//Process
void Process()
{
    int d[] = {0, 1, 2, 4, 5, 8, 9, 10};
    FOR(i, 0, 8)
    {
        FOR(j, 0, 8)
        {
            fr[i][j] = ok(d[i], d[j]);
        }
    }
    FOR(i, 0, n)
    {
        FOR(j, 0, 8)
        {
            int t = -200000000;
            FOR(k, 0, 8)
            {
                if(fr[j][k] == 1 && F[k][i-1] > t) t = F[k][i-1];
            }
            F[j][i] = t + getVal(d[j], i);
        }
    }
    FOR(i, 0, 8) res = max(res, F[i][n]);
    printf("%d", res);
}
void Solve()
{
    if(inMax < 0) printf("%d", inMax);
    else Process();
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
