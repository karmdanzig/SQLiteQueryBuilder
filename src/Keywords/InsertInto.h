/*
 * InsertInto.h
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_INSERTINTO_H_
#define SRC_KEYWORDS_INSERTINTO_H_

#include "Keyword.h"

namespace Keys
{

class InsertInto : public Keyword
{
private:

    std::string table;

public:

    InsertInto(const std::string& table);
    ~InsertInto();
    void processKeyword();
};

}

#endif /* SRC_KEYWORDS_INSERTINTO_H_ */
