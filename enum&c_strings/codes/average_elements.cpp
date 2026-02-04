#include <iostream>
#define endl '\n'
using std::cin;
using std::cout;

int main(){
    int n;
    cin >> n;

    char** strings_num = new char* [n];

    for(int i = 0; i < n; i++){
        strings_num[i] = new char[4];
    }
    
    for(int i = 0; i < n; i++){
        cin >> strings_num[i];
    }

    double sum = 0.0;
    for(int i = 0; i < n; i++){
        int num = 0;
        int j = 0;
        while(strings_num[i][j] != '\0'){
            num = num * 10 + (strings_num[i][j] - '0'); 
            j++;
        }
        sum += num;
    }
        
    cout << sum/n << endl;
    
    if(strings_num != nullptr){
        for(int i = 0; i < n; i++){
            delete[] strings_num[i];
            strings_num[i] = nullptr;
        }
        delete[] strings_num;
        strings_num = nullptr;
    }

    return 0;
}