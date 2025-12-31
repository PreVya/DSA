#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int size,flag=0,i;
    cout<<"Enter string size ";
    cin>>size;
    getchar();
    char *s = new char[size];
    cout<<"Enter string  ";
    fgets(s,size,stdin);
    
    cout<<"String is ";
    for(i=0;s[i]!='\0';i++){
        cout<<s[i];
    }


    for(i=0;s[i]!='\0';i++){
        if(!(s[i]>=65 && s[i]<=90) && !(s[i]>=97 && s[i]<=122)){
            flag = 1;
            break;
        }
        else{
            flag = 0;
        }
    }

    if(flag == 0){
        cout<<"Entered is string. Validation successful";
    }
    else{
        cout<<"Entered is not a string. Not valid.";
    }
}