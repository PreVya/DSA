#include<iostream>
#include<cstring>

using namespace std;

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
// TC= O(n^2), SC = O(1) ... n is size of string 1
int main(){
    int size1,size2,flag=0;
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


    for(int i = 0; i < strlen(s1) - 1; i++) {
        for(int j = 0; j < strlen(s1) - i - 1; j++) {
            if(s1[j] > s1[j+1]) swap(s1[j], s1[j+1]);
        }
    }

    for(int i = 0; i < strlen(s2) - 1; i++) {
        for(int j = 0; j < strlen(s2) - i - 1; j++) {
            if(s2[j] > s2[j+1]) swap(s2[j], s2[j+1]);
        }   
    }   

    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0') {
        if(s1[i] != s2[i]) { flag = 1; break; }
        i++;
    }
    if(flag == 0 && s1[i] == '\0' && s2[i] == '\0') {
        cout << "Anagram";
    } else {
        cout << "Not anagram";
    }

    delete[] s1;
    delete[] s2;
    return 0;
}
