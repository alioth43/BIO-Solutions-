#include <bits/stdc++.h>
using namespace std;

vector<string> rows;

string simplify(string s)
{
    int leng = s.size();
    string new_s = "";
    for (int i = 0; i < leng - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            new_s += s[i];
        }
        else
        {
            if (s[i] == 82 && s[i + 1] == 71)
            {
                new_s += "B";
            }
            else if (s[i] == 82)
            {
                new_s += "G";
            }
            else if (s[i] == 71 && s[i + 1] == 82)
            {
                new_s += "B";
            }
            else if (s[i] == 71)
            {
                new_s += "R";
            }
            else if (s[i] == 66 && s[i + 1] == 71)
            {
                new_s += "R";
            }
            else
            {
                new_s += "G";
            }
        }
    }
    return new_s;
}

int main()
{
    string s;
    cin >> s;

    if (s.size() == 1)
    {
        cout << s;
        return 0;
    }

    while (simplify(s).size() != 1)
    {
        s = simplify(s);
    }
    cout << simplify(s);
    // G = 71
    // R = 82
    // B = 66
}