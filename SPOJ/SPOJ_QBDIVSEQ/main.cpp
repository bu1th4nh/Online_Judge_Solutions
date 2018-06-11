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
int F[maxvalueinp];
int n, res;
vi vect;


//=====================================
//Functions and procedures
//Input
void Input()
{
    scanf("%d", &n);
    vect.push_back(-89999);
    FOR(i, 1, n)
    {
        int x;
        scanf("%d", &x);
        vect.push_back(x);
    }
}


//Check
int BinarySearch(int index, int num)
{
    int l = 1;
    int r = num;
    while(l<r)
    {
        int k = (l+r)/2;
        if(vect[F[k]] > vect[index]) l = k+1;
        else r = k;
    }
    return l;
}


//Process
void Process()
{
    F[1] = 1;
    res = 1;
    FOR(i, 2, n)
    {
        if(vect[i] < vect[F[res]])
        {
            ++res;
            F[res] = i;
        }
        else F[BinarySearch(i, res)] = i;
    }
    printf("%d", res);
}


//Output





//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
