// https://olympiad.org.uk/papers/2004/bio/bio04ex.pdf

#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> mp;

    // TODO optimise this if necessary
    mp["kin"] = 1;
    mp["uinal"] = 20;
    mp["tun"] = 18 * 20;
    mp["katun"] = 20 * 18 * 20;
    mp["baktun"] = 20 * 20 * 18 * 20;

    int baktun, katun, tun, uinal, kin;
    cin >> baktun >> katun >> tun >> uinal >> kin;

    long long totalday = 0;
    totalday += baktun * mp["baktun"];
    totalday += katun * mp["katun"];
    totalday += tun * mp["tun"];
    totalday += uinal * mp["uinal"];
    totalday += kin * mp["kin"];

    cout << endl
         << baktun * mp["baktun"] << endl;
    cout << katun * mp["katun"] << endl;
    cout << tun * mp["tun"] << endl;
    cout << uinal * mp["uinal"] << endl;
    cout << kin * mp["kin"] << endl;

    cout << "Total Days: " << totalday << endl;

    int year = 0;
    while (totalday > 1461)
    {
        // passing of leap year (4 years)
        year += 4;
        totalday -= 1461;
    }
    cout << "Years(x4): " << year << endl;
}