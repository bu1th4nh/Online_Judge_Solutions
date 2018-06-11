///===================================== SPOJ - Problem NHAY ======================================///
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
string src, cmp;
int n, m;
vi Z;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    cin.ignore(1);
	getline(cin, cmp);
	getline(cin, src);
	src = cmp + '?' + src;
	m = src.length();
}

//Z Function
void MakeZ()
{
    int l = 0, r = 0;
    Z = vi(m+2, 0);
    Z[0] = m;
    FORl(i, 1, m)
    {
        if(i > r)
        {
            l = r = i;
            while(r < m && src[r] == src[r - l]) ++r;
            Z[i] = r - l, --r;
        }
        else
        {
            int k = i - l;
            if(Z[k] < r - i + 1) Z[i] = Z[k];
            else
            {
                l = i;
                while(r < m && src[r] == src[r - l]) ++r;
                Z[i] = r - l, --r;
            }
        }
    }
}

//Process
void Solve()
{
    int cnt = 0;
    FORl(i, n + 1, m) if(Z[i] >= n)
    {
        printf("%d\n", i - n - 1);
        ++cnt;
    }
    if(cnt == 0) printf("\n\n");
}

//Multi-test data processing
void MTest()
{
    while(scanf("%d", &n) == 1)
    {
        Enter();
        MakeZ();
        Solve();
    }
}

//Main Procedure
int main()
{
    MTest();
    return 0;
}
