#include <bits/stdc++.h>
using namespace std;
#define int int64_t
struct Data{
    string Name,lName/*lowercase name*/; 
    int points, wins ,gameplay;
    int Tie , Loss;
    int goalDone , goalHave; 
    Data(){
        points =0; 
        wins =0; 
        Tie = 0; 
        Loss = 0;
        gameplay = 0; 
        goalDone = 0; 
        goalHave = 0;
    }
    int goaldiff(void){
        return goalDone - goalHave; 
    }
};
bool compare(Data&a, Data&b){
    if(a.points == b.points){
        if(a.wins == b.wins){
            int x =a.goalDone - a.goalHave; 
            int y =b.goalDone - b.goalHave; 
            if(x == y){
                if(a.goalDone == b.goalDone){
                    if(a.gameplay == b.gameplay){
                        return a.lName < b.lName;
                    }else{
                        return a.gameplay < b.gameplay;
                    }
                }else{
                    return a.goalDone > b.goalDone;
                }
            }else{
                return x > y;
            }
        }else{
            return a.wins > b.wins;
        }
    }else{
        return a.points > b.points;
    }
}
string lower(string &s){
    string res;
    for(auto&itr:s){
        res+=char(tolower(itr));
    }
    return res;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int N; cin >> N; 
    cin.ignore();
    while(N--){
        vector<Data>v;
        map<string , Data> f;
        string tName; getline(cin, tName); cout<< tName << '\n'; 
        int T; cin >> T; cin.ignore(); 
        Data d;
        vector<string>teams;
        while(T--){
            getline(cin , tName); 
            d.Name = tName;
            d.lName = lower(tName);
            f.insert(make_pair(tName, d));
        }
        int G; cin >> G; cin.ignore(); 
        string dummy;
        while(G--){
            getline(cin , tName); 
            istringstream ss(tName);
            string teamA , teamB, goalA, goalB ; 
            getline(ss , teamA , '#');
            getline(ss , goalA , '@'); 
            getline(ss , goalB , '#'); 
            getline(ss , teamB);
            int gA = stoi(goalA); 
            int gB = stoi(goalB); 
            if(gA > gB){
                f[teamA].points += 3;
                f[teamA].wins += 1;
                f[teamB].Loss += 1;
            }else if(gB > gA){
                f[teamB].points += 3;
                f[teamB].wins += 1;
                f[teamA].Loss += 1;
            }else{
                f[teamA].points += 1;
                f[teamB].points += 1;
                f[teamA].Tie += 1;
                f[teamB].Tie += 1;
            }
            f[teamA].goalDone += gA; 
            f[teamB].goalDone += gB; 
            f[teamA].goalHave += gB;
            f[teamB].goalHave += gA;
            f[teamA].gameplay += 1;
            f[teamB].gameplay += 1; 
        }
        for(auto&itr:f){
            v.push_back(itr.second);
        }
        sort(v.begin(), v.end() , compare);
        for(int i=0; i<(int)v.size(); ++i){
            cout <<i+1 <<") " << v[i].Name << " " << v[i].points <<"p, " << v[i].gameplay <<"g ("
                << v[i].wins << "-" << v[i].Tie << "-" << v[i].Loss << "), "
                << v[i].goaldiff() << "gd (" << v[i].goalDone << "-" << v[i].goalHave << ")\n"; 
        }
        if(N){
            cout << '\n'; 
        }
    }
    return 0;
}
