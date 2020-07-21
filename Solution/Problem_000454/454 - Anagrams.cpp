//  Author : Amit Kumar 
//  Date   : Tuesday 21 July 2020 01:44:05 PM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int int64_t
bool ok(string &a , string &b){
    map<char , int>A , B; 
    for(auto&itr:a){
        if(isspace(itr))
            continue;
        A[itr]++;
    }
    for(auto&itr:b){
        if(isspace(itr))
            continue;
        B[itr]++;
    }
    for(auto&itr:A){
        if(B[itr.first] != itr.second){
            return false;
        }
    }
    for(auto&itr:B){
        if(A[itr.first] != itr.second){
            return false;
        }
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
    int t; cin >> t; 
    cin.ignore();
    string S;
    getline(cin , S);
    while(t--){
        vector<string>s; 
        while(getline(cin , S)){
            if(S.size() == 0){
                break;
            }
            s.emplace_back(S);
        }
        sort(s.begin() ,s.end());
        map<string , multiset<string>>f; 
        for(int i=0; i<(int)s.size(); ++i){
            for(int j = i+1; j<(int)s.size(); ++j){
                if(ok(s[i] , s[j])){
                    f[s[i]].insert(s[j]);
                }
            }
        }
        for(auto&itr:f){
            for(auto&it:itr.second){
                cout << itr.first <<" = " << it << '\n'; 
            }
        }
        if(t){
            cout << '\n'; 
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
