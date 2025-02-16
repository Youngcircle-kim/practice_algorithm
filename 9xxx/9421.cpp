#include <bits/stdc++.h>
using namespace std;

int sumD(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int in;
    cin >> in;

    vector<bool> arr(in + 1, false);

    for (int i = 2; i * i <= in; i++)
    {
        if (!arr[i])
        {
            for (int j = i * i; j <= in; j += i)
            {
                arr[j] = true;
            }
        }
    }

    for (int i = 2; i <= in; i++)
    {
        if (arr[i])
            continue; 

        int tmp = sumD(i);
        unordered_set<int> htr;

        while (tmp != 1 && htr.find(tmp) == htr.end()) 
        {
            htr.insert(tmp);
            tmp = sumD(tmp);
        }

        if (tmp != 1) 
        {
            for (int e : htr)
            {
                arr[e] = true;
            }
            arr[i] = true; 
        }
    }

    for (int i = 2; i <= in; i++)
    {
        if (!arr[i]) 
        {
            cout << i << "\n";
        }
    }
}