#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int number_counter = 1;
struct Proposal{
    string name;
    int number, requirement_completes;
    vector<string>requirement;
    double price;
    Proposal(){
        requirement.clear();
    }
    friend istream& operator>>(istream&in , Proposal& p){
        p.number = number_counter++;
        getline(in , p.name);
        in >> p.price >> p.requirement_completes;
        in.ignore();
        string temp;
        for(int i=0; i< p.requirement_completes; ++i){
            getline(in , temp);
            p.requirement.push_back(temp);
        }
        return in;
    }
};
bool compare(Proposal&a , Proposal&b){
    if(a.requirement_completes == b.requirement_completes){
        if(a.price == b.price){
            return a.number < b.number;
        }else{
            return a.price < b.price;
        }
    }else {
        return a.requirement_completes > b.requirement_completes;
    }
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n , p;
    int test_counter = 1;
    while(cin >> n >> p && n + p){
        if(test_counter!=1){
            cout << endl;
        }
        cout <<"RFP #" << test_counter ++ << endl;
        number_counter = 1;
        cin.ignore();
        vector<string>requirement;
        string temp;
        for (int i=0; i < n; ++i) {
            getline(cin, temp);
            requirement.push_back(temp);
        }
        vector<Proposal>proposals;
        Proposal pro;
        while(p--){
            cin >> pro;
            proposals.push_back(pro);
        }
        sort(proposals.begin(), proposals.end(), compare);
        cout << proposals.at(0).name << endl;
    }
    return 0;
}
