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
#define MODUL (int)(1e9)
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
typedef vector<ii> vii;
typedef long long ll;
int f[131072][2];
bool ok = true;
int n, b;
vi vect;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
	int x;
	scanf("%d%d", &n, &b);
	vect.push_back(-1);
	FOR(i, 1, n)
	{
	    scanf("%d", &x);
	    vect.push_back(x);
	    if(b<=x)
        {
            ok = false;
            return;
        }
	}
}

//Process
void Solve()
{
    if(ok)
    {
        bool ok1 = true;
        FOR(i, 2, n) if(vect[i]>vect[1])
        {
            ok1 = false;
            break;
        }
        if(ok1) printf("2\n");
        else printf("1\n");
        f[1][0] = 1;
        FOR(i, 1, n)
        {
            f[i+1][0] = (f[i+1][0] + f[i][0]) % MODUL;
            f[i+1][1] = (f[i+1][1] + f[i][0]) % MODUL;
            f[i+1][0] = (f[i+1][0] + f[i][1]) % MODUL;
        }
        printf("%d", ((f[n+1][0]+f[n+1][1])%MODUL));
    }
    else
    {
        printf("0\n");
        printf("0");
    }
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
