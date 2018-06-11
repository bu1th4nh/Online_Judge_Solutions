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
ll res;

//=====================================
//Functions and procedures
void Multitest()
{
    priority_queue<int, vi, greater<int>> pq;
    res = 0;
    scanf("%d", &n);
    FOR(i, 1, n)
    {
        int x;
        scanf("%d", &x);
        pq.push(x);
    }
    FORl(i, 1, n)
    {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a+b);
        res += a+b;
    }
    printf("%lld\n",res);
}

int main()
{
    scanf("%d", &nTest);
    while(nTest--)
    {
        Multitest();
    }
    return 0;
}
