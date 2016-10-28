/*
 * Having.h
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_HAVING_H_
#define SRC_HAVING_H_

#include "Keyword.h"

namespace Keys
{

class Having : public Keyword
{
private:

    std::vector<std::string> havingList;

public:

    Having(const std::vector<std::string>& havingList);
    ~Having();
    void processKeyword();
};

}



#endif /* SRC_HAVING_H_ */
