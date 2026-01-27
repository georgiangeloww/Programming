#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

// const int H=20;
// const int W=35;
const int MAX_INV = 6;
const int MAX_ENEMIES = 8;
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

void tryPickupItem(char** map, int r, int c, char* inventory, int* invSize);
void useItem(char* inventory, int* invSize, int slot, int* php, int* buffHits);
bool hasKey(const char* inventory, int invSize);
int enemyAt(int r, int c, int* enemiesR, int* enemiesC, bool* enemiesAlive, int n);
void resolveCombat(int* php, int patk, int* buffHits, int* ehp, int eatk);
void moveEnemies(char** map, int h, int w, int pr, int pc,
                 int* enemiesR, int* enemiesC, int* enemiesHP, int* enemiesATK,
                 bool* enemiesAlive, int enemyCount,
                 int* php, int patk, int* buffHits);

void destroyMap(char** map, int h);


int main(){
    int h;
    int w;
    cin >> h;
    cin >> w;

    srand(time(nullptr));

    int pr = 1, pc = 1;
    int HP = 14;
    int atkp = ATK;
    int buffHits = 0;
    int moves = 0;
    char cmd;


    char inventory[MAX_INV];
    int invSize = 0;
    bool enemiesAlive[MAX_ENEMIES];

    bool running = true;
    bool reachedExit = false;

    char** map = createMap(h, w);
    fillRooms(map, h, w);

    placeRandom(map, h, w, 'D');
    placeRandom(map, h, w, 'E');
    placeRandom(map, h, w, 'C');
    placeRandom(map, h, w, 'S');
    placeRandom(map, h, w, 'K');
    placeRandom(map, h, w, 'X');

    int enemiesR[MAX_ENEMIES];
    int enemiesC[MAX_ENEMIES];
    int enemiesHP[MAX_ENEMIES];
    int enemiesATK[MAX_ENEMIES];
    bool enemiesAlive[MAX_ENEMIES];
    int enemyCount = 2;

    enemiesHP[0] = 7; enemiesATK[0] = 2; enemiesAlive[0] = true;
    enemiesHP[1] = 10; enemiesATK[1] = 3; enemiesAlive[1] = true;


     for(int i = 0; i < enemyCount; i++){
        for(int r = 0; r < h; r++){
            for(int c = 0; c < w; c++){
                if((i==0 && map[r][c]=='D') || (i==1 && map[r][c]=='E')){
                    enemiesR[i] = r;
                    enemiesC[i] = c;
                    map[r][c] = '.';
                }
            }
        }
    }

    while (running){
        
        int aliveCount = 0;
        for(int i = 0; i < enemyCount; i++){
            if(enemiesAlive[i]) 
            aliveCount++;
        }

        render(map, h, w, pr, pc, HP, atkp, buffHits, moves, inventory, invSize, aliveCount);

            
        cmd = readInput();
        
        if(cmd == 'Q') break;

        else if(cmd == 'U'){
            int slot;
            cin >> slot;
            slot--;
            useItem(inventory, &invSize, slot, &HP, &buffHits);
        }


         else if(cmd == 'W' || cmd == 'A' || cmd == 'S' || cmd == 'D'){
            if(movePlayer(map, h, w, &pr, &pc, cmd, inventory, &invSize, &HP, atkp, &buffHits, &reachedExit))
                moves++;
        }
        


        moveEnemies(map, h, w, pr, pc,
                    enemiesR, enemiesC, enemiesHP, enemiesATK,
                    enemiesAlive, enemyCount,
                    &HP, atkp, &buffHits);

        if(reachedExit && hasKey(inventory, invSize)){
            cout << "YOU WIN!\n";
            running = false;
        }
        if(HP <= 0){
        cout << "YOU LOSE!\n";
        running = false;
        }

    }



    destroyMap(map, h);


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

void tryPickupItem(char** map, int r, int c, char* inventory, int* invSize){
    char tile = map[r][c];

    if(tile == 'C' || tile == 'S' || tile == 'K'){
        if(*invSize < MAX_INV){
            inventory[*invSize] = tile;
            (*invSize)++;
            map[r][c] = '.';
        }
    }
}


void useItem(char* inventory, int* invSize, int slot, int* php, int* buffHits){
    if(slot < 0 || slot >= *invSize) return;

    char item = inventory[slot];

    if(item == 'C'){
        *php += 5;
        if(*php > HP_CAP)
            *php = HP_CAP;
    }
    else if(item == 'S'){
        *buffHits = 3;
    }

    for(int i = slot; i < (*invSize)-1; i++)
        inventory[i] = inventory[i+1];
    (*invSize)--;
}


bool hasKey(const char* inventory, int invSize){
    for(int i = 0; i < invSize; i++)
        if(inventory[i] == 'K')
            return true;
    return false;
}

int enemyAt(int r, int c, int* enemiesR, int* enemiesC, bool* enemiesAlive, int n) {
    for(int i = 0; i < n; i++){
        if(enemiesAlive[i] && enemiesR[i] == r && enemiesC[i] == c)
            return i;
    }
    return -1;
}

void resolveCombat(int* php, int patk, int* buffHits, int* ehp, int eatk) {
    int currentATK = patk;
    if(*buffHits > 0){
        currentATK += 2;
        (*buffHits)--;
    }

    *ehp -= currentATK;
    if(*ehp <= 0) return;

    *php -= eatk;
}

void moveEnemies(char** map, int h, int w, int pr, int pc,
                 int* enemiesR, int* enemiesC, int* enemiesHP, int* enemiesATK,
                 bool* enemiesAlive, int enemyCount,
                 int* php, int patk, int* buffHits) {

    for(int i = 0; i < enemyCount; i++){
        if(!enemiesAlive[i]) continue;

        int er = enemiesR[i];
        int ec = enemiesC[i];

        int dr = pr - er;
        int dc = pc - ec;

        int nr = er;
        int nc = ec;

        if(abs(dr) + abs(dc) <= 5){
            if(abs(dr) > abs(dc)) nr += (dr > 0 ? 1 : -1);
            else nc += (dc > 0 ? 1 : -1);
        } else {
            int dir = rand() % 4;
            switch(dir){
                case 0: nr = er-1; break;
                case 1: nr = er+1; break;
                case 2: nc = ec-1; break;
                case 3: nc = ec+1; break;
            }
        }

        if(!inBounds(nr, nc, h, w)) { nr = er; nc = ec; }
        else if(map[nr][nc] == '#') { nr = er; nc = ec; }
        else if(enemyAt(nr, nc, enemiesR, enemiesC, enemiesAlive, enemyCount) != -1) { nr = er; nc = ec; }

        if(nr == pr && nc == pc){
            resolveCombat(php, patk, buffHits, &enemiesHP[i], enemiesATK[i]);
            if(enemiesHP[i] <= 0) enemiesAlive[i] = false;
            continue;
        }

        enemiesR[i] = nr;
        enemiesC[i] = nc;
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

