#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

//=====================================
//Macros
#define task ""
#define maxn (int)(1e3+1)
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORlj(x, y) for(int j=x; j<y; ++j)
#define FORlk(x, y) for(int k=x; k<y; ++k)
#define FORbi(x, y) for(int i=x; i>=y; --i)

//=====================================
//Typedef
typedef stack<int> si;
typedef vector<int> vi;
int Left[maxn], Right[maxn];
int n, res;
si stck;
vi k;


//=====================================
//Functions and procedures
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
void IOSOpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Input
void Input()
{
    k.push_back(0);
    cin >> n;
    FORi(1, n)
    {
        int x;
        cin >> x;
        k.push_back(x);
    }
    k.push_back(0);
    k.push_back(0);
    k.push_back(0);
    k.push_back(0);
    k.push_back(0);
    k.push_back(0);
}

//Preparation
void Prep()
{
    //Prep Left[i]
    Left[1] = 0;
    stck.push(0);
    stck.push(1);
    FORi(2, n)
    {
        while(stck.size()>=1 && k[stck.top()]>=k[i]) stck.pop();
        Left[i] = stck.top();
        stck.push(i);
    }

    while(!stck.empty()) stck.pop(); //Cleanup

    //Prep Right[i]
    Right[n+1] = n+2;
    Right[n] = n+1;
    stck.push(n+1);
    stck.push(n);
    FORbi(n-1, 1)
    {
        while(stck.size()>=1 && k[stck.top()]>=k[i]) stck.pop();
        Right[i] = stck.top();
        stck.push(i);
    }
}

//Process
void Process()
{
    res = -INFINITY;
    FORi(1, n) res = max(res, k[i]*(Right[i] - Left[i] - 1));
    cout << res;
}

int main()
{
    Input();
    Prep();
    Process();
    return 0;
}
