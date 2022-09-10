/*
 * DirectoryObserver.h
 *
 *  Created on: 9/10/22.
 *      Author: Francois Smith
 */

#pragma once
#include "Directory.h"
#include "Observer.h"

class DirectoryObserver : public Observer
{
public:
    explicit DirectoryObserver(Directory* directory);
    void update() override;


public:
    Directory* subject;
};
