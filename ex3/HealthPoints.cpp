//
// Created by DELL on 23-May-22.
//

#include "HealthPoints.h"
#include <iostream>


HealthPoints::HealthPoints(int maxPoints) :
m_HP(maxPoints)
{
    if (maxPoints<=0)
    {

    }

}

void HealthPoints::InvalidArgument()
{
    //////////////////////////////To check
    std::cout << "Wrong" << std::endl;
}

;
