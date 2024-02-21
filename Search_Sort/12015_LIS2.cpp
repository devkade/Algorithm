#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int N;
int arr[1000001];
vector<int> vec;

void Input(){
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
}

int binary_search(int target){
    int start = -1;
    int end = vec.size()-1;
    // int res = INT32_MAX;
    while(end > start+1){
        int mid = (start + end)/2;
        if(vec[mid] >= target){
            end = mid;
        }
        else start = mid;
    }
    return end;
}

void Solution(){
    vec.push_back(arr[0]);
    for(int i=1; i<N; i++){
        if(vec.back() < arr[i]){
            vec.push_back(arr[i]);
        }
        else {
            int idx = binary_search(arr[i]);
            vec[idx] = arr[i];   
        }
    }
    cout << vec.size() << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();

    return 0;
}