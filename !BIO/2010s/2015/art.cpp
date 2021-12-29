#include <bits/stdc++.h>
using namespace std;

long long facts[20];

int main()
{
    int a, b, c, d;
    long long pos;
    cin >> a >> b >> c >> d >> pos;

    string art = "";
    for (int i = 0; i < a; i++)
    {
        art += "A";
    }
    for (int i = 0; i < b; i++)
    {
        art += "B";
    }
    for (int i = 0; i < c; i++)
    {
        art += "C";
    }
    for (int i = 0; i < d; i++)
    {
        art += "D";
    }

    long long current = 0;
    do
    {
        current++;
        if (current == pos)
        {
            cout << art;
            break;
        }
    } while (next_permutation(art.begin(), art.end()));
}