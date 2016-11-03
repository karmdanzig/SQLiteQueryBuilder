/*
 * Create.h
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_CREATETABLE_H_
#define SRC_KEYWORDS_CREATETABLE_H_

#include "Keyword.h"

namespace Keys
{

class CreateTable : public Keyword
{
private:

    std::string table;
    bool temporary;
    bool ifNotExists;
    std::vector<std::string> fieldsList;

public:

    CreateTable(const std::string& table, const bool& temporary, const bool& ifNotExists, std::vector<std::string>& fieldsList);
    ~CreateTable();
    void processKeyword();
};

}

#endif /* SRC_KEYWORDS_CREATETABLE_H_ */
