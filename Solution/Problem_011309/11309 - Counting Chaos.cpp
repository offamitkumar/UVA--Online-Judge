//  Author : Amit Kumar 
//  Date   : Tuesday 21 July 2020 12:54:12 PM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int int64_t
bool palin(int a, int b){
    string s; 
    if(a == 0){
        if(b == 0){
            return true;
        }
        s+=to_string(b);
    }else{
        s+=to_string(a); 
        string ss = to_string(b); 
        if(ss.size() == 2){
            s+=ss;
        }else{
            s+="0"+ss;
        }
    }
    int low = 0 , high = s.size()-1; 
    while(low<high){
        if(s[low]!=s[high]){
            return false;
        }
        ++low; 
        --high;
    }
    return true;
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
    int n; cin >> n; 
    while(n--){
        int h , m; char ch; 
        cin >> h >> ch >> m; 
        bool firstTime = true;
        while(firstTime || not(palin(h,m))){
            firstTime = false;
            m++; 
            if(m == 60){
                m = 0; 
                h++; 
                if(h == 24){
                    h = 0; 
                }
            }
        }
        cout << setfill('0') << setw(2) << h ;
        cout << ch; 
        cout << setfill('0') << setw(2) << m ;
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
