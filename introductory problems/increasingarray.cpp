#include <iostream>
#include <vector>

using namespace std;

int main(){
    unsigned long int n;
    unsigned long int handle;
    unsigned long int number_of_moves = 0;
    vector<unsigned long int> numbers;
    
    cin >> n;

    for(unsigned long int i = 0; i<n; i++){
        cin >> handle;
        numbers.push_back(handle);
    }
    
    for(unsigned long int i = 1; i < numbers.size(); i++){
        while(numbers[i]<numbers[i-1]){
            numbers[i] += 1;
            number_of_moves++;
        }
    }

    cout << number_of_moves << endl;


    return 0;
}