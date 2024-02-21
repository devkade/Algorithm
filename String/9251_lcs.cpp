#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int lcs[1005][1005];

int main(){
    
    string source, target;
    char res[1005];     // 결과 저장
    int len = 0;

    cin >> source >> target;

    for(int i = 1; i <= source.length(); i++){
        for(int j = 1; j <= target.length(); j++){
            if(source[i-1] == target[j-1])              // 문자열 인덱스의 시작도 0부터 시작한다.
                lcs[i][j] = lcs[i-1][j-1] + 1;          // 같으면 좌대각+1로 구분한다. 
            else
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }

    int i = source.length();
    int j = target.length();

    while(true){
        if(lcs[i][j] == 0) break;
        if(lcs[i][j] != lcs[i-1][j] && lcs[i][j] != lcs[i][j-1]){
            res[len++] = source[j-1];
            i = i - 1;
            j = j - 1;
            continue;
        }
        else{
            if(lcs[i][j] == lcs[i-1][j]) i = i-1;
            else if(lcs[i][j] == lcs[i][j-1]) j = j-1;
        }
    }

    cout << len << endl;

    return 0;
}