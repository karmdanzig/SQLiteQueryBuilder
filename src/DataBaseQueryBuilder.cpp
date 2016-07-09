#include <sstream>
#include "DataBaseQueryBuilder.h"
#include "Constants.h"

using namespace std;

DataBaseQueryBuilder::DataBaseQueryBuilder () :
		m_finalString(""),
		m_from(""),
		m_update(""),
		m_insertInto(""),
		m_createTable(""),
		m_dropTable(""),
		m_alterTable(""),
		m_delete(false),
		m_asc(false),
		m_desc(false),
		m_selectAll(false),
		m_queryType(None),
		m_distinct(false),
		m_ifExists(false),
		m_ifNotExists(false),
		m_temporary(false),
		m_renameTable("")
{
}

DataBaseQueryBuilder::~DataBaseQueryBuilder ()
{
}

void DataBaseQueryBuilder::addReturnLine()
{
    m_finalString.append("\n");
};

void DataBaseQueryBuilder::processSelectClause()
{
	m_finalString = SelectClause + " " + (m_distinct? DistinctClause + " " : "");

	if (m_selectAll)
	{
		m_finalString.append("*");
	}
	else
	{
		insertFromListWithSeparator(m_selectList, ",");
	}
};

void DataBaseQueryBuilder::processFromClause()
{
    m_finalString.append(FromClause + " ");
    m_finalString.append(m_from);
};

void DataBaseQueryBuilder::processWhereClause()
{
    if (m_whereList.size() > 0)
    {
    	addReturnLine();

    	m_finalString.append(WhereClause + " ");

    	for(std::vector<string>::iterator it = m_whereList.begin(), it2 = m_operatorList.begin() ; it != m_whereList.end(); it++, it2++)
    	{
    		m_finalString.append(*it);
    		if (*it != m_whereList.at(m_whereList.size() - 1))
    		{
    			m_finalString.append(" " + *it2 +" ");
    		}

    	}
    }
}

void DataBaseQueryBuilder::processGroupByClause()
{
    if (m_groupbyList.size() > 0)
    {
    	addReturnLine();

    	m_finalString.append(GroupByClause + " ");

    	insertFromListWithSeparator(m_groupbyList, ", ");

    }
}

void DataBaseQueryBuilder::processHavingClause()
{
    if (m_havingList.size() > 0)
    {
    	addReturnLine();

    	m_finalString.append(HavingClause + " ");

    	insertFromListWithSeparator(m_havingList, ", ");

    }
}

void DataBaseQueryBuilder::processOrderByClause()
{
    if (m_orderbyList.size() > 0)
    {
    	addReturnLine();

    	m_finalString.append(OrderByClause + " ");

    	insertFromListWithSeparator(m_orderbyList, ", ");

    }
    if (m_asc)
    {
    	m_finalString.append(" " + AscClause);
    }
    if (m_desc)
	{
		m_finalString.append(" " + DescClause);
	}

}

void DataBaseQueryBuilder::processDeleteClause()
{
	m_finalString = DeleteClause + " ";
}

void DataBaseQueryBuilder::processInsertIntoClause()
{
	m_finalString = InsertIntoClause + " " + m_insertInto;
}

void DataBaseQueryBuilder::processValuesClause()
{
	m_finalString.append(ValuesClause + " (");

	insertFromListWithSeparator(m_valuesList, ", ");

	m_finalString.append(")");
}

void DataBaseQueryBuilder::processUpdateClause()
{
	m_finalString = UpdateClause + " " + m_update;
}

void DataBaseQueryBuilder::processSetClause()
{
	m_finalString.append(SetClause + " ");

	insertFromListWithSeparator(m_setList, ", ");
}

void DataBaseQueryBuilder::processCreateClause()
{
	m_finalString = CreateClause + " " + (m_temporary? TemporaryClause + " " : "") + Table + " " + (m_ifNotExists? IfNotExistsClause + " " : "") + m_createTable;
}

