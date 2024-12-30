#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i < 100)
        {
            cnt++;
        }
        else if (i < 1000)
        {
            int a = i / 100;
            int b = (i % 100) / 10;
            int c = i % 10;
            if (a - b == b - c)
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}
// 입력 최대 1000 
// 완전 탐색으로 품.
// 100 미만은 무조건 매자리가 등차, 100 이상은 자릿수 쪼개서 똑같은지 확인.
// 입력값이 1000이하로 고정되어 어렵진 않은거 같다.