//  Author : Amit Kumar 
//  Date   : Monday 20 July 2020 04:50:19 PM IST

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
    int h1 , m1 , h2 , m2; 
    while(cin>> h1 >> m1 >> h2 >> m2 , h1+m1+h2+m2){
        int ah=0, am=0;
        if(h2 < h1){
            ah +=  24 - h1; 
            ah += h2; 
            if(m2 < m1){
                ah --; 
                am += (60 - m1);
                am += m2;
            }else{
                am = m2 - m1;
            }
        }else if(h2 == h1){
            if(m2 < m1){
                ah+=24; 
                if(m2 < m1){
                    ah --; 
                    am += (60 - m1);
                    am += m2;
                }else{
                    am = m2 - m1;
                }
            }else{
                am = m2 - m1;
            }
        }else{
            ah = h2 - h1; 
            if(m2 < m1){
                ah --; 
                am += (60 - m1);
                am += m2;
            }else{
                am = m2 - m1;
            }
        }

        cout << ah * 60 + am << '\n'; 
    }
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
