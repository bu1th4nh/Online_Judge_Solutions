#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>
#define NAME "VMUNCH."
using namespace std;

const int tx[4]={0,0,-1,1},ty[4]={-1,1,0,0};

int r,c; const int maxr=100+5,maxc=100+5;
char A[maxr][maxc];
int L[maxr][maxc];
queue <int> qx,qy;

int main()
{
    //freopen(NAME"inp","r",stdin);
    //freopen(NAME"out","w",stdout);
    cin>>r>>c;
    memset(L,20000,sizeof(L));
    for (int i=1;i<=r;i++)
        for (int j=1;j<=c;j++)
        {
            cin>>A[i][j];
            if (A[i][j]=='C') {qx.push(i); qy.push(j); L[i][j]=0;}
        }
    while (!qx.empty() && !qy.empty())
    {
        int x=qx.front(),y=qy.front();
        qx.pop(); qy.pop();
        for (int i=0;i<4;i++)
        {
            int x1=x+tx[i], y1=y+ty[i];
            if (1<=x1 && x1<=r && 1<=y1 && y1<=c && A[x1][y1]!='*' && L[x1][y1]>L[x][y]+1)
            {
                L[x1][y1]=L[x][y]+1;
                qx.push(x1); qy.push(y1);
            }
        }
    }
    cout<<L[1][1];
}
