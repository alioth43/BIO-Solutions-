// https://olympiad.org.uk/papers/2003/bio/bio03ex.pdf

// 1a: 24/24
// 1b: 2/2
// 1c: Not Attempted 35 mins left.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    char isbn[10];
    cout << "ISBN: ";
    cin >> isbn;

    int factor;
    int total = 0;
    for (int i = 0; i < 10; i++)
    {
        int num;
        // cout << isbn[i];
        if (isbn[i] == 88)
        {
            num = 10;
            total += num * (10 - i);
        }
        else if (isbn[i] == 63)
        {
            factor = i;
        }
        else
        {
            num = isbn[i] - 48;
            total += num * (10 - i);
        }
    }
    total = total % 11;

    cout << "Missing Digit: ";
    char ans;
    for (int i = 0; i < 11; i++)
    {
        if (((10 - factor) * i + total) % 11 == 0)
        {
            if (i == 10)
            {
                cout << "X";
            }
            else
            {
                cout << i;
            }

            break;
        }
    }
}