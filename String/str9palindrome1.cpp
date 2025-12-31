#include<iostream>
#include<cstdio>
#include <cstring>

using namespace std;

int main(){
    int size,i=0,j=0,flag=0;

    cout<<"Enter string size ";
    cin>>size;
    getchar();
    char *s1 = new char[size];
    char *s2 = new char[size];
    
    cout<<"Enter string  1 ";
    fgets(s1,size,stdin);
    
    int len = strlen(s1);
    if (len > 0 && s1[len - 1] == '\n') {
        s1[len - 1] = '\0';
        len--; // Update length after removing \n
    }

    cout<<"String is ";
    for(i=0;s1[i]!='\0';i++){
        cout<<s1[i];
    } 
    cout<<endl;

    for(i=0;s1[i]!='\0';i++);
    i = i-1;

    for(j=0;i>=0;j++){
        s2[j]= s1[i];
        i--;
    }
     s2[j] = '\0'; 

    i=0,j=0;
    while(s1[i]!='\0' && s2[j]!= '\0'){
        if(s1[i]!= s2[j]){
            flag=1;
            break;
        }
        i++;
        j++;
    }
    if(flag==0){
        cout<<"String is a palindrome!";
    }
    else{
        cout<<"String is not a palindrome.";
    }

    delete[] s1;
    delete[] s2;
    return 0;
}