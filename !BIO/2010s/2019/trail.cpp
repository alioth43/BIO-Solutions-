// https://olympiad.org.uk/papers/2019/bio/bio19-exam.pdf

#include <bits/stdc++.h>
using namespace std;

queue<tuple<int, int>> trail;
set<tuple<int, int>> seen;

void solve()
{
    int max, moves, facing = 0;
    string instructions;
    cin >> max >> instructions >> moves;
    int x = 0, y = 0, move = 1, leng = instructions.size();

    while (move <= moves)
    {
        int newx = x, newy = y;
        int ind = move % leng;
        if (ind == 0)
        {
            ind = leng;
        }
        ind--;
        // cout << instructions[ind] << " ";
        if (instructions[ind] == 70)
        {
            bool moved = false;
            int count = 0;
            while (!moved)
            {
                // move forward
                if (facing == 0)
                {

                    if (!seen.count({x, y + 1}))
                    {
                        // facing north & square in front not on trail
                        newy = y + 1;
                        moved = true;
                    }
                    else
                    {
                        facing = (facing + 1) % 4;
                        count++;
                    }
                }
                else if (facing == 1)
                {
                    if (!seen.count({x + 1, y}))
                    {
                        newx = x + 1;
                        moved = true;
                    }
                    else
                    {
                        facing = (facing + 1) % 4;
                        count++;
                    }
                }
                else if (facing == 2)
                {
                    if (!seen.count({x, y - 1}))
                    {
                        newy = y - 1;
                        moved = true;
                    }
                    else
                    {
                        facing = (facing + 1) % 4;
                        count++;
                    }
                }
                else if (facing == 3)
                {
                    if (!seen.count({x - 1, y}))
                    {
                        newx = x - 1;
                        moved = true;
                    }
                    else
                    {
                        facing = (facing + 1) % 4;
                        count++;
                    }
                }
                if (count > 4)
                {
                    cout << "(" << x << "," << y << ")" << endl;
                    return;
                }
            }
        }
        else if (instructions[ind] == 76)
        {
            bool moved = false;
            int count = 0;
            // move left

            while (!moved)
            {
                if (facing == 0)
                {
                    // facing north & square in front not on trail
                    if (!seen.count({x - 1, y}))
                    {
                        newx = x - 1;
                        moved = true;
                    }
                    else
                    {
                        facing = (facing + 1) % 4;
                        count++;
                    }
                }
                else if (facing == 1)
                {
                    if (!seen.count({x, y + 1}))
                    {
                        newy = y + 1;
                        moved = true;
                    }
                    else
                    {
                        facing = (facing + 1) % 4;
                        count++;
                    }
                }
                else if (facing == 2)
                {
                    if (!seen.count({x + 1, y}))
                    {
                        newx = x + 1;
                        moved = true;
                    }
                    else
                    {
                        facing = (facing + 1) % 4;
                        count++;
                    }
                }
                else if (facing == 3)
                {
                    if (!seen.count({x, y - 1}))
                    {
                        newy = y - 1;
                        moved = true;
                    }

                    else
                    {
                        facing = (facing + 1) % 4;
                        count++;
                    }
                }
                if (count > 4)
                {
                    cout << "(" << x << "," << y << ")" << endl;
                    return;
                }
            }
            facing = (facing + 3) % 4;
        }
        else if (instructions[ind] == 82)
        {
            bool moved = false;
            int count = 0;
            while (!moved)
            {
                // move right
                if (facing == 0)
                {
                    if (!seen.count({x + 1, y}))
                    {
                        // facing north & square in front not on trail
                        newx = x + 1;
                        moved = true;
                    }
                    else
                    {
                        facing = (facing + 1) % 4;
                        count++;
                    }
                }
                else if (facing == 1)
                {
                    if (!seen.count({x, y - 1}))
                    {
                        newy = y - 1;
                        moved = true;
                    }
                    else
                    {
                        facing = (facing + 1) % 4;
                        count++;
                    }
                }
                else if (facing == 2)
                {
                    if (!seen.count({x - 1, y}))
                    {
                        newx = x - 1;
                        moved = true;
                    }
                    else
                    {
                        facing = (facing + 1) % 4;
                        count++;
                    }
                }
                else if (facing == 3)
                {
                    if (!seen.count({x, y + 1}))
                    {
                        newy = y + 1;
                        moved = true;
                    }
                    else
                    {
                        facing = (facing + 1) % 4;
                        count++;
                    }
                }

                if (count > 4)
                {
                    cout << "(" << x << "," << y << ")" << endl;
                    return;
                }
            }
            facing = (facing + 1) % 4;
        }

        // * Adjust the trail
        if (trail.size() == max)
        {
            // if size of queue = MAX
            // remove first element
            tuple<int, int> fr = trail.front();
            trail.pop();
            seen.erase(fr);
        }
        trail.push({x, y});
        // cout << "(" << x << "," << y << ")" << endl;
        seen.insert({x, y});

        x = newx;
        y = newy;

        move++;
    }
    cout << "(" << x << "," << y << ")" << endl;
    return;
}

int main()
{
    solve();
}
