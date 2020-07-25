#pragma once 
#include "Soldier.hpp"
#include <map>
#include <unordered_map>
#include <sstream> //for std::stringstream 
#include <string>  //for std::string
using namespace std;
class FootCommander: public Soldier {
public:
    FootCommander(int t) : Soldier(150,20,t,1,true){}
     ~FootCommander(){}

    virtual void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) override {
       std::pair<int,int> toAttack = this->minDistance(source,board);
          if(toAttack.first == std::numeric_limits<int>::max()) return;
          int life = board[toAttack.first][toAttack.second]->HP;
          int damage = board[source.first][source.second]->DAMAGE;
          int team = board[source.first][source.second]->team;
           board[toAttack.first][toAttack.second]->HP=life-damage;
           if(board[toAttack.first][toAttack.second]->HP<=0) {
          //delete board[toAttack.first][toAttack.second];
          board[toAttack.first][toAttack.second]= nullptr;
    }
    for(int i = 0; i<board.size(); i++){
        for(int j =0; j<board[i].size() ; j++){
            // dynamic cast to know if its a sniper soldier checks in run time 
            if(board[i][j] !=nullptr && board[i][j]->team == team && dynamic_cast<FootSoldier*>(board[i][j]))
                board[i][j]->attack(board,{i,j});
        }
    }  
    }
    int resetlife() override{
        this->HP = 150;
        return this->HP;
    }
    
    
            
    
};