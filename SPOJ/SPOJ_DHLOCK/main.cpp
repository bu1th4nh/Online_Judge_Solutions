
#include <bits/stdc++.h>
using namespace std;


//=====================================
//Macros
#define task ""
#define fi first
#define se second
#define pb push_back
#define maxinp (int)(16)
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
int n, k, res, tmp2;
int stat[maxinp];
vi src, dst;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int x;
	src.push_back(-99);
	dst.push_back(-99);
	scanf("%d%d", &n, &k);
	FOR(i, 1, n)
	{
	    scanf("%d", &x);
	    src.push_back(x);
	}
	FOR(i, 1, n)
	{
	    scanf("%d", &x);
	    dst.push_back(x);
	}
}

//Check
void Process()
{
    int tmp;
    FOR(cnt, 0, n-1)
    {
        FOR(i, 1, n)
        {
            tmp = ((i + cnt) > n) ? ((i + cnt)%n) : (i + cnt);
            stat[i] = (dst[tmp] >= src[i]) ? (dst[tmp] - src[i]) : (dst[tmp] + k - src[i] + 1);
        }
        FOR(i, 1, n)
        {
            tmp2 = 0;
            tmp = stat[i];
            FOR(j, 1, n)
            {
                tmp2 += (stat[j] >= tmp) ? (stat[j] - tmp) : (stat[j] + k - tmp + 1);
            }
            if(res > tmp2 + cnt + tmp) res = tmp2 + tmp + cnt;
        }
    }
    printf("%d", res);
}

//Process
void Solve()
{
    res = 0;
    FOR(i, 1, n)
    {
        res += (dst[i] >= src[i]) ? (dst[i] - src[i]) : (dst[i] + k - src[i] + 1);
    }
    Process();
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
