/*
 * Where.h
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_WHERE_H_
#define SRC_WHERE_H_

#include "Keyword.h"

namespace Keys
{

class Where : public Keyword
{
private:

    std::vector<std::string> whereList;
    std::queue<std::string> theQueue;

public:

    Where(const std::vector<std::string>& whereList);
    Where(const std::vector<std::string>& whereList, std::queue<std::string>& theQueue);
    ~Where();
    void processKeyword();
};

}

#endif /* SRC_WHERE_H_ */
