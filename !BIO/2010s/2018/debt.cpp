#include <bits/stdc++.h>
using namespace std;

float calculateInterest(float interest, float amount)
{
    float added = ceil(interest * amount);
    // cout << "Added: " << added;
    amount += added;
    // cout << " Amount: " << amount << endl;
    return amount;
}

float calculateRepayment(float repayment, float amount, float &paid)
{
    float repay = ceil(amount * repayment);
    // cout << "Calc.: " << repay << " ";
    if (repay < 5000)
    {
        repay = 5000;
    }

    if (amount <= repay)
    {
        paid += amount;
        amount = 0;
    }
    else
    {
        amount -= repay;
        paid += repay;
    }
    // cout << "Repaid: " << repay << " Amount: " << amount << endl;
    return amount;
}

void solve()
{
    float interest, repayment;

    float amount = 10000, paid = 0;
    cin >> interest >> repayment;
    interest /= 100;
    repayment /= 100;
    // cout << interest << " " << repayment << endl;
    while (amount > 0)
    {
        // cout << "HERE!";
        amount = calculateInterest(interest, amount);
        amount = calculateRepayment(repayment, amount, paid);
    }
    cout << paid / 100;

    // while (amount > 0)
    // {
    //     float debt = ceil(round(amount * interest));
    //     amount += debt;
    //     float repay = ceil(round(amount * repayment));
    //     if
    // }
}

int main()
{
    solve();
}
