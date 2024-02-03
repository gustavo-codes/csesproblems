#include <bits/stdc++.h>

using namespace std;

int n,m;
bool found = false;
char grid[1000][1000];
bool visited[1000][1000];
char parents[1000][1000];
pair<int,int> startPos;
pair<int,int> endPos; 
queue<pair<int,int>> q;
string path = "";
int neighborX[4] = {0,0,1,-1};
int neighborY[4] = {1,-1,0,0};

bool isValid(int x, int y){
	if(x<0||y<0||x>=n||y>=m||grid[x][y]=='#') return false;
	if(visited[x][y]) return false;
	return true;
}

void BFS(int x, int y){
	visited[x][y] = true;
	parents[x][y] = 'N';
	q.push(make_pair(x,y));
	while(!q.empty()){
		pair<int,int> actual = q.front(); q.pop();
		for(int i = 0; i<4;i++){
			char pos;
			if(i == 0) pos = 'R';
			if(i == 1) pos = 'L';
			if(i == 2) pos = 'D';
			if(i == 3) pos = 'U';
			
			int newX = actual.first + neighborX[i];
			int newY = actual.second + neighborY[i];
			if(isValid(newX, newY)){
				if(newX == endPos.first && newY == endPos.second){
					found = true;
					path += pos;
					int x1 = actual.first;
					int y1 = actual.second;
				
					while(parents[x1][y1] != 'N'){ 
						if(parents[x1][y1] == 'R'){
							y1 -= 1;
							path += 'R';
						}else if(parents[x1][y1] == 'L'){
							y1 += 1;
							path += 'L';
						}else if(parents[x1][y1] == 'U'){
							x1 += 1;
							path += 'U';
						}else if(parents[x1][y1] == 'D'){
							x1 -= 1;
							path += 'D';
						}
					}
				}
				visited[newX][newY] = true;
				q.push(make_pair(newX,newY));
				parents[newX][newY] = pos;
			} 
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;

	for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
			if(grid[i][j] == 'A'){
				startPos = make_pair(i,j);
			} 
			if(grid[i][j] == 'B'){
				endPos = make_pair(i,j);
			}
        }
    }

	BFS(startPos.first, startPos.second);

	
	if(found){
		reverse(path.begin(), path.end());
		cout << "YES" << endl;
		cout << path.size() << endl;
		cout << path << endl;
	}else{
		cout << "NO" << endl;
	}
	
	return 0;


}
