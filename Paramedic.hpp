
#pragma once
#include "Soldier.hpp"
#include <iostream>
class Paramedic: public Soldier {
public:
    Paramedic(int t) : Soldier(100,50,t,3,false){}
    ~Paramedic(){}
    
    virtual void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) override {
        int check = board[source.first][source.second]->team;
    for(int i = source.first-1;i<=source.first+1;i++){
        for(int j = source.second-1;j<=source.second+1;j++){
            if(i>=0 && i<board.size() && j>=0 && j<board[i].size()) {
                if (board[i][j]!=nullptr && i != source.first && j != source.second && board[i][j]->team == check)
                    board[i][j]->HP = this->resetlife();
            }
        }
    }
    }
    int resetlife() override{
         this->HP = 100;
         return this->HP;
    }
    
};