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
//BigInt
typedef unsigned long long ull;
typedef vector<ull> BigInt;
const ull BASE = 1000000000;

void println(const BigInt& a) {
    int L = a.size();
    printf("%llu", a[L - 1]);
    for (int i = L - 2; i >= 0; i--) printf("%09llu", a[i]);
    printf("\n");
}
BigInt operator + (const BigInt& a, const BigInt& b) {
    BigInt c; ull carry = 0;
    for (size_t i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        c.push_back(carry % BASE); carry /= BASE;
    }
    if (carry) c.push_back(carry); return c;
}
BigInt operator * (const BigInt& a, const int mul) {
    BigInt c; ull carry = 0;
    for (size_t i = 0; i < a.size(); i++) {
        carry += a[i] * mul; c.push_back(carry % BASE); carry /= BASE;
    }
    if (carry) c.push_back(carry); return c;
}
bool operator < (const BigInt& a, const BigInt& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] != b[i]) return a[i] < b[i];
    return false;
}

//=====================================
//Typedef
typedef vector<BigInt> vbi;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vbi> vvbi;
typedef vector<vii> vvii;
typedef long long ll;
int n, s, w, m, bmin, bmax;
BigInt F[201][201];
vvbi g;
vvb x;
vi a;

//=====================================
//Functions and procedures
//Preliminary Processing
void Prepare()
{
    F[0][0] = {1};
    FOR(i, 1, 200)
    {
        F[i][0] = F[i-1][0];
        FORl(j, 1, i)
        {
            F[i][j] = F[i-1][j]*(j+1) + F[i-1][j-1]*(i-j);
        }
    }

    FOR(i, 1, 200)
    {
        FOR(j, 1, 200)
        {
            F[i][j] = F[i][j] + F[i][j-1];
        }
    }
}
//Enter
void Enter()
{
    scanf("%d%d%d%d%d%d", &n, &s, &w, &m, &bmin, &bmax);
    g = vvbi(n+1, vbi(s+1));
    x = vvb(n+1, vb(s+1, false));
    a = vi(n);

    FOR(i, 0, n-1)
    {
        scanf("%d", &a[i]);
        a[i] *= m;
    }
}

//Process
void Solve()
{
    BigInt xxx;
    x[0][0] = true;
    FOR(i, 1, n)
    {
        FOR(j, 1, s)
        {
            int b = 0;
            FORb(k, i-1, 0)
            {
                b += a[k];
                if(b > bmax) break;
                if(bmin <= b && x[k][j-1])
                {
                    x[i][j] = true;
                    BigInt tmp = g[k][j-1] + F[i-k][w];
                    if((g[i][j] < tmp)) g[i][j] = tmp;
                }
            }
        }
    }
    println(g[n][s]);
}

//Output
void Multitest()
{
    int T;
    Prepare();
    scanf("%d", &T);
    while(T--)
    {
        Enter();
        Solve();
    }
}

//Main Procedure
int main()
{
    Multitest();
    return 0;
}
