#include<iostream>
using namespace std;
class players{
    string playerX,playerO;
    char grid[3][3]={'.','.','.','.','.','.','.','.','.'};
    public: 
        players(string p1,string p2){
            playerX=p1;
            playerO=p2;
        }
        void checkValidity(){
            string p;
            cout<<"Who playes first, "<<playerX<<" or "<<playerO<<endl;
            cin>>p;
            if(p==playerX){
                TurnX();
            }
            else if(p==playerO){
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
        void TurnX(){
            display();
            cout<<"Player of current turn: "<<playerX<<endl;;
        }
        void TurnO(){
            display();
            cout<<"Player of current turn: "<<playerO<<endl;
        }
};

int main(){
    string p1,p2;
    cout<<"Enter the name for X player: "<<endl;
    cin>>p1;
    cout<<"Enter the name for O player: "<<endl;
    cin>>p2;
    players P(p1,p2);
    P.checkValidity();
    return 0;
}