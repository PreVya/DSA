#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int size,i,j;
    cout<<"Enter string size ";
    cin>>size;
    getchar();
    char *s = new char[size];
    char *r = new char[size];
    cout<<"Enter string  ";
    fgets(s,size,stdin);
    
    cout<<"String is ";
    for(i=0;s[i]!='\0';i++){
        cout<<s[i];
    }

    for(i=0;s[i]!='\0';i++);
    i = i-1;

    for(j=0;i>=0;j++){
        r[j] = s[i];
        i--;
    }
    r[j] = '\0';

    cout<<"Reversed String is ";
    for(i=0;r[i]!='\0';i++){
        cout<<r[i];
    }
}