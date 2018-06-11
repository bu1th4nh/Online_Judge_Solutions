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
#define maxvalueinp (int)(1e7)
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
const long long maxn = 300000;
static int LP[maxn+1];
vector<int> prime;
int a, b;

//=====================================
//Functions
void Sieve()
{
    FOR(i, 2, maxn)
    {
        if(LP[i] == 0)
        {
            LP[i] = i;
            prime.push_back(i);
        }
        for(int j = 0; j<(int)(prime.size()) && prime[j]<=LP[i] && i*prime[j]<=maxn; ++j)
        {
            LP[i*prime[j]] = prime[j];
        }
    }
}

int main()
{
    Sieve();
    cin >> a >> b;
    FORl(i, 0, siz(prime))
    {
        int j = prime[i];
        if(j>=a && j<=b) cout << j << endl;
        if(j>b) return 0;
    }
    return 0;
}
