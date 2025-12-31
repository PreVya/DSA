#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int size,i;

    cout<<"Enter character array size ";
    cin>>size;
    getchar();
    char *s = new char[size];
    cout<<"Enter the string ";
    fgets(s,size,stdin);

    for(i=0;s[i]!='\0';i++){}
    i= i-1;
    cout<<i<<" characters in string";
    return 0;
}