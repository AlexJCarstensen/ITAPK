//
// Created by stud on 10/18/16.
//

#ifndef EXAM_MOVECHOOSERS_H
#define EXAM_MOVECHOOSERS_H

#include <iostream>
#include <algorithm>
#include <random>
#include "IMove.h"
#include "IMoveSet.h"
#include "MoveSets/GroundMoveSet.h"
#include "../Elements/Elements.h"
#include "MoveSets/FireMoveSet.h"
#include "MoveSets/LightningMoveSet.h"
#include "MoveSets/GrassMoveSet.h"
#include "MoveSets/WaterMoveSet.h"

namespace pokemonGame
{
    static bool containsMove(std::vector<int> moves, int move) {

        return std::find(moves.begin(), moves.end(), move) != moves.end();

    }

    static int generateRandomNumber(int min, int max){
        std::random_device rd;
        std::mt19937 eng(rd());
        std::uniform_int_distribution<> distr(min, max);
        return distr(eng);
    }

    static std::vector<int> generateMoveNumbers(int maxNumberInMoveset)
    {
        //Creating random of how many moves are to be assigned
        int maxNumberOfMoves = 4;

        int numberOfMoves = generateRandomNumber(1, maxNumberOfMoves);

        //Creating random numbers between 0 and numberOfMoves in moveSet
        std::vector<int> moveNumbers;
        for (int i = 0; i < numberOfMoves; ++i) {

            int move = generateRandomNumber(0, maxNumberInMoveset);


            //if moveNumbers is empty, put in generated number
            if (moveNumbers.empty()) {
                moveNumbers.push_back(move);
            } else {
                //Checking if number already is generated
                if (containsMove(moveNumbers, move))
                {
                    --i;
                }
                else{
                    moveNumbers.push_back(move);
                }
            }
        }

        return moveNumbers;
    }

    //Basic Template
    template<int N>
    struct MoveChooser {
    };

    //Fire chooser
    template<>
    struct MoveChooser<(int) Elements::FIRE> {

        std::vector<std::shared_ptr<IMove>> getMoves() {
            std::vector<std::shared_ptr<IMove>> moves;
            std::shared_ptr<IMoveSet> firemoves = std::make_shared<FireMoveSet>();
            //Generating numbers to retrieve from firemoveSet
            std::vector<int> moveNumbers = generateMoveNumbers(firemoves.get()->NumberOfMoves() - 1);

            //Generating new moves based on numbers generated
            for (auto &&number  : moveNumbers)
            {
                moves.push_back(firemoves.get()->getNewMove(number));
            }

            return moves;
        }



    };

    //Lightning chooser
    template<>
    struct MoveChooser<(int) Elements::LIGHTNING> {

        std::vector<std::shared_ptr<IMove>> getMoves() {
            std::vector<std::shared_ptr<IMove>> moves;
            std::shared_ptr<IMoveSet> lightningmoves = std::make_shared<LightningMoveSet>();
            //Generating numbers to retrieve from lightningmoveSet
            std::vector<int> moveNumbers = generateMoveNumbers(lightningmoves->NumberOfMoves() - 1);

            //Generating new moves based on numbers generated
            for (auto &&number  : moveNumbers)
            {
                moves.push_back(lightningmoves->getNewMove(number));
            }

            return moves;
        }

    };

    //Grass chooser
    template<>
    struct MoveChooser<(int) Elements::GRASS> {

        std::vector<std::shared_ptr<IMove>> getMoves() {
            std::vector<std::shared_ptr<IMove>> moves;
            std::shared_ptr<IMoveSet> grassmoves = std::make_shared<GrassMoveSet>();
            //Generating numbers to retrieve from grassmoveSet
            std::vector<int> moveNumbers = generateMoveNumbers(grassmoves->NumberOfMoves() - 1);

            //Generating new moves based on numbers generated
            for (auto &&number  : moveNumbers)
            {
                moves.push_back(grassmoves->getNewMove(number));
            }

            return moves;
        }



    };

    //Water chooser
    template<>
    struct MoveChooser<(int) Elements::WATER> {

        std::vector<std::shared_ptr<IMove>> getMoves() {
            std::vector<std::shared_ptr<IMove>> moves;
            std::shared_ptr<IMoveSet> watermoves = std::make_shared<WaterMoveSet>();
            //Generating numbers to retrieve from watermoveSet
            std::vector<int> moveNumbers = generateMoveNumbers(watermoves->NumberOfMoves() - 1);

            //Generating new moves based on numbers generated
            for (auto &&number  : moveNumbers) {
                moves.push_back(watermoves->getNewMove(number));
            }

            return moves;
        }
    };

    //Ground chooser
    template<>
    struct MoveChooser<(int) Elements::GROUND> {

        std::vector<std::shared_ptr<IMove>> getMoves() {
            std::vector<std::shared_ptr<IMove>> moves;
            std::shared_ptr<IMoveSet> groundmoves = std::make_shared<GroundMoveSet>();
            //Generating numbers to retrieve from groundmoveSet
            std::vector<int> moveNumbers = generateMoveNumbers(groundmoves->NumberOfMoves() - 1);

            //Generating new moves based on numbers generated
            for (auto &&number  : moveNumbers) {
                moves.push_back(groundmoves->getNewMove(number));
            }

            return moves;
        }
    };

    }

#endif //EXAM_MOVECHOOSERS_H
