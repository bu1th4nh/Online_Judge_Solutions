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
#define maxinp (int)(128)
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
typedef pair<ii, int> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
int r, k, n, m, nPeople, res;
int reach[maxinp][maxinp];
int plres[maxinp];
int Count[maxinp];
viii house;
vii place;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
	int u, v, s;
	nPeople = res = 0;
	scanf("%d%d", &k, &r);
	scanf("%d", &m);
	FOR(i, 1, m)
	{
    	scanf("%d%d", &u, &v);
	    place.push_back(ii(u, v));
	}
	scanf("%d", &n);
	FOR(i, 1, n)
	{
	    scanf("%d%d%d", &u, &v, &s);
	    house.push_back(iii(ii(u, v), s));
	    nPeople += s;
	    Count[i] = 0;
	}
}

//Check
void Check(int cur, int nIgnored, int nPlaced)
{
    if(cur == m)
    {
        int nServ = 0;
        int mark[maxinp] = {0};
        FOR(i, 0, k-1)
        {
            int idRest = plres[i];

            FOR(j, 0, Count[idRest]-1)
            {
                int idHouse = reach[idRest][j];
                if(mark[idHouse] == 0)
                {
                    nServ += house[idHouse].se;
                    mark[idHouse] = 1;
                }
                if(nServ == nPeople) break;
            }
        }

        if(nServ > res) res = nServ;
        return;
    }

    if(res == nPeople) return;

    if(nPlaced < k)
    {
        plres[nPlaced] = cur;
        Check(cur + 1, nIgnored, nPlaced + 1);
        if(res == nPeople) return;
    }

    if(nIgnored < m - k)
    {
        Check(cur + 1, nIgnored + 1, nPlaced);
    }
}



//Process
void Solve()
{
    FOR(i, 0, m-1)
    {
        FOR(j, 0, n-1)
        {
            int tmp = (house[j].fi.fi - place[i].fi)*(house[j].fi.fi - place[i].fi) + (house[j].fi.se - place[i].se)*(house[j].fi.se - place[i].se);
            if(tmp <= r*r) reach[i][Count[i]++] = j;
        }
    }

    Check(0, 0, 0);

    printf("%d", res);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
