/*
 * FileObserver.h
 *
 *  Created on: 9/10/22.
 *      Author: Francois Smith
 */

#pragma once
#include "Observer.h"
#include "File.h"

class FileObserver : public Observer
{
public:
    explicit FileObserver(File* file);
    void update() override;

private:
    File* subject;
};
