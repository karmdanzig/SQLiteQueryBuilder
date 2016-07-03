#include <string>

#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_

using namespace std;

typedef enum
{
	None = 0,
	SelectQuery,
	DeleteQuery,
	InsertQuery,
	UpdateQuery,
	CreateQuery,
	DropQuery,
} QueryType;

const string SelectClause = "SELECT";
const string DeleteClause = "DELETE";
const string InsertIntoClause = "INSERT INTO";
const string UpdateClause = "UPDATE";
const string DropTableClause = "DROP TABLE";
const string CreateTableClause = "CREATE TABLE";
const string FromClause = "FROM";
const string WhereClause = "WHERE";
const string AndClause = "AND";
const string OrClause = "OR";
const string SetClause = "SET";
const string ValuesClause = "VALUES";
const string PrimaryKeyClause = "PRIMARY KEY";
const string NotNullClause = "NOT NULL";
const string LikeClause = "LIKE";
const string EqualClause = "=";
const string GreaterClause = ">";
const string LessClause = "<";
const string GreaterOrEqualClause = ">=";
const string LessOrEqualClause = "<=";
const string GroupByClause="GROUP BY";
const string OrderByClause="ORDER BY";
const string AscClause="ASC";
const string DescClause="DESC";

#endif /* SRC_CONSTANTS_H_ */
