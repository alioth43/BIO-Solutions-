// https://olympiad.org.uk/papers/2006/bio/bio06-exam.pdf

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    map<int, int> mpa;
    map<int, int> mpb;
    set<char> letters;
    // cout << "A: " << a << endl;
    // cout << "B: " << b << endl;

    for (int i = 0; i < a.size(); i++)
    {
        if (mpa.find(a[i]) != mpa.end())
        {
            mpa[a[i]]++;
        }
        else
        {
            mpa[a[i]] = 1;
        }
        letters.insert(a[i]);
    }

    for (int i = 0; i < b.size(); i++)
    {
        if (mpb.find(a[i]) != mpb.end())
        {
            mpb[b[i]]++;
        }
        else
        {
            mpb[b[i]] = 1;
        }
    }

    bool same = true;

    for (char c : letters)
    {
        if (mpa[c] != mpb[c])
        {
            same = false;
        }
    }
    // cout << same;

    if (same)
    {
        cout << "Anagrams";
    }
    else
    {
        cout << "Not anagrams";
    }
    return 0;
}

// ! TEST: FORT, FORTY fails.
/*
SUMMER
RESUME
*/