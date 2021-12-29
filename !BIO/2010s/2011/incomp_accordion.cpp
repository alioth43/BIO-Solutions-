#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int>> shuffled;
vector<string> deck;
void shuffle(vector<string> deck, int numbers[6])
{
    int loc = 0;
    bool run = true;
    while (run)
    {
        for (int i = 0; i < 6; i++)
        {
            loc = (loc + (numbers[i] - 1) % deck.size()) % deck.size();
            shuffled.push_back({deck[loc], 1});
            deck.erase(deck.begin() + loc);
            if (deck.size() == 1)
            {
                run = false;
                break;
            }
        }
    }
    shuffled.push_back({deck[0], 1});
    cout << shuffled[0].first << " "
         << shuffled[shuffled.size() - 1].first << endl;
}

vector<string> types;
vector<string> values;

bool moveable(string a, string b)
{
    if (a[0] == b[0])
    {
        return true;
    }
    else if (a[1] == b[1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void strat1(vector<pair<string, int>> shuffled1)
{
    for (int i = shuffled1.size() - 1; i < 0;)
    {
        if (moveable(shuffled1[i].first, shuffled1[i - 1].first))
        {
            shuffled1[i - 1].first = shuffled1[i].first;
            shuffled1[i - 1].second += shuffled1[i].second;
            shuffled1.erase(shuffled1.begin() + i);
        }
    }
    cout << shuffled1.size() << " " << shuffled1[0].first;
}

int main()
{
    types.push_back("C");
    types.push_back("H");
    types.push_back("S");
    types.push_back("D");

    values.push_back("A");
    values.push_back("2");
    values.push_back("3");
    values.push_back("4");
    values.push_back("5");
    values.push_back("6");
    values.push_back("7");
    values.push_back("8");
    values.push_back("9");
    values.push_back("T");
    values.push_back("J");
    values.push_back("Q");
    values.push_back("K");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            string card = values[j];
            card += types[i];
            deck.push_back(card);
        }
    }

    int nums[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> nums[i];
    }

    shuffle(deck, nums);

    vector<pair<string, int>> shuffled1 = shuffled;
    strat1(shuffled1);
}