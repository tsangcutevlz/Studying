#include <iostream>
#include<vector>
#include <queue>
using namespace std;

class Solution{
    public:
    vector<int> bfsGraph(int V, vector<int> adj[]){
        int vis[V] = {0};
        vis[0] = 1;
        queue<int> q;

        q.push(0);
        vector<int> bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
}

void addEdges(vector<int> arr[], int u, int v){
    arr[u].push_back(v);
    arr[v].push_back(u);
}

void printAns(vector<int> &ans){
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
}

int main(){
    vector <int> adj[6];
    
    addEdges(adj, 0, 1);
    addEdges(adj, 1, 2);
    addEdges(adj, 1, 3);
    addEdges(adj, 0, 4);

    Solution obj;
    vector <int> ans = obj.bfsGraph(5, adj);
    printAns(ans);

    return 0;
}