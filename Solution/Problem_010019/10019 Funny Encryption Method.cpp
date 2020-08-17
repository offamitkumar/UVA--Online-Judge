#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int change2(int n ){
    int counter{};
    while(n){
        counter+=(n%2);
        n/=2; 
    }
    return counter;
}
int change16(int n){
    int counter{}; 
    while(n){
        counter += change2(n%10);
        n/=10;
    }
    return counter;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        cout << change2(n) << ' '; 
        cout << change16(n) << '\n';
    }
    return 0;
}
