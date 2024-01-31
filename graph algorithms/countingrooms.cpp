#include <bits/stdc++.h>

using namespace std;

int c {0};
int neighborX[4] = {0, 0, 1, -1};
int neighborY[4] = {1, -1, 0, 0};

char grid[1000][1000];
bool visited[1000][1000];
int n,m;

bool isValid(int x, int y){
    if(x<0||y<0) return false;
    if(x>=n||y>=m) return false;
    if(grid[x][y] == '#') return false;
    return true;
}

void DFS(int x, int y){
    visited[x][y] = true;
    
    for(int i = 0; i < 4; i++){
        int newX = x+neighborX[i];
        int newY = y+neighborY[i];
        if(isValid(newX,newY) && !visited[newX][newY]){
            DFS(newX, newY);
        }
    }
}

int main(){

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && isValid(i,j)){
                DFS(i,j);
                c++;
            }
        }
    }

    cout << c << endl;


    /* Print Grid
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j];
        }
        cout << "\n";
    }*/

    return 0;
}