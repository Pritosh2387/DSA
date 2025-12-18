#include<bits/stdc++.h>
using namespace std;
void Reverse_words_in_an_string(string &str){
    auto strt = str.begin();
    for(auto it = strt; it !=str.end();it++ ){
        if(*it!=' '){
            continue;
        }else{
            reverse(strt,it);
            strt=it+1;
        }
    }
    reverse(strt,str.end());
    cout<<str;
}
void replaceSpaces(string &str) {
    int spaces = 0;
    int originalLength = str.length();
    // Count spaces
    for (char ch : str) {
        if (ch == ' ') spaces++;
    }
    // Resize string to fit "@40" (3 chars) instead of ' ' (1 char)
    str.resize(originalLength + 2 * spaces); // +2 extra for each space
    // Start filling from end
    int i = originalLength - 1;
    int j = str.length() - 1;
    while (i >= 0) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '4';
            str[j--] = '@';
        } else {
            str[j--] = str[i];
        }
        i--;
    }
}
int main(){
    string str="I am Pritosh Burman";
    replaceSpaces(str);
    cout << str << endl;
    return 0;
}