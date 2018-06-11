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
typedef vector<bool> vb;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int MOD, n, st, fi;

//=====================================//Matrix Exponentiation
typedef vector<vi> Matrix;
#define nRow(a) (int(a.size()))
#define nCol(a) (int(a[0].size()))
#define NewMat(m, n, v) Matrix(m, vi(n, v))

void inc(ll &a, ll b)
{
    a = (a + b) % MOD;
}

Matrix operator * (const Matrix &a, const Matrix &b)
{
    Matrix c = NewMat(nRow(a), nCol(b), 0);
    FORl(i, 0, nRow(c))
    {
        FORl(j, 0, nCol(c))
        {
            FORl(k, 0, nCol(a))
            {
                inc(c[i][j], a[i][k] * b[k][j]);
            }
        }
    }
    return c;
}

Matrix UnitMat(int n)
{
    Matrix c = NewMat(n, n, 0);
    FORl(i, 0, n) c[i][i] = 1;
    return c;
}

Matrix POWER(Matrix a, ll p)
{
    Matrix c = UnitMat(nRow(a));
    {
        while(p > 0)
        {
            if(p&1) c = c * a;
            a = a * a;
            p >>= 1;
        }
    }
    return c;
}

//=====================================
#define index(u, i) ((u) * 4 + i)
#define next(i) ((i + 1) % 4)
#define prev(i) ((i + 3) % 4)
vi adj[8];
char f, t;
Matrix a;
ll res;

//=====================================
//Functions and procedures
//Process
void AddEdge(vi fro, vi bck)
{
    FORl(i, 0, 4)
    {
        adj[fro[i]].pb(fro[prev(i)]);
        adj[fro[i]].pb(fro[next(i)]);
        adj[fro[i]].pb(bck[i]);
    }
}
void Prepare()
{
    vi fr, bk;
    FORl(i, 0, 4) fr.push_back(i);
    FORl(i, 4, 8) bk.push_back(i);
    AddEdge(fr, bk);
    AddEdge(bk, fr);

    a = NewMat(8 * 4, 8 * 4, 0);

    FORl(u, 0, 8) FORl(i, 0, 4)
    {
        FORl(j, 0, 3) if(i != j)
        {
            int v = adj[u][j], v_i = 0;

            FORl(k, 0, 3) if(adj[v][k] == u)
            {
                v_i = k;
                break;
            }
            a[index(u, i)][index(v, v_i)] = 1;
        }
    }
}
void Solve()
{
    Prepare();
    scanf("%c %c\n%d %d", &f, &t, &n, &MOD);
    st = f - 'A'; fi = t - 'A'; res = 0;
    a = POWER(a, n);
    FORl(i, 0, 3)
    {
        inc(res, a[index(st, 3)][index(fi, i)]);
    }
    printf("%lld", res);
}

//Main Procedure
int main()
{
    Solve();
    return 0;
}
