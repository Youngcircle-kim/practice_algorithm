#include <bits/stdc++.h>
using namespace std;
int a1, a0, c, n, d;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a1 >> a0;
    cin >> c;
    cin >> n;

    d = (c - a1) * n;
    if (d >= a0 && c - a1 >= 0)
    {
        cout << 1;
        return 0;
    }
    cout << 0;
}
// 1차함수의 대소를 비교하는 문제
// f(n) = a1*n + a0
// g(n) = c*n
// g(n)이 n0보다 큰 x범위에서 항상 같거나 위에 있어야 한다.
// d(n) = (c-a1)* n >= a0로 양변을 이항하여 풀었다.