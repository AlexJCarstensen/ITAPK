//
// Created by stud on 10/18/16.
//

#ifndef EXAM_MOVESETS_H
#define EXAM_MOVESETS_H

#include <iostream>
#include <memory>
#include "Move.h"
#include "Element.h"
#include "Pokemon.h"



namespace pokemonGame {

    using namespace std;

    //For debugging moves
    class FireMoveSet {
    public:

        FireMoveSet() {
            //Creating moves to put in container
            Fire fire;
            shared_ptr <IMove> fireBlast = make_shared<AttackMove>(fire, "Fire Blast", 80);
            shared_ptr <IMove> ember = make_shared<AttackMove>(fire, "Ember", 15);
            shared_ptr <IMove> flamethrower = make_shared<AttackMove>(fire, "Flamethrower", 50);
            shared_ptr <IMove> fireFang = make_shared<AttackMove>(fire, "Fire fang", 25);
            shared_ptr <IMove> fireSpin = make_shared<AttackMove>(fire, "Firespin", 30);
            shared_ptr <IMove> firePunch = make_shared<AttackMove>(fire, "Fire Punch", 45);

            //Creating basic move
            //basicMove = ember;

            //Inserting moves to container
            fireMoves = {fireBlast, ember, flamethrower, fireFang, fireSpin, firePunch};
        }

        int NumberOfMoves() {
            return fireMoves.size();
        }


        std::shared_ptr<IMove> getNewMove(int index) {
            if (index >= 0 && index < fireMoves.size()) { return fireMoves[index]; }
            else return basicMove;

        }

    private:
        std::vector<std::shared_ptr<IMove>> fireMoves;
        std::shared_ptr<IMove> basicMove;
    };



    class LightningMoveSet {
    public:

        LightningMoveSet() {
            //Creating moves to put in container
            Lightning lightning;
            shared_ptr <IMove> thunderbolt = make_shared<AttackMove>(lightning, "Thunderbolt", 80);
            shared_ptr <IMove> thunder = make_shared<AttackMove>(lightning, "Thunder", 15);
            shared_ptr <IMove> thundershock = make_shared<AttackMove>(lightning, "Thundershock", 50);
            shared_ptr <IMove> thunderpunch = make_shared<AttackMove>(lightning, "Thunder punch", 25);
            shared_ptr <IMove> charge = make_shared<AttackMove>(lightning, "Charge", 30);
            shared_ptr <IMove> voltTackle = make_shared<AttackMove>(lightning, "Volt tackle", 45);

            //Creating basic move
            //basicMove = ember;

            //Inserting moves to container
            lighningMoves = {thunderbolt, thunder, thundershock, thunderpunch, charge, voltTackle};
        }

        int NumberOfMoves() {
            return lighningMoves.size();
        }


        std::shared_ptr<IMove> getNewMove(int index) {
            if (index >= 0 && index < lighningMoves.size()) { return lighningMoves[index]; }
            else return basicMove;

        }

    private:
        std::vector<std::shared_ptr<IMove>> lighningMoves;
        std::shared_ptr<IMove> basicMove;
    };
}



#endif //EXAM_MOVESETS_H
