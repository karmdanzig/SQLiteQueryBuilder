/*
 * Set.h
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_SET_H_
#define SRC_KEYWORDS_SET_H_

#include "Keyword.h"

class Set : public Keyword
{
private:

    std::vector<std::string> setList;

public:

    Set(const std::vector<std::string>& setList);
    ~Set();
    void processKeyword();
};



#endif /* SRC_KEYWORDS_SET_H_ */
