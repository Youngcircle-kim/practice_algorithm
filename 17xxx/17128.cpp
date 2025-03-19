#include <bits/stdc++.h>
using namespace std;
int N, Q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;

    vector<int> A(N);
    vector<int> v(Q);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> v[i];
    }

    long long curSum = 0;
    vector<long long> sum(N, 1);

    for (int i = 0; i < N; i++)
    {
        sum[i] = 1;
        for (int j = 0; j < 4; j++)
        {
            sum[i] *= A[(i + j) % N]; // 원형 배열 처리
        }
        curSum += sum[i];
    }

    for (int i = 0; i < Q; i++)
    {
        int k = v[i] - 1;

        for (int j = 0; j < 4; j++)
        {
            int idx = (k - j + N) % N;
            curSum -= sum[idx];
            sum[idx] *= -1;
            curSum += sum[idx];
        }
        cout << curSum << "\n";
    }

    return 0;
}