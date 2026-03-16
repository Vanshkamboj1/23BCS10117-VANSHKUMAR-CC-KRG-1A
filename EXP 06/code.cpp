#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<vector<int>> adj(26);
    vector<int> indeg(26,0);

    for(int i=0;i<n-1;i++){
        string a=v[i], b=v[i+1];
        int len=min(a.size(),b.size());
        bool found=false;

        for(int j=0;j<len;j++){
            if(a[j]!=b[j]){
                adj[a[j]-'a'].push_back(b[j]-'a');
                indeg[b[j]-'a']++;
                found=true;
                break;
            }
        }

        if(!found && a.size()>b.size()){
            cout<<"Impossible";
            return 0;
        }
    }

    queue<int> q;
    for(int i=0;i<26;i++){
        if(indeg[i]==0) q.push(i);
    }

    string ans="";
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back('a'+node);

        for(auto it:adj[node]){
            indeg[it]--;
            if(indeg[it]==0) q.push(it);
        }
    }

    if(ans.size()!=26){
        cout<<"Impossible";
        return 0;
    }

    cout<<ans;
}