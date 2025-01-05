#include <bits/stdc++.h>
using namespace std;
string dp[10001];
int n;
string sum(string a, string b)
{
    string result = "";
    int carry = 0;

    while (a.size() || b.size())
    {
        int num1 = 0, num2 = 0;
        if (a.size())
        {
            num1 = a.back() - '0'; 
            a.pop_back();
        }
        if (b.size())
        {
            num2 = b.back() - '0'; 
            b.pop_back();
        }
       
        int currentSum = num1 + num2 + carry;
        result += to_string(currentSum % 10); 
        carry = currentSum / 10;             
    }


    if (carry)
    {
        result += "1";
    }

    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp[0] = "0";
    dp[1] = "1";

    for (int i = 2; i <= n; i++)
    {
        dp[i] = sum(dp[i - 1],dp[i - 2]);
    }

    cout << dp[n];
}