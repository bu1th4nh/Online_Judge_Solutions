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
#define maxvalueinp (int)(65536)
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
vi seq;


//=====================================
//Functions and procedures
//Input
void Input()
{
    seq.push_back(0);
    scanf("%d", &n);
    FOR(i, 1, n)
    {
        int x;
        scanf("%d", &x);
        seq.push_back(x);
    }
}


//Check
int BinarySearch(int i, int j)
{
    int l = 1;
    int r = j;
    while(l<r)
    {
        int k = (l+r+1) / 2;
        if (seq[F[k]] < seq[i])
        {
            l = k;
        }
        else r = k - 1;
    }
    return l;
}



//Process
void Process()
{
    res = 1;
    F[1] = 1;
    FOR(i, 2, n)
    {
        if(seq[i]<seq[F[1]])
        {
            F[1] = i;
        }
        else if(seq[i] > seq[F[res]])
        {
            ++res;
            F[res] = i;
        }
        else
        {
            int mid = BinarySearch(i, res);
            if(seq[i] > seq[F[mid]] && seq[i]<seq[F[mid + 1]]) F[mid+1] = i;
        }
    }
    printf("%d", res);
}



//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
