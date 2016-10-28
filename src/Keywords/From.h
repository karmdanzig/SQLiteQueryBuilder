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

    std::vector<std::string> fromList;
    std::string table;


public:

    From(const std::string& table);
    ~From();
    void processKeyword();
};

}

#endif /* FROM_H_ */
