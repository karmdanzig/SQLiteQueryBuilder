/*
 * Pragma.h
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_PRAGMA_H_
#define SRC_KEYWORDS_PRAGMA_H_

#include "Keyword.h"

namespace Keys
{

class Pragma : public Keyword
{
private:

    PragmaType command;

public:

    Pragma(const PragmaType& command);
    ~Pragma();
    void processKeyword();
};

}

#endif /* SRC_KEYWORDS_PRAGMA_H_ */
