#include <bits/stdc++.h>

using namespace std;

// row, height
const char *board[7][6] = {"-"};
const char *t1 = "*";
const char *t2 = "o";
const char *empty = "-";

void addtoken(int c, const char *t)
{
    for (int i = 0; i < 6; i++)
    {
        if (board[c - 1][i] == empty)
        {
            board[c - 1][i] = t;
        }
    }
}

void printboard()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << board[j][i];
        }
    }
}

int main()
{
    int N, k;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> k;
        if (i % 2 == 0)
        {
            addtoken(k, t1);
        }
        else
        {
            addtoken(k, t2);
        }
    }

    printboard();
}

/*
9
3 2 3 4 4 4 2 2 3
*/