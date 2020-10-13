#include<iostream>
using namespace std;
class players{
    string playerX,playerO,p;
    char grid[3][3]={'.','.','.','.','.','.','.','.','.'};
    int x,y;
    public: 
        players(string p1,string p2,string px){
            playerX=p1;
            playerO=p2;
            p=px;
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
                checkValidity();
            }
            return;
        }
        void display(){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
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
                cout<<x<<" is not a valid row."<<endl;
                getColumnLocation();
            }
        }
        void TurnX(){
            if(grid[x][y]=='.'){
                grid[x][y]='X';
                display();
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
                display();
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