
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
bool inBounds(int r, int c, int h, int w);
bool isWalkable(char ch);
void fillRooms(char** map, int h, int w);
void randomEmptyCell(char** map, int h, int w, int* rr, int* cc);
void placeRandom(char** map, int h, int w, char ch);

void renderMap(char** map, int h, int w);
void destroyMap(char** map, int h);


int main(){

    int h;
    int w;
    cin >> h;
    cin >> w;

   

    char** map = createMap(h, w);
    fillRooms(map, h, w);

    placeRandom(map, h, w, 'P');
    placeRandom(map, h, w, 'D');
    placeRandom(map, h, w, 'E');
    placeRandom(map, h, w, 'C');
    placeRandom(map, h, w, 'S');
    placeRandom(map, h, w, 'K');
    placeRandom(map, h, w, 'X');

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

bool inBounds(int r, int c, int h, int w){
    return r >= 0 && r < h && c >= 0 && c < w;
}

bool isWalkable(char ch){
    return ch == '.' || ch == 'D' || ch == 'E' || ch == 'C' || ch == 'S' || ch == 'K' || ch == 'X';
}

void fillRooms(char** map, int h, int w){
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
                map[i][j] = '#';
            else
                map[i][j] = '.';
        }
    }
}

void randomEmptyCell(char** map, int h, int w, int* rr, int* cc){
    int r, c;
    do {
        r = rand() % h;
        c = rand() % w;
    } while (map[r][c] != '.');
    *rr = r;
    *cc = c;
}

void placeRandom(char** map, int h, int w, char ch){
    int r, c;
    randomEmptyCell(map, h, w, &r, &c);
    map[r][c] = ch;
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
        for(int i = 0; i < h; i++){
            delete[] map[i];
            map[i] = nullptr;   
        }
        delete[] map;
    }
    map = nullptr;
}