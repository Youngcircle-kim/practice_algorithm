#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(4);
    string str;
    int N = 0;
    while (getline(cin, str))
    {
        N++;
        m[str]++;
    }
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        cout << iter->first << " " << (double)iter->second / N * 100 << "\n";
    }
}
// 사용 알고리즘 : 없음
// 사용 자료구조 : Key-Value 형태의 Map
// 입력이 들어올 때까지 반복문을 돌힌다. 돌아가는 중 Key Value 자료구조로 Count해준다.