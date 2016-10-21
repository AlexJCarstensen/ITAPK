//
// Created by stud on 10/18/16.
//

#ifndef EXAM_MOVESETS_H
#define EXAM_MOVESETS_H

#include <iostream>
#include <memory>
#include "Move.h"
#include "Elements/Element.h"
#include "Pokemon.h"
#include "IMoveSet.h"
#include "Elements/Fire.h"
#include "Elements/Water.h"
#include "Elements/Lightning.h"
#include "Elements/Ground.h"
#include "Elements/Grass.h"


namespace pokemonGame {

    class FireMoveSet : public IMoveSet {
    public:

        FireMoveSet() {
            //Creating moves to put in container
            std::shared_ptr<Element> fire = std::make_shared<Fire>();
            std::shared_ptr<IMove> fireBlast = std::make_shared<AttackMove>(fire, "Fire Blast", 80);
            std::shared_ptr<IMove> ember = std::make_shared<AttackMove>(fire, "Ember", 15);
            std::shared_ptr<IMove> flamethrower = std::make_shared<AttackMove>(fire, "Flamethrower", 50);
            std::shared_ptr<IMove> fireFang = std::make_shared<AttackMove>(fire, "Fire fang", 25);
            std::shared_ptr<IMove> fireSpin = std::make_shared<AttackMove>(fire, "Firespin", 30);
            std::shared_ptr<IMove> firePunch = std::make_shared<AttackMove>(fire, "Fire Punch", 45);

            //Inserting moves to container
            moves_ = {fireBlast, ember, flamethrower, fireFang, fireSpin, firePunch};
        }

        std::shared_ptr<IMove> getNewMove(int index) {
            if (index >= 0 && index < moves_.size()) { return moves_[index]; }
            else return basicMove_;
        }
    };

    class LightningMoveSet : public IMoveSet {
    public:

        LightningMoveSet() {
            //Creating moves to put in container
            std::shared_ptr<Element> lightning = std::make_shared<Lightning>();
            std::shared_ptr<IMove> thunderbolt = std::make_shared<AttackMove>(lightning, "Thunderbolt", 80);
            std::shared_ptr<IMove> thunder = std::make_shared<AttackMove>(lightning, "Thunder", 15);
            std::shared_ptr<IMove> thundershock = std::make_shared<AttackMove>(lightning, "Thundershock", 50);
            std::shared_ptr<IMove> thunderpunch = std::make_shared<AttackMove>(lightning, "Thunder punch", 25);
            std::shared_ptr<IMove> charge = std::make_shared<AttackMove>(lightning, "Charge", 30);
            std::shared_ptr<IMove> voltTackle = std::make_shared<AttackMove>(lightning, "Volt tackle", 45);

            //Inserting moves to container
            moves_ = {thunderbolt, thunder, thundershock, thunderpunch, charge, voltTackle};
        }

        std::shared_ptr<IMove> getNewMove(int index) {
            if (index >= 0 && index < moves_.size()) { return moves_[index]; }
            else return basicMove_;

        }
    };

    class GrassMoveSet : public IMoveSet {
    public:

        GrassMoveSet() {
            //Creating moves to put in container
            std::shared_ptr<Element> grass = std::make_shared<Grass>();
            std::shared_ptr<IMove> razorLeafs = std::make_shared<AttackMove>(grass, "Razor Leafs", 25);
            std::shared_ptr<IMove> megaDrain = std::make_shared<AttackMove>(grass, "Thunder", 30);
            std::shared_ptr<IMove> absorb = std::make_shared<AttackMove>(grass, "Absorb", 15);
            std::shared_ptr<IMove> solarBeam = std::make_shared<AttackMove>(grass, "Solar Beam", 80);
            std::shared_ptr<IMove> vineWhip = std::make_shared<AttackMove>(grass, "Vine Whip", 45);
            std::shared_ptr<IMove> leafBlade = std::make_shared<AttackMove>(grass, "Leaf Blade", 50);

            //Inserting moves to container
            moves_ = {razorLeafs, megaDrain, absorb, solarBeam, vineWhip, leafBlade};
        }

        std::shared_ptr<IMove> getNewMove(int index) {
            if (index >= 0 && index < moves_.size()) { return moves_[index]; }
            else return basicMove_;
        }
    };

    class WaterMoveSet : public IMoveSet {
    public:

        WaterMoveSet() {
            //Creating moves to put in container
            std::shared_ptr<Element> water = std::make_shared<Water>();
            std::shared_ptr<IMove> watergun = std::make_shared<AttackMove>(water, "Water gun", 15);
            std::shared_ptr<IMove> hydroPump = std::make_shared<AttackMove>(water, "Hydro pump", 80);
            std::shared_ptr<IMove> bubbleBeam = std::make_shared<AttackMove>(water, "Bubble beam", 40);
            std::shared_ptr<IMove> bubble = std::make_shared<AttackMove>(water, "Bubble", 25);
            std::shared_ptr<IMove> aquaTail = std::make_shared<AttackMove>(water, "Aqua tail", 30);
            std::shared_ptr<IMove> surf = std::make_shared<AttackMove>(water, "Surf", 50);

            //Inserting moves to container
            moves_ = {watergun, hydroPump, bubbleBeam, bubble, aquaTail, surf};
        }

        std::shared_ptr<IMove> getNewMove(int index) {
            if (index >= 0 && index < moves_.size()) { return moves_[index]; }
            else return basicMove_;
        }
    };

    class GroundMoveSet : public IMoveSet {
    public:
        GroundMoveSet() {
            //Creating moves to put in container
            std::shared_ptr<Element> ground = std::make_shared<Ground>();
            std::shared_ptr<IMove> earthquake = std::make_shared<AttackMove>(ground, "Earthquake", 100);
            std::shared_ptr<IMove> dig = std::make_shared<AttackMove>(ground, "Dig", 50);
            std::shared_ptr<IMove> mudShot = std::make_shared<AttackMove>(ground, "Mud shot", 35);
            std::shared_ptr<IMove> bullDoze = std::make_shared<AttackMove>(ground, "Bulldoze", 25);
            std::shared_ptr<IMove> mudSlap = std::make_shared<AttackMove>(ground, "Mud slap", 15);
            std::shared_ptr<IMove> fissure = std::make_shared<AttackMove>(ground, "Fissure", 40);

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
