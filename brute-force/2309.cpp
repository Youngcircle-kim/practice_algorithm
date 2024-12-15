#include <bits/stdc++.h>
using namespace std;
int N = 9;
int a;
vector<int> sol;
// 9개의 입력값 중 답이 아닌 2개만 찾으면 되는 문제인거 같다.
// 9C2=36이니 많은 연산이 필요하지 않을것 같다. 완전 탐색으로 풀어도 될거 같다.
int main()
{
    cin.tie(0);
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        sol.push_back(a);
        sum += a;
    }
    bool found = false;
    for (int i = 0; i < N && !found; i++)
    {
        for (int j = i + 1; j < N && !found; j++)
        {
            int c = sol[i] + sol[j];
            if (sum - c == 100)
            {
                sol.erase(sol.begin() + j);
                sol.erase(sol.begin() + i);
                found = true;
            }
        }
    }

    sort(sol.begin(), sol.end());
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << '\n';
    }
}