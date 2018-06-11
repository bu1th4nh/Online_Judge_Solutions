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
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> iii;
typedef vector<iii> viii;
typedef vector<ll> vll;
priority_queue<iii, viii, greater<iii>> pq;
int m, n, k;
vll a, b;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d%d%d", &m, &n, &k);
    a.push_back(0);
    b.push_back(0);
    FOR(i, 1, m)
    {
        ll x;
        scanf("%lld", &x);
        a.push_back(x);
    }
    FOR(i, 1, n)
    {
        ll x;
        scanf("%lld", &x);
        b.push_back(x);
    }
}

//Process
void Process()
{
    sort(whole(a));
    sort(whole(b));
    FOR(i, 1, n)
    {
        pq.push(iii(a[1]+b[i], ii(1, i)));
    }
    while(k--)
    {
        printf("%lld\n", pq.top().first);
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(x>=m) continue;
        pq.push(iii(a[x+1]+b[y], ii(x+1, y)));
    }
}

//Main Procedure
int main()
{
    Enter();
    Process();
    return 0;
}
