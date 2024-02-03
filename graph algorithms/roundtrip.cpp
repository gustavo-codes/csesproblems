#define MAX 100000
#include <bits/stdc++.h>

using namespace std;

int n,m;
int cicleIndex = -1;
int parents[MAX];
bool visited[MAX];
vector<int> path;
vector<int> graph[MAX];

void DFS(int x, int d){
    visited[x] = true;
    for(auto u:graph[x]){
        if(cicleIndex!= -1) return;
        if(!visited[u]){
            parents[u] = x;
            DFS(u,x);
        }else if(u!=d){
            cicleIndex = u;
            parents[u] = x;
        }
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i< m; i++){
        int origin, dest;
        cin >> origin >> dest;
        graph[origin -1].push_back(dest-1);
        graph[dest-1].push_back(origin-1);
    };

    for(int i = 0; i<n;i++){
        if(!visited[i]){
            DFS(i,i);
        }
        
    }
    

    if(cicleIndex==-1){
        cout << "IMPOSSIBLE" << '\n';
    }else{
        path.push_back(cicleIndex);
        int handle = parents[cicleIndex];
        
        while(handle!=cicleIndex){
            path.push_back(handle);
            handle = parents[handle];
        }
        path.push_back(cicleIndex);

        cout << path.size() << '\n';
        
        for(int i = 0; i < path.size(); i++){
            cout << path[i]+1 << " ";
        };
    };




    return 0;
}