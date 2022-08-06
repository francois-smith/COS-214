/*
 * GameMemento.h
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "GameState.h"

/**
 * Game Memento class. Stores state objects, which contains all values for game.
 */
class GameMemento
{
public:
    //Destructor
    ~GameMemento();
    explicit GameMemento(GameState* state);

    //Getter and Setter
    void setState(GameState* state);
    GameState* getState() const;

private:
    //Member Variable
    GameState* state;
};
