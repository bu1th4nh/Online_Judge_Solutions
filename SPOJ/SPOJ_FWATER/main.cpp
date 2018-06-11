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
typedef vector<iii> viii;typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
viii EdgeList;
int n, cnt;
vi lab;
ll res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d", &n);
	lab = vi(n+8, -1);
	FOR(i, 1, n)
	{
	    int x;
	    scanf("%d", &x);
	    EdgeList.push_back(iii(x, ii(n+1, i)));
	}
	FOR(i, 1, n)
	{
	    FOR(j, 1, n)
	    {
	        int x;
	        scanf("%d", &x);
	        if(i == j && x == 0) continue;
	        EdgeList.push_back(iii(x, ii(i, j)));
	    }
	}
}

//Disjoint Sets
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
    sort(whole(EdgeList));
    res = cnt = 0;

    for(iii itr: EdgeList)
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


//Process
void Solve()
{
    Kruskal();
    printf("%lld", res);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
