#include <bits/stdc++.h>
using namespace std;
#define int int64_t
struct Node{
    bool isEnd; 
    Node* ch[26]; 
    Node(){
        isEnd = false;
        for(int i =0; i<26; ++i){
            ch[i] = nullptr;
        }
    }
};
void Insert(Node*root , string &s){
    Node*temp = root;
    for(auto&itr:s){
        int x = itr-'0';
        if(temp->ch[x] == nullptr){
            temp->ch[x] = new Node();
        }
        temp = temp->ch[x];
    }
    temp->isEnd = true;
}
bool Find(Node*root , string&s){
    Node*temp = root;
    for(auto&itr:s){
        int x = itr-'0';
        if(temp->ch[x] == nullptr){
            return false;
        }
        if(temp->ch[x]->isEnd){
            return true;
        }
        temp = temp->ch[x];
    }
    return true;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        Node *root = new Node(); 
        string s; 
        bool possible = true;
        for(int i=0; i<n; ++i){
            cin >> s; 
            if(!possible){continue;}
            if(Find(root , s)){
                possible = false; 
                continue;
            }
            Insert(root , s);
        }
        if(possible){
            cout <<"YES";
        }else{
            cout <<"NO";
        }
        cout << '\n'; 
    }
    return 0;
}
