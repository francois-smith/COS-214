/*
 * DirectoryObserver.cpp
 *
 *  Created on: 9/10/22.
 *      Author: Francois Smith
 */

#include "DirectoryObserver.h"

DirectoryObserver::DirectoryObserver(Directory *directory)
{
    subject = directory;
    directory->attach(this);
}

void DirectoryObserver::update()
{
    std::cout << "\t" << "DirectoryObserver: " << subject->getName() << " detected a change" << std::endl;
}
