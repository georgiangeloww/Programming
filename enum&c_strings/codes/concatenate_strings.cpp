#include <iostream>
#include <cstring>
int const MAX = 10;


int main(){
    int n;
    std::cin >> n;
    char** strings = new char*[n];

    for(int i = 0; i < n; i++){
        strings[i] = new char[MAX];
        std::cout << "Enter text:" << std::endl;
        std::cin >> strings[i];
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

