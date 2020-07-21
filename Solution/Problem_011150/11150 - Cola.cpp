//  Author : Amit Kumar 
//  Date   : Tuesday 21 July 2020 03:18:14 PM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int int64_t
pair<int,int> sol(int a){
    int drink = a;
    int remaining = 0;
    while((a+remaining)>=3){
        int pr_r = remaining;
        remaining = (a + remaining) % 3; 
        a = (a+pr_r)/3;
        drink += a;
    }
    return make_pair(drink , a+remaining);
}
signed main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    ios::sync_with_stdio(false); // FLUSH THE STREAM IF USING puts / printf / scanf/
    cin.tie(nullptr);            // DISABLE FOR INTERACTIVE PROBLEMS
    cout.tie(nullptr);           //
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    int n; 
    while(cin >> n){
        int ans{};
        pair<int,int> a= sol(n); 
        ans = a.first;
        pair<int,int> b= sol(n+1); 
        if(b.second >= 1){
            ans = max(ans , b.first-1);
        }
        pair<int,int> c= sol(n+2);
        if(c.second >= 2){
            ans = max(ans , c.first-2);
        }
        cout << ans << '\n'; 
    }
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
