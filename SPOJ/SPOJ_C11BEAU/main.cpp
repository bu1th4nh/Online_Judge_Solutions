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
typedef vector<ii> vii;
typedef long long ll;
ll cntA, cntB, maxA, maxB, res;
int nTest;

//=====================================
//Functions and procedures
//Process
void Solve()
{
    scanf("%lld%lld%lld%lld", &cntA, &cntB, &maxA, &maxB);
    if(maxA == 0) cntA = 0;
    if(maxB == 0) cntB = 0;
    if(cntB < cntA)
    {
        swap(cntA, cntB);
        swap(maxA, maxB);
    }
    res = cntA + min(cntB, maxB*(cntA + 1));
    printf("%lld\n", res);
}

//Multi-test data processing
void Multitest()
{
    scanf("%d", &nTest);
    while(nTest--)
    {
        Solve();
    }
}

//Main Procedure
int main()
{
    Multitest();
    return 0;
}
