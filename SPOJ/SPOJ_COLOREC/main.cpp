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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<ii> vii;
vvi vect(512, vi(512, 0));
const int bs = 200;
ll res;
int n;

//=====================================
//Functions and procedures
//Process
void Solu1()
{
    int x, y, z;
	scanf("%d", &n);
	FOR(i, 1, n)
	{
	    scanf("%d%d%d", &x, &y, &z);
	    vect[x+bs][y+bs] = 1 << (z - 1);
	}



    res = 0;
    FOR(i, 0, 400)
    {
        FOR(j, 0, i)
        {
            vll F(16, 0);
            FOR(k, 0, 400)
            {
                if(vect[i][k] && vect[j][k] && vect[i][k] != vect[j][k])
                {
                    int c = vect[i][k] | vect[j][k];
                    res += F[15 - c];
                    ++F[c];
                }
            }
        }
    }
    printf("%lld", res);
}








void Solu2()
{
    int x, y, z;
	scanf("%d", &n);
	FOR(i, 1, n)
	{
	    scanf("%d%d%d", &x, &y, &z);
	    vect[x+bs][y+bs] = z;
	}


    res = 0;
    FOR(i, 0, 400-1)
    {
        FOR(j, i+1, 400)
        {
            vvi combi = vvi(5, vi(5, 0));
            FOR(k, 0, 400)
            {
                if(vect[i][k]*vect[j][k]>0)
                {
                    ++combi[min(vect[i][k], vect[j][k])][max(vect[i][k], vect[j][k])];
                }
            }
            res += combi[1][2] * combi[3][4] + combi[1][3] * combi[2][4] + combi[1][4] * combi[2][3];
        }
    }
    printf("%lld", res);
}

//Main Procedure
int main()
{
    Solu2();
    return 0;
}
