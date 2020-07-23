//  Author : Amit Kumar 
//  Date   : Thursday 23 July 2020 08:23:09 PM IST

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
    unordered_set<string>s; 
    string st;
    while(cin>>st){
        s.insert(st);
    }
    set<string>res;
    for(auto&itr:s){
        for(int i=1;i<itr.size();++i){
            if(s.find(itr.substr(0,i))!=s.end()){
                if(s.find(itr.substr(i,itr.size()))!=s.end()){
                    res.insert(itr);
                    break;
                }
            }
        }
    }
    for(auto&itr:res){
        cout << itr << '\n'; 
    }
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
