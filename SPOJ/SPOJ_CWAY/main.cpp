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
#define MODUL (int)(100000)
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
//Big Integers
typedef vector<int> BigInt;

BigInt operator + (BigInt a, BigInt b)
{
    BigInt c; int carry = 0;
    for(int i = 0; i < a.size() || i < b.size(); ++i)
    {
        if(i < a.size()) carry += a[i];
        if(i < b.size()) carry += b[i];
        c.push_back(carry % MODUL);
        carry /= MODUL;
    }
    if(carry) c.push_back(carry);
    return c;
}

BigInt operator * (BigInt a, int b)
{
    BigInt c; int carry = 0;
    for(int i = 0; i < a.size(); i++)
    {
        carry += a[i] * b;
        c.push_back(carry % MODUL);
        carry /= MODUL;
    }
    if (carry) c.push_back(carry);
    return c;
}

void Print(BigInt a)
{
    printf("%d", a[a.size()-1]);
    FORb(i, a.size()-2, 0) printf("%05d", a[i]);
    printf("\n");
}


//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
BigInt res;
BigInt tmp;
int n;

//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    scanf("%d", &n);
    res.push_back(1);
    tmp = res;
    FORb(i, n-2, 1)
    {
        tmp = tmp*(i);
        res = res + tmp;
    }
    Print(res);
    return 0;
}
