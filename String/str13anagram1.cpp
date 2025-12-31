#include<iostream>
#include<cstring>

using namespace std;

// H as hash array approach 
//TC = O(m+n), SC= O(1) ... m is size of string 1 and n is size of string 2
int main(){
    int size1, size2, flag=0;
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

    int H[26]={0};

    for(int i=0; s1[i]!='\0'; i++){
        H[s1[i]-'a']++;
    }

    for(int i=0; s2[i]!='\0'; i++){
        H[s2[i]-'a']--;
    }

    for(int i=0;i<26;i++){
        if(H[i]!=0){
            flag =1;
            cout<<"Not anagram";
            break;
        }
    }
    if(flag==0){
        cout<<"Strings are anagram";
    }

    delete[] s1;
    delete[] s2;
    return 0;
}   