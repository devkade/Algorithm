#include <iostream>

#define endl '\n'
using namespace std;

int n;
int preorder[100001];
int inorder[100001];
int postorder[100001];

void Input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> inorder[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> postorder[i];
    }
}

void Solution(int begin1, int end1, int begin2, int end2){
    if(begin1 > end1 && begin1 > end2) return;
    int root = postorder[end2];

    int flag = -1;
    for(int i=begin1; i <= end1; i++){
        if(inorder[i]==root) {
            flag = i;
            break;
        }
    }
    int len = flag - begin1;

    cout << root << ' ';
    Solution(begin1, flag-1, begin2, begin2+len-1);
    Solution(flag+1, end1, begin2+len, end2-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Input();
    Solution(1, n, 1, n);

    return 0;
}