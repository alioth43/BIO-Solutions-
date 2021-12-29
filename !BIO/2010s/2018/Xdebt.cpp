#include <bits/stdc++.h>
using namespace std;

float repaid = 0;
float start = 100;
int interest, repayment;

float twodp(float repaid)
{
    repaid = round(repaid * 100);
    return repaid / 100;
}

void interes(int interest)
{
    // cout << interest;
    // float percent = interest / 100;
    start += (start * interest) / 100;
}

void repaycalc(int repayment)
{
    float calcrepay = (start * repayment) / 100;
    float repay = max(calcrepay, (float)50);

    if (repay >= start)
    {

        repay = start;
        // cout << "Repaid: " << repay << endl;
        repaid += repay;
        start = 0;
    }
    else
    {
        start -= repay;
        // cout << "Repaid: " << repay << endl;
        repaid += repay;
    }
}

int main()
{

    cin >> interest >> repayment;
    while (start)
    {
        interes(interest);
        // cout << start << " ";
        repaycalc(repayment);
        // cout << start << "\n";
    }

    cout << twodp(repaid);
}