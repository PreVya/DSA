#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int size, vcount =0, ccount =0, i;
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
        if(s[i]=='a'|| s[i]=='A'||s[i]=='e'|| s[i]=='E'|| s[i]=='i'|| s[i]=='I'|| s[i]=='o'|| s[i]=='O'|| s[i]=='u'|| s[i]=='U'){
            vcount++;
        }
        else if((s[i]>=65 && s[i]<=90) || (s[i] >=92 && s[i]<=122)){
            ccount++;
        }
    }

    cout<<"Vowels: "<<vcount<<"  Consonants: "<<ccount;
    return 0;
}