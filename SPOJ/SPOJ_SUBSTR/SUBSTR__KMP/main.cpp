///==================================== SPOJ - Problem SUBSTR =====================================///
///========================== Solved by Knuth - Morris - Pratt Algorithm ==========================///
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
int pi[1048576];
string src, cmp;
int m, n;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	getline(cin, src);
	getline(cin, cmp);
	m = src.length();
	n = cmp.length();
	src = '?' + src;
	cmp = '?' + cmp;
}

//Check
void Solve()
{
    pi[0] = -1;
    FOR(i, 1, n)
    {
        pi[i] = 0;
        for(int j = pi[i-1]; j != -1; j = pi[j])
        {
            if(cmp[j+1] == cmp[i])
            {
                pi[i] = j+1;
                break;
            }
        }
    }

    int u = 0;
    FOR(i, 1, m)
    {
        while(u != 0 && cmp[u+1] != src[i]) u = pi[u];
        if(cmp[u+1] == src[i]) ++u;
        if(u == n) printf("%d ", i-n+1);
    }
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
