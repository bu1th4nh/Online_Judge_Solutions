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
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int m, n, res, cnt;
vi cost, lab;
viii EList;

//=====================================
//Functions and procedures
///Enter
void Enter()
{
    scanf("%d%d", &n, &m);
    cost = vi(n+1, 1234567890);
    lab = vi(n+1, -1);

    FOR(i, 1, n)
    {
        scanf("%d", &cost[i]);
    }
    res = *min_element(whole(cost));

    FOR(i, 1, m)
    {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        c = 2*c + cost[u] + cost[v];
        EList.push_back(iii(c, ii(u, v)));
    }
}


///Kruskal's Algorithm
//Disjoint Sets DS
int FSet(int u)
{
    return (lab[u] < 0) ? u : lab[u] = FSet(lab[u]);
}
void Union(int r, int s)
{
    if(lab[s] < lab[r]) swap(r, s);
    lab[r] += lab[s];
    lab[s] = r;
}
//Kruskal's Algorithm
void Kruskal()
{
    sort(whole(EList));
    cnt = 0;

    for(iii itr: EList)
    {
        int u = FSet(itr.second.first);
        int v = FSet(itr.second.second);
        if(u!=v)
        {
            ++cnt;
            Union(u, v);
            res += itr.first;
            if(cnt == n) return;
        }
    }
}

///Process
void Solve()
{
    Kruskal();
    printf("%d", res);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
