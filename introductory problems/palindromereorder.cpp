#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string word;
    vector<char> halfWord;
    long long int oddCount {0};
    long long int oddIndex = -1;
    long long int occurrences {0};
    long long int handle {0};
    cin >> word;

    sort(word.begin(),word.end());

    for(int i = 0; i < word.size(); i++){
        handle = i;
        while(word[i] == word[handle]){
            occurrences++;
            handle++;
        }
        if(occurrences%2 != 0){
            oddCount++;
            oddIndex = i;
            occurrences--;
            while(occurrences > 0){
                halfWord.push_back(word[i]);
                occurrences -= 2;
            }
        }else{
            while(occurrences > 0){
                halfWord.push_back(word[i]);
                occurrences -= 2;
            }
        }
        
        i = handle - 1;
        occurrences = 0;
    }

    if(oddCount > 1){
        cout << "NO SOLUTION" << endl;
    }else{
        
        for(int i = 0; i < halfWord.size() ; i++){
            cout << halfWord[i] ;
        }                
        if(oddCount == 1){
            cout << word[oddIndex];
        }
        for(int i = halfWord.size() - 1; i >= 0; i-- ){
            cout << halfWord[i];
        }
        cout << endl;
    }


    return 0;
}