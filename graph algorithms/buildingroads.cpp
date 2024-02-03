#include <bits/stdc++.h>

using namespace std;

int c{0};
vector<bool> visited;
vector<int> component;
vector<pair<int,int>> roads;
vector<vector<int>> graph;

void DFS(int x){
    if(visited[x]) return;
    visited[x] = true;
    component[x] = c;
    for(auto u : graph[x]){
        DFS(u);
    }
    

}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;


    cin >> n >> m;

    for(int i = 0; i<n; i++){
        graph.push_back({});
        visited.push_back({});
        component.push_back({});
    }

    for(int i = 0; i < m; i++){
        int origin, dest;
        cin >>  origin >> dest;
        graph[origin - 1].push_back(dest-1);
        graph[dest-1].push_back(origin-1);
        
    }

    for(int i = 0; i < graph.size(); i++){
        if(!visited[i]){
            if(i!=0){
                //cout << i << " " << i+1 << endl;
                roads.push_back(make_pair(i,i+1));
            }
            c++;
            DFS(i);
        }
    }

    cout << c-1 << endl;

    for(int i = 0; i < c-1; i++){
        cout << roads[i].first << " " << roads[i].second << endl;
    }

    return 0;
}