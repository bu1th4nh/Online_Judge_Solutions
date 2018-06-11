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
#define maxvalueinp (int)(110)
#define MODUL (int)(10e9+57)
#define len(xxx) (int)(xxx.length())
#define siz(xxx) (int)(xxx.size())
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
string F[maxvalueinp];
vector<int> query;
int n;
int TEST;


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
int CVTInt(char t)
{
    return static_cast<int>(t-'0');
}
char CVTChr(int t)
{
    return static_cast<char>(t+48);
}


string AddBigNum(string x, string y)
{
    while(len(x) < len(y)) x = '0' + x;
    while(len(x) > len(y)) y = '0' + y;
    string S = "";
    int carry = 0;
    int sum = 0;
    FORbi(len(x)-1, 0)
    {
        sum = CVTInt(x[i]) + CVTInt(y[i]) + carry;
        carry = (int)(sum/10);
        //sum %= 10;
        S = CVTChr(sum%10) + S;
    }
    if (carry>0) S = '1' + S;
    return S;
}

//Process
void PreProcess()
{
    //MEMS(F, 0);
    //F[0] = 0;
    F[1] = '1';
    F[2] = '2';
    F[3] = '3';
    FORi(3, 100)
    {
        F[i] = AddBigNum(F[i-1], F[i-2]);
    }
}


//Output
void MultiTest()
{
    cin >> TEST;
    FORj(1, TEST)
    {
        int x;
        cin >> x;
        query.push_back(x);
    }
    FORi(0, TEST-1) cout << F[query[i]] << endl;
}



//Main Procedure
int main()
{
    PreProcess();
    //cout << F[100];
    MultiTest();
    return 0;
}
