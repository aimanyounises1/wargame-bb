#pragma once
#include "Soldier.hpp"
#include <iostream>


class ParamedicCommander: public Soldier {
public:
    ParamedicCommander(int t) : Soldier(200,100,t,3,true){}
   
    virtual void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) override{
      int check  = board[source.first][source.second]->team;
    for(int i = source.first-1;i<=source.first+1;i++){
        for(int j = source.second-1;j<=source.second+1;j++){
            if(i>=0 && i<board.size() && j>=0 && j<board[i].size()) {
                if (board[i][j]!=nullptr && i != source.first && j != source.second && board[i][j]->team == check)
                    board[i][j]->HP = this->resetlife();
            }
        }
    }
    for(int i = 0; i<board.size(); i++){
        for(int j =0; j<board[i].size() ; j++){
            if(board[i][j]!=nullptr && board[i][j]->team==check && dynamic_cast<Paramedic*>(board[i][j]))
                board[i][j]->attack(board,{i,j});
        }
    }
    }
    int resetlife() override{
        this->HP = 200;
        return this->HP;
    }
    
};