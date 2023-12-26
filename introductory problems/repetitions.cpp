#include <iostream>

using namespace std;

int main(){
    unsigned long int maxsequence = 1;
    unsigned long int localmaxsequence = 1;
    char handle;
    string word;

    cin >> word;

    handle = word[0];

    for(int i = 1; i < word.size();i++){
        int j = i;
        while(handle == word[j]){
            localmaxsequence++;
            j++;
        }
        if(localmaxsequence > maxsequence){
            maxsequence = localmaxsequence;
        }
        localmaxsequence = 1;
        i = j;
        handle = word[i];
    }
    cout << maxsequence << endl;
    return 0;
}