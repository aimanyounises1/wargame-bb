#pragma once
#include <vector>
#include <utility>
#include <limits>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>

class Soldier{
public:
    int HP;
    int DAMAGE;
    int team;
    int type;
    bool commander;
    Soldier(int h, int d,int t, int ty, bool c){
        this->HP = h;
        this->DAMAGE = d;
        this->team = t;
        this->type = ty;
        this->commander=c;
    }
    virtual ~Soldier(){}
    virtual void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source)= 0;
    virtual int resetlife() = 0;
    void print(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source){
    for(int i=0; i<board.size();i++){
        for(int j=0; j< board[0].size();j++){
            if( i == source.first && j == source.second){
                    std::cout << "||" << "FireZone";
            }
            else if (board[i][j]==0)
            {
                std::cout << "||" << "0000000";
            }
            else
            {
                if(board[i][j]->commander){
                std::cout << "||" << "Commander";

                }else{
                std::cout << "||" << "Soldier";

                }
            }
            
            
        }
        std::cout << "||" << std::endl;
    }
    std::cout << "" << std::endl; 
}
std::pair<int,int> minDistance (std::pair<int,int> source,const std::vector<std::vector<Soldier*>>& board){
        std::pair<int,int> ans;
        int min=std::numeric_limits<int>::max();
        ans.first=min;
        ans.second=min;
        int toAttack;
        double distance;
        if(board[source.first][source.second]->team==1) toAttack=2; //check who i need to attack;
        else toAttack=1;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]!=nullptr && board[i][j]->team==toAttack){
                    distance=sqrt(pow(source.first-i,2)+pow(source.second-j,2));
                    if(distance<min) {
                        min=distance;
                        ans.first=i;
                        ans.second=j;
                    }
                }
            }
        }
     //   print_board(board,source);
        return ans;
    }
    
};
;
