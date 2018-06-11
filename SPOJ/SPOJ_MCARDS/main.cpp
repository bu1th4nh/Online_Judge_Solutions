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
#define maxvalueinp (int)(1000)
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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int val[maxvalueinp];
int F[maxvalueinp];
int n, c, m, res;
vii vect;
vi order;


//=====================================
//Functions and procedures
//Input
void Input()
{
    vect.push_back(ii(-99999, -99999));
    scanf("%d%d", &c, &n);
    m = c*n;
    FOR(i, 1, m)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        vect.push_back(ii(a, b));
    }
    FOR(i, 1, c) order.push_back(i);
}

//LIS
int BinarySearch(int index, int num)
{
    int l = 1;
    int r = num;
    while(l<r)
    {
        int k = (l+r) >> 1;
        if(val[F[k]] < val[index]) l = k + 1;
        else r = k;
    }
    return l;
}
int LIS()
{
    int lgth = 1;
    F[1] = 1;
    FOR(i, 2, m)
    {
        if(val[i] > val[F[lgth]])
        {
            ++lgth;
            F[lgth] = i;
        }
        else F[BinarySearch(i, lgth)] = i;
    }
    return lgth;
}


//Output
void Output()
{
    res = 1000000000;
    do
    {
        FOR(i, 1, m)
        {
            val[i] = order[vect[i].first-1] * 1000 + vect[i].second;
        }
        res = min(res, m - LIS());
    }
    while(next_permutation(whole(order)));
    printf("%d", res);
}



//Main Procedure
int main()
{
    Input();
    Output();
    return 0;
}
