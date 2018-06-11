//Libraries and namespaces
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <iostream>
#include <fstream>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(2001)
#define MODUL (int)(10e9+57)
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
string res;
string s;
int n;
int F[maxvalueinp][maxvalueinp];


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP(task)
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
void IOSTROpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Input
void Input()
{
    cin >> s;
    n = (int)(s.length());
}

//Process
void Process()
{
    MEMS(F, 0);
    for(int i=0; i<n; ++i) F[i][i] = 1;
    for(int i=n-1; i>=0; --i)
    {
        for(int j=i+1; j<n; ++j)
        {
            F[i][j] = (s[i] == s[j]) ? F[i+1][j-1]+2 : max(F[i+1][j], F[i][j-1]);
        }
    }
}

//Output
void Output()
{
    int firstpiv=0, lastpiv=n-1;
    string LPart, RPart;
    while(firstpiv<=lastpiv)
    {
        if(s[firstpiv]==s[lastpiv])
        {
            LPart += s[firstpiv];
            RPart = s[lastpiv] + RPart;
            ++firstpiv;
            --lastpiv;
        }
        else
        {
            if (F[firstpiv+1][lastpiv]==F[firstpiv][lastpiv]) ++firstpiv;
            else --lastpiv;
        }
    }
    //if ((F[0][n-1]&1)) RPart.erase(1, 1);
    if ((F[0][n-1]&1)) LPart.erase((int)(LPart.size())-1, 1);
    res = LPart + RPart;
    cout << res;
}

//Main Procedure
int main()
{
    Input();
    Process();
    Output();
    return 0;
}
