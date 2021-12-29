#include <bits/stdc++.h>
using namespace std;

map<string, bool> visited;
map<string, vector<string>> adj;
queue<string> q;
map<string, int> dist, removals;
map<string, string> parent;

string invrot(string str)
{
    string a = "";
    a += str[str.size() - 1];
    for (int i = 0; i < str.size() - 1; i++)
    {
        a += str[i];
    }
    return a;
}

string invadd(string str)
{
    string a = "";
    if (str.size() == (str[str.size() - 1]) - 64)
    {
        for (int i = 0; i < str.size() - 1; i++)
        {
            a += str[i];
        }
        return a;
    }
    return str;
}

string invswap(string str)
{
    string a = "";
    a += str[1];
    a += str[0];
    for (int i = 2; i < str.size(); i++)
    {
        a += str[i];
    }
    return a;
}

int solve(string inp, string goal)
{
    int leng = inp.size();

    // * BFS for goal string, using inverse operations
    dist[inp] = 0;
    visited[inp] = true;
    parent[inp] = "";
    removals[inp] = 0;
    q.push(inp);

    while (!q.empty())
    {
        string str = q.front();
        q.pop();
        cout << "Looking at: " << str << endl;

        string rot = invrot(str);
        if (visited[rot])
        {
        }
        else
        {
            visited[rot] = true;
            dist[rot] = dist[str] + 1;
            parent[rot] = str;
            if (rot == goal && removals[rot] == leng)
            {
                return dist[rot];
            }
            q.push(rot);
        }

        string addd = invadd(str);
        if (visited[addd])
        {
        }
        else
        {
            visited[addd] = true;
            dist[addd] = dist[str] + 1;
            parent[addd] = str;
            removals[addd] = removals[str] + 1;
            if (addd == goal && removals[addd] == leng)
            {
                return dist[addd];
            }
            q.push(addd);
        }

        string swapp = invswap(str);
        if (visited[swapp])
        {
        }
        else
        {
            visited[swapp] = true;
            dist[swapp] = dist[str] + 1;
            parent[swapp] = str;
            if (swapp == goal && removals[swapp] == leng)
            {
                return dist[swapp];
            }
            q.push(swapp);
        };
    }
    return 1e9;
}

int main()
{
    string s;
    cin >> s;

    // * define goal string
    int leng = s.size();
    string goal = "";
    // for (int i = 0; i < leng; i++)
    // {
    //     goal += (char)(65 + i);
    // }

    cout << "GOAL: " << goal << "\n";

    cout << solve(s, goal) << endl;

    while (parent[goal] != "")
    {
        cout << parent[goal] << "<-";
        goal = parent[goal];
    }
}