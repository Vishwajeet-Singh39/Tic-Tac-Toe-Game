#include<iostream>
using namespace std;
class players{
    string playerX,playerO,p;
    char grid[3][3]={'.','.','.','.','.','.','.','.','.'};
    int x,y,i,j;
    char temp;
    public: 
        players(string p1,string p2,string px){
            playerX=p1;
            playerO=p2;
            p=px;
        }
        void gridReset(){
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    grid[i][j]='.';
                }
            }
        }
        void checkValidity(){
            if(p==playerX){
                display();
                cout<<"Player of current turn: "<<playerX<<endl;
                getRowLocation();
                TurnX();
            }
            else if(p==playerO){
                display();
                cout<<"Player of current turn: "<<playerO<<endl;
                getRowLocation();
                TurnO();
            }
            else{
                cout<<p<<" is not a registered player."<<endl;
                cin>>p;
                checkValidity();
            }
            return;
        }
        void display(){
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    cout<<grid[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            return;
        }
        void getRowLocation(){
            cout<<"Choose a row number (0 to 2)"<<endl;
            cin>>x;
            if(x>-1&&x<3){
                getColumnLocation();
            }
            else{
                cout<<x<<" is not a valid row."<<endl;
                getRowLocation();
            }
            return;
        }
        void getColumnLocation(){
            cout<<"Choose a column number (0 to 2)"<<endl;
            cin>>y;
            if(y>-1&&y<3){
                return;
            }
            else{
                cout<<x<<" is not a valid column."<<endl;
                getColumnLocation();
            }
        }
        void TurnX(){
            if(grid[x][y]=='.'){
                grid[x][y]='X';
                check();
                p=playerO;
                checkValidity();
            }
            else{
                cout<<"This slot is already occupied"<<endl;
                getRowLocation();
                TurnX();
            }
        }
        void TurnO(){
            if(grid[x][y]=='.'){
                grid[x][y]='O';
                check();
                p=playerX;
                checkValidity();
            }
            else{
                cout<<"This slot is already occupied"<<endl;
                getRowLocation();
                TurnO();
            }
        }
        void check(){
            for(i=0;i<3;i++){
                temp=grid[i][0];
                for(j=1;j<3;j++){
                    if(grid[i][j]=='.' || grid[i][j]!=temp){
                        temp=grid[i][j];
                        break;
                    }
                    if(j==2){
                        cout<<"1";
                        gameOver();
                    }
                }
            }
            for(i=0;i<3;i++){
                temp=grid[0][i];
                for(j=1;j<3;j++){
                    if(grid[j][i]=='.' || grid[j][i]!=temp){
                        temp=grid[j][i];
                        break;
                    }
                    if(j==2){
                        cout<<"2";
                        gameOver();
                    }
                }
            }
            temp=grid[0][0];
            for(i=1;i<3;i++){
                if(grid[i][i]=='.' || grid[i][i]!=temp){
                    temp=grid[i][i];
                    break;
                }
                if(i==2){
                    cout<<"3";
                    gameOver();
                }
            }
            temp=grid[0][2];
            for(i=1;i<3;i++){
                if(grid[i][2-i]=='.' || grid[i][2-i]!=temp){
                    temp=grid[i][2-i];
                    break;
                }
                if(i==2){
                    cout<<"4";
                    gameOver();
                }
            }
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(grid[i][j]=='.'){
                        return;
                    }
                }
            }
            cout<<"Tie."<<endl;
            temp='.';
            gameOver();
        }
        void gameOver(){
            display();
            if(temp=='X'){
                cout<<"The winner is "<<playerX<<endl;
            }
            else if(temp=='O'){
                cout<<"The winner is "<<playerO<<endl;
            }
            cout<<"Would you like to play again? (Y/N)"<<endl;
            cin>>temp;
            if(temp=='Y'||temp=='y'){
                gridReset();
                checkValidity();
            }
            else if(temp=='N'||temp=='n'){
               cout<<"Bye!";
                exit(0);
            }
            else{
                cout<<"Ivalid Choice"<<endl;
                gameOver();
            }
        }
};
int main(){
    string p1,p2,p;
    cout<<"Enter the name for X player: "<<endl;
    cin>>p1;
    cout<<"Enter the name for O player: "<<endl;
    cin>>p2;
    cout<<"Who playes first, "<<p1<<" or "<<p2<<endl;
    cin>>p;
    players P(p1,p2,p);
    P.checkValidity();
    return 0;
}