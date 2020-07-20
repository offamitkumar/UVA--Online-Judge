//  Author : Amit Kumar 
//  Date   : Monday 20 July 2020 06:04:17 PM IST

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
    int n; 
    while(cin >> n , n){
        vector<int>v(n); 
        bool lessThanZero = true;
        for(auto&itr:v){
            cin >> itr;
            if(itr>0){
                lessThanZero = false;
            }
        }
        if(lessThanZero){
            cout <<"Losing streak." << '\n'; 
        }else{
            int max_ = 0; 
            int temp = 0; 
            for(int i=0;i<n;++i){
                temp += v[i]; 
                max_ = max(max_ , temp);
                if(temp < 0){
                    temp = 0;
                }
            }
            cout <<"The maximum winning streak is " << max_ << ".\n"; 
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
