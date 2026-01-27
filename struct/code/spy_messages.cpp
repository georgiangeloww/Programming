#include <iostream>
#include <string>
#define endl '\n'
using std::cin;
using std::cout;


struct Message{
    std::string name;
    std::string text;
    int levelSec;
    void input();
    void output();

};

int main(){
    int n;
    cin >> n;
    Message* messagesArr = new Message[n];

        
    if(messagesArr != nullptr){
        delete[] messagesArr;
        messagesArr = nullptr;
    }
    return 0;
}

