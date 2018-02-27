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
#define task "test"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define MODUL (int)(123456789)
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
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
int n, nVtx, res1, st1, st2;
vvi d1, d2;
vc res2;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    char age, orien, src, dst, ss1, ss2;
    int cost, vsrc, vdst;

    d1 = d2 = vvi(27, vi(27, MODUL));
    res2.clear();

    FOR(i, 1, n)
    {
        //scanf("%c %c %c %c %d", &age, &orien, &src, &dst, &cost);
        cin >> age >> orien >> src >> dst >> cost;

        vsrc = src - 'A', vdst = dst - 'A';
        nVtx = max(nVtx, max(vsrc, vdst));
        if(orien == 'U')
        {
            if(age == 'Y') d1[vsrc][vdst] = cost;
            else if(age == 'M') d2[vsrc][vdst] = cost;
        }
        else if(orien == 'B')
        {
            if(age == 'Y') d1[vsrc][vdst] = d1[vdst][vsrc] = cost;
            else if(age == 'M') d2[vsrc][vdst] = d2[vdst][vsrc] = cost;
        }

    }

    //scanf("%c %c", &ss1, &ss2);
    cin >> ss1 >> ss2;

    st1 = ss1 - 'A', st2 = ss2 - 'A';

    FOR(i, 0, nVtx) d1[i][i] = d2[i][i] = 0;
}

//Process
void Solve()
{
    FOR(k, 0, nVtx)
    {
        FOR(i, 0, nVtx)
        {
            FOR(j, 0, nVtx)
            {
                d1[i][j] = min(d1[i][k] + d1[k][j], d1[i][j]);
                d2[i][j] = min(d2[i][k] + d2[k][j], d2[i][j]);
            }
        }
    }

    res1 = MODUL;
    FOR(i, 0, nVtx)
    {
        int tmp = d1[st1][i] + d2[st2][i];
        if(res1 > tmp)
        {
            res1 = tmp;
            res2.clear();
            res2.push_back((char)(i + (int)('A')));
        }
        else if(res1 == tmp)
        {
            res2.push_back((char)(i + (int)('A')));
        }
    }

    if(res1 == MODUL) printf("You will never meet.\n");
    else
    {
        printf("%d", res1);
        for(auto x: res2) printf(" %c", x);
        puts("");
    }

}


//Output
void Multitest()
{
    while(scanf("%d", &n) == 1 && n)
    {
        Enter();
        Solve();
    }
}



//Main Procedure
int main()
{
    //FILEOP();

    Multitest();
    return 0;
}
