/*
 * CreateIndex.h
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_CREATEINDEX_H_
#define SRC_KEYWORDS_CREATEINDEX_H_

#include "Keyword.h"

namespace Keys
{

class CreateIndex : public Keyword
{
private:

    std::string table;
    bool unique;
    bool ifNotExists;
    std::vector<std::string> fieldsList;

public:

    CreateIndex(const std::string& index, const bool& unique, const bool& ifNotExists, std::vector<std::string>& fieldsList);
    ~CreateIndex();
    void processKeyword();
};

}



#endif /* SRC_KEYWORDS_CREATEINDEX_H_ */
