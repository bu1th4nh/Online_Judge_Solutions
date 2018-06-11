///===================================== SPOJ - Problem NHAY ======================================///
///========================== Solved by Knuth - Morris - Pratt Algorithm ==========================///
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
int m, n;
vi pi;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    cin.ignore(1);
	getline(cin, cmp);
	getline(cin, src);
	m = src.length();
	src = '?' + src;
	cmp = '?' + cmp;
}

//KMP
void KMP()
{
    int cnt = 0, u = 0;
    pi = vi(n+1);
    pi[0] = -1;
    FOR(i, 1, n)
    {
        pi[i] = 0;
        for(int j = pi[i-1]; j != -1; j = pi[j])
        {
            if(cmp[j+1] == cmp[i])
            {
                pi[i] = j + 1;
                break;
            }
        }
    }

    FOR(i, 1, m)
    {
        while(u != 0 && cmp[u+1] != src[i]) u = pi[u];
        if(cmp[u+1] == src[i]) ++u;
        if(u == n)
        {
            printf("%d\n", i - n);
            ++cnt;
        }
    }
    if(cnt == 0) printf("\n\n");
}

//Multi-test data processing
void MTest()
{
    while(scanf("%d", &n) == 1)
    {
        Enter();
        KMP();
    }
}


//Main Procedure
int main()
{
    MTest();
    return 0;
}
