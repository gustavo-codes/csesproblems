#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    unsigned long int n;
    unsigned long int handle;
    vector<unsigned long int> numbers;
    cin >> n;


    for(unsigned long int i = 0; i< n-1 ; i++){
        cin >> handle;
        numbers.push_back(handle);
    }
    sort(numbers.begin(),numbers.end());

    for(unsigned long int i = 0; i < n ; i++){
        if(numbers[i]!=i+1){
            cout << i+1 << endl;
            break;
        }
    }

    return 0;
}