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
int n, res, sum, s;
vi vect;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int x;
    vect.push_back(-1111111111);
    scanf("%d", &n);
    F[n+1] = 10000*100000 + 1;
    int tmp = 0;
    FOR(i, 1, n)
    {
        scanf("%d", &x);
        vect.push_back(x);
        tmp += x;
        F[n+1] = min(F[n+1], tmp);
        sum+=x;
    }
    //F[1] = s;
}

//Process
void Process()
{
    res = 0;
    if(sum < 0)
    {
        printf("0");
        return;
    }
    if(F[n+1] > 0) ++res;
    FORb(i, n, 2)
    {
        F[i] = min(F[i+1] + vect[i], vect[i]);
        if(F[i] > 0) ++res;
    }
    printf("%d", res);
}

//Main Procedure
int main()
{
    Enter();
    Process();
    return 0;
}
