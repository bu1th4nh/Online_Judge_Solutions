//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
//#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(1e6+12)
#define MODUL (int)(1000000007)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
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
string s;
ull res;
int n;

//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    cin >> s;
    n = s.length();
    ull hold = 0;
    s = 'X' + s;
    FOR(i, 1, n)
    {
        int x = static_cast<int>(s[i]) - 48;
        hold = (hold*10 + x*i)%MODUL;
        res = (res + hold)%MODUL;
    }
    cout << res;
    return 0;
}
