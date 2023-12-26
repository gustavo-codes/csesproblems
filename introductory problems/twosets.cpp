#include <iostream>
#include <vector>

using namespace std;
void printVector(vector<int>& vec){
    cout << vec.size() << endl;
    for(int i = 0; i< (int)vec.size();i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}
int main(){
    unsigned long long int n;
    vector<int> setOne;
    vector<int> setTwo;
    

    cin >> n;

    unsigned long long int sum = ((n*(n+1))/2);
    
    if(sum%2 == 0){
        unsigned long long int halfSum = sum/2;
        unsigned long long int localSum = n;
        setOne.push_back(n);

        for(int i = n-1; i > 0 ; i--){
            if((localSum + i ) <= halfSum){
                localSum += i;
                setOne.push_back(i);
            }else{
                setTwo.push_back(i);
            }
        }
        cout << "YES" << endl;
        printVector(setOne);
        printVector(setTwo);

 
    }else{
        cout << "NO" << endl;
    }

    return 0;
}