#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define MOD (int)(1e9+7)
#define task "C11ID"
#define whole(x) x+1, x+n+1
#define FORi(x, y) for(int i=x; i<=y; ++i)

//=====================================
//Typedef
int resi[100000];
int n;
int res;

//=====================================

int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    FORi(1, n)
    {
        cin >> resi[i];
    }
    sort(whole(resi));
    res = resi[1];
    FORi(2, n)
    {
        res =(res * (resi[i] - i + 1))%MOD;
    }
    cout << res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
