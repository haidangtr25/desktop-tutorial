#include <iostream>

using namespace std;
const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 800;
const int OBJECT_SIZE = 30;
const int PLAYER_Size = 50;
const int gravity = 2;

struct Player{
    int x,y;
};
struct Object{
int x,y,speed;
};
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_RenderTexture* PlayerTexture = nullptr;
SDL_RenderTexture* ObjectTexture = nullptr;

bool init(){
if(SDL_Init(SDL_INIT_VIDEO) < 0){
    cerr<< "can't initilize SDL" << SDL_GetError();
    return false;
}
window = SDL_CreateWindow("Dodge falling object",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_HEIGHT,WINDOW_WIDTH,SDL_WINDOW_SHOWN);
if(!window){
        cerr<<"cant create window";
    return false;
}
renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
if(!renderer){
        cerr<< "cant create renderer";
    return false;
}
return true;
}

bool LoadTexture(){
PlayerTexture = IMG_LoadTexture(renderer,"player.png");
ObjectTexture = IMG_LoadTexture(renderer,"object.png");
if(!PlayerTexture || !ObjectTexture){
    cerr << "failed to load texture";
    return false;

}
return true;
}
void close(){
SDL_DestroyTexture(playerTexture);
SDL_DestroyTexture(objectTexture);
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_QUIT();

}
bool checkCollision(const int &x1,const int &y1,const int &w1,const int &h1,const int &x2,const int &y2,const int &w2,const int &h2){
    //(y1 < y2+h2 && x2 < x1+w1 &&
    return (x1<x2+w2&& x2<x1+w1 && y1 < y2 +h2);
}
int main()
{
    if(!init()){
        return 0;
    }
    if(!loadTexture()){
        return 0;
    }

    bool quit = false;
    SDL_PollEvent e;
    srand(time(0));
    Object object = {rand() % (SCREEN_WIDTH-PLAYER_SIZE),0,3};
    Player player = {SCREENWIDTH/2,SCREENHEIGHT-PLAYER_SIZE};
    while(!quit){
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                quit = true;
            }
        }
        Uint8* keystates = SDL_GetKeyStates(nullptr);
        if(keystates[SDL_SCAN_A] && player.x > 0){
            player.x -=1;
        }
        if(keystates[SDL_SCAN_D] && player.x < SCREEN_WIDTH-PLAYER_SIZE){
            player.x += 1;
        }
    //update player movement
    if(object.y + PLAYER_SIZE< SCREEN_HEIGHT){
        object.y += object.speed;
        if(object.y+PLAYER_SIZE>= SCREEN_HEIGHT){
            object.y = 0;
            object.x = rand() %(SCREEN_WIDTH-PLAYER_SIZE);
        }
    }
    // nap
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_Rect PlayeRect = {player.x,player.y,PLAYER_SIZE,PLAYER_SIZE};
    SDL_Rect ObjectRect = {object.x,object.y,OBJECT_SIZE,OBJECT_SIZE};
    //ve
    SDL_RenderCopy(renderer,PlayerTexture,nullptr,&PlayerRect};
    SDL_Rendercopy(renderer,ObjectTexture,nullptr,&ObjectRect};
    // present it
    SDL_RenderPresent(renderer);
    //delete
    SDL_RenderClear(renderer);
    SDL_Delay(16);
    }
    return 0;
}
dbabasj
ádasda
đáa
đâsd
adasdasd
adadasd
ádada
đâsda
ádadas
đaada