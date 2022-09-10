/*
 * Node.cpp
 *
 *  Created on: 07 Sep 2022
 *      Author: Francois Smith
 */

#include "Node.h"

std::string Node::getName() const
{
	return this->name;
}

void Node::rename(std::string newName)
{
	this->name = std::move(newName);
}





