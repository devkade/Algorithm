#include <bits/stdc++.h>
using namespace std;

int l, c;
char val[20];
char ch[20];
int is_used[20];
int vowel = 0;

void func(int k){
    if(k==l){
        if(vowel==0 || l-vowel<2){
            return;
        }
        for(int i=0; i<l; i++){
            cout << ch[i];
        }
        cout << '\n';
        return;
    }
    for(int i=0; i<c; i++){
        if(is_used[i]) continue;
        if(k!=0 && (int)ch[k-1] > (int)val[i]) continue;
        if(val[i]=='a'||val[i]=='e'||val[i]=='i'||val[i]=='o'||val[i]=='u') vowel++;
        is_used[i] = 1;
        ch[k] = val[i];
        func(k+1);
        is_used[i] = 0;
        if(val[i]=='a'||val[i]=='e'||val[i]=='i'||val[i]=='o'||val[i]=='u') vowel--;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> c;
    for(int i=0; i<c; i++){
        cin >> val[i];
    }
    sort(val, val+c);
    func(0);
    return 0;
}