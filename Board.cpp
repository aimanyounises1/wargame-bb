#include "Board.hpp"
#include <iostream>
#include "Soldier.hpp"
#include <stdexcept>
#include <string>         // std::string


namespace WarGame {
    // reference to pointer
    Soldier*& Board::operator[](std::pair<int,int> location){
       // changePlace(location);
        return this->board[location.first][location.second];
    }
    
       Soldier* Board:: operator[](std::pair<int,int>location) const{
        return this->board[location.first][location.second];

        }       
    
    void Board::attack(std::pair<int,int> source, Soldier* soldier){
        // calls the suitable function by soldier type i.e footcommander or paramedic
        soldier->attack(board,source);
    }
    

    void Board:: move(uint player_number, std::pair<int,int> source, MoveDIR direction){
    if(source.first<0 || source.first>=board.size()|| source.second<0 || source.second>=board[source.first].size()) {
        throw std::invalid_argument("Action is forbidden,out of Board");
    }
    Soldier* toMove = (*this)[source];
    std::pair<int,int> target;
    switch(direction){
        case Up:
            target.first=source.first+1;
            target.second=source.second;
            break;
        case Down:
            target.first=source.first-1;
            target.second=source.second;
            break;
        case Left:
            target.first=source.first;
            target.second=source.second-1;
            break;
        case Right:
            target.first=source.first;
            target.second=source.second+1;
            break;
    }
    if(target.first<0 || target.first>=board.size()|| target.second<0 || target.second>=board[target.first].size()) {
        throw std::invalid_argument("Action is forbidden,out of Board");
    }
    if(toMove == nullptr || toMove->team!=player_number || (*this)[target]!= nullptr){

        throw std::invalid_argument("Action is forbidden a");
    }

    (*this)[target]=toMove;
    (*this)[source]=nullptr;
    toMove->attack(board,target);

       }   
        
    // a function to check if there is a soldier 
    bool Board:: has_soldiers(uint player_number) const{
        for(std::vector<Soldier*> v:board){
            for(Soldier* s:v){
                if ((s != nullptr) && s->team == player_number)
                {
                    return true;
                }
                
            }
        }
        return false;
    }
};