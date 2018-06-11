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
#define maxvalueinp (int)(100001)
#define MODUL (int)(10e9+57)
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
typedef stack<int> si;
typedef vector<int> vi;
vi vect, Left, Right;
int n, res;
si stck;

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
    scanf("%d", &n);
    Left.resize(n+2);
    Right.resize(n+2);
    vect.resize(n+2);
    FORi(1, n)
    {
        scanf("%d", &vect[i]);
    }
}

//Process
void PrepL()
{
    stck.push(0);
    FORi(1, n)
    {
        while(!stck.empty() && vect[stck.top()] >= vect[i]) stck.pop();
        if (!stck.empty()) Left[i] = stck.top();
        stck.push(i);
    }
    while(!stck.empty()) stck.pop(); //Cleanup
}
void PrepR()
{
    stck.push(n+1);
    FORbi(n, 1)
    {
        while(!stck.empty() && vect[stck.top()] >= vect[i]) stck.pop();
        if (!stck.empty()) Right[i] = stck.top();
        stck.push(i);
    }
}

//Output
void Output()
{
    res = 0;
    FORi(1, n)
    {
        if (Right[i] - Left[i] - 1 >= vect[i]) res = max(res, vect[i]);
    }
    printf("%d", res);
}

//Main Procedure
int main()
{
    Input();
    PrepL();
    PrepR();
    Output();
    return 0;
}
