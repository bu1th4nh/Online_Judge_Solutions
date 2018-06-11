//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)()
#define MODUL (int)(10e9+57)
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
typedef double ldb;
vector<ldb> vect;
ldb res;
int n;
ldb pi = 3.1415926;

//=====================================
//Functions and procedures
//Input
void Input()
{
    vect.push_back(0);
    cin >> n;
    FOR(i, 1, n)
    {
        ldb x;
        cin >> x;
        vect.push_back(x);
    }
}

//Check
ldb Cal(ldb a, ldb b, ldb c)
{
    return (ldb)(acos((a*a + b*b - c*c)/(2*a*b)));
}
ldb Check(ldb x)
{
    ldb cor = Cal(vect[n]+x, vect[1]+x, vect[n]+vect[1]);
    FOR(i, 2, n) cor+=Cal(vect[i-1]+x, vect[i]+x, vect[i-1]+vect[i]);
    return cor;
}

//Process
void Process()
{
    ldb left = 0;
    ldb right = 0;
    FOR(i, 1, n) right += (ldb)vect[i];
    ldb mid = (left + right)/2;
    while(left!=mid && right!=mid)
    {
        ldb corner = Check(mid);
        if((corner == 2*pi)) break;
        if(corner > 2*pi) left = mid;
        else right = mid;
        mid = (left + right)/2;
    }
    res = mid;
    printf("%.3f\n", res);
}

//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
