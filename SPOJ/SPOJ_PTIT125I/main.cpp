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
#define maxvalueinp (int)()
#define MODUL (int)(10e9+57)
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
typedef deque<char> dqc;
string s;
int n, k;
dqc deq;
//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    scanf("%d%d", &n, &k);
    cin >> s;
    s = 'X' + s;
    n = len(s) - 1;
    deq.push_front(s[1]);
    FOR(i, 2, n)
    {
        while(!deq.empty() && s[i]>deq.front() && k>0)
        {
            --k;
            deq.pop_front();
        }
        deq.push_front(s[i]);
    }
    while(!deq.empty())
    {
        cout << deq.back();
        deq.pop_back();
    }
    return 0;
}
