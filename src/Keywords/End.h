/*
 * End.h
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_END_H_
#define SRC_KEYWORDS_END_H_

#include "Keyword.h"

namespace Keys
{

class End : public Keyword
{
private:

    std::string transaction;

public:

    End(const std::string& transaction);
    ~End();
    void processKeyword();
};

}



#endif /* SRC_KEYWORDS_END_H_ */
