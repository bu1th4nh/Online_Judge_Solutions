#include <bits/stdc++.h>
using namespace std;

//=====================================
//Macros
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORlj(x, y) for(int j=x; j<y; ++j)
#define FORlk(x, y) for(int k=x; k<y; ++k)

//=====================================
//Typedef
typedef map<char, int> mci;
typedef unsigned int ui;
typedef stack<int> si;
mci element;
string s;
si mass;
int res;
ui n;

//=====================================
//Functions and procedures
//Initialization
void DeterMass()
{
    element['('] = 0;
    element['H'] = 1;
    element['C'] = 12;
    element['N'] = 14;
    element['O'] = 16;
    element['F'] = 18;
    element['P'] = 31;
    element['I'] = 127;
    element['U'] = 238;
}
int ChrToInt(char t)
{
    return (static_cast<int> (t)) - (static_cast<int> ('0'));
}

//Input
void Input()
{
    cin >> s;
    n = s.length();
}

//Check
bool IsElementOrOB(char t)
{
    return (element.find(t)!=element.end());
}
bool IsNum(char t)
{
    return (t>='2')&&(t<='9');
}

//Calculate
void CalcCompound()
{
    int local = 0;
    while (mass.top()!=0)
    {
        local += mass.top();
        mass.pop();
    }
    mass.pop();
    mass.push(local);
}
void Multiply(int x)
{
    int local = mass.top()*x;
    mass.pop();
    mass.push(local);
}

//Process
void Process()
{
    res = 0;
    FORli(0, n)
    {
        if(IsElementOrOB(s[i])) mass.push(element[s[i]]);
        else if(IsNum(s[i])) Multiply(ChrToInt(s[i]));
        else CalcCompound();
    }
    while (!mass.empty())
    {
        res+=mass.top();
        mass.pop();
    }
    cout << res;
}


int main()
{
    Input();
    DeterMass();
    Process();
    return 0;
}
