/*
 * Rollback.h
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_ROLLBACK_H_
#define SRC_KEYWORDS_ROLLBACK_H_

#include "Keyword.h"

namespace Keys
{

class Rollback : public Keyword
{
public:

    Rollback();
    ~Rollback();
    void processKeyword();
};

}



#endif /* SRC_KEYWORDS_ROLLBACK_H_ */
