// https://olympiad.org.uk/papers/2013/bio/bio13-exam.pdf

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int sol = 0;
    int ta = (60 + a) % 1440, tb = (60 + b) % 1440;
    while (ta != tb)
    {
        ta += 60 + a;
        ta = ta % 1440;
        tb += 60 + b;
        tb = tb % 1440;
        sol++;
    }

    if (floor(ta / 60) < 10)
    {
        if (ta % 60 < 10)
        {
            cout << "0" << floor(ta / 60) << ":"
                 << "0" << ta % 60;
        }
        else
        {
            cout << "0" << floor(ta / 60) << ":"
                 << ta % 60;
        }
    }
    else if (ta % 60 < 10)
    {
        cout << floor(ta / 60) << ":"
             << "0" << ta % 60;
    }
    else
    {
        cout << floor(ta / 60) << ":" << ta % 60;
    }
}