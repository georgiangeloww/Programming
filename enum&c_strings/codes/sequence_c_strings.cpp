#include <iostream>
#include <cstring>
#define endl '\n'
using std::cout;
using std::cin;



int main(){

    int n;
    cin >> n;

    char** strings = new char* [n];

    for(int i = 0; i < n; i++){
        strings[i] = new char[10];
    }
    
    for(int i = 0; i < n; i++){
        cin >> strings[i];
    }

    bool is_monotonne_discending = true;
    for(int i = 0; i < n - 1; i++){
        if(std::strcmp(strings[i], strings[i + 1]) <= 0){
            is_monotonne_discending = false;
            break;
        }
    }

    if(is_monotonne_discending){
        cout << "Strings are monotone discending!";
    }
    else{
        cout << "Strings are Not monotonne discending!";
    }

    if(strings != nullptr){
        for(int i = 0; i < n; i++){
            delete[] strings[i];
            strings[i] = nullptr;
        }
        delete[] strings;
        strings = nullptr;
    }

    return 0;
}