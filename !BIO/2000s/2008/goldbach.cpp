#include <bits/stdc++.h>
using namespace std;

bool checkprime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    int sol = 0;

    for (int i = 2; i <= floor(n / 2); i++)
    {
        if (checkprime(i) && checkprime(n - i))
        {
            // cout << i << " ";
            sol++;
        }
    }
    cout << sol;
}

int main()
{
    solve();
}