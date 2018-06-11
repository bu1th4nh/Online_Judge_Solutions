//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
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
#define maxvalueinp (int)(1010)
#define MODUL (1000000000)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef vector<int> vi;
int d[maxvalueinp][maxvalueinp];
int F[maxvalueinp];
int n;
vi price;
int res;

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


//Main Procedure
int main()
{
    res = MODUL;
    price.push_back(0);
    //MEMS(d, MODUL);
    MEMS(F, 0);
    d[0][0] = 0;
    F[0] = 0;
    cin >> n;
    FORi(1, n)
    {
        int x;
        cin >> x;
        F[i] = (x>100) ? F[i-1]+1 : F[i-1];
        price.push_back(x);
    }
    FORi(1, n)
    {
        FORj(0, F[i])
        {
            d[i][j] = MODUL;
            if(j<=F[i-1]) d[i][j] = d[i-1][j] + price[i];
            if(price[i]>100 && j>0) d[i][j] = min(d[i][j], d[i-1][j-1]+price[i]);
            if(j<F[i-1]) d[i][j] = min(d[i][j], d[i-1][j+1]);
        }
    }
    FORi(0, F[n])
    {
        res = min(res, d[n][i]);
    }
    cout << res;
    return 0;
}
