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
#define MODUL (int)(1e9+57)
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
int n, m, res1;
vvi vect;
vii res2;
bool ok;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d%d", &m, &n);
	vect = vvi(m+2, vi(n+2, 0));
	FOR(i, 1, m)
	{
	    FOR(j, 1, n)
	    {
	        scanf("%d", &vect[i][j]);
	    }
	}
}

//Check
void FlipBit(int __i, int __j)
{
    FOR(i, __i, __i+2)
    {
        FOR(j, __j, __j+2)
        {
            vect[i][j] = 1 - vect[i][j];
        }
    }
}


//Process
void Solve()
{
    res1 = 0;
    FOR(i, 1, m)
    {
        FOR(j, 1, n-2)
        {
            if(vect[i][j] == 1)
            {
                ++res1;
                FlipBit(i, j);
                res2.push_back(ii(i, j));
            }
        }
        FOR(j, n-1, n)
        {
            if(vect[i][j] == 1)
            {
                printf("-1");
                return;
            }
        }
    }

    printf("%d\n", res1);
    for(ii res3: res2)
    {
        printf("%d %d \n", res3.first, res3.second);
    }
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
