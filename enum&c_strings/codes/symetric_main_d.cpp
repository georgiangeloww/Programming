#include <iostream>
// #include <cstring>
#define endl '\n'
using std::cin;
using std::cout;


bool isSymetric(char*** strArr, int n);

int main(){
    int n;
    cin >> n;

    char*** strings = new char** [n];
    for(int i = 0; i < n; i++){
        strings[i] = new char* [n];
        for(int j = 0; j < n; j++){
            strings[i][j] = new char[10];
            cin >> strings[i][j];
        } 
    }

    if(isSymetric(strings, n)){
        cout << "The matrix is symetric in terms of the main diagonal!" << endl;
    }
    else{
        cout << "The matrix is NOT symetric in terms of the main diagonal!" << endl;
    }


    if(strings != nullptr){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                delete[] strings[i][j];
                strings[i][j] = nullptr;
            }
            delete[] strings[i];
        }
        delete[] strings;
    }

    return 0;
}

bool isSymetric(char*** strArr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(std::strcmp(strArr[i][j], strArr[j][i])){
                return false;
            }
        }
    }
    return true;
}
