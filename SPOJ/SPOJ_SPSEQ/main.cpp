//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(131072)
#define MODUL (int)(1e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef vector<int> vi;
int T[maxvalueinp];
int S[maxvalueinp];
int F[maxvalueinp];
int n, res;
vi vect;

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
    vect.push_back(0);
    scanf("%d", &n);
    FOR(i, 1, n)
    {
        int x;
        scanf("%d", &x);
        vect.push_back(x);
    }
}


//Check
int BinarySearch(int index, int d)
{
    int l = 1;
    int r = d;
    while(l<r)
    {
        int k = (l+r) >> 1;
        if(vect[F[k]] < vect[index])
        {
            l = k + 1;
        }
        else
        {
            r = k;
        }
    }
    return l;
}


//Process
void Process()
{
    F[1] = 1;
    int d = 1;
    FOR(i, 2, n)
    {
        if(vect[i] > vect[F[d]])
        {
            ++d;
            F[d] = i;
            S[i] = d;
        }
        else
        {
            int j = BinarySearch(i, d);
            F[j]  = i;
            S[i]  = j;
        }
    }


    FOR(i, 1, n>>1)
    {
        swap(vect[i], vect[n-i+1]);
    }



    F[1] = 1;
    d = 1;
    FOR(i, 2, n)
    {
        if(vect[i] > vect[F[d]])
        {
            ++d;
            F[d] = i;
            T[i] = d;
        }
        else
        {
            int j = BinarySearch(i, d);
            F[j]  = i;
            T[i]  = j;
        }
    }
}


//Output
void Outut()
{
    res = 0;
    FOR(i, 1, n)
    {
        res = max(res, 2*min(S[i], T[n-i+1]) - 1);
    }
    printf("%d", res);
}



//Main Procedure
int main()
{
    Input();
    Process();
    Outut();
    return 0;
}
