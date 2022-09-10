/*
 * Observer.h
 *
 *  Created on: 9/10/22.
 *      Author: Francois Smith
 */

#pragma once

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};
