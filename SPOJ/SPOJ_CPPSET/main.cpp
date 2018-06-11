//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
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
typedef set<int>::iterator st;
typedef set<int> si;
si myset;


//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    set<int>::iterator it;
    int state = -1;
    while(state != 0)
    {
        scanf("%d", &state);
        if(state == 0) return 0;
        switch (state)
        {
        case 1:
            {
                int x;
                scanf("%d", &x);
                myset.insert(x);
                break;
            }
        case 2:
            {
                int x;
                scanf("%d", &x);
                if(!myset.empty() && myset.find(x)!=myset.end())
                {
                    myset.erase(x);
                }
                break;
            }
        case 3:
            {
                if(myset.empty())
                {
                    printf("empty\n");
                    break;
                }
                else
                {
                    printf("%d\n", (*myset.begin()));
                }
                break;
            }
        case 4:
            {
                if(myset.empty())
                {
                    printf("empty\n");
                    break;
                }
                else
                {
                    set<int>::iterator it = myset.end();
                    printf("%d\n", (*--it));
                }
                break;
            }
        case 5:
            {
                if(myset.empty())
                {
                    printf("empty\n");
                    break;
                }
                else
                {
                    int x;
                    scanf("%d", &x);
                    it = myset.upper_bound(x);
                    if(it == myset.end()) printf("no\n");
                    else printf("%d\n", (*it));
                }
                break;
            }
        case 6:
            {
                if(myset.empty())
                {
                    printf("empty\n");
                    break;
                }
                else
                {
                    int x;
                    scanf("%d", &x);
                    it = myset.lower_bound(x);
                    if(it == myset.end()) printf("no\n");
                    else printf("%d\n", (*it));
                }
                break;
            }
        case 7:
            {
                if(myset.empty())
                {
                    printf("empty\n");
                    break;
                }
                else
                {
                    int x;
                    scanf("%d", &x);
                    it = myset.lower_bound(x);
                    if(it == myset.begin()) printf("no\n");
                    else printf("%d\n", (*--it));
                }
                break;
            }
        case 8:
            {
                if(myset.empty())
                {
                    printf("empty\n");
                    break;
                }
                else
                {
                    int x;
                    scanf("%d", &x);
                    it = myset.upper_bound(x);
                    if(it == myset.begin()) printf("no\n");
                    else printf("%d\n", (*--it));
                }
                break;
            }
        }
    }
    return 0;
}
