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
#define MODUL (int)(1000000000)
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
int F[1048576];
int n, k, s;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d%d", &n, &k);
}

//Check
int add(int a, int b)
{
    a += b;
    if(a >= MODUL) a -= MODUL;
    return a;
}
int sub(int a, int b)
{
    a -= b;
    if(a < 0) a += MODUL;
    return a;
}

//Process
void Solve()
{
    F[0] = 1;
    FOR(i, 1, k) F[i] = add(F[i-1], F[i-1]), s = add(s, F[i]);
    FOR(i, k+1, n)
    {
        F[i] = s;
        s = add(s, F[i]);
        s = sub(s, F[i-k]);
    }
    printf("%d", F[n]);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
