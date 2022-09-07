/*
 * Node.h
 *
 *  Created on: 02 Sep 2022
 *      Author: Francois Smith
 */

#pragma once
#include <exception>
#include <string>
#include <iostream>

/**
 * @brief Node class is the base class for all nodes in the file system. \n
 * Implements the composite and iterator design patterns.
 */
class Node
{
public:
    explicit Node(std::string aName) : name(std::move(aName)) {};
    virtual ~Node() = default;
    std::string getName() const;
    void setName(std::string aName);

private:
    std::string name;
};