#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cnt = 0;int n = 0;
    string s;
    cin >> n >> s;
    for(int i = 1; i < s.size(); ++i)
    {
        if(s[i] == s[i-1]) ++cnt;
    }
    cout << cnt;
    return 0;
}
