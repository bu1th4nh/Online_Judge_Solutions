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
#define maxvalueinp (int)()
#define MODUL (int)(10e9+57)
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
int n;
vector<int> vect;
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
    scanf("%d", &n);
    res = 0;
    vect.push_back(-999);
    FORi(1, n)
    {
        int x;
        scanf("%d", &x);
        vect.push_back(x);
        res+=x;
    }
    sort(whole(vect));
    int tmp = n/2;
    if(n&1)
    {
        FORi(tmp+2, n) res+=vect[i];
        FORi(1, tmp) res-=vect[i];
    }
    else
    {
        FORi(tmp+1, n) res+=vect[i];
        FORi(1, tmp) res-=vect[i];
    }
    printf("%d", res);
    return 0;
}
