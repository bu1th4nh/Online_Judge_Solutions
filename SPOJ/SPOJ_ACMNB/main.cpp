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
#define maxvalueinp ()
#define MODUL (int)(10e9+57)
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define whole(x) x.begin(), x.end()
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
struct PROB
{
    int a;
    int b;
};
vector <PROB> vect;
int n;
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

//Input
void Input()
{
    cin >> n;
    FORi(1, 2*n)
    {
        PROB x;
        cin >> x.a >> x.b;
        vect.push_back(x);
    }
}

//Check
bool cmp(PROB x, PROB y)
{
    return x.a + y.b < x.b + y.a;
}


//Process
void Process()
{
    res = 0;
    sort(whole(vect), cmp);
    int mid = n;
    FORli(0, mid)
    {
        res += vect[i].a;
    }
    FORli(mid, 2*n)
    {
        res += vect[i].b;
    }
    cout << res;
}

//Output

//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
