#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "CAR"
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<y; ++j)

//=====================================
//Typedef
struct C4R
{
    int a;    //Fine
    int b;    //Time requirement
    int id;
};
vector<C4R> vect;
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
bool cmp(C4R x, C4R y)
{
    return (y.b*x.a) > (x.b*y.a);
    //return (b.second*a.first) > (a.second*b.first);
}

//Input
void Input()
{
    cin >> n;
    FORi(1, n)
    {
        C4R x;
        cin >> x.a;
        x.id = i;
        vect.push_back(x);
    }
    FORi(0, n-1)
    {
        cin >> vect[i].b;
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
        day+=vect[i].b;
        res+=day*vect[i].a;
    }
    cout << res << endl;
    FORj(0, n) cout << vect[j].id << ' ';
}

int main()
{
    //FileInit();
    Input();
    Process();
    //FileClose();
    return 0;
}
