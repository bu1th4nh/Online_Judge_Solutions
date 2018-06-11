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
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef stack<int> si;
typedef long long ll;
int num[maxinp];
int low[maxinp];
vi adj[maxinp];
int m, n, cnt;
int res;
si st;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	res = 0, cnt = 0;
	scanf("%d%d", &n, &m);
	int u, v;
	FOR(i, 1, m)
	{
	    scanf("%d%d", &u, &v);
	    adj[u].push_back(v);
	}
}

//Check
void DFS(int u)
{
    low[u] = num[u] = ++cnt;
    st.push(u);

    for(int v: adj[u])
    {
        if(num[v]) low[u] = min(low[u], num[v]);
        else
        {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if(num[u] == low[u])
    {
        ++res;
        int v;
        do
        {
            v = st.top();
            st.pop();
            num[v] = low[v] = MODUL;
        }
        while(v!=u);
    }
}

//Process
void Solve()
{
    FOR(i, 1, n)
    {
        if(!num[i]) DFS(i);
    }
    printf("%d", res);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
