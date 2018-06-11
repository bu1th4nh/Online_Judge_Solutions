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
int m, n, prod;
int st[6][6];
int a[5][5];
int res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d%d", &m, &n);
	FOR(i, 1, m)
	{
	    FOR(j, 1, n)
	    {
	        scanf("%d", &a[i][j]);
	    }
	}
	prod = m*n;
}

//Check
int GetBit(int __x, int __k)
{
    return ((__x >> (__k - 1)) & 1);
}
int Calc(int state)
{
    int num = 0;
    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            int dir = (i-1)*n+j;
            st[i][j] = GetBit(state, dir);
        }
    }
    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            if(st[i][j] != -1)
            {
                if(st[i][j] == 0)                      ///Vertical
                {
                    vi lst;
                    int x = i, y = j, tmp = 0;
                    while(x<=m && y<=n && st[x][y] == 0)
                    {
                        lst.push_back(a[x][y]);
                        st[x][y] = -1;
                        ++x;
                    }
                    FOR(k, 0, (lst.size()-1))
                    {
                        tmp = tmp*10 + lst[k];
                    }
                    num += tmp;
                }
                else                                   ///Horizontal
                {
                    vi lst;
                    int x = i, y = j, tmp = 0;
                    while(x<=m && y<=n && st[x][y] == 1)
                    {
                        lst.push_back(a[x][y]);
                        st[x][y] = -1;
                        ++y;
                    }
                    FOR(k, 0, (lst.size()-1))
                    {
                        tmp = tmp*10 + lst[k];
                    }
                    num += tmp;
                }
            }
        }
    }
    return num;
}

//Process
void Solve()
{
    res = -123456789;
    int lim = (1 << prod) - 1;
    FOR(MainState, 0, lim)
    {
        int sample = Calc(MainState);
        res = max(res, sample);
    }
    printf("%d", res);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
