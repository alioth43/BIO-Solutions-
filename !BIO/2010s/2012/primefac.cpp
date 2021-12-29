// https://olympiad.org.uk/papers/2012/bio/bio12-exam.pdf

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int total = 1;
    for (int i = 2; i <= N; i++)
    {
        if (N % i == 0)
        {
            total *= i;
            while (N % i == 0)
            {
                N /= i;
            }
        }
    }
    cout << total;
}