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
		m_delete(false),
		m_asc(false),
		m_desc(false),
		m_selectAll(false),
		m_queryType(None)
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
	m_finalString = SelectClause + " ";

	if (m_selectAll)
	{
		m_finalString.append("*");
	}
	else{
		for(std::vector<string>::iterator it = m_selectList.begin() ; it != m_selectList.end(); it++)
		{
			m_finalString.append(*it);
			if (*it != m_selectList.at(m_selectList.size() - 1))
			{
				m_finalString.append(",");
			}

		}
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

    	m_finalString.append(WhereClause + " (");

    	for(std::vector<string>::iterator it = m_whereList.begin(), it2 = m_operatorList.begin() ; it != m_whereList.end(); it++, it2++)
    	{
    		m_finalString.append(*it);
    		if (*it != m_whereList.at(m_whereList.size() - 1))
    		{
    			m_finalString.append(" " + *it2 +" ");
    		}

    	}

    	m_finalString.append(")");
    }
}

void DataBaseQueryBuilder::processGroupByClause()
{
    if (m_groupbyList.size() > 0)
    {
    	addReturnLine();

    	m_finalString.append(GroupByClause + " ");

    	for(std::vector<string>::iterator it = m_groupbyList.begin(); it != m_groupbyList.end(); it++)
    	{
    		m_finalString.append(*it);
    		if (*it != m_groupbyList.at(m_groupbyList.size() - 1))
    		{
    			m_finalString.append(", ");
    		}

    	}

    }
}

void DataBaseQueryBuilder::processOrderByClause()
{
    if (m_orderbyList.size() > 0)
    {
    	addReturnLine();

    	m_finalString.append(OrderByClause + " ");

    	for(std::vector<string>::iterator it = m_orderbyList.begin(); it != m_orderbyList.end(); it++)
    	{
    		m_finalString.append(*it);
    		if (*it != m_orderbyList.at(m_orderbyList.size() - 1))
    		{
    			m_finalString.append(", ");
    		}

    	}

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
			processOrderByClause();
		break;
		}
	case (DeleteQuery) :
		{
			m_finalString = DeleteClause + " ";
			processFromClause();
			processWhereClause();
		break;
		}
	case (InsertQuery) :
		{
			m_finalString = InsertIntoClause + " ";

			m_finalString.append(m_insertInto);

			addReturnLine();

			m_finalString.append(ValuesClause + " (");

			for(std::vector<string>::iterator it = m_valuesList.begin() ; it != m_valuesList.end(); it++)
			{
				m_finalString.append(*it);
				if (*it != m_valuesList.at(m_valuesList.size() - 1))
				{
					m_finalString.append(", ");
				}

			}

			m_finalString.append(")");
		break;
		}
	case (UpdateQuery) :
		{
			m_finalString = UpdateClause + " ";
			m_finalString.append(m_update);

			addReturnLine();

			m_finalString.append(SetClause + " ");

			for(std::vector<string>::iterator it = m_setList.begin() ; it != m_setList.end(); it++)
			{
				m_finalString.append(*it);
				if (*it != m_setList.at(m_setList.size() - 1))
				{
					m_finalString.append(", ");
				}

			}

			processWhereClause();
		break;
		}
	case (CreateQuery) :
		{
			m_finalString = CreateTableClause + " ";
			m_finalString.append(m_createTable);

			m_finalString.append(" (");
			addReturnLine();

			for(std::vector<string>::iterator it = m_fieldsList.begin() ; it != m_fieldsList.end(); it++)
			{
				m_finalString.append(*it);
				if (*it != m_fieldsList.at(m_fieldsList.size() - 1))
				{
					m_finalString.append(",");
					addReturnLine();
				}

			}

			m_finalString.append(")");
		break;
		}
	case (DropQuery) :
		{
			m_finalString = DropTableClause + " ";
			m_finalString.append(m_dropTable);
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

DataBaseQueryBuilder& DataBaseQueryBuilder::CreateTable(string table)
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

DataBaseQueryBuilder& DataBaseQueryBuilder::DropTable(string table)
{
    m_dropTable = table;
    m_queryType = DropQuery;
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
