/*
 * Commit.h
 *
 *  Created on: 4 Nov 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_COMMIT_H_
#define SRC_KEYWORDS_COMMIT_H_

#include "Keyword.h"

namespace Keys
{

class Commit : public Keyword
{
public:

    Commit();
    ~Commit();
    void processKeyword();
};

}



#endif /* SRC_KEYWORDS_COMMIT_H_ */
