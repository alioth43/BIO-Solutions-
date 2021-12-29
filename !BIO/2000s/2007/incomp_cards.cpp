#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums;
    int a;
    for (int i = 0; i < 5; i++)
    {
        cin >> a;
        nums.push_back(a);
    }

    sort(nums.begin(), nums.begin() + 5);

    int fif = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 15)
                {
                    fif++;
                }
            }
        }
    }

    int same = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (nums[i] == nums[j])
            {
                same++;
            }
        }
    }

    int total = same + fif;
    cout << total;
}