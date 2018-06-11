///==================================== SPOJ - Problem SUBSTR =====================================///
///==================================== Solved by Z Algorithm =====================================///
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
string src, cmp, X;
int n, m;
vi Z;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	getline(cin, src);
	getline(cin, cmp);
	src = cmp + '?' + src;
	n = src.length();
	m = cmp.length();
}

//Z - Function
void MakeZ()
{
    int l = 0, r = 0;
    Z = vi(n+2, 0);
    Z[0] = n;
    FORl(i, 1, n)
    {
        if(i > r)
        {
            l = r = i;
            while(r < n && src[r] == src[r - l]) ++r;
            Z[i] = r - l, --r;
        }
        else
        {
            int k = i - l;
            if(Z[k] < r - i + 1) Z[i] = Z[k];
            else
            {
                l = i;
                while(r < n && src[r] == src[r - l]) ++r;
                Z[i] = r - l, --r;
            }
        }
    }

}


//Process
void Solve()
{
    MakeZ();
    FORl(i, m + 1, n) if(Z[i] >= m)
    {
        printf("%d ", i - m);
    }
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
