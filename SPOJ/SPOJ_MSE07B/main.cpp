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
typedef pair<int, int> ii;
typedef set<ii> sii;
sii::iterator ptr;
sii sett;
int stat;

//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    stat = 2222;
    while(stat != 0)
    {
        scanf("%d", &stat);
        if(stat == 0) break;
        switch(stat)
        {
        case 1:
            {
                int x, y;
                scanf("%d%d", &x, &y);
                sett.insert(ii(y, x));
                break;
            }
        case 2:
            {
                if(!sett.empty())
                {
                    ptr = sett.end();
                    --ptr;
                    printf("%d\n", ptr->second);
                    sett.erase(ptr);
                }
                else printf("0\n");
                break;
            }
        case 3:
            {
                if(!sett.empty())
                {
                    ptr = sett.begin();
                    printf("%d\n", ptr->second);
                    sett.erase(ptr);
                }
                else printf("0\n");
                break;
            }
        }
    }
    return 0;
}
