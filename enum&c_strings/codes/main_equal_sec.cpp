#include <iostream>
#define endl '\n'
using std::cin;
using std::cout;

char* concatenateStr(char*** word, int n);

const int MAX_W = 7;

int main(){
    int n;
    cin >> n;


    return 0;
}

char* concatenateStr(char*** word, int n){
    int max_lenght = n * n * MAX_W;

    char* resArrMain = new char [max_lenght];

    resArrMain = {'\0'};

    for(int i = 0; i < n; i++){
        std::strcat(word[i][i], resArrMain);
    }

    return resArrMain;

}
