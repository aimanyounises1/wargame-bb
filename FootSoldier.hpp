#pragma once
#include "Soldier.hpp"
#include <iostream>
class FootSoldier: public Soldier {
public:
    FootSoldier(int t) : Soldier(100,10,t,1,false){}
    virtual void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) override {
         std::pair<int, int> toAttack = this->minDistance(source, board);
        if (toAttack.first == std::numeric_limits<int>::max())
            return;
        int life = board[toAttack.first][toAttack.second]->HP;
        int damage = board[source.first][source.second]->DAMAGE;
        int team = board[source.first][source.second]->team;
        board[toAttack.first][toAttack.second]->HP = life - damage;
        if (board[toAttack.first][toAttack.second]->HP <= 0)
        {
           // delete board[toAttack.first][toAttack.second];
            board[toAttack.first][toAttack.second] = nullptr;
        }
    }
    int resetlife() override{
        this->HP = 100;
        return this->HP;
    }
    
            
    
};