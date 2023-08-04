#include <bits/stdc++.h>
using namespace std;

int N, K, res=0, check[26] = {};
string alphabet = "bdefghjklmopqrsuvwxyz", pick;
vector<string> words;

void dfs(int depth, int start){
    if (depth == K-5){
        int num = 0;
        for(int i=0; i<words.size(); i++){
            int teach = 1;
            for(auto ch : words[i]){
                // cout << "Word Sequence : " << i << '\t' << "ch : " << ch << '\t' << "num : " << num << endl;
                if (ch == 'a' || ch == 'n' || ch == 't' || ch == 'i' || ch == 'c')
                    continue;
                if (check[int(ch)-97] == 0){
                    teach = 0;
                    break;
                }
            }
            if (teach) num++;
        }   
        res = max(res, num);
        return;
    }

    for(int i=start; i<alphabet.size(); i++){
        // cout << "alphabet : " << alphabet[i] << endl;
        check[int(alphabet[i])-97] = 1;
        // pick.push_back(alphabet[i]);
        dfs(depth+1, i+1);
        // pick.pop_back(alphabet[i]);
        check[int(alphabet[i])-97] = 0;
    }
}

int main(){
    ios::sync_with_stdio(true);
    cin.tie(); cout.tie();
    
    cin >> N >> K;
    string str;

    for(int i = 0; i < N; i++){
        map<char, int> temp;
        string cut;
        cin >> str;
        str = str.substr(4, str.size()-4);
        for(int j = 0; j < str.size(); j++){
            temp[str[j]]=1;
        }
        for(auto ch : temp) cut += ch.first;
        words.push_back(cut);

    }

    
    if (K < 5){
        cout << 0 << endl;
        return 0;
    }

    dfs(0, 0);
    
    cout << res << endl;


    return 0;
}