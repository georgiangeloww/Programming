
/*


Етап 1(Карта и рендер) -
4) Данни и константи (пример)
H=20, W=35; MAX_INV=6; MAX_ENEMIES=8 (използвани ~6); HP старт=14, ATK=3, BuffHits=0; D: HP7/ATK2; E: HP10/ATK3; HP_CAP=20.

3.7 Рендер/статус
Показвайте карта и статус лента: HP/MAX, ATK, BuffHits, Moves, EnemiesAlive, Items[..].

Рендер и вход:
void render(char** map, int h, int w,
           int pr, int pc, int php, int patk, int buffHits, int moves,
           const char* inv, int invSize, int enemiesAlive);
char readInput();


5) Задължителни функции (API договор)
Карта и помощни:
char** createMap(int h, int w);
void   destroyMap(char** m, int h);
bool   inBounds(int r, int c, int h, int w);
bool   isWalkable(char ch);


*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const int H=20;
const int W=35;
const int MAX_INV=6;
const int MAX_ENEMIES=8; //(използвани ~6);
const int ATK=3;
const int HP_CAP=20;


char** createMap(int h, int w);
void renderMap(char** map, int h, int w);
void destroyMap(char** map, int h);
bool isBounds(int r, int c, int h, int w);


int main(){

    int h;
    int w;
    cin >> h;
    cin >> w;

   

    char** map = createMap(h, w);
    renderMap(map, h, w);
    destroyMap(map, h);


   
    int HP = 14; 
    int BuffHits = 0; 
    // D: HP7/ATK2; E: HP10/ATK3;

    // cout << HP << "/" << HP_CAP << ATK << BuffHits;Moves, EnemiesAlive, Items[..]


    return 0;
}

char** createMap(int h, int w){
    char** map = new char* [h];

    for (int i = 0; i < h; i++){
        map[i] = new char [w];
    }

    return map;
}

// test render
void renderMap(char** map, int h, int w){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}


void destroyMap(char** map, int h){
        if(map != nullptr){
        for(int i = 0; i < h; h++){
            delete[] map[i];
            map[i] = nullptr;   
        }
        delete[] map;
    }
    map = nullptr;
}

bool isBounds(int r, int c, int h, int w){
    if (r >= 0 && r < h && c >= 0 && c < w){
        return true;
    }
}

