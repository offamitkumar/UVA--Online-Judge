//  Author : Amit Kumar 
//  Date   : Wednesday 22 July 2020 01:56:19 PM IST

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
    int n , m; 
    while(cin >> n >> m , n+m){
        int tn = n , tm = m; 
        if(n>m){swap(n,m);}
        if(n==1) cout << m;
        else if(n == 2) cout << m / 4 * 4 + (m % 4 == 1? 2 : (m % 4 >= 2? 4 : 0));
        else cout << (n*m+1)/2; 
        cout << " knights may be placed on a " <<tn <<" row "<<tm <<" column board." << '\n'; 
    }
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
