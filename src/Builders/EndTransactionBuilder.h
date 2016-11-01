/*
 * EndTransactionBuilder.h
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_ENDTRANSACTIONBUILDER_H_
#define SRC_BUILDERS_ENDTRANSACTIONBUILDER_H_

#include "QueryBuilder.h"

class EndTransactionBuilder : public QueryBuilder
{
private:

    std::string m_transaction;

public:

    EndTransactionBuilder();
    ~EndTransactionBuilder();

    EndTransactionBuilder& End(const std::string& transaction);
    std::string Build();

};



#endif /* SRC_BUILDERS_ENDTRANSACTIONBUILDER_H_ */
