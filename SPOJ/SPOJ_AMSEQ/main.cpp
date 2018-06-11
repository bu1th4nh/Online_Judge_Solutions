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
#define maxvalueinp (int)(10001)
#define MODUL (int)(10e9+57)
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbj(x, y) for(int j=x; j>=y; --j)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
vector<int> vect;
int F[maxvalueinp];
int n, k;

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
    vect.push_back(-999999);
    cin >> n >> k;
    FORi(1, n)
    {
        int x;
        cin >> x;
        vect.push_back(x);
    }
}

//Process
void Process()
{
    F[0] = 0;
    int maxx = 0;
    FORi(1, n)
    {
        F[i] = F[i-1] + vect[i];
        FORbj(i-2, i-k)
        {
            if (j>=0) F[i] = max(F[i], F[j]+vect[i]);
            else break;
        }
        maxx = max(maxx, F[i]);
    }
    cout << maxx;
}

//Output





//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
