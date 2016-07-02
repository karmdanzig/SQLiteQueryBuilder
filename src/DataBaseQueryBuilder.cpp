#include <iostream>
#include <sstream>
#include <vector>
#include "DataBaseQueryBuilder.h"

using namespace std;

DataBaseQueryBuilder::DataBaseQueryBuilder () : m_delete(false)
{
}

DataBaseQueryBuilder::~DataBaseQueryBuilder ()
{
}

string DataBaseQueryBuilder::Build()
{
    m_finalString = "";
    if(!m_selectList.empty())
    {
        m_finalString = "SELECT ";

        for(std::vector<string>::iterator it = m_selectList.begin() ; it != m_selectList.end(); it++)
        {
            m_finalString.append(*it);
            if (*it != m_selectList.at(m_selectList.size() - 1))
            {
                m_finalString.append(",");
            }

        }

        m_finalString.append("\n");

        m_finalString.append("FROM ");
        m_finalString.append(m_from);

        if (m_whereList.size() > 0)
        {
            m_finalString.append("\n");
        	m_finalString.append("WHERE (");

        	for(std::vector<string>::iterator it = m_whereList.begin() ; it != m_whereList.end(); it++)
        	{
        		m_finalString.append(*it);
        		if (*it != m_whereList.at(m_whereList.size() - 1))
        		{
        			m_finalString.append(" AND ");
        		}

        	}

        	m_finalString.append(")");
        }
    }
    if(m_update != "")
    {
        m_finalString.append("UPDATE ");
        m_finalString.append(m_update);

        m_finalString.append("\n");

        m_finalString.append("SET ");

        for(std::vector<string>::iterator it = m_setList.begin() ; it != m_setList.end(); it++)
        {
            m_finalString.append(*it);
            if (*it != m_setList.at(m_setList.size() - 1))
            {
                m_finalString.append(", ");
            }

        }

        if (m_whereList.size() > 0)
		{
			m_finalString.append("\n");

			m_finalString.append("WHERE (");

			for(std::vector<string>::iterator it = m_whereList.begin() ; it != m_whereList.end(); it++)
			{
				m_finalString.append(*it);
				if (*it != m_whereList.at(m_whereList.size() - 1))
				{
					m_finalString.append(" AND ");
				}

			}

			m_finalString.append(")");
		}
    }
    if(m_delete == true)
    {
        m_finalString.append("DELETE ");
        m_finalString.append("FROM ");
        m_finalString.append(m_from);


        if (m_whereList.size() > 0)
		{
			m_finalString.append("\n");

			m_finalString.append("WHERE (");

			for(std::vector<string>::iterator it = m_whereList.begin() ; it != m_whereList.end(); it++)
			{
				m_finalString.append(*it);
				if (*it != m_whereList.at(m_whereList.size() - 1))
				{
					m_finalString.append(" AND ");
				}

			}

			m_finalString.append(")");
		}

    }
    if(m_insertInto != "")
    {
        m_finalString = "INSERT INTO ";

        m_finalString.append(m_insertInto);

        m_finalString.append("\n");

        m_finalString.append("VALUES (");

        for(std::vector<string>::iterator it = m_valuesList.begin() ; it != m_valuesList.end(); it++)
        {
            m_finalString.append(*it);
            if (*it != m_valuesList.at(m_valuesList.size() - 1))
            {
                m_finalString.append(", ");
            }

        }

        m_finalString.append(")");
    }
    if(m_createTable != "")
    {
        m_finalString.append("CREATE TABLE ");
        m_finalString.append(m_createTable);

        m_finalString.append(" (\n");

        for(std::vector<string>::iterator it = m_fieldsList.begin() ; it != m_fieldsList.end(); it++)
        {
            m_finalString.append(*it);
            if (*it != m_fieldsList.at(m_fieldsList.size() - 1))
            {
                m_finalString.append(",\n");
            }

        }

        m_finalString.append(")");

    }
    if(m_dropTable != "")
    {
        m_finalString.append("DROP TABLE ");
        m_finalString.append(m_dropTable);
    }


    m_finalString.append(";");

    return m_finalString;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Select(string ColumnToSelect)
{
    m_selectList.push_back(ColumnToSelect);
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
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::InsertInto(string table)
{
    m_insertInto = table;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Update(string TableToUpdate)
{
    m_update = TableToUpdate;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::CreateTable(string table)
{
    m_createTable = table;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Field(string fieldName, string fieldType, bool primaryKey, bool notNull)
{
    string temp = fieldName + " " + fieldType + " " + (primaryKey? "PRIMARY KEY " : "") + (notNull? "NOT NULL" : "");
    m_fieldsList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::DropTable(string table)
{
    m_dropTable = table;
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
    string temp = setField + " = \'" + value + "\'";
    m_setList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Set(string setField, int value)
{
    ostringstream ss;
    ss << value;
    string temp = setField + " = " + ss.str();
    m_setList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqual(string FilterField, string value)
{
    string temp = FilterField + " = \'" + value + "\'";
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereLessThan(string FilterField, string value)
{
    string temp = FilterField + " < \'" + value + "\'";
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereGreaterThan(string FilterField, string value)
{
    string temp = FilterField + " > \'" + value + "\'";
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqualOrLessThan(string FilterField, string value)
{
    string temp = FilterField + " <= \'" + value + "\'";
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqualOrGreaterThan(string FilterField, string value)
{
    string temp = FilterField + " >= \'" + value + "\'";
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqual(string FilterField, int value)
{
    ostringstream ss;
    ss << value;
    string temp = FilterField + " = " + ss.str();
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereLessThan(string FilterField, int value)
{
    ostringstream ss;
    ss << value;
    string temp = FilterField + " < " + ss.str();
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereGreaterThan(string FilterField, int value)
{
    ostringstream ss;
    ss << value;
    string temp = FilterField + " > " + ss.str();
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqualOrLessThan(string FilterField, int value)
{
    ostringstream ss;
    ss << value;
    string temp = FilterField + " <= " + ss.str();
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqualOrGreaterThan(string FilterField, int value)
{
    ostringstream ss;
    ss << value;
    string temp = FilterField + " >= " + ss.str();
    m_whereList.push_back(temp);
    return *this;
}
