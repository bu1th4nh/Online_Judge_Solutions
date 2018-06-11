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
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<ull, ull> p2ll;
typedef vector<p2ll> vp;
int n, res;
vp vect;
ull b;


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
bool cmp(p2ll x, p2ll y)
{
    return x.first < y.first;
}

void DEBUG()
{
    cout << endl;
    FORli(0, siz(vect))
    {
        cout << vect[i].first << ' ' << vect[i].second << endl;
    }
}

int main()
{
    scanf("%d%I64d", &n, &b);
    FORi(1, n)
    {
        ull x, y;
        scanf("%I64d%I64d", &x, &y);
        vect.push_back(make_pair(x, y));
    }
    sort(whole(vect), cmp);
    DEBUG();
    res = 0;
    int i = 0;
    FORli(0, n)
    {
        if(b/vect[i].first < vect[i].second)
        {
            res+=b/(vect[i].first);
            break;
        }
        else
        {
            b -= vect[i].first*vect[i].second;
            res += vect[i].second;
        }
    }
    cout << res;
    return 0;
}
