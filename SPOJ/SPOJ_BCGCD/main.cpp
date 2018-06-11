//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#define maxvalueinp (int)()
#define MODUL (int)(1e9+57)
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
ull a, b;

//=====================================
//Functions and procedures
ull GCD(ull a, ull b)
{
    while(b>0)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
int main()
{
    a = 1;
    b = 1;
    while(true)
    {
        scanf("%llu%llu", &a, &b);
        if(a == 0 && b == 0) break;
        ull gcd = GCD(a, b);
        ull lcm = a*b/gcd;
        printf("%llu %llu", gcd, lcm);
        cout << endl;
    }
    return 0;
}
