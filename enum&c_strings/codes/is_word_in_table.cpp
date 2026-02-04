#include <iostream>
#include <cstring>
#define endl '\n'

using std::cin;
using std::cout;

bool isStrInArr(char*** array, char* word, int n);

int main(){

    char* s = new char[7];
    
    cout << "Enter the searched word: ";
    cin >> s;

    int n;
    cout << "Enter the size of the table nxn: ";
    cin >> n;

    char*** strings = new char** [n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
        }
    }






    if(s != nullptr){
        delete[] s;
    }
    return 0;
}

bool isStrInArr(char*** array, char* word, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(std::strcmp(word, array[i][j]) == 0){
                return true;
            } 
        }
    }
    return false;
}