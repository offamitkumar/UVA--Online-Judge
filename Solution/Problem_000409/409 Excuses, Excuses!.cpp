#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int m , n; 
    int t_counter = 1;
    while(cin >> n >> m){
        set<string>excuse; 
        string s;
        for(int i=0; i<n;++i){
            cin >> s; 
            for_each(s.begin(), s.end(), [](char &ch){
                    ch = char(tolower(ch));
                    });
            excuse.insert(s);
        }
        unordered_map<string , int>scores;
        cin.ignore();
        vector<string>vec;
        auto getScore = [&excuse](string k){
            for_each(k.begin(), k.end(), [](char &ch){
                    ch = char(tolower(ch));
                    });
            istringstream ss(k); 
            string te;
            int counter{};
            while(ss >> te){
                string temp;
                for(auto&itr:te){
                    if(itr>='a' && itr<='z'){
                        temp+=itr;
                    }else{
                        if(excuse.find(temp)!=excuse.end()){
                            ++counter;
                        }
                        temp ="";
                    }
                }
                if(excuse.find(temp)!=excuse.end()){
                    ++counter;
                }
            }
            return counter;
        };
        int max_score{};
        for(int i=0; i<m;++i){
            getline(cin,s);
            vec.emplace_back(s);
            scores[s] = getScore(s);
            max_score = max(max_score , (int)scores[s]);
        }
        cout << "Excuse Set #" << t_counter++ << '\n';
        for(auto&itr:vec){
            if(scores[itr] == max_score){
                cout << itr << '\n'; 
            }
        }
        cout << '\n';
    }
    return 0;
}
