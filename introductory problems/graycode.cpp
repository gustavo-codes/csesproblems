#include <iostream>
#include <vector>

using namespace std;

vector<string> grayCode(int n){
    vector<string> codes;
    if(n <= 1){
        codes.push_back("0");
        codes.push_back("1");
        return codes;
    }else{
        vector<string> previous = grayCode(n-1);
        for(int i = 0; i<previous.size() ; i++){
            codes.push_back("0"+ previous[i]);
        }
        for(int i = previous.size() - 1 ; i >= 0 ; i--){
            codes.push_back("1"+ previous[i]);
        }
        return codes;
    }
}

int main(){
    int n;

    cin >> n;
    vector<string> solution = grayCode(n);

    for(int i = 0; i<solution.size(); i++){
        cout << solution[i] << endl;
    }

    return 0;
}