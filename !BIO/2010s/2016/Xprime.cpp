#include <bits/stdc++.h>
using namespace std;

vector<long long> twos;

bool isprime(long long n)
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

int main()
{
    int MAX, p, q;
    cin >> MAX >> p >> q;

    for (int i = 0; pow(2, i) <= MAX; i++)
    {
        twos.push_back(-1 * pow(2, i));
        twos.push_back(pow(2, i));
    }

    int maxt = twos.back();
    int dp[MAX];
    dp[0] = 1;
}