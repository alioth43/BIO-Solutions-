#include <bits/stdc++.h>
using namespace std;

bool check(string num)
{
    int leng = num.size();
    int mid = floor(leng / 2);
    for (int i = 0; i <= mid; i++)
    {
        if (num[i] != num[leng - i - 1])
        {
            return false;
        }
    }
    return true;
}

int find(string s)
{
    int leng = s.size();
    int mid = floor(leng / 2);
    string start = "";
    string end = "";

    for (int i = 0; i <= mid; i++)
    {
        if (s[i] == s[leng - i - 1])
        {
            start += s[i];
        }
        else if (s[i] > s[leng - i - 1])
        {
            start += s[i];
        }
        else
        {
            int add = s[i] - 48;
            add = (add + 1) % 10;
            if (!add)
            {
                // s[i-1]
            }
        }
    }
}

int main()
{
    string num;
    cin >> num;

    find(num);
}