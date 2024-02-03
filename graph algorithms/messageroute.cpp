#define MAX 200000
#include <bits/stdc++.h>

using namespace std;

int n,m;
bool found = false;
bool visited[MAX];
int parents[MAX];
queue<int> q;
vector<int> graph[MAX];


void BFS(int x){
    visited[x] = true;
    q.push(x);
    while(!q.empty()){
        int s = q.front(); q.pop();
        for(auto u : graph[s]){
            if(!visited[u] && !found){
                if(u == n - 1){
                    found = true;
                }
                visited[u] = true;
                parents[u] = s;
                q.push(u);
            }

        }
    }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int origin, dest;
        cin >> origin >> dest;
        graph[origin - 1].push_back(dest - 1);
        graph[dest - 1].push_back(origin - 1);
    }

    BFS(0);

    if(found){
        int handle = n;
        vector<int> path;
        path.push_back(handle);
        while(handle != 1){
            path.push_back(parents[handle-1]+1);
            handle = parents[handle-1]+1;
        }
        cout << path.size() << endl;
        for(int i = path.size() - 1; i >= 0; i--){
            cout << path[i] << " ";
        }
    }else{
        cout << "IMPOSSIBLE" << endl;
    }


    return 0;
}