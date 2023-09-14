#include <bits/stdc++.h>
using namespace std;

pair<char, int> alpha_scores[30];

bool compare(const pair<char, int>& a, const pair<char, int>& b){
    return a.second > b.second;
}

int main(){
    ios:: sync_with_stdio(false);
    cin.tie(0);

    vector<string> words;

    int N, res = 0;
    int num = 9;
    string str, temp;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> str;
        int size = str.size()-1;
        words.push_back(str);
        for(int j = 0; j < str.size(); j++){
            alpha_scores[str[j]-'A'].first = str[j];
            alpha_scores[str[j]-'A'].second += pow(10, size--);
        }
    }
    sort(alpha_scores, alpha_scores+26, compare);

    for (int i = 0; i < 27; i++){
        if(alpha_scores[i].second == 0) continue;
        res += alpha_scores[i].second * num--;
    }

    cout << res << '\n';

    return 0;
}