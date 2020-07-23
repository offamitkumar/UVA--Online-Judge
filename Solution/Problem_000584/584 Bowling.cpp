//  Author : Amit Kumar 
//  Date   : Thursday 23 July 2020 01:42:40 PM IST
//
//
//  Reference Video for this problem : https://www.youtube.com/watch?v=aBe71sD8o8c

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
    string s; 
    while(getline(cin  , s)){
        if(s == "Game Over"){
            return 0;
        }
        istringstream ss(s); 
        char ch; 
        vector<pair<char , char>>bowl;
        // changed into real bowling game(each turn you will get 2 rounds to take down all 10 pins) so that 
        // simulation will be easy. 
        while(ss >> ch){
            if(ch == 'X'){
                bowl.emplace_back(make_pair('X','0'));
            }else{
                char ch2; ss >> ch2; 
                if(ch2 == '/'){
                    // if you take down all the pins in second then you previous score of this round 
                    // isn't counted & you will get one more chance to throw the ball
                    bowl.emplace_back(make_pair(ch,'/'));
                }else{
                    bowl.emplace_back(make_pair(ch , ch2));
                }
            }
        }
        int finalResult{};
        for(int i=0;i<min((int)bowl.size() , (int)10); ++i){
            if(bowl[i].first == 'X') {
                finalResult += 10; 
                if(bowl[i+1].first == 'X'){
                    finalResult+=10; 
                    if(bowl[i+2].first == 'X'){
                        finalResult+=10;
                    }else{
                        finalResult+=(bowl[i+2].first - '0');
                    }
                }else if(bowl[i+1].second == '/'){
                    finalResult+=10;
                }else{
                    finalResult+=(bowl[i+1].first-'0' + bowl[i+1].second-'0');
                }
            }else if (bowl[i].second == '/') {
                finalResult += 10; 
                if (bowl[i+1].first == 'X') {
                    finalResult+=10;
                }else{
                    finalResult+=(bowl[i+1].first-'0');
                }
            }else {
                finalResult += (bowl[i].first-'0' + bowl[i].second-'0');
            }
        }
        cout << finalResult << '\n'; 
    }
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;

}
