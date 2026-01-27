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

void Message::input(){
    cout << "Enter the name of the message: ";
    cin >> name;

    cout << "Enter the message: ";
    std::getline(cin >> std::ws, text);

    cout << "Enter the secturity level of the message: ";
    cin >> levelSec;
}