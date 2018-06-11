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
#define maxvalueinp (int)(32768)
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
typedef pair<int, int> ii;
typedef vector<ii> vii;
int F[maxvalueinp];
int n, nTest;
ii vect[maxvalueinp];
int res;

//=====================================
//Functions and procedures
//Initialization
void Init()
{
    FOR(i, 1, n) F[i] = 0;
}

//Input
void Input()
{
    scanf("%d", &n);
    FOR(i, 1, n)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        vect[i] = ii(x, y);
    }
}


//Check
bool cmp(ii a, ii b)
{
    return (a.first < b.first) || (a.first == b.first && a.second < b.second);;
}
bool cmp2(ii a, ii b)
{
    return a.second >= b.second;
}


int BinarySearch(int index, int num)
{
    int l = 1;
    int r = num;
    while(l<r)
    {
        int k = (l+r) >> 1;
        if(vect[F[k]].second > vect[index].second)
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
    sort(vect+1, vect+n+1, cmp);


    /*
    cout << endl;
    FOR(i, 1, n)
    {
        cout << vect[i].first << " " << vect[i].second << endl;
    }
    //*/


    F[1] = 1;
    res = 1;
    FOR(i, 2, n)
    {
        if(vect[i].second < vect[F[res]].second)
        {
            res++;
            F[res] = i;
        }
        else F[BinarySearch(i, res)] = i;
    }
    printf("%d\n", res);

}


//Output
void Multitest()
{
    //Init();
    Input();
    Process();
}



//Main Procedure
int main()
{
    scanf("%d", &nTest);
    while(nTest--)
    {
        Multitest();
    }
    return 0;
}
