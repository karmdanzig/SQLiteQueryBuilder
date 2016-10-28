/*
 * Update.cpp
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#include "Update.h"

namespace Keys
{

Update::Update(const std::string& table)
: table(table)
{
    processKeyword();
}

Update::~Update()
{
}

void Update::processKeyword()
{
    m_completeKeyword = UpdateClause + " " + table + " ";
}

}
