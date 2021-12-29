#include <bits/stdc++.h>
using namespace std;

bool ispat(string s)
{
    if (s.size() == 1)
    {
        return true;
    }

    bool pat = false;
    for (int i = 1; i < s.size(); i++)
    {
        string a = "", b = "";
        char mina = s[0], maxb = s[s.size() - 1];
        for (int j = 0; j < i; j++)
        {
            a += s[j];
            mina = min(mina, s[j]);
        }
        for (int j = i; j < s.size(); j++)
        {
            b += s[j];
            maxb = max(maxb, s[j]);
        }
        if (maxb >= mina)
        {
        }
        else
        {

            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            if (ispat(a) && ispat(b))
            {
                return true;
            };
        }
    }
    return pat;
}

int main()
{
    // string s1, s2;
    // cin >> s1 >> s2;
    // string s3 = s1;
    // s3 += s2;

    // string s1;
    // while (cin >> s1)
    // {
    //     cout << ispat(s1) << "\n";
    // };

    // if (ispat(s1))
    // {
    //     cout << "YES\n";
    // }
    // else
    // {
    //     cout << "NO\n";
    // }

    // if (ispat(s2))
    // {
    //     cout << "YES\n";
    // }
    // else
    // {
    //     cout << "NO\n";
    // }

    // if (ispat(s3))
    // {
    //     cout << "YES\n";
    // }
    // else
    // {
    //     cout << "NO\n";
    // }

    // string s1 = "ABCD";
    // do
    // {
    //     if (ispat(s1))
    //     {
    //         cout << "YES: " << s1 << endl;
    //     }
    // } while (next_permutation(s1.begin(), s1.end()));

    string s1 = "BACDEFGHIJKLMNOPQRSTUVWXYZ";
    int total = 0;
    do
    {
        total += ispat(s1);
    } while (next_permutation(s1.begin(), s1.end()));
    cout << total;
}