#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int size,i;
    cout<<"Enter size od character array ";
    cin>>size;
    getchar();

    char *s = new char[size];
    cout<<"Enter string in uppercase:";
    fgets(s,size,stdin);

    cout<<"Before case change ";
     for (i=0;s[i]!='\0';i++){
        cout<<s[i];
    }
    cout<<endl;

    for(i=0;s[i]!= '\0';i++){
        s[i] = s[i] + 32;
    }

    cout<<"After case chnage ";
    for (i=0;s[i]!='\0';i++){
        cout<<s[i];
    }
}