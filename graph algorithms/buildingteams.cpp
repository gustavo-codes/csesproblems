#define MAX 100000
#include <bits/stdc++.h>

using namespace std;

int n,m;
bool bipartite = true;
int colors[MAX]; // 0 none, 1 blue, 2 red, 0 = no visited
vector<int> graph[MAX];

void DFS(int x, int c){
    if(colors[x] != 0) return;
    if(c == 1){
        colors[x] = 1;
        for(auto u:graph[x]){
            if(colors[u] == 1) bipartite = false;
            DFS(u,2);
        }
    }if(c == 2){
        colors[x] = 2;
        for(auto u:graph[x]){
            if(colors[u] == 2) bipartite = false;
            DFS(u,1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int dest, origin;
        cin >> origin >> dest;
        graph[origin - 1].push_back(dest-1);
        graph[dest - 1].push_back(origin-1);
    }

    for(int i =0; i<n;i++){
        if(colors[i] == 0) DFS(i,1);;
    }
    


    if(bipartite){
        for(int i = 0; i < n; i++){
            if(colors[i] == 0) 
                cout << 1 << " ";
            else
                cout << colors[i] << " ";
        }
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    

    return 0;
}