void DataBaseQueryBuilder::processTableFields()
{
	m_finalString.append(" (");
	addReturnLine();

	insertFromListWithSeparator(m_fieldsList, ",\n");

	m_finalString.append(")");
}

void DataBaseQueryBuilder::processDropClause()
{
	m_finalString = DropClause + " " + Table + " " + (m_ifExists? IfExistsClause + " " : "") + m_dropTable;
}

void DataBaseQueryBuilder::processAlterClause()
{
	m_finalString = AlterClause + " " + m_alterTable + " " + RenameToClause + " " + m_renameTable;
}

void DataBaseQueryBuilder::insertFromListWithSeparator(vector<string>& whichList, string separator)
{
	for(std::vector<string>::iterator it = whichList.begin() ; it != whichList.end(); it++)
	{
		m_finalString.append(*it);
		if (*it != whichList.at(whichList.size() - 1))
		{
			m_finalString.append(separator);
		}

	}
}

string DataBaseQueryBuilder::Build()
{
	switch(m_queryType)
	{
	case (SelectQuery) :
		{
			processSelectClause();
			addReturnLine();
			processFromClause();
			processWhereClause();
			processGroupByClause();
			processHavingClause();
			processOrderByClause();
			break;
		}
	case (DeleteQuery) :
		{
			processDeleteClause();
			processFromClause();
			processWhereClause();
			break;
		}
	case (InsertQuery) :
		{
			processInsertIntoClause();
			addReturnLine();
			processValuesClause();
			break;
		}
	case (UpdateQuery) :
		{
			processUpdateClause();
			addReturnLine();
			processSetClause();
			processWhereClause();
			break;
		}
	case (CreateQuery) :
		{
			processCreateClause();
			processTableFields();
			break;
		}
	case (DropQuery) :
		{
			processDropClause();
			break;
		}
	case (AlterQuery) :
		{
			processAlterClause();
			break;
		}
	}

    m_finalString.append(";");

    return m_finalString;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Select(string ColumnToSelect)
{
    m_selectList.push_back(ColumnToSelect);
    m_queryType = SelectQuery;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::SelectAll()
{
    m_selectAll = true;
    m_queryType = SelectQuery;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Distinct()
{
    m_distinct = true;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::From(string fromClause)
{
    m_from = fromClause;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Delete()
{
    m_delete = true;
    m_queryType = DeleteQuery;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::InsertInto(string table)
{
    m_insertInto = table;
    m_queryType = InsertQuery;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Update(string TableToUpdate)
{
    m_update = TableToUpdate;
    m_queryType = UpdateQuery;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Create(string table)
{
    m_createTable = table;
    m_queryType = CreateQuery;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Field(string fieldName, string fieldType, bool primaryKey, bool notNull)
{
    string temp = fieldName + " " + fieldType + " " + (primaryKey? PrimaryKeyClause + " " : "") + (notNull? NotNullClause : "");
    m_fieldsList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Drop(string table)
{
    m_dropTable = table;
    m_queryType = DropQuery;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Alter(string table)
{
    m_alterTable = table;
    m_queryType = AlterQuery;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::RenameTo(string table)
{
    m_renameTable = table;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Values(string value)
{
    string temp = "\'" + value + "\'";
    m_valuesList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Values(int value)
{
    ostringstream ss;
    ss << value;
    string temp = ss.str();
    m_valuesList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Set(string setField, string value)
{
    string temp = setField + " " + EqualClause + " \'" + value + "\'";
    m_setList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Set(string setField, int value)
{
    ostringstream ss;
    ss << value;
    string temp = setField + " " + EqualClause + " " + ss.str();
    m_setList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqual(string FilterField, string value)
{
    string temp = FilterField + " " + EqualClause + " \'" + value + "\'";
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereLessThan(string FilterField, string value)
{
    string temp = FilterField + " " + LessClause + " \'" + value + "\'";
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereGreaterThan(string FilterField, string value)
{
    string temp = FilterField + " " + GreaterClause + " \'" + value + "\'";
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqualOrLessThan(string FilterField, string value)
{
    string temp = FilterField + " " + LessOrEqualClause + " \'" + value + "\'";
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqualOrGreaterThan(string FilterField, string value)
{
    string temp = FilterField + " " + GreaterOrEqualClause + " \'" + value + "\'";
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqual(string FilterField, int value)
{
    ostringstream ss;
    ss << value;
    string temp = FilterField + " " + EqualClause + " " + ss.str();
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereLessThan(string FilterField, int value)
{
    ostringstream ss;
    ss << value;
    string temp = FilterField + " " + LessClause + " " + ss.str();
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereGreaterThan(string FilterField, int value)
{
    ostringstream ss;
    ss << value;
    string temp = FilterField + " " + GreaterClause + " " + ss.str();
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqualOrLessThan(string FilterField, int value)
{
    ostringstream ss;
    ss << value;
    string temp = FilterField + " " + LessOrEqualClause + " " + ss.str();
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqualOrGreaterThan(string FilterField, int value)
{
    ostringstream ss;
    ss << value;
    string temp = FilterField + " " + GreaterOrEqualClause + " " + ss.str();
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereLike(string FilterField, string value)
{
    string temp = FilterField + " " + LikeClause + " \'" + value + "\'";
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereLike(string FilterField, int value)
{
    ostringstream ss;
    ss << value;
    string temp = FilterField + " " + LikeClause + " " + ss.str();
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereNotLike(string FilterField, string value)
{
    string temp = FilterField + " " + NotClause + " " + LikeClause + " \'" + value + "\'";
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereNotLike(string FilterField, int value)
{
    ostringstream ss;
    ss << value;
    string temp = FilterField + " " + NotClause + " " + LikeClause + " " + ss.str();
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::And()
{
    m_operatorList.push_back(AndClause);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Or()
{
    m_operatorList.push_back(OrClause);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::GroupBy(string column)
{
	m_groupbyList.push_back(column);
	return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::OrderBy(string column)
{
	m_orderbyList.push_back(column);
	return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Asc()
{
    m_asc = true;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Desc()
{
	m_desc = true;
	return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Having(string FilterField, string value)
{
    string temp = FilterField + " = \'" + value + "\'";
    m_havingList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Having(string FilterField, int value)
{
    ostringstream ss;
    ss << value;
    string temp = FilterField + " = " + ss.str();
    m_havingList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereIn(string FilterField, string value)
{
	string temp1 = value;
	temp1 = FilterField + " " + InClause + " (" + temp1.substr(0, temp1.size()-1) + ")";
    m_whereList.push_back(temp1);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereBetween(string FilterField, int min, int max)
{
    ostringstream ss, ss1;
    ss << min;
    ss1 << max;
	string temp1 = FilterField + " " + BetweenClause + " " + ss.str() + " " + AndClause + " " + ss1.str();
    m_whereList.push_back(temp1);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereBetween(string FilterField, string min, string max)
{
	string temp1 = FilterField + " " + BetweenClause + " " + min + " " + AndClause + " " + max;
    m_whereList.push_back(temp1);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereNotBetween(string FilterField, int min, int max)
{
    ostringstream ss, ss1;
    ss << min;
    ss1 << max;
	string temp1 = FilterField + " " + NotClause + " " + BetweenClause + " " + ss.str() + " " + AndClause + " " + ss1.str();
    m_whereList.push_back(temp1);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereNotBetween(string FilterField, string min, string max)
{
	string temp1 = FilterField + " " + NotClause + " " + BetweenClause + " " + min + " " + AndClause + " " + max;
    m_whereList.push_back(temp1);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::IfExists()
{
	m_ifExists = true;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::IfNotExists()
{
	m_ifNotExists = true;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Temporary()
{
	m_temporary = true;
    return *this;
}
