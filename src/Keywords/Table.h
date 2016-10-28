/*
 * Table.h
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_TABLE_H_
#define SRC_KEYWORDS_TABLE_H_

#include "Keyword.h"

namespace Keys
{

class Table : public Keyword
{
private:

    std::vector<std::string> fieldsList;

public:

    Table(const std::vector<std::string>& fieldsList);
    ~Table();
    void processKeyword();
};

}

#endif /* SRC_KEYWORDS_TABLE_H_ */
