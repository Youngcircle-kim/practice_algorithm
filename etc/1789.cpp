#include <bits/stdc++.h>
using namespace std;
long long s, sum = 0, cnt = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for (int i = 1;; i++)
    {
        sum += i;
        if (sum > s)
        {
            cout << cnt;
            return 0;
        }
        cnt++;
    }
}
// N개의 자연수 합 = s가 되는 N의 최댓값 구하는 문제
// 작은 자연수 별로 더하다가, 어떤 i에서 S를 넘기는 상황이 발생하는데 그 때 멈추면 된다.