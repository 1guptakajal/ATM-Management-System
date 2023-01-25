#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<time.h>
using namespace std;
enum DIR{LEFT,UP,RIGHT,DOWN};
struct POS{
int x,y;
POS(){
    x=-50;
    y=0;
}
};
class food{
    private:
    POS foodPos;
    public:
    void draw();
    void generate(int,int);
    bool update(int,int);
};
void food::draw(){
    setcolor(RED);
    rectangle(foodPos.x,foodPos.y,foodPos.x+30,foodPos.y+30);
    setfillstyle(INTERLEAVE_FILL,RED);
    floodfill(foodPos.x+15,foodPos.y+15,RED);
}
void food::generate(int snakeHeadx,int snakeHeady){
    srand(time(0));
    foodPos.x=30*(rand()%15+1);
    srand(time(0));
    foodPos.y=30*(rand()%15+1);
    if(foodPos.x==snakeHeadx &&foodPos.y==snakeHeady){
        generate(snakeHeadx,snakeHeady);
    }
}
bool food::update(int snakeHeadx,int snakeHeady){
    if(foodPos.x==snakeHeadx && foodPos.y==snakeHeady){
        return true;
    }
    else{
        return false;
    }
}
class snakeBody{
    private:
    POS arr[31];
    int direction;
    int lenght;
    public:
    snakeBody(){
        arr[0].x=30;
        arr[0].y=30;
        lenght=2;
        direction=RIGHT;
    }
    void drawSnake();
    void appendSnake();
    void changeDirTo(int);
    int update();
    int getPosx();
    int getPosy();
    int getlenght();
};
void snakeBody::drawSnake(){
for(int i=0;i<lenght;i++){
    setcolor(BLUE);
    rectangle(arr[i].x,arr[i].y,arr[i].x+30,arr[i].y+30);
    if(i==0){setfillstyle(SOLID_FILL,GREEN);}
    else{setfillstyle(SOLID_FILL,LIGHTGREEN);}
    floodfill(arr[i].x+15,arr[i].y+15,BLUE);
}
}
void snakeBody::appendSnake(){
    if(lenght<30){lenght++;}
}
void snakeBody::changeDirTo(int newdir){
    if(newdir==LEFT ||newdir==RIGHT){
        if(direction==UP || direction==DOWN){direction=newdir;}
    }
    else if(newdir==UP ||newdir==DOWN){
        if(direction==LEFT || direction==RIGHT){direction==newdir;}
    }
}
int snakeBody::update(){
    for(int i=0;i<lenght;++i){
        if(arr[0].x==arr[i].x && arr[0].y==arr[i].y){return 0;}
    }
    for(int i=lenght;i>=0;--i){
        if(i==0){
            arr[1].x=arr[0].x;
            arr[1].y=arr[0].y;
        }
        else{
            arr[i].x=arr[i-1].x;
            arr[i].y=arr[i-1].y;
        }
    }
    if(direction==LEFT){
        arr[0].x-=30;
        if(arr[0].x==0){
            arr[0].x=450;
        }
            }
            else if(direction==RIGHT){
                arr[0].x+=30;
                if(arr[0].x==480){
                    arr[0].x=30;
                }
            }
            else if(direction==UP){
                arr[0].y-=30;
                if(arr[0].y==0){
                    arr[0].y=450;
                }
            }
            else if(direction==DOWN){
                arr[0].y+=30;
                if(arr[0].y==480){
                    arr[0].y=30;
                }
                  }
                  return 1;
}
int snakeBody::getPosx(){
    return arr[0].x;
}
int snakeBody::getPosy(){
    return arr[0].y;
}
int snakeBody::getlenght(){
}
int main(){
    initwindow(800,510,"SNAKE GAME");
    snakeBody body;
    food fruit;
    int lenght,count=0;
    bool playing=true;
    char lenghtarr[30];
    fruit.generate(body.getPosx(),body.getPosy());
    int page=0;
    while(1){
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        setcolor(BLUE);
        setfillstyle(SOLID_FILL,BLUE);
        if(GetAsyncKeyState(VK_LEFT)){
            body.changeDirTo(LEFT);
        }
        if(GetAsyncKeyState(VK_LEFT)){
            body.changeDirTo(LEFT);
        }
        if(GetAsyncKeyState(VK_UP)){
            body.changeDirTo(UP);
        }
        if(GetAsyncKeyState(VK_RIGHT)){
            body.changeDirTo(RIGHT);
        }
        if(GetAsyncKeyState(VK_DOWN)){
            body.changeDirTo(DOWN);
        }
        if(GetAsyncKeyState(VK_ESCAPE)){break;}
        if(playing==true && !body.update()){playing=false;}
        else{body.drawSnake();}
        if(fruit.update(body.getPosx(),body.getPosy()));{
         fruit.generate(body.getPosx(),body.getPosy());
         body.appendSnake();
        }
        setcolor(BLUE);
        rectangle(0,0,30,510);
        rectangle(30,0,480,30);
        rectangle(480,0,510,510);
        rectangle(30,480,480,510);
        rectangle(510,0,800,20);
        rectangle(510,250,800,270);
        rectangle(780,20,800,250);
        rectangle(510,490,800,510);
        rectangle(7800,270,800,490);
        setfillstyle(SOLID_FILL,BLUE);
        floodfill(15,250,BLUE);
        floodfill(250,15,BLUE);
        floodfill(495,250,BLUE);
        floodfill(250,495,BLUE);
        floodfill(550,260,BLUE);
        floodfill(550,10,BLUE);
        floodfill(790,500,BLUE);
        floodfill(550,500,BLUE);
        floodfill(790,300,BLUE);
        settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
        setcolor(GREEN);
        outtextxy(550,70,"LENGHT");
        outtextxy(520,130,"ACHIEVED");
        lenght=body.getlenght();
        lenghtarr[0]=char(48+lenght/10);
        lenghtarr[1]=char(48+lenght%10);
        lenghtarr[2]='\0';
        outtextxy(620,190,lenghtarr);
        settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
        outtextxy(520,300,"STATUS:-");
        if(body.getlenght()==30){
            outtextxy(520,350,"you won !");
            playing=false;
        }
        else if(playing){
            outtextxy(520,350,"PLAYING");
        }
        else{
            outtextxy(520,350,"GAME OVER");
        }
        settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
        outtextxy(520,400,"PRESS ESC TO EXIT");
        fruit.draw();
        page=1-page;
        delay(100);
    }
    getch();
    closegraph();
}