// https://olympiad.org.uk/papers/2002/samples/bio02smp.pdf

#include <bits/stdc++.h>

using namespace std;

// ! Part c not finished yet. 15 mins left.

int main()
{
    int friends, wordlen;
    vector<int> out, remaining;
    cout << "Number of friends: ";
    cin >> friends;
    cout << "Words in rhyme: ";
    cin >> wordlen;

    for (int i = 0; i < friends; i++)
    {
        remaining.push_back(i + 1);
    }

    int ind = 1;
    cout << remaining.size() << "\n";
    while (remaining.size() != 1)
    {
        ind = (ind - 1 + wordlen) % remaining.size();
        if (!ind)
        {
            ind += remaining.size();
        }

        // cout << ind - 1 << " " << remaining[ind - 1];

        // Order they leave:
        // cout << remaining[ind - 1] << " ";

        out.push_back(remaining[ind - 1]);
        remaining.erase(remaining.begin() + ind - 1);
        // cout << " " << ind << "\n";
    }
    cout << "\nAnswer: " << remaining[0];
}
