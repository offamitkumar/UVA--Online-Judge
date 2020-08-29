#include <bits/stdc++.h>
using namespace std;
#define int int64_t
struct TrieNode{
    TrieNode* character[2]; // 0 & 1
    bool isEnd;
    TrieNode(){
        isEnd = false;
        character[0] = nullptr;
        character[1] = nullptr;
    }
};
bool Search(TrieNode*root , const string&s){
    TrieNode* temp = root;
    for(auto&itr:s){
        int index = itr-'0';
        if(temp->character[index]==nullptr){
            return false;
        }
        temp = temp->character[index];
        if(temp->isEnd){
            return true;
        }
    }
    return true;
}
void Add(TrieNode*root , const string&s){
    TrieNode*temp = root;
    for(auto&itr:s){
        int index = itr-'0';
        if(temp->character[index]==nullptr){
            temp->character[index] = new TrieNode();
        }
        temp = temp ->character[index];
    }
    temp->isEnd = true;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    string s;
    TrieNode *root =new TrieNode();
    int test_counter = 1;
    bool ok = true;
    while(cin >> s){
        if(s == "9"){
            if(ok){
                cout <<"Set " << test_counter++ <<" is immediately decodable\n";
            }else{
                cout <<"Set " << test_counter++ <<" is not immediately decodable\n";
            }
            ok =true;
            delete root;
            root = new TrieNode();
            continue;
        }
        if(ok && Search(root, s)){
            ok = false;
        }
        if(ok){
            Add(root , s);
        }
    }
    return 0;
}
