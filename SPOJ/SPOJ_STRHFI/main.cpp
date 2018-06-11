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
typedef pair<char, char> cc;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<cc> vcc;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
int n, nVtx, d;
vcc vertex;
vii path;
vvi adj;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    string t; char ss[64];
    scanf("%d%d", &n, &d);

    nVtx = n - d + 1;
    adj = vvi(nVtx+1, vi(nVtx+1, 0));

    FOR(i, 1, n - d + 1)
    {
        scanf("%s", &ss);
        t = string(ss);

        vertex.push_back(cc(t[0], t[d-1]));
    }
}

//Check
void LoadEdge()
{
    sort(whole(vertex));

    for(cc x: vertex) printf("%c %c\n", x.first, x.second);

    FORl(i, 0, nVtx)
    {
        FORl(j, 0, nVtx) if(j != i)
        {
            cc u = vertex[i], v = vertex[j];
            if(u.second == v.first)
            {
                adj[i][j]++;
                adj[j][i]++;
            }
        }
    }

    puts("ADJ - MAT");
    for(vi x: adj)
    {
        for(int i: x)
        {
            printf("%d ", i);
        }
        puts("");
    }
    puts("");
}

//Process
void FindEulerTour(int u)
{
    FOR(v, 0, nVtx-1)
    {
        if(adj[u][v] > 0)
        {
            adj[u][v]--;
            adj[v][u]--;
            FindEulerTour(v);
            path.push_back(ii(u, v));
        }
    }
}

void Solve()
{
    LoadEdge();
    FindEulerTour(nVtx-1);
    reverse(whole(path));

    puts("PATH:");
    for(ii x: path)
    {
        printf("%d %d\n", x.first, x.second);
    }
    puts("");

}



//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
