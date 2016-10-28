/*
 * Update.h
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_UPDATE_H_
#define SRC_KEYWORDS_UPDATE_H_

#include "Keyword.h"

class Update : public Keyword
{
private:

    std::string table;

public:

    Update(const std::string& table);
    ~Update();
    void processKeyword();
};



#endif /* SRC_KEYWORDS_UPDATE_H_ */
