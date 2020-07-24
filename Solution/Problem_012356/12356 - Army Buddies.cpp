//  Author : Amit Kumar 
//  Date   : Friday 24 July 2020 01:53:41 PM IST

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
    int s ,b ; 
    while(cin >> s >> b , s+b){
        vector<int>left(s+2) , right(s+2); 
        for(int i=1;i<=s;++i){
            left[i] = i-1;
            right[i] = i+1;
        }
        while(b--){
            int l , r; cin >> l >> r; 
            int left_sol = left[l]; 
            int right_sol = right[r]; 
            left[right_sol] = left_sol; 
            right[left_sol] = right_sol;
            if(left_sol==0){
                cout <<"*";
            }else{
                cout << left_sol;
            }
            cout <<" ";
            if(right_sol == s+1){
                cout <<"*";
            }else{
                cout << right_sol;
            }
            cout << '\n'; 
        }
        cout <<"-" << '\n'; 
    }
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
