//
// Created by ubuntuudvikling on 10/10/16.
//

#ifndef EXAM_MOVES_H
#define EXAM_MOVES_H

#include <iostream>
#include "Element.h"
#include "IMove.h"
#include "Pokemon.h"

namespace pokemonGame {


    class AttackMove : public IMove{
    public:
        AttackMove(Element& e,std::string name, size_t power) :  IMove(e), power_(power), name_(name) {}
        ~AttackMove(){};

        void doMove(IPokemon& pokemon) {
            //TODO: Attack should do damage acording to type and power


            if(this->element_.isSuperEffective(pokemon.getElement()))
            {
                //TODO: Reduce opposing pokemon health much
                std::cout << "Move is super effective" << std::endl;
                pokemon.setHealth((pokemon.getHealth() - power_));
            }
            else if(this->element_.isNotEffective(pokemon.getElement()))
            {
                //TODO: Reduce opposing pokemon health not much
                std::cout << "Move is not effective" << std::endl;
            }
            else
            {
                //TODO: Reduce opposing pokemon health normally
                std::cout << "Move is normally effective" << std::endl;
            }

        }

    private:
       // Element& element_;
        size_t power_;
        std::string name_;

    };

//    class FireMoveSet
//    {
//    public:
//        IMove& getNewMove(int index)
//        {
//            return fireMoves[index];
//        }
//
//    private:
//        std::vector<IMove> fireMoves;
//    };



//    template<>
//    struct MoveChooser<Fire>{
//
//        std::vector<IMove> getMoves()
//        {
//            std::vector moves;
//
//            int move1 = rand() % 10;
//
//        }
//
//    };
};


#endif //EXAM_MOVES_H
