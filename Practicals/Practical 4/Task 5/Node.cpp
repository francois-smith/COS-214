/*
 * Node.cpp
 *
 *  Created on: 07 Sep 2022
 *      Author: Francois Smith
 */

#include "Observer.h"
#include "Node.h"

Node::~Node()
{
    for (Observer* observer : observerList)
    {
        delete observer;
    }
}

std::string Node::getName() const
{
	return this->name;
}

void Node::rename(std::string newName)
{
	this->name = std::move(newName);
}

void Node::attach(Observer* observer)
{
    observerList.push_back(observer);
}

void Node::detach(Observer* observer)
{
    int index = 0;
    for(Observer* obs : observerList)
    {
        if(obs == observer)
        {
            delete obs;
            observerList.erase(observerList.begin() + index);
        }
        index++;
    }
}

void Node::notify()
{
    for(Observer* obs : observerList)
    {
        obs->update();
    }
}