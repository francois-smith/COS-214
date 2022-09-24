/*
 * Antivirus.h
 *
 *  Created on: 9/10/22.
 *      Author: Francois Smith
 */

#pragma once
#include "File.h"

class Antivirus
{
public:
    void notify(File* file);
};
