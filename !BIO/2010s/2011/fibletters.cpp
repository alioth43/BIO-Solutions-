// https://olympiad.org.uk/papers/2011/bio/bio2011-Round1-Exam.pdf

#include <bits/stdc++.h>
using namespace std;

long long vals[27][27];

const int MxN = 1e6;
int sols[MxN + 2];

int main()
{
    for (int i = 1; i < 27; i++)
    {
        for (int j = 1; j < 27; j++)
        {
            vals[i][j] = (i + j) % 26;
            if (vals[i][j] == 0)
            {
                vals[i][j] = 26;
            }
        }
    }

    char a, b;
    cin >> a >> b;
    int av = a - 64;
    int bv = b - 64;

    sols[0] = av;
    sols[1] = bv;
    int n;
    cin >> n;
    for (int i = 2; i < n + 2; i++)
    {
        sols[i] = vals[sols[i - 1]][sols[i - 2]];
        // cout << sols[i] << endl;
    }
    cout << (char)(sols[n - 1] + 64);
}