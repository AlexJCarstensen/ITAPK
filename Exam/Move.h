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
                //Reduce opposing pokemon health significantly
                std::cout << "Move is super effective" << std::endl;
                pokemon.setHealth((pokemon.getHealth() - (power_ * 1.5)));
            }
            else if(this->element_.isNotEffective(pokemon.getElement()))
            {
                //Reduce opposing pokemon health slightly
                std::cout << "Move is not effective" << std::endl;
                pokemon.setHealth((pokemon.getHealth() - (power_ * 0.5)));
            }
            else
            {
                //Reduce opposing pokemon health normally
                std::cout << "Move is normally effective" << std::endl;
                pokemon.setHealth((pokemon.getHealth() - power_ ));
            }

        }

    private:
       // Element& element_;
        size_t power_;
        std::string name_;

    };


    //For debugging moves
    class FireMoveSet
    {
    public:

        FireMoveSet()
        {
            //Creating moves to put in container
            Fire fire;
            IMove *fireBlast = new AttackMove(fire, "Fire Blast", 80);
            IMove *ember = new AttackMove(fire, "Ember", 15);
            IMove *flamathrower = new AttackMove(fire, "Flamethrower", 50);
            IMove *fireFang = new AttackMove(fire, "Fire fang", 25);
            IMove *fireSpin = new AttackMove(fire, "Firespin", 30);
            IMove *firePunch = new AttackMove(fire, "Fire Punch", 45);

            //Creating basic move
            basicMove = ember;

            //Inserting moves to container
            fireMoves = {fireBlast, ember, flamathrower, fireFang, fireSpin,firePunch};
        }
        ~FireMoveSet()
        {

            for (auto &&move : fireMoves) {
                delete move;
            }
        }

        IMove* getNewMove(int index)
        {
            if(index >= 0 && index < fireMoves.size())
            {return  fireMoves[index];}
            else return basicMove;

        }

    private:
        std::vector<IMove*> fireMoves;
        IMove *basicMove;
    };


    //Basic Template
    template<int N>
    struct MoveChooser
    {
    };

    //Fire chooser
    template<>
    struct MoveChooser<1>{

        std::vector<IMove*> getMoves()
        {
            std::vector<IMove*> moves;
            FireMoveSet firemoves;

            //Creating random numbers between 0 and 5
            int move1 = rand() % 6;
            int move2 = rand() % 6;
            int move3 = rand() % 6;
            int move4 = rand() % 6;

            //Generating new moves
            moves.push_back(firemoves.getNewMove(move1));
            moves.push_back(firemoves.getNewMove(move2));
            moves.push_back(firemoves.getNewMove(move3));
            moves.push_back(firemoves.getNewMove(move4));

            return moves;

        }

    };
};


#endif //EXAM_MOVES_H
