#include <bits/stdc++.h>
using namespace std;

struct Grid
{
    // if red connected = 1, if green connected = 0
    bool north, south, east, west;
};

void setGrid(Grid g, int type)
{
    if (type == 1)
    {
        g.north = 1;
        g.south = 1;
        g.east = 0;
        g.west = 0;
    }
    else if (type == 2)
    {
        g.north = 0;
        g.south = 0;
        g.east = 1;
        g.west = 1;
    }
    else if (type == 3)
    {
        g.north = 1;
        g.west = 1;
        g.south = 0;
        g.east = 0;
    }
    else if (type == 4)
    {
        g.north = 1;
        g.east = 1;
        g.south = 0;
        g.west = 0;
    }
    else if (type == 5)
    {
        g.north = 0;
        g.west = 0;
        g.south = 1;
        g.east = 1;
    }
    else
    {
        g.north = 0;
        g.east = 0;
        g.west = 1;
        g.south = 1;
    }
}

int main()
{

    int n, k;
    cin >> n;

    Grid graph[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> k;
            setGrid(graph[i][j], k);
        }
    }

    cout << graph[0][0].west;
}