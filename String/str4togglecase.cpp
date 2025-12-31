#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int size,i;
    cout<<"Enter string size ";
    cin>>size;
    getchar();
    char *s = new char[size];
    cout<<"Enter string in toggle case ";
    fgets(s,size,stdin);
    
    cout<<"Before toggle ";
    for(i=0;s[i]!='\0';i++){
        cout<<s[i];
    }

    for(i=0;s[i]!='\0';i++){
        if(s[i]>=65 && s[i]<90){
            s[i]+=32;
        }
        else if(s[i]>90 && s[i]<=122){
            s[i]-=32;
        }
    }
    
    cout<<"After toggle ";
    for(i=0;s[i]!='\0';i++){
        cout<<s[i];
    }

}