//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define MODUL (int)(1e9+57)
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int m, n, k, res;
string src, sam;

//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    res = 1234567890;
    scanf("%d%d%d", &n, &m, &k);
    char a[1024]; scanf("%s", &a); src = string(a);
    //cin >> src;

    while(k--)
    {
        scanf("%s", &a); sam = string(a);
        //cin >> sam;

        for(auto i = src.begin(); i != src.end(); i++)
        {
            auto j = i;
            int dis = 0;
            for(auto b: sam)
            {
                if(j == src.end()) j = src.begin();
                if(*j != b) ++dis;
                ++j;
            }
            if(res > dis) res = dis;
        }
    }

    printf("%d\n", res);
    return 0;
}
