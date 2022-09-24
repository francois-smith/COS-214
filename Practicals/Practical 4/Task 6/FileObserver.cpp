/*
 * FileObserver.cpp
 *
 *  Created on: 9/10/22.
 *      Author: Francois Smith
 */

#include "FileObserver.h"

FileObserver::FileObserver(File *file)
{
    subject = file;
    subject->attach(this);
}

void FileObserver::update()
{
    std::cout << "\t" << "FileObserver: file has been modified" << std::endl;
}
