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
#include "IMoveSet.h"


namespace pokemonGame {

    using namespace std;




    class FireMoveSet : public IMoveSet {
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
            moves_ = {fireBlast, ember, flamethrower, fireFang, fireSpin, firePunch};
        }




        std::shared_ptr<IMove> getNewMove(int index) {
            if (index >= 0 && index < moves_.size()) { return moves_[index]; }
            else return basicMove_;

        }


    };

    class LightningMoveSet : public IMoveSet{
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
            moves_ = {thunderbolt, thunder, thundershock, thunderpunch, charge, voltTackle};
        }


        std::shared_ptr<IMove> getNewMove(int index) {
            if (index >= 0 && index < moves_.size()) { return moves_[index]; }
            else return basicMove_;

        }


    };

    class GrassMoveSet : public IMoveSet{
    public:

        GrassMoveSet() {
            //Creating moves to put in container
            Grass grass;
            shared_ptr <IMove> razorLeafs = make_shared<AttackMove>(grass, "Razor Leafs", 25);
            shared_ptr <IMove> megaDrain = make_shared<AttackMove>(grass, "Thunder", 30);
            shared_ptr <IMove> absorb = make_shared<AttackMove>(grass, "Absorb", 15);
            shared_ptr <IMove> solarBeam = make_shared<AttackMove>(grass, "Solar Beam", 80);
            shared_ptr <IMove> vineWhip = make_shared<AttackMove>(grass, "Vine Whip", 45);
            shared_ptr <IMove> leafBlade = make_shared<AttackMove>(grass, "Leaf Blade", 50);

            //Creating basic move
            //basicMove = ember;

            //Inserting moves to container
            moves_ = {razorLeafs, megaDrain, absorb, solarBeam, vineWhip, leafBlade};
        }




        std::shared_ptr<IMove> getNewMove(int index) {
            if (index >= 0 && index < moves_.size()) { return moves_[index]; }
            else return basicMove_;

        }


    };

    class WaterMoveSet : public IMoveSet{
    public:

        WaterMoveSet() {
            //Creating moves to put in container
            Water water;
            shared_ptr <IMove> watergun = make_shared<AttackMove>(water, "Water gun", 15);
            shared_ptr <IMove> hydroPump = make_shared<AttackMove>(water, "Hydro pump", 80);
            shared_ptr <IMove> bubbleBeam = make_shared<AttackMove>(water, "Bubble beam", 40);
            shared_ptr <IMove> bubble = make_shared<AttackMove>(water, "Bubble", 25);
            shared_ptr <IMove> aquaTail = make_shared<AttackMove>(water, "Aqua tail", 30);
            shared_ptr <IMove> surf = make_shared<AttackMove>(water, "Surf", 50);

            //Creating basic move
            //basicMove = ember;

            //Inserting moves to container
            moves_ = {watergun, hydroPump, bubbleBeam, bubble, aquaTail, surf};
        }




        std::shared_ptr<IMove> getNewMove(int index) {
            if (index >= 0 && index < moves_.size()) { return moves_[index]; }
            else return basicMove_;

        }


    };

    class GroundMoveSet : public IMoveSet{
    public:

        GroundMoveSet() {
            //Creating moves to put in container
            Ground ground;
            shared_ptr <IMove> earthquake = make_shared<AttackMove>(ground, "Earthquake", 100);
            shared_ptr <IMove> dig = make_shared<AttackMove>(ground, "Dig", 50);
            shared_ptr <IMove> mudShot = make_shared<AttackMove>(ground, "Mud shot", 35);
            shared_ptr <IMove> bullDoze = make_shared<AttackMove>(ground, "Bulldoze", 25);
            shared_ptr <IMove> mudSlap = make_shared<AttackMove>(ground, "Mud slap", 15);
            shared_ptr <IMove> fissure = make_shared<AttackMove>(ground, "Fissure", 40);

            //Creating basic move
            //basicMove = ember;

            //Inserting moves to container
            moves_ = {earthquake, dig, mudShot, bullDoze, mudSlap, fissure};
        }




        std::shared_ptr<IMove> getNewMove(int index) {
            if (index >= 0 && index < moves_.size()) { return moves_[index]; }
            else return basicMove_;

        }


    };
}



#endif //EXAM_MOVESETS_H
