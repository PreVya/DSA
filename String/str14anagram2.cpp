#include<iostream>
#include<cstring>
#include<unordered_map>

using namespace std;

//TC= O(n+m), SC=O(k)
int main(){
    int size1,size2;
    cout<<"Enter size1 ";
    cin>>size1;
    getchar();
    char *s1= new char[size1];  
    cout<<"Enter string 1 ";
    cin.getline(s1, size1); 

    cout<<"Enter size2 ";
    cin>>size2;
    getchar();
    char *s2= new char[size2];  
    cout<<"Enter string 2 ";
    cin.getline(s2, size2); 

    // CORE LOGIC FIX: Check length first
    if(strlen(s1) != strlen(s2)) {
        cout << "Not anagram";
        delete[] s1; delete[] s2;
        return 0;
    }

    unordered_map<char,int> counts;

    for(int i = 0; s1[i] != '\0'; i++) counts[s1[i]]++;

    for(int i = 0; s2[i] != '\0'; i++){
        if(counts.find(s2[i]) == counts.end() || counts[s2[i]] <= 0){
            cout << "Not anagram";
            delete[] s1; delete[] s2;
            return 0;
        }
        counts[s2[i]]--;
    }

    cout << "Anagram";

    delete[] s1;
    delete[] s2;
    return 0;
}