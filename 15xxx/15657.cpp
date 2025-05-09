#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
int seq[10];
void func(int cnt, int k){
    if(cnt == m) {
        for(int i = 0; i < m; i++) cout << arr[seq[i]] <<" ";
        cout << "\n";
        return ;
    }
    for(int i = k; i < n; i++){
        seq[cnt] = i;
        func(cnt+ 1, i);
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //constraints
    //1<=n,m<=8
    //1<= i <= 10_000
    cin >> n >> m;
    for(int i=0; i < n;i++) cin >> arr[i];
    sort(arr, arr+n);
    func(0,0); 
}
