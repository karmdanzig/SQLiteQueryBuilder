/*
 * AlterBuilder.h
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_ALTERBUILDER_H_
#define SRC_BUILDERS_ALTERBUILDER_H_

#include "QueryBuilder.h"
#include "../Keywords/Alter.h"

class AlterBuilder : public QueryBuilder
{
private:


    std::string m_tableToAlter;
    AlterType m_type;
    std::string m_newValue;



public:

    AlterBuilder();
    ~AlterBuilder();

    AlterBuilder& Alter(const std::string& table);

    AlterBuilder& RenameTo(const std::string& table);
    AlterBuilder& AddColumn(const std::string& fieldName, const std::string& fieldType, const bool& primaryKey, const bool& notNull);
    std::string Build();

};



#endif /* SRC_BUILDERS_ALTERBUILDER_H_ */
