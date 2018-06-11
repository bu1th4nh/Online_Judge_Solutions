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
int nTest;
string s;


//=====================================
//Functions and procedures
//Check
bool IsAll9(string _t)
{
    FOR(i, 0, _t.length()-1)
    {
        if(_t[i] != '9') return false;
    }
    return true;
}


//Process
void Solve()
{
    int n = s.size();
    if(IsAll9(s))
    {
        string res = "1";
        FOR(i, 1, n-1)
        {
            res += '0';
        }
        res += '1';
        printf("%s\n", res.c_str());
    }
    else
    {
        int i = n / 2;
        int j = i;
        if(n % 2 == 0) --i;
        while(i>=0 && s[i] == s[j])
        {
            --i, ++j;
        }
        if(i<0 || s[i] < s[j])
        {
            i = n / 2, j = i;
            if(n%2 == 0) --i;
            int tmp = 1;
            while(i>=0)
            {
                int num = (s[i] - '0') + tmp;
                tmp = num / 10;
                s[i] = (num%10) + '0';
                s[j] = s[i];
                ++j, --i;
            }
        }
        else
        {
            while(i>=0)
            {
                s[j] = s[i];
                ++j, --i;
            }
        }
        printf("%s\n", s.c_str());
    }
}


//Output
void Multit()
{
    scanf("%d", &nTest);
    FOR(kkkkk, 1, nTest)
    {
        char xxx[1048576];
        scanf("%s", &xxx);
        s = string(xxx);
        Solve();
    }
}



//Main Procedure
int main()
{
    Multit();
    return 0;
}
