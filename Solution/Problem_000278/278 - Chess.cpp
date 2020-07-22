//  Author : Amit Kumar 
//  Date   : Wednesday 22 July 2020 01:47:58 PM IST

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
        char ch; cin >> ch; int m , n; cin >> n >> m; 
        switch(ch){
            case 'r': 
                cout << min(m,n) << '\n'; 
                break; 
            case 'Q':
                cout << min(m,n) << '\n'; 
                break; 
            case 'k':
                cout << (((m+1)/2) * ((n+1)/2)) + ((m/2) * (n/2)) << '\n'; 
                break; 
            case 'K':
                cout << (((m+1)/2) * ((n+1)/2)) << '\n'; 
                break;
        }
    }
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
