/*
 * Drop.h
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_DROP_H_
#define SRC_KEYWORDS_DROP_H_


#include "Keyword.h"

namespace Keys
{

class Drop : public Keyword
{
private:

    std::string table;
    bool ifExists;
    DropType typeOfDropOrCreate;

public:

    Drop(const std::string& table, const bool& ifExists, DropType typeOfDropOrCreate);
    ~Drop();
    void processKeyword();
};

}

#endif /* SRC_KEYWORDS_DROP_H_ */
