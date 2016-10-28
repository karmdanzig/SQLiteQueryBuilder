/*
 * Create.h
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_CREATE_H_
#define SRC_KEYWORDS_CREATE_H_

#include "Keyword.h"

class Create : public Keyword
{
private:

    std::string table;
    bool temporary;
    bool ifNotExists;


public:

    Create(const std::string& table, bool temporary, bool ifNotExists);
    ~Create();
    void processKeyword();
};



#endif /* SRC_KEYWORDS_CREATE_H_ */
