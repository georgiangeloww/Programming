#include <iostream>
#include <cstring>
int const MAX = 10;

char* concatenateStrings(char** words, int n);

int main(){
    int n;
    std::cin >> n;
    char** strings = new char*[n];

    for(int i = 0; i < n; i++){
        strings[i] = new char[MAX];
        std::cout << "Enter text:" << std::endl;
        std::cin >> strings[i];
    }

    char* finalResult = concatenateStrings(strings, n);

    std::cout << "Final result: " << finalResult << std::endl;


    if(strings != nullptr){
        for(int i = 0; i < n; i++){
            delete[] strings[i];
            strings[i] = nullptr;
        }
        delete[] strings;
        strings = nullptr;

        delete[] finalResult; 
        finalResult = nullptr;  

    }

    return 0;
}

char* concatenateStrings(char** words, int n){
    size_t totalLength = 0;
    
    for(int i = 0; i < n; i++){
        totalLength += std::strlen(words[i]);
    }

    char* result = new char[totalLength + 1];
    result[0] = '\0';

    for(int i = 0; i < n; i++){
        std::strcat(result, words[i]);
    }

    return result;
}