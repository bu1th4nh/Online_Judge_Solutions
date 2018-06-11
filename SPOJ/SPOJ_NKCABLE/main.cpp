//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(25652)
#define MODUL (int)(1e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef vector<int> vi;
int F[maxvalueinp];
vi vect;
int n;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int x;
    scanf("%d", &n);
    vect.push_back(-99);
    //vect.push_back(-99);
    FORl(i, 1, n)
    {
        scanf("%d", &x);
        vect.push_back(x);
    }
}

//Process
void Solve()
{
    F[0] = 0;
    F[1] = 0;
    F[2] = vect[1];
    F[3] = vect[1] + vect[2];
    FOR(i, 4, n)
    {
        F[i] = min(F[i-1], F[i-2]) + vect[i-1];
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
