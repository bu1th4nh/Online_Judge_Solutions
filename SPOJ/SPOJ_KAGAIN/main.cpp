#include <iostream>
#include <stack>
#include <vector>
#include <memory>
#include <cmath>
#include <cstring>
using namespace std;
//=====================================
//Macros
#define task ""
#define maxn (int)(3e4+100)
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORlj(x, y) for(int j=x; j<y; ++j)
#define FORlk(x, y) for(int k=x; k<y; ++k)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))

//=====================================
//Typedef
typedef stack<int> si;
typedef vector<int> vi;
int Left[maxn], Right[maxn];
int resi, resj, respow;
int TEST;
int n;
si stck;
vi A;

//=====================================
//Functions and procedures
//Input
void Input()
{
    A.push_back(0);
    cin >> n;
    FORi(1, n)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
}

//Preparation
void Build()
{
    Left[1] = 0;
    stck.push(0);
    stck.push(1);
    FORi(2, n)
    {
        while(stck.size()>=1 && A[stck.top()]>=A[i]) stck.pop();
        Left[i] = stck.top();
        stck.push(i);
    }

    while (!stck.empty()) stck.pop(); //Sweep the stack

    Right[n+1] = 0;
    Right[n] = n+1;
    stck.push(n+1);
    stck.push(n);
    FORbi(n-1, 1)
    {
        while(stck.size()>=1 && A[stck.top()]>=A[i]) stck.pop();
        Right[i] = stck.top();
        stck.push(i);
    }

    while (!stck.empty()) stck.pop(); //Sweep the stack
}
void Clear()
{
    MEMS(Left, 0);
    MEMS(Right, 0);
    A.clear();
    respow = 0;
    resi = 0;
    resj = 0;
    n = 0;
}

//Process
void Process()
{
    respow = -INFINITY;
    FORi(1, n)
    {
        int pow = A[i]*(Right[i]-Left[i]-1);
        if(respow < pow)
        {
            respow = pow;
            resi = Left[i]+1;
            resj = Right[i]-1;
        }
    }
    cout << respow << " " << resi << " " << resj << endl;
}

//Multi-test
void Multitest()
{
    cin >> TEST;
    FORk(1, TEST)
    {
        Input();
        Build();
        Process();
        Clear();
    }
}

int main()
{
    Multitest();
    return 0;
}
