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
#include "MoveSets.h"

namespace pokemonGame
{

    using namespace std;

    static bool containsMove(vector<int> moves, int move) {

        if(std::find(moves.begin(), moves.end(), move) != moves.end()) {
            /* v contains x */
            return true;
        } else {
            /* v does not contain x */
            return false;
        }

    }

    static vector<int> generateMoveNumbers(int maxNumberInMoveset)
    {
        //Creating random of how many moves are to be assigned
        int maxNumberOfMoves = 4;
        std::random_device rd;
        std::mt19937 eng(rd());
        uniform_int_distribution<> distr(1, maxNumberOfMoves);
        int numberOfMoves = distr(eng);

        //Creating random numbers between 0 and numberOfMoves in moveSet
        std::vector<int> moveNumbers;
        for (int i = 0; i < numberOfMoves; ++i) {
            std::random_device rd;
            std::mt19937 eng(rd());
            uniform_int_distribution<> distr(0, maxNumberInMoveset);
            int move = distr(eng);
            if(move >6 )
                std::cout << "hej!" << std::endl;

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
            IMoveSet* firemoves;
            firemoves = new FireMoveSet();

            //Generating numbers to retrieve from firemoveSet
            vector<int> moveNumbers = generateMoveNumbers(firemoves->NumberOfMoves()-1);

            //Generating new moves based on numbers generated
            for (auto &&number  : moveNumbers)
            {
                moves.push_back(firemoves->getNewMove(number));
            }

            return moves;
        }



    };

    //Lightning chooser
    template<>
    struct MoveChooser<(int) Elements::LIGHTNING> {

        std::vector<std::shared_ptr<IMove>> getMoves() {
            std::vector<std::shared_ptr<IMove>> moves;
            IMoveSet* lightningmoves = new LightningMoveSet();

            //Generating numbers to retrieve from firemoveSet
            vector<int> moveNumbers = generateMoveNumbers(lightningmoves->NumberOfMoves()-1);

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
            IMoveSet* grassmoves = new GrassMoveSet();

            //Generating numbers to retrieve from firemoveSet
            vector<int> moveNumbers = generateMoveNumbers(grassmoves->NumberOfMoves()-1);

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
            IMoveSet *watermoves = new WaterMoveSet();

            //Generating numbers to retrieve from firemoveSet
            vector<int> moveNumbers = generateMoveNumbers(watermoves->NumberOfMoves() - 1);

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
            IMoveSet *groundmoves = new GroundMoveSet();

            //Generating numbers to retrieve from firemoveSet
            vector<int> moveNumbers = generateMoveNumbers(groundmoves->NumberOfMoves() - 1);

            //Generating new moves based on numbers generated
            for (auto &&number  : moveNumbers) {
                moves.push_back(groundmoves->getNewMove(number));
            }

            return moves;
        }
    };

    }

#endif //EXAM_MOVECHOOSERS_H
