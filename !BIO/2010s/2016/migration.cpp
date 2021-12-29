#include <bits/stdc++.h>
using namespace std;

int p, s, n;
int board[2005][2005] = {0};
vector<int> seq;

// * outputs board
void printboard()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << board[i + 1000][j + 1000] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void resolve_issue(int i, int j)
{
    board[i][j] -= 4;

    board[i - 1][j]++;
    board[i + 1][j]++;
    board[i][j - 1]++;
    board[i][j + 1]++;

    if (board[i - 1][j] >= 4)
    {
        resolve_issue(i - 1, j);
    }

    if (board[i][j - 1] >= 4)
    {
        resolve_issue(i, j - 1);
    }

    if (board[i + 1][j] >= 4)
    {
        resolve_issue(i + 1, j);
    }

    if (board[i][j + 1] >= 4)
    {
        resolve_issue(i, j + 1);
    }
}

int addp(int start, int jump)
{
    int newloc = (jump + start) % 25;
    if (newloc == 0)
    {
        newloc = 25;
    }
    int i = (floor((newloc - 1) / 5)) + 1000;
    int j = ((newloc - 1) % 5) + 1000;
    board[i][j]++;

    if (board[i][j] >= 4)
    {
        resolve_issue(i, j);
    }
    return newloc;
}

int main()
{
    cin >> p >> s >> n;

    // * Add to list of jumps
    for (int i = 0, k; i < s; i++)
    {
        cin >> k;
        seq.push_back(k);
    }

    int location = addp(p, 0);
    for (int i = 0; i < n - 1; i++)
    {
        location = addp(location, seq[i % s]);
        // cout << location << " ";
    }
    cout << endl;

    printboard();
}