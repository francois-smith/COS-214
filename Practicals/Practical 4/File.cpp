/*
 * Directory.cpp
 *
 *  Created on: 02 Sep 2022
 *      Author: Francois Smith
 */

#include "File.h"

void Directory::printName()
{
	std::cout << this->getName() << ".file" << std::endl;
}

std::string Directory::getContent() const
{
	return this->content;
}

void Directory::setContent(std::string newContent)
{
	this->content = std::move(newContent);
}