/*
 * Node.h
 *
 *  Created on: 07 Sep 2022
 *      Author: Francois Smith
 */

#pragma once
#include <string>
#include <iostream>
#include <vector>

class Directory;
class File;
class Observer;

/**
 * @brief Node class is the base class for all nodes in the file system. \n
 * Implements the composite and iterator design patterns.
 */
class Node
{
public:
    explicit Node(std::string aName) : name(std::move(aName)) {};
    virtual ~Node();
    virtual void printName() = 0;
    virtual Node* clone() = 0;
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify();

    //Getters and Setters
    std::string getName() const;
    void rename(std::string aName);

protected:
    std::string name;
    std::vector<Observer*> observerList;
};