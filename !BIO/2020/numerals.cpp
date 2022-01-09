#include <bits/stdc++.h>
using namespace std;

void count(string numeral)
{
    int is = 0, vs = 0;
    for (int i = 0; i < numeral.size(); ++i)
    {
        if (numeral[i] == 73)
        {
            ++is;
        }
        else if (numeral[i] == 86)
        {
            ++vs;
        }
    }
    cout << is << " " << vs << endl;
}

string roman(int n)
{
    string sol = "";
    if (n < 4)
    {
        for (int i = 0; i < n; i++)
        {
            sol += "I";
        }
    }
    else if (n == 4)
    {
        sol += "IV";
    }
    else
    {
        sol += "V";
    }
    return sol;
}

string look(string s)
{
    vector<char> letters;
    vector<int> counts;
    letters.push_back(s[0]);
    counts.push_back(1);
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] == letters[letters.size() - 1])
        {
            counts[counts.size() - 1]++;
        }
        else
        {
            letters.push_back(s[i]);
            counts.push_back(1);
        }
    }

    string output = "";
    for (int i = 0; i < letters.size(); ++i)
    {
        output += roman(counts[i]);
        output += letters[i];
    }
    return output;
}

void solve()
{
    string numeral;
    int n;
    cin >> numeral >> n;
    while (n-- > 0)
    {
        numeral = look(numeral);
    }

    count(numeral);
}

int main()
{
    solve();
}
