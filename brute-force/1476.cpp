#include <bits/stdc++.h>
using namespace std;
int E, S, M;
int a, b, c;
// 100만이 넘는 연산이 필요하지 않을거 같아. 완전 탐색을 시도했다.
int main()
{
    cin.tie(0);
    cin >> E >> S >> M;
    for (int year = 0;; year++)
    {
        if (a == E && b == S && c == M)
        {
            cout << year;
            break;
        }
        a++;
        b++;
        c++;
        if (a > 15)
            a = 1;
        if (b > 28)
            b = 1;
        if (c > 19)
            c = 1;
    }
}