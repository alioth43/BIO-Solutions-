// https://olympiad.org.uk/papers/2014/bio/bio14-exam.pdf

#include <bits/stdc++.h>
using namespace std;

vector<int> luckies;

int v = 3;

void cull(int count, int start)
{
    int length = luckies.size();
    for (int i = length - (length - start) % count; i >= 0; i -= count)
    {
        luckies.erase(luckies.begin() + i - 1);
    }
}

int main()
{
    for (int i = 1; i < 11000; i += 2)
    {
        luckies.push_back(i);
    }

    for (int i = 1; i < 1e4; i++)
    {
    }
}