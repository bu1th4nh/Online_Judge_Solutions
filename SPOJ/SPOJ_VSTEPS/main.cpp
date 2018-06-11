//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(123456)
#define MODUL (int)(14062008)
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
bool ok[maxvalueinp];
int F[maxvalueinp];
int n, k;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int x;
    MEMS(ok, true);
    scanf("%d%d", &n, &k);
    FOR(i, 1, k)
    {
        scanf("%d", &x);
        ok[x] = false;
    }
}


//Process
void Process()
{
    F[1] = 1;
    FOR(i, 2, n)
    {
        if(ok[i-1] && ok[i-2]) F[i] = F[i-1]%MODUL + F[i-2]%MODUL;
        else if(ok[i-2] && !ok[i-1]) F[i] = F[i-2]%MODUL;
        else if(ok[i-1] && !ok[i-2]) F[i] = F[i-1]%MODUL;
        else F[i] = 0;
    }
    printf("%d", F[n]%MODUL);
}


//Output





//Main Procedure
int main()
{
    Enter();
    Process();
    return 0;
}
