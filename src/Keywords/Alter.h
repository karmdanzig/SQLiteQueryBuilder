/*
 * Alter.h
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_ALTER_H_
#define SRC_KEYWORDS_ALTER_H_


#include "Keyword.h"

class Alter : public Keyword
{
private:

    std::string table;
    AlterType type;
    std::string newvalue;


public:

    Alter(std::string table, AlterType type, std::string newvalue);
    ~Alter();
    void processKeyword();
}


#endif /* SRC_KEYWORDS_ALTER_H_ */
