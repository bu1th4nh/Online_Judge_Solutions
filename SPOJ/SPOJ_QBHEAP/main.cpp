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
priority_queue<int, vi, less_equal<int>> pq;
string t;
vi res;


//=====================================
//Functions and procedures
int main()
{
    while(cin >> t)
    {
        if(t[0] == '+')
        {
            t.erase(0, 1);
            int tmp = strtol(t.c_str(), NULL, 0);
            if(pq.size() < 15000) pq.push(tmp);
        }
        else
        {
            if(t[0] == '-')
            {
                if(!pq.empty())
                {
                    int tmp = pq.top();
                    while(!pq.empty() && pq.top()==tmp) pq.pop();
                }
            }
            else break;
        }
    }

    while(!pq.empty())
    {
        int tmp = pq.top();
        while(!pq.empty() && pq.top()==tmp) pq.pop();
        res.push_back(tmp);
    }

    printf("%d\n", res.size());

    FORl(i, 0, res.size())
    {
        printf("%d\n", res[i]);
    }

    return 0;
}
