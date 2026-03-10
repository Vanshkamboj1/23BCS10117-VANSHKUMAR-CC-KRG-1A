#include<bits/stdc++.h>
using namespace std;
int bitmask(string word){
    int ans = 0;
    for(int i=0;i<word.size();i++){
        ans = ans | (1<<(word[i]-'a'));
    }
    return ans;
}
int main(){
    int n;
    cin>>n;

    vector<string> words;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        words.push_back(temp);
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((bitmask(words[i])&bitmask(words[j]))==0){
                int length = words[i].size() * words[j].size();
                ans = max(ans,length);
            }
        }
    }
    cout<< ans;
    return 0;

}