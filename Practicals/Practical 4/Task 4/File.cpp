/*
 * Directory.cpp
 *
 *  Created on: 07 Sep 2022
 *      Author: Francois Smith
 */

#include "File.h"

void File::printName()
{
	std::cout << this->getName() << ".file" << std::endl;
}

std::string File::getContent() const
{
	return this->content;
}

void File::setContent(std::string newContent)
{
	this->content = std::move(newContent);
}

Node* File::clone()
{
    return new File(this->getName(), this->getContent());
}