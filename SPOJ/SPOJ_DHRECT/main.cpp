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
typedef vector<int> vi;
typedef long long ll;
int n, nTest;
vi vect;
ll res;

//=====================================
//Functions and procedures
//Multi-test
void Multitest()
{
    int x;
    ll pre;
    res = 0;
    int nPair = 0;
    scanf("%d", &n);
    FOR(i, 1, n)
    {
        scanf("%d", &x);
        vect.push_back(x);
    }
    sort(whole(vect));
    FORb(i, n-2, 0)
    {
        if(vect[i] == vect[i+1])
        {
            if(++nPair == 2)
            {
                res = 1LL*pre*vect[i];
                printf("%lld\n", res);
                return;
            }
            pre = vect[i];
            vect[i] = -1;
        }
    }
    printf("-1\n");
}

int main()
{
    scanf("%d", &nTest);
    while(nTest--)
    {
        Multitest();
        vect.clear();
    }
    return 0;
}
