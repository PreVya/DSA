#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int size1,size2,i=0,j=0;

    cout<<"Enter string size ";
    cin>>size1;
    getchar();
    char *s1 = new char[size1];
    
    cout<<"Enter string  1 ";
    fgets(s1,size1,stdin);
    
    cout<<"String is 1";
    for(i=0;s1[i]!='\0';i++){
        cout<<s1[i];
    }

    
    cout<<"Enter string size ";
    cin>>size2;
    getchar();
    char *s2 = new char[size2];
    
    cout<<"Enter string 2 ";
    fgets(s2,size2,stdin);
    
    cout<<"String is 1";
    for(i=0;s2[i]!='\0';i++){
        cout<<s2[i];
    }

    i=0,j=0;
    while(s1[i]!= '\0'&& s2[j]!='\0'){
        if(s1[i]!=s2[j]){
            break;
        }
        i++;
        j++;
    }

    if(s1[i]==s2[j]){
        cout<<"Strings are equal!";
    }
    else if(s1[i]>s2[j]){
        cout<<"String1 > string2";
    }
    else{
        cout<<"String1 < string2";
    }
    return 0;
}
   