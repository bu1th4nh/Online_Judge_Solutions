#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "DHEXP"
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<y; ++j)

//=====================================
//Typedef
vector <int> vect;
int n, k;
long long res;


//=====================================
//Function and procedures
//Initialization
void FileInit()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
bool cmp(int a, int b)
{
    return a>b;
}

//Input
void Input()
{
    cin >> n >> k;
    FORi(1, n)
    {
        int x;
        cin >> x;
        vect.push_back(x);
    }
}

void Process()
{
    sort(whole(vect), cmp);
    res = vect[0];
    FORi(1, k)
    {
        res += vect[i];
    }
    FORj(k+1, n)
    {
        res -= vect[j];
    }
    cout << res;
}

int main()
{
    FileInit();
    Input();
    Process();
    FileClose();
    return 0;
}
