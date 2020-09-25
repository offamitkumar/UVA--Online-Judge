#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int Get(int n) {
    int sum{};
    while(n){
        int t = (n%10); 
        n/=10;
        sum+=(t*t);
    }
    return sum;
}
bool happy(int n) {
    set<int>s; 
    while(s.find(n) == s.end()) {
        s.insert(n); 
        if(n == 1) {
            return true;
        }
        n = Get(n);
    }
    return false;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int i; 
    cin >> i;
    int counter=1;
    while(cin >>i){
        printf("Case #%ld: %ld",counter++,i);
        if(happy(i)) {
            puts(" is a Happy number.");
        }else {
            puts(" is an Unhappy number.");
        }
    }
    return 0;
}
