#include <bits/stdc++.h>
using namespace std;

set<char> letters;

bool isblockchain(string chain)
{
    int leng = chain.size();
    int counts[leng] = {0};

    for (int i = 0; i < leng; i++)
    {
        for (int j = i + 1; j < leng; j++)
        {
            if (chain[i] < chain[j])
            {
                counts[i]++;
            }
        }
        if (counts[i] > 1)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    string left;
    cin >> n >> left;
    for (int i = 0; i < n; i++)
    {
        letters.insert((char)i + 65);
    }
    for (int i = 0; i < left.size(); i++)
    {
        letters.erase(left[i]);
    }

    string right = "";
    for (auto letter : letters)
    {
        right += letter;
    }

    // cout << left << " " << right;

    int sol = 0;
    do
    {
        string test = left + right;
        sol += isblockchain(test);
    } while (next_permutation(right.begin(), right.end()));
    cout << sol;
}

int main()
{
    solve();
}