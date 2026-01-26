#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
#define endl "\n"


enum HType{
    MAGE,
    WARRIOR,
    ARCHER,
    DRAGON
};


struct Hero{
    std::string name;
    HType type;
    int level;
    int gold;
    void input();
    void output();
};



int main(){
    int n;
    cin >> n;
    Hero** heroesArr = new Hero*[n];
    for(int i = 0; i < n; i++){
        heroesArr[i] = new Hero;
    }

    for(int i = 0; i < n; i++){
        heroesArr[i]->input();
    }

    for(int i = 0; i < n; i++){
        heroesArr[i]->output();
    }



    return 0;
}

void Hero::input(){
    cout << "Enter the name of the Hero: ";
    cin >> name;

    cout << "Enter what type of Hero is: 0-MAGE, 1-WARRIOR, 2-ARCHER, 3-DRAGON";
    int t;
    cin >> t;
    switch(t){
        case 0: type = MAGE; break;
        case 1: type = WARRIOR; break;
        case 2: type = ARCHER; break;
        case 3: type = DRAGON; break;
        default: cout << "No such type!";
    }

    cout << "Enter the level of the hero: ";
    cin >> level;

    cout << "Enter the gold quantity the hero has: ";
    cin >> gold;
}



void Hero::output(){
    cout << "Name: " << name << endl;

    cout << "The type of the hero: ";

    switch(type){
        case 0: cout << MAGE; break;
        case 1: cout << WARRIOR; break;
        case 2: cout << ARCHER; break;
        case 3: cout << DRAGON; break;
        default: cout << "No such hero!";
    }
    cout << endl;

    cout << "The level of the hero is: ";
    cout << level << endl;

    cout << "The gold of the hero is: ";
    cout << gold << endl;
}