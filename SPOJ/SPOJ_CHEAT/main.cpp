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
#define maxvalueinp (int)()
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
vi vect;
si stck;
int Max;
int n;


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
    Max = 0;
    vect.push_back(0);
    scanf("%d", &n);
    FORi(1, n)
    {
        int x;
        scanf("%d", &x);
        vect.push_back(x);
    }
    FORi(1, n)
    {
        if(vect[i]<Max)
        {
            if(vect[i]!=stck.top())
            {
                cout << "YES";
                return 0;
            }
            stck.pop();
        }
        else
        {
            FORj(Max+1, vect[i]-1) stck.push(j);
            Max = vect[i];
        }
    }
    cout << "NO";
    return 0;
}
