#include<bits/stdc++.h>
using namespace std;
int n, k;
bool isPrime(int a){
    if(a == 1) return 0;
    for(int i = 2; i * i <= a; i++){
        if(a%i == 0 ) return 0;
    }
    return 1;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int cnt = 0;
    while(n--){
        cin >> k;
        cnt += isPrime(k);
    }
    cout << cnt << '\n';
}
