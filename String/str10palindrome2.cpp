#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    int size,i,j,flag=0;

    cout<<"Enter size for array: ";
    cin>>size;
    getchar();
    char *s = new char[size];
    cout<<"Enter the string to check ";
    fgets(s,size,stdin);

    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--; 
    }

    for(i=0;s[i]!='\0';i++){
        cout<<s[i];
    }
    j=i-1;
    cout<<endl;
    i=0;
    while(i<j){
        if(s[i]!=s[j]){
            flag=1;
            break;
        }
        i++;
        j--;
    }
    if(flag == 1){
        cout<<"not a palindrome";
    }
    else{
        cout<<"String is palindrome.";
    }
    delete[] s;
    return 0;

}