/*
 * Keyword.h
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORD_H_
#define SRC_KEYWORD_H_
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "../Constants.h"

namespace Keys
{

class Keyword
{
protected:

    std::string m_completeKeyword;
    void insertFromListWithSeparator(const std::vector<std::string>& whichlist, const std::string& separator);
    void insertFromListWithOperatorList(const std::vector<std::string>& whichList, std::queue<std::string>& operatorList);
    void addReturnLine();

public:

    Keyword();
    virtual ~Keyword();
    string& getCompleteKeyword();
    virtual void processKeyword () = 0;
};

}

#endif /* SRC_KEYWORD_H_ */
