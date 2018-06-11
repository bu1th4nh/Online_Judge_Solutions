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
#define maxinp (int)(256)
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
typedef queue<int> qi;
typedef long long ll;
bool avail[maxinp];
vi adj[maxinp];
int n, m;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP(task)
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
void IOSTROpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Enter
void Enter()
{
	int u, v;
	scanf("%d%d", &n, &m);
	FOR(i, 1, m)
	{
	    scanf("%d%d", &u, &v);
	    adj[u].pb(v);
	    adj[v].pb(u);
	}
	MEMS(avail, true);
}

//BFS
int BFS(int start)
{
    qi que;
    int tmp = 0;
    que.push(start);
    avail[start] = false;

    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        ++tmp;

        for(int v: adj[u])
        {
            if(avail[v])
            {
                que.push(v);
                avail[v] = false;
            }
        }
    }

    return tmp;
}


//Process
void Solve()
{
    int t = BFS(1);
    if(t == n) printf("0");
    else
    {
        FOR(i, 1, n)
        {
            if(avail[i])
            {
                printf("%d\n", i);
            }
        }
    }
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
