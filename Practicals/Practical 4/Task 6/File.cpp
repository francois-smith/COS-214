/*
 * Directory.cpp
 *
 *  Created on: 07 Sep 2022
 *      Author: Francois Smith
 */

#include "Observer.h"
#include "FileObserver.h"
#include "File.h"

void File::printName()
{
	std::cout << this->getName() << std::endl;
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
    File* file = new File(this->getName(), this->getContent());
    for(Observer* observer : this->observerList)
    {
        new FileObserver(file);
    }
    return file;
}