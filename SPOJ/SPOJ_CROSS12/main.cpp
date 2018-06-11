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
typedef vector<ii> vii;
typedef long long ll;
vi a, cache;
int m, n;
string b;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d%d", &n, &m);

    cache = vi(101, 0);
    a = vi(n);

    FOR(i, 0, n-1) scanf("%d", &a[i]);
    //char s[131072]; scanf("%s", &s); b = string(s);

    cin >> b;
    b = '0' + b + '0';
}

//Check
int CTime(int r, int t, const char* br)
{
    int i = 0, lr = 1;
    while(i + r <= t)
    {
        ++lr;
        i += r;
        while(br[i] == '1') i--;
    }
    return lr;
}

//Process
void Solve()
{
    for(auto &x: a)
    {
        if(!cache[x]) x = cache[x] = CTime(x, m, b.data());
        else x = cache[x];
    }
    sort(whole(a));

    if(n == 1 || n == 2) printf("%d", a[n - 1]);
    else
    {
        int f0 = a[0], f1 = a[1];
        FORl(i, 2, n)
        {
            int f2 = min(f0 + a[0] + 2*a[1] + a[i], f1 + a[0] + a[i]);
            f0 = f1, f1 = f2;
        }
        printf("%d", f1);
    }
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
