//
// Created by Francois Smith on 2022/08/24.
//

#pragma once
#include <string>
#include <iostream>

/**
 * @brief The Abstract BattleState class \n
 * This class is used to implement the State Design Pattern.
 */
class BattleState
{
public:
    /**
     * @brief State function for the BattleState class.
     * @param name - The name of the Pokemon.
     * @param damage - The damage of the Pokemon.
     * @return - The modified damage of the Pokemon.
     */
    virtual int handle(std::string name, int damage) = 0;
    virtual ~BattleState() = default;
    std::string getBattleStyle() const;

protected:
    std::string battleStyle;
};
