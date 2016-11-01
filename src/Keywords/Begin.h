/*
 * Begin.h
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_BEGIN_H_
#define SRC_KEYWORDS_BEGIN_H_

#include "Keyword.h"

namespace Keys
{

class Begin : public Keyword
{
private:

    std::string transaction;

public:

    Begin();
    Begin(const std::string& transaction);
    ~Begin();
    void processKeyword();
};

}



#endif /* SRC_KEYWORDS_BEGIN_H_ */
