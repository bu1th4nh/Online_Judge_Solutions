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
int sum, maxsum, res;
int distr[128];
int s[4];

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	sum = 0;
	MEMS(distr, 0);
	scanf("%d%d%d", &s[1], &s[2], &s[3]);
}

//Check
void Try(int i)
{
    FOR(j, 1, s[i])
    {
        sum += j;
        if(i == 3) ++distr[sum];
        else Try(i+1);
        sum -= j;
    }
}


//Process
void Solve()
{
    int cnt = 0;
    res = 0;
    Try(1);
    FORb(k, 86, 1) if(cnt <= distr[k])
    {
        res = k;
        cnt = distr[k];
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
