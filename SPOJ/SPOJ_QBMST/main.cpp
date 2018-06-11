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
#define maxinp (int)(16384)
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
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
int m, n, res;
viii EdgeList;
vi lab;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d%d", &n, &m);
	lab = vi(n+1, -1);
	FOR(i, 1, m)
	{
	    int u, v, c;
	    scanf("%d%d%d", &u, &v, &c);
	    EdgeList.push_back(iii(c, ii(u, v)));
	}
}

///Kruskal's Algorithm
//Disjoint Sets DS
int FindSet(int u)
{
    return (lab[u] < 0) ? u : (lab[u] = FindSet(lab[u]));
}
void Union(int r, int s)
{
    if(lab[s] < lab[r]) swap(r, s);
    lab[r] += lab[s];
    lab[s] = r;
}
//Main Algorithm
void Kruskal()
{
    res = 0;
    sort(whole(EdgeList));
    for(iii edge: EdgeList)
    {
        int u = FindSet(edge.second.second);
        int v = FindSet(edge.second.first);
        if(u != v)
        {
            Union(u, v);
            res += edge.first;
        }
    }
    printf("%d", res);
}

///Prim's Algorithm




//Process
void Solve()
{
    Kruskal();
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
