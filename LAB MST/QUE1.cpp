#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        vector<int> temp;
        int a,b;
        cin>>a>>b;
        temp.push_back(a);
        temp.push_back(b);
        arr.push_back(temp);
    }

    int required=0;
    sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
        int diffA = a[1] - a[0];
        int diffB = b[1] - b[0];
        return diffA > diffB;
        
    });
    for(int i=0;i<n;i++){
            required+=arr[i][0];
    }
    int remaining = required;
    for(int i=n-1;i>=0;i--){
        if(arr[i][1]>remaining){
            required += arr[i][1]-remaining;
        }
        remaining-=arr[i][0];
    }
    cout<< required;
    return 0;
}