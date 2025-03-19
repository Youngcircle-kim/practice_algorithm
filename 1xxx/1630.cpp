#include <bits/stdc++.h>
using namespace std;
int N;
const long long moduler = 987654321;
bool p_number[1000004];
vector<int> p_numbers;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // constraint : 0 < N < 1,000,000
    // example 1 : 10 -> 2520(2^3 * 3^2 * 5* 7)
    cin >> N;
    // input보다 작은 소수 찾고, 가장 큰 소인수의 제곱수를 곱해주는거 
    for (int i = 2; i <= N; i++)
    {
        for (int j = 2 * i; j <= N; j += i)
        {
            p_number[j] = 1;
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (!p_number[i])
        {
            p_numbers.push_back(i);
        }
    }
    long long res = 1;
    for (auto p : p_numbers)
    {
        if (p > N)
            break;
        long long cur = p;
        while (cur * p <= N)
        {
            cur *= p;
        }
        res = (res * cur) % moduler;
    }
    cout << res;
}