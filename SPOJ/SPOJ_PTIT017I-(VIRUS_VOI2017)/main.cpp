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
#define task "virus"
#define fi first
#define se second
#define maxinp (int)(4096)
#define MODUL (int)(1e9+57)
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
int F[maxinp];
int nQuery, n;
string t;
vi vect;
ll cnt;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP(task)
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
void IOSTROpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Enter
void Enter()
{
	MEMS(F, 0);
	scanf("%d", &nQuery);
	cin.ignore(1);
	getline(cin, t);
	n = t.size();
	t = '0' + t;
}


//Process
void Solve()
{
    FOR(i, 1, n-1)
    {
        FOR(j, i, n)
        {
            int diff = 0;
            int lgth = j - i + 1;
            if(j + lgth > n) break;
            FOR(k, i, j)
            {
                if(t[k] != t[k+lgth]) ++diff;
            }
            F[diff] = max(F[diff], j-i+1);
        }
    }
}
void Test()
{
    cin >> n;
    cnt = 0LL;
    Solve();
    cout << cnt;
}

//Output
void Print()
{
	int x;
	FOR(i, 1, nQuery)
	{
	    scanf("%d", &x);
	    printf("%d\n", F[x]);
	}
}

//Main Procedure
int main()
{
    freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);
    Enter();
    Solve();
    Print();
    return 0;
}
