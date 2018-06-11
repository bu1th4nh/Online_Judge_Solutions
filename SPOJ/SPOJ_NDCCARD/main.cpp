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
int n, m, res;
vi vect;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int x;
	scanf("%d%d", &n, &m);
	FOR(i, 1, n)
	{
	    scanf("%d", &x);
	    vect.push_back(x);
	}
}

//Process
void Solve()
{
    sort(whole(vect));
    res = vect[0] + vect[1] + vect[2];
    FORl(i, 2, n)
    {
        int s = m - vect[i];
        int j = i - 1;
        int k = 0;

        while(j > k)
        {
            while(j > k && vect[j] + vect[k] > s) --j;
            while(j > k && vect[j] + vect[k] <= s)
            {
                res = max(res, vect[i] + vect[j] + vect[k]);
                ++k;
            }
        }
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
