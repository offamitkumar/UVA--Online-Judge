//  Author : Amit Kumar 
//  Date   : Tuesday 21 July 2020 01:15:20 PM IST

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
    int round; 
    while(cin >> round && round != -1){
        cout <<"Round " << round << '\n'; 
        string a,b; cin >> a >> b; 
        set<char>A,B;
        set<char>checked;
        for(auto&itr:a){
            A.insert(itr);
            checked.insert(itr);
        }
        int played{};
        for(auto&itr:b){
            if(A.find(itr)!=A.end()){
                checked.erase(itr);
                if(checked.size() == 0)
                    break;
            }else if(B.find(itr)==B.end()){
                played++;
                if(played>=7){
                    break;
                }
                B.insert(itr);
            }
        }
        if(checked.size() == 0){
            cout <<"You win." << '\n';
        }else if(played<7){
            cout <<"You chickened out." << '\n';
        }else{
            cout <<"You lose." << '\n'; 
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
