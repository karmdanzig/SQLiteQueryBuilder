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
#include "Constants.h"

class Keyword
{
protected:

    std::string m_completeKeyword;
    void insertFromListWithSeparator(const std::vector<std::string>& whichlist, const std::string& separator);
    void insertFromListWithOperatorList(const std::vector<std::string>& whichList, std::queue<std::string>& operatorList);
    void addReturnLine();

public:

    Keyword();
    string& getCompleteKeyword();
};



#endif /* SRC_KEYWORD_H_ */
