#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "CAR"
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)

//=====================================
//Typedef
typedef pair<int, int> p2i;
vector <p2i> vect;
int n, day;
int res;

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
bool cmp(p2i a, p2i b)
{
    return (b.second*a.first) > (a.second*b.first);
}

//Input
void Input()
{
    cin >> n;
    FORi(1, n)
    {
        p2i x;
        cin >> x.first;
        vect.push_back(x);
    }
    FORi(0, n-1)
    {
        cin >> vect[i].second;
    }
}

//Process
void Process()
{
    sort(whole(vect), cmp);
    res = 0;
    day = 0;
    FORi(0, n-1)
    {
        day+=vect[i].second;
        res+=day*vect[i].first;
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
