//  Author : Amit Kumar 
//  Date   : Monday 20 July 2020 04:30:38 PM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int int64_t

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
    int t; cin >> t; 
    while(t--){
        int h , m; char ch; cin >> h >> ch >> m; 
        h = 23 - h; 
        m = 60 - m; 
        if(m == 60){ 
            h++;
            m=0;
        }
        if(h>12){
            h -=12;
        }
        cout << setfill('0') << setw(2) << h; 
        cout <<':';
        cout << setfill('0') << setw(2) << m; 
        cout << '\n'; 
    }
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
