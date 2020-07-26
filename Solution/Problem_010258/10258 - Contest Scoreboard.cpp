//  Author : Amit Kumar 
//  Date   : Sunday 26 July 2020 04:19:26 PM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int int64_t
struct Score{
    int number;
    set<int> problem_solved; // same user can submit same problem many times
    bool made_submission;
    map<int ,int> incorrect_submission;
    int penalty;
    Score(){
        number = 0;
        made_submission = false;
        problem_solved.clear();
        penalty = 0;
    }
};
bool Compare(Score &a , Score&b){
    if(a.problem_solved.size() == b.problem_solved.size()){
        if(a.penalty == b.penalty){
            return a.number < b.number; 
        }else{
            return a.penalty < b.penalty;
        }
    }else{
        return a.problem_solved.size() > b.problem_solved.size();
    }

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
    string s; getline(cin , s);
    bool more = false;
    while(t--){
        if(more){
            cout << '\n'; 
        }
        more = true;
        vector<Score>contestent(103);
        for(int i = 0; i<=101;++i){
            contestent[i].number = i;
        }
        while(getline(cin , s)){
            if(s.size()==0){
                break;
            }
            istringstream ss(s); 
            int a, b, c; char ch; 
            ss >> a >> b >> c >> ch; 
            contestent[a].made_submission = true;
            if(ch == 'I'){
                if(contestent[a].problem_solved.find(b)==contestent[a].problem_solved.end()){
                    contestent[a].incorrect_submission[b] += 20;
                }
            }else if(ch == 'C'){
                if(contestent[a].problem_solved.find(b)==contestent[a].problem_solved.end()){
                    contestent[a].penalty += (contestent[a].incorrect_submission[b] + c);
                    contestent[a].problem_solved.insert(b);
                }
            }
        }
        sort(contestent.begin() , contestent.end() , Compare);
        for(int i=0;i<=102;++i){
            if(contestent[i].made_submission){
                cout << contestent[i].number <<' ' << contestent[i].problem_solved.size() <<' ' << contestent[i].penalty << '\n'; 
            }
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
