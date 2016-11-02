/*
 * From.h
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#ifndef FROM_H_
#define FROM_H_


#include "Keyword.h"

namespace Keys
{

class From : public Keyword
{
private:

    std::string table;
    std::string join;
    std::vector<std::string> fromList;
    std::vector<std::string> onList;
    std::queue<std::string> theQueue;

public:

    From(const std::string& table);
    From(const std::string& table, const std::string& join, std::vector<std::string>& fromList, std::vector<std::string>& onList, std::queue<std::string>& theQueue);
    ~From();
    void processKeyword();
};

}

#endif /* FROM_H_ */
