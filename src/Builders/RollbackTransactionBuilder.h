/*
 * RollbackTransactionBuilder.h
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_ROLLBACKTRANSACTIONBUILDER_H_
#define SRC_BUILDERS_ROLLBACKTRANSACTIONBUILDER_H_

#include "QueryBuilder.h"

class RollbackTransactionBuilder : public QueryBuilder
{
public:

    RollbackTransactionBuilder();
    ~RollbackTransactionBuilder();

    RollbackTransactionBuilder& Rollback();
    std::string Build();

};



#endif /* SRC_BUILDERS_ROLLBACKTRANSACTIONBUILDER_H_ */
