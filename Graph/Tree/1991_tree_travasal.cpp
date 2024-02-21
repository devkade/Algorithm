#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

pair<char, char> edge[26];
int N;

void Input(){
    int N;
    cin >> N;
    char p, l, r;
    for(int i = 0; i < N; i++){
        cin >> p >> l >> r;
        edge[p-'A'].first = l;
        edge[p-'A'].second = r;
    }
}

void preorder(char cur){
    if(cur == '.') return;

    cout << cur;
    preorder(edge[cur-'A'].first);
    preorder(edge[cur-'A'].second);
}
void inorder(char cur){
    if(cur == '.') return;

    inorder(edge[cur-'A'].first);
    cout << cur;
    inorder(edge[cur-'A'].second);
}
void postorder(char cur){
    if(cur == '.') return;

    postorder(edge[cur-'A'].first);
    postorder(edge[cur-'A'].second);
    cout << cur;
}


void Solution(){
    preorder('A');
    cout << endl;
    inorder('A');
    cout << endl;
    postorder('A');
    cout << endl;
}

int main(){
   ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();

    return 0;
}