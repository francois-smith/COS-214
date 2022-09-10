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
    virtual void printName() = 0;
    virtual void addNode(Node* newNode) = 0;
    virtual bool removeNode(Node* node) = 0;
    std::string getName() const;
    void setName(std::string aName);
    virtual Node* clone() = 0;

private:
    std::string name;
};