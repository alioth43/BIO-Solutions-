#include <bits/stdc++.h>
using namespace std;

int keypad[5][5];
int copyk[5][5];

void print_keypad()
{
    cout << "Printing keypad:\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << keypad[i][j] << " ";
        }
        cout << "\n";
    }
}

void reset_keypad()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            keypad[i][j] = copyk[i][j];
        }
    }
}

void toggle(int x, int y)
{
    keypad[y][x] = (keypad[y][x] + 1) % 3;
    if (y > 0)
    {
        keypad[y - 1][x] = (keypad[y - 1][x] + 1) % 3;
    }
    if (y < 4)
    {
        keypad[y + 1][x] = (keypad[y + 1][x] + 1) % 3;
    }
    if (x > 0)
    {
        keypad[y][x - 1] = (keypad[y][x - 1] + 1) % 3;
    }
    if (x < 4)
    {
        keypad[y][x + 1] = (keypad[y][x + 1] + 1) % 3;
    }
}

void simulate(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] > 96)
        {
            int left = s[i] - 97;
            int xc = left % 5;
            int yc = left / 5;
            toggle(xc, yc);
        }
        else
        {
            int left = s[i] - 65;
            int xc = left % 5;
            int yc = left / 5;
            toggle(xc, yc);
            toggle(xc, yc);
        }
    }
}

int main()
{
    // * implementation of keypad, with string input
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] > 96)
        {
            int left = s[i] - 97;
            int xc = left % 5;
            int yc = left / 5;
            keypad[yc][xc] = 1;
        }
        else
        {
            int left = s[i] - 65;
            int xc = left % 5;
            int yc = left / 5;
            keypad[yc][xc] = 2;
        }
    }
    print_keypad();
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            copyk[i][j] = keypad[i][j];
        }
    }

    print_keypad();

    // toggle(2, 3);
    // toggle(2, 3);
    // toggle(3, 3);
    // toggle(3, 3);
    // toggle(4, 3);
    // toggle(4, 3);
    print_keypad();
}

/*
0 0 0 0 0
0 0 0 0 0
0 0 1 1 1
0 1 2 0 2 
0 0 1 1 1
*/