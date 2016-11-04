/*
 * DropTriggerBuilder.cpp
 *
 *  Created on: 4 Nov 2016
 *      Author: porcellic
 */

#include "DropTriggerBuilder.h"
#include "../Keywords/Drop.h"

DropTriggerBuilder::DropTriggerBuilder()
: m_ifExists(false)
{
}

DropTriggerBuilder::~DropTriggerBuilder()
{
}

DropTriggerBuilder& DropTriggerBuilder::DropTrigger(const std::string& nameOfTrigger)
{
    m_nameOfTrigger = nameOfTrigger;
    return *this;
}

DropTriggerBuilder& DropTriggerBuilder::IfExists()
{
    m_ifExists = true;
    return *this;
}

std::string DropTriggerBuilder::Build()
{
    Keys::Drop d(m_nameOfTrigger, m_ifExists, Trigger_DropType);
    return d.getCompleteKeyword() + TerminationQueryCharacter;
}



