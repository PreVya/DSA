#include <iostream>
#include <cstring>

using namespace std;

//TC = O(n) and SC = O(1)
int main() {
    int size;
    cout << "Enter size for array: ";
    cin >> size;
    getchar(); 

    char *s = new char[size];
    cout << "Enter the string to check (lowercase): ";
    fgets(s, size, stdin);

    int H[26] = {0};
    for (int i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
        H[s[i] - 'a']++;  //H[s[i]-'A'] for uppercase letters
    }

    //for toggle case as user is naughty :
//     for (int i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
//     if (s[i] >= 'a' && s[i] <= 'z') {
//         H[s[i] - 'a']++; // Handle lowercase
//     } 
//     else if (s[i] >= 'A' && s[i] <= 'Z') {
//         H[s[i] - 'A']++; // Handle uppercase
//     }
//}


    for (int i = 0; i < 26; i++) {
        if (H[i] > 1) {
            cout << "Index: " << i << ", Letter: " << (char)(i + 'a') << ", Occurrences: " << H[i] << endl;
        }
    }

    // Time Complexity: O(n) where n is string length, Space Complexity: O(1) as the hash array size is fixed at 26.
    delete[] s;
    return 0;
}