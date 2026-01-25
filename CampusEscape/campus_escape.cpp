#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

// const int H=20;
// const int W=35;
const int MAX_INV = 6;
const int MAX_ENEMIES = 8; //(използвани ~6);
const int ATK = 3;
const int HP_CAP = 20;


char** createMap(int h, int w);
bool inBounds(int r, int c, int h, int w);
bool isWalkable(char ch);
void fillRooms(char** map, int h, int w);
void randomEmptyCell(char** map, int h, int w, int* rr, int* cc);
void placeRandom(char** map, int h, int w, char ch);
char readInput();
void render(char** map, int h, int w,
           int pr, int pc, int php, int patk, int buffHits, int moves,
           const char* inv, int invSize, int enemiesAlive);

bool movePlayer(char** map, int h, int w, 
                int* pr, int* pc, char dir,
                char* inventory, int* invSize,
                int* php, int patk, int* buffHits,
                bool* reachedExit);

void renderMap(char** map, int h, int w);
void destroyMap(char** map, int h);


int main(){
    int h;
    int w;
    cin >> h;
    cin >> w;

    srand(time(nullptr));

    int pr = 1, pc = 1; // позиция на играча
    int HP = 14;
    int atkp = ATK;
    int buffHits = 0;
    int moves = 0;
    char cmd = readInput();

    char inventory[MAX_INV];
    int invSize = 0;
    int enemiesAlive = 3;

    bool running = true;
    bool reachedExit = false;

    char** map = createMap(h, w);
    fillRooms(map, h, w);

    // placeRandom(map, h, w, 'P');
    placeRandom(map, h, w, 'D');
    placeRandom(map, h, w, 'E');
    placeRandom(map, h, w, 'C');
    placeRandom(map, h, w, 'S');
    placeRandom(map, h, w, 'K');
    placeRandom(map, h, w, 'X');


    while (running){
        render(map, h, w,
            pr, pc, HP, atkp, buffHits, moves,
            inventory, invSize, enemiesAlive);

        

        int nr = pr;
        int nc = pc;

        switch (cmd) {
            case 'W': nr--; break;
            case 'S': nr++; break;
            case 'A': nc--; break;
            case 'D': nc++; break;
            case 'Q': running = false; continue;
            default: continue;
        }

        if (inBounds(nr, nc, h, w) && isWalkable(map[nr][nc])){
            pr = nr;
            pc = nc;
            moves++;
        }
    }


    if (movePlayer(
        map, h, w,
        &pr, &pc, cmd,
        inventory, &invSize,
        &HP, atkp,
        &buffHits,
        &reachedExit)) moves++; 

    if (reachedExit) {
        cout << "YOU WIN!" << endl;
        running = false;
    }


    renderMap(map, h, w);
    destroyMap(map, h);

    // D: HP7/ATK2; E: HP10/ATK3;
    // дали да не ги разменя enemiesAlive, Items[..]


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

char readInput(){
    char ch;
    cin >> ch;
    return ch;
}

void render(char** map, int h, int w, 
    int pr, int pc, int php, int patk, int buffHits, int moves, 
    const char* inv, int invSize, int enemiesAlive){
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (r == pr && c == pc)
                cout << 'P';
            else
                cout << map[r][c];
        }
        cout << endl;
    }

    cout << endl;

    cout << "HP: " << php << "/" << HP_CAP << "  ATK: " << patk;

    if (buffHits > 0)
        cout << " (buff " << buffHits << ")";

    cout << endl;

    cout << "Moves: " << moves << endl;

    cout << "Inventory: ";
    for (int i = 0; i < invSize; i++)
        cout << inv[i] << ' ';
    cout << endl;

    cout << "Enemies alive: " << enemiesAlive << endl;
}


bool movePlayer(
    char** map, int h, int w,
    int* pr, int* pc, char dir,
    char* inventory, int* invSize,
    int* php, int patk,
    int* buffHits,
    bool* reachedExit){

    int nr = *pr;
    int nc = *pc;

    switch (dir) {
        case 'W': nr--; break;
        case 'S': nr++; break;
        case 'A': nc--; break;
        case 'D': nc++; break;
        default: return false;
    }

    if (!inBounds(nr, nc, h, w))
        return false;

    char tile = map[nr][nc];

    if (tile == '#')
        return false;


    if (tile == 'C' || tile == 'S' || tile == 'K') {
        tryPickupItem(map, nr, nc, inventory, invSize);
    }

    if (tile == 'D' || tile == 'E') {
        return false;
    }
    else if (tile == 'X') {
        *reachedExit = true;
    }

    *pr = nr;
    *pc = nc;

    return true;
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

