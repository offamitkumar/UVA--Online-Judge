#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int f(int current_bottle) {
    int drink{};
    while(current_bottle >= 3) {
        int buy=(current_bottle/3); 
        drink+=buy;
        current_bottle = (current_bottle%3); 
        current_bottle+=buy;
    }
    if(current_bottle == 2) {
        ++drink;
    }
    return drink;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n;
    while (cin >> n, n) {
        cout << f(n) << '\n'; 
    }
    return 0;
}
