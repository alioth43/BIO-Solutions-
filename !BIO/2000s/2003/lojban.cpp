// https://olympiad.org.uk/papers/2002/bio/bio02ex.pdf

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string num;
    cin >> num;
    // cout << num.size();

    map<string, int> mp;
    mp["pa"] = 1;
    mp["re"] = 2;
    mp["ci"] = 3;
    mp["vo"] = 4;
    mp["mu"] = 5;
    mp["xa"] = 6;
    mp["ze"] = 7;
    mp["bi"] = 8;
    mp["so"] = 9;
    mp["no"] = 0;

    bool nz = false;
    for (int i = 0; i < num.size(); i += 2)
    {
        string ans;
        ans.assign(1, num[i]);
        ans += num[i + 1];
        cout << mp[ans];
    }
}