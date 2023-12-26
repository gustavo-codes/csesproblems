#include <iostream>
#include <vector>

using namespace std;

int main(){
    unsigned int n;
    vector<unsigned int> odd;
    vector<unsigned int> even;

    cin >> n;

    if(n==3 || n==2){
        cout << "NO SOLUTION" << endl;
        return 0;
    } 

    for(int i = 1; i <= n; i++){
        if(i%2 == 0){
            even.push_back(i);
        }else{
            odd.push_back(i);
        }
    }

    for(unsigned int i = 0; i<even.size();i++){
        cout << even[i] << " ";
    }
    for(unsigned int i = 0; i<odd.size();i++){
        cout << odd[i] << " ";
    }
    
    


    return 0;
}