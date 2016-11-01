/*
 * BeginTransactionBuilder.h
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_BEGINTRANSACTIONBUILDER_H_
#define SRC_BUILDERS_BEGINTRANSACTIONBUILDER_H_

#include "QueryBuilder.h"

class BeginTransactionBuilder : public QueryBuilder
{
private:

    std::string m_transaction;

public:

    BeginTransactionBuilder();
    ~BeginTransactionBuilder();

    BeginTransactionBuilder& Begin();
    BeginTransactionBuilder& Begin(const std::string& transaction);
    std::string Build();

};



#endif /* SRC_BUILDERS_BEGINTRANSACTIONBUILDER_H_ */
