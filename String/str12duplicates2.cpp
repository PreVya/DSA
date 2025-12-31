// TC = O(n) and SC = O(k) where k is number of keys in hash map
#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

int main(){
    int size;
    cout<<"Enter string size ";
    cin>>size;
    getchar();

    char *s = new char[size];

    cout<<"Enter string ";
    fgets(s,size,stdin);

    unordered_map <char,int> counts;

    for(int i=0;s[i]!= '\0' && s[i] != '\n';i++){
        char currentChar = s[i];
        counts[currentChar] = counts[currentChar] + 1;
    }


    for(auto pair : counts){
        if(pair.second > 1){
            cout<<pair.first<<" has occured "<<pair.second<<" times"<<endl;
        }
    }
    delete []s;
    return 0;

}