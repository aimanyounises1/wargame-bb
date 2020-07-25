#pragma once
//
//Created by Aiman Younis
#include "Soldier.hpp"
#include <iostream>
#include <limits>
#include<cmath>
#include<iomanip>

class SniperCommander: public Soldier {
public:
    SniperCommander(int t) : Soldier(120,100,t,2,true){}
   // attack the closet every time loop with recursin
    virtual void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) override{
        std::pair<int,int> toAttack = this->minDistance(source,board);
          if(toAttack.first == std::numeric_limits<int>::max()) return;
          int life = board[toAttack.first][toAttack.second]->HP;
          int damage = board[source.first][source.second]->DAMAGE;
          int team = board[source.first][source.second]->team;
           board[toAttack.first][toAttack.second]->HP=life-damage;
           if(board[toAttack.first][toAttack.second]->HP<=0) {
        //  delete board[toAttack.first][toAttack.second];
          board[toAttack.first][toAttack.second]= nullptr;
    }
    for(int i = 0; i<board.size(); i++){
        for(int j =0; j<board[i].size() ; j++){
            // dynamic cast to know if its a sniper soldier checks in run time 
            if(board[i][j] !=nullptr && board[i][j]->team == team && dynamic_cast<Sniper*>(board[i][j]))
                board[i][j]->attack(board,{i,j});
        }
    }  
    }
    int resetlife() override{
        this->HP = 120;
        return this->HP;
    }
};