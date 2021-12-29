#include <bits/stdc++.h>
using namespace std;

vector<char> first, second, dummy;

int remove_ele(int n, int loc)
{
    int ind = (loc + n - 1) % dummy.size();
    second.push_back(dummy[ind]);
    dummy.erase(dummy.begin() + ind);
    // cout << ind << " ";
    return ind;
}

int main()
{
    for (int i = 0; i < 26; i++)
    {
        first.push_back((char)65 + i);
    }
    dummy = first;

    int n;
    cin >> n;
    int loc = 0;
    while (dummy.size())
    {
        loc = remove_ele(n, loc);
        // cout << loc << endl;
    }
    // cout << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << second[i];
    }
    cout << endl;

    string s;
    cin >> s;
    string output = "";

    for (int i = 0; i < s.size(); i++)
    {
        output += second[(s[i] + i - 65) % 26];
    }

    cout << output;
}