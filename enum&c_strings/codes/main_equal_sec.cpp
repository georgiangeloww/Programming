#include <iostream>
#define endl '\n'
using std::cin;
using std::cout;

char* concatenateStrMain(char*** word, int n);
char* concatenateStrSec(char*** word, int n);

const int MAX_W = 7;

int main(){
    int n;
    cin >> n;
    
    char*** stringsTableArr = new char** [n];
    for(int i = 0; i < n; i++){
        stringsTableArr[i] = new char* [n];
        for(int j = 0; j < n; j++){
            stringsTableArr[i][j] = new char [n];
            cin >> stringsTableArr[i][j];
        }
    }

    char* finalResMain = concatenateStrMain(stringsTableArr, n);
    char* finalResSec = concatenateStrSec(stringsTableArr, n);

    cout << "Concatenate sentance: " << endl;
    cout << finalResMain << endl;

    cout << "Concatenate sentance: " << endl;
    cout << finalResSec << endl;


    if(std::strcmp(finalResMain, finalResSec) == 0){
        cout << "The diagonals of the table are equal!" << endl;
    }
    else{
        cout << "The digonals of the tabel are NOT equal!" << endl;
    }


    if(stringsTableArr != nullptr){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                delete[] stringsTableArr[i][j];
                stringsTableArr[i][j]  = nullptr;
            }
            delete[] stringsTableArr[i];
            stringsTableArr[i] = nullptr;
        }
        delete[] stringsTableArr;
        stringsTableArr = nullptr;
    }

    return 0;
}

char* concatenateStrMain(char*** word, int n){
    size_t maxLenght = 0;

    for(int i = 0; i < n; i++){
        maxLenght += std::strlen(word[i][i]);
    }

    char* resArrMain = new char [maxLenght + 1];
    resArrMain[0] = '\0';

    for(int i = n - 1; i >= 0; i--){
        std::strcat(resArrMain, word[i][i]);
    }

    return resArrMain;

}

char* concatenateStrSec(char*** word, int n){
    size_t maxLenght = 0;

    for(int i = 0; i < n; i++){
        for(int j = n - i - 1; j >= n - i - 1; j--){
            maxLenght += std::strlen(word[i][j]);
        }
    }

    char* resArrSec = new char [maxLenght + 1];
    resArrSec[0] = '\0';

    for(int i = 0; i < n; i++){
        for(int j = n - i - 1; j >= n - i - 1; j--){
            std::strcat(resArrSec, word[i][j]);
        }
    }

    return resArrSec;

}
