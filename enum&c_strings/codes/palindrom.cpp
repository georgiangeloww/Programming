#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

const int MAX = 20;

bool isPalindrom(char* array, size_t len);


int main(){
    char string[MAX];
    cout << "Enter string: " << endl;
    std::cin.getline(string, MAX);

    size_t len = std::strlen(string);

    if(isPalindrom(string, len)){
        cout << "It is a palindrom" << endl;
    }
    else{
        cout << "It is NOT a palindrom" << endl;
    }


    return 0;
}

bool isPalindrom(char* array, size_t sz){
    for(int i = 0; i < sz / 2; i++){
        if(array[i] != array[sz - 1 - i]){
            return false;
        }
    }
    return true;
}