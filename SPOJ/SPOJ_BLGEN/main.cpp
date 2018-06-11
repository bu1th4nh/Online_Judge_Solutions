//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task "TEST"
#define maxvalueinp (int)(2154435)
#define MODUL (int)(10e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORbj(x, y) for(int j=x; j>=y; --j)
#define FORbk(x, y) for(int k=x; k>=y; --k)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef vector<ull> vull;
vull src, dst, prime;
static int LP[maxvalueinp+1];
string srcstr, dststr;
map<ull, int> name;
int F[1010][1010];
int m, n;


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

//Check
void Sieve()
{
    FORi(2, maxvalueinp)
    {
        if(LP[i] == 0)
        {
            LP[i] = i;
            prime.push_back(i);
        }
        for(int j = 0; j<siz(prime) && prime[j]<=LP[i] && i*prime[j]<=maxvalueinp; ++j)
        {
            LP[i*prime[j]] = prime[j];
        }
    }
    FORli(0, siz(prime))
    {
        int k = prime[i];
        name[k*k*k] = 1;
    }
}
bool Check(ull t)
{
    ull SRT = (sqrt(t));
    if(SRT*SRT == t) return true;
    else if (name.find(t) != name.end()) return true;
    return false;
}

//Input
void Input()
{
    ull k;
    src.push_back(0);
    dst.push_back(0);
    getline(cin, srcstr);
    getline(cin, dststr);
    stringstream s1(srcstr);
    stringstream s2(dststr);
    //=============================================        ---> Source Processing
    while(s1 >> k)
    {
        if(Check(k)) src.push_back(k);
    }

    //=============================================        ---> Destination Processing
    while(s2 >> k)
    {
        if(Check(k)) dst.push_back(k);
    }

    //=============================================
    m = siz(src) - 1;
    n = siz(dst) - 1;
}


//Process
void Process()
{
    FORi(0, m) F[i][0] = 0;
    FORi(0, n) F[0][i] = 0;
    FORi(1, m)
    {
        FORj(1, n)
        {
            F[i][j] = (src[i] == dst[j]) ? F[i-1][j-1] + 1 : max(F[i-1][j], F[i][j-1]);
        }
    }
    cout << F[m][n];
}

//Main Procedure
int main()
{
    //FileInit();
    Sieve();
    Input();
    Process();
    return 0;
}
