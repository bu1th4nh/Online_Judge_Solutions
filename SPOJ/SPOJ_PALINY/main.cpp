/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
string s;
int n;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
    char t[65536];
    scanf("%d", &n);
    scanf("%s", &t);
    s = string(t);
}

//Manacher Algorithm
int Manacher(const string &s)
{
    string a;
    for(char c: s) a += '?', a += c;
    a += '.';

    vi F(n);
    int r = 0, c = 0;

    FORl(i, 0, n)
    {
        F[i] = (i < r) ? min(r - i, F[c - (i-c)]) : 0;
        while(a[i - F[i] - 1] == a[i + F[i] + 1]) ++F[i];
        if(i + F[i] > r)
        {
            r = i + F[i];
            c = i;
        }
    }

    return *max_element(whole(F));
}


//Process
void Solve()
{
    cout << Manacher(s);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
