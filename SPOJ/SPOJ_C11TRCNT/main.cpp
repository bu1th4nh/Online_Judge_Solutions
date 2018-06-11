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
typedef vector<ii> vii;
typedef long long ll;
int n, res1, res2;
int distr[256];
vii vect;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;
    MEMS(distr, 0);
    res1 = res2 = 0;
    vect.push_back(ii(-1000000001, -1000000001));
	scanf("%d", &n);
	FOR(i, 1, n)
	{
	    scanf("%d%d", &u, &v);
	    vect.push_back(ii(u, v));
	}
}

//Check
bool Check(int _x, int _y, int _z)
{
    ii pt1 = vect[_x];
    ii pt2 = vect[_y];
    ii pt3 = vect[_z];
    ii vct1 = ii( pt2.first - pt1.first , pt2.second - pt1.second );
    ii vct2 = ii( pt3.first - pt1.first , pt3.second - pt1.second );
    if( vct1.first * vct2.second * 1LL == vct1.second * vct2.first * 1LL ) return false;
    return true;
}
void BruteForce()
{
    FOR(i, 1, n)
    {
        FOR(j, i+1, n)
        {
            if(j!=i)
            {
                FOR(k, j+1, n)
                {
                    if(k!=i && k!=j)
                    {
                         if(Check(i, j, k))
                         {
                             ++res1;
                         }
                    }
                }
            }
        }
    }
    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            if(j!=i)
            {
                FOR(k, 1, n)
                {
                    if(k!=i && k!=j)
                    {
                         if(Check(i, j, k))
                         {
                             ++distr[i];
                         }
                    }
                }
            }
        }
    }
}

//Process
void Solve()
{
    int cnt = 2147483646;
    BruteForce();
    FORb(i, n, 1)
    {
        if(cnt >= distr[i])
        {
            cnt = distr[i];
            res2 = i;
        }
    }
    printf("%d %d", res1, res2);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
