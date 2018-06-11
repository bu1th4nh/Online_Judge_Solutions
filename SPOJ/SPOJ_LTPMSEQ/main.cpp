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
typedef map<string, int> msi;
typedef pair<int, int> ii;
typedef set<string> sstr;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
sstr StrSet;
msi MapStr;
char s[15];
string t;
int n;


//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    scanf("%d", &n);
    FOR(i, 1, n)
    {
        scanf("%s", &s);
        t = string(s);
        ++MapStr[t];
        StrSet.insert(t);
    }
    for(string s: StrSet)
    {
        if(MapStr[s] & 1)
        {
            printf("%s", s.c_str());
            return 0;
        }
    }
    printf("-1");
    return 0;
}
