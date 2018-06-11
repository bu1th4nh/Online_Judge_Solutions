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
typedef bitset<maxinp> bs;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
bs bit[maxinp];
int m, n, res;
vvi adj;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;
    scanf("%d%d", &n, &m);
    adj = vvi(n+1);
    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        if(!bit[u][v])
        {
            adj[u].pb(v);
            adj[v].pb(u);
            bit[u][v] = bit[v][u] = 1;
        }
    }
}

//Process
void Solve()
{
    FOR(u, 1, n)
    {
        bs f;
        for(int v: adj[u])
        {
            bit[v][u] = 0;
            if((f & bit[v]).any())
            {
                f &= bit[v];
                int w = 1;
                while(!f[w]) ++w;
                for(int k: adj[w])
                {
                    if(bit[u][k])
                    {
                        printf("%d %d %d %d", u, v, w, k);
                        return;
                    }
                }
            }
            else
            {
                f |= bit[v];
            }
            bit[v][u] = 1;
        }
    }

    printf("-1\n");
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
