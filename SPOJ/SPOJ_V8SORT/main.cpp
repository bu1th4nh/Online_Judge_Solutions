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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
int a[10], dst[10], c[10][10];
int f[83886626], cl[83886626];
int n, start, endd;
char s[7];

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    MEMS(cl, 0);
    string t;
    int xxx;

    getline(cin, t);
    stringstream sss(t);

    while(sss >> xxx)
    {
        a[++n] = xxx;
        dst[n] = xxx;
    }


	sort(dst+1, dst+n+1);
	FOR(i, 1, n)
	{
	    a[i] = lower_bound(dst+1, dst+n+1, a[i]) - dst;
	}

	FOR(i, 1, n)
	{
	    FOR(j, 1, n)
	    {
	        scanf("%d", &c[i][j]);
	    }
	}

	while(n<7)
    {
        a[++n] = 0;
    }
}

//Check
int taoso()
{
    int u=0;
    for(int i=1; i<=n; i++)
        u=u*10+a[i];
    return u;
}
int taoen()
{
    int u=0;
    for(int i=1; i<=n; i++)
        if(a[i])
            u=u*10+i;
        else u=u*10;
    return u;
}
int Swp(int _u, int _i, int _j)
{
    sprintf(s, "%d", _u);
    swap(s[_i-1], s[_j-1]);
    sscanf(s, "%d", &_u);
    return _u;
}
bool Check(int _u, int _i, int _j)
{
    if(_i==_j) return 0;
    sprintf(s, "%d", _u);
    if(s[_i-1] == '0' || s[_j-1] == '0') return 0;
    return 1;
}

//Dijkstra's Algorithm
void Dijkstra()
{
    int u, v;
    set <ii> pq;
    pq.insert(ii(0, start));
    cl[start] = 1;
    f[start]  = 0;
    while(!pq.empty())
    {
        ii t = *pq.begin();
        pq.erase(t);
        u = t.second;
        if(u == endd)
        {
            printf("%d", f[u]);
            return;
        }
        FOR(i, 1, 7)
        {
            FOR(j, 1, 7)
            {
                if(Check(u, i, j))
                {
                    v = Swp(u, i, j);
                    if(cl[v] == 0)
                    {
                        cl[v] = 1;
                        f[v] = f[u] + c[i][j];
                        pq.insert(ii(f[v], v));
                    }
                    else
                    {
                        if(f[v] > f[u] + c[i][j])
                        {
                            pq.erase(ii(f[v], v));
                            f[v] = f[u] + c[i][j];
                            pq.insert(ii(f[v], v));
                        }
                    }
                }
            }
        }
    }
}


//Process
void Solve()
{
    start = taoso();
    endd  = taoen();
    Dijkstra();
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
