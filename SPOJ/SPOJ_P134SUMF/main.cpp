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
#define maxvalueinp (int)(1001)
#define MODUL (int)(10e9+57)
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
bool prime[maxvalueinp];
int n, k;

//=====================================
//Functions and procedures
void Sieve()
{
    int cnt = 0;
    MEMS(prime, true);
    FOR(i, 2, n)
    {
        if(prime[i])
        {
            int base = 1;
            while((base*i)<=n)
            {
                int x = i*base;
                ++base;
                if(prime[x])
                {
                    ++cnt;
                    prime[x] = false;
                    if(cnt == k)
                    {
                        cout << x;
                        return;
                    }
                }
            }
        }
    }
}

//Main Procedure
int main()
{
    scanf("%d%d", &n, &k);
    Sieve();
    return 0;
}
