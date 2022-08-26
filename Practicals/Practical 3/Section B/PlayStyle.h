//
// Created by Francois Smith on 2022/08/24.
//

#pragma once
#include <string>

/**
 * @brief The Abstract PlayStyle class \n
 * This class is used to implement the Strategy Design Pattern.
 */
class PlayStyle
{
public:

    /**
     * @brief Strategy function for the PlayStyle class.
     */
    virtual std::string attack() const = 0;
    virtual ~PlayStyle() = default;
};
