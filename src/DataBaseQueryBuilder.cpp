#include <sstream>
#include "DataBaseQueryBuilder.h"
#include "Constants.h"
#include <stdarg.h>

using namespace std;

DataBaseQueryBuilder::DataBaseQueryBuilder () :
		m_finalString(""),
		m_from(""),
		m_update(""),
		m_insertInto(""),
		m_createTable(""),
		m_dropTable(""),
		m_alterTable(""),
		m_renameTable(""),
		m_addColumn(""),
		m_join(""),
		m_pragma(""),
		m_delete(false),
		m_asc(false),
		m_desc(false),
		m_selectAll(false),
		m_queryType(None),
		m_distinct(false),
		m_ifExists(false),
		m_ifNotExists(false),
		m_temporary(false),
		m_pragmaType(None)
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

    if (!m_from.empty())
    {
        m_finalString.append(m_from);
        if (!m_join.empty())
        {
            m_finalString.append(" " + m_join);
        }
    }

    if (!m_fromAsList.empty())
    {
        insertFromListWithSeparator(m_fromAsList, " JOIN ");
        m_finalString.append(" " + OnClause + " ");
        insertFromListWithOperatorList(m_OnList);
    }
};

void DataBaseQueryBuilder::processWhereClause()
{
    if (!m_whereList.empty())
    {
    	addReturnLine();
    	m_finalString.append(WhereClause + " ");
    	insertFromListWithOperatorList(m_whereList);
    }
}

void DataBaseQueryBuilder::processGroupByClause()
{
    if (!m_groupbyList.empty())
    {
    	addReturnLine();
    	m_finalString.append(GroupByClause + " ");
    	insertFromListWithSeparator(m_groupbyList, ", ");
    }
}

void DataBaseQueryBuilder::processHavingClause()
{
    if (!m_havingList.empty())
    {
    	addReturnLine();
    	m_finalString.append(HavingClause + " ");
    	insertFromListWithSeparator(m_havingList, ", ");
    }
}

void DataBaseQueryBuilder::processOrderByClause()
{
    if (!m_orderbyList.empty())
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
	m_finalString = AlterClause + " " + m_alterTable + " ";
	if (!m_renameTable.empty())
	{
		m_finalString.append(RenameToClause + " " + m_renameTable);
	}
	else if (!m_addColumn.empty())
	{
		m_finalString.append(AddColumnClause + " " + m_addColumn);
	}
}

void DataBaseQueryBuilder::processPragmaClause()
{
	m_finalString = PragmaClause + " ";

    switch(m_pragmaType)
    {
    	case ApplicationId :
		{
			m_finalString.append("application_id");
			break;
		}
		case AutoVacuum :
		{
			m_finalString.append("auto_vacuum");
			break;
		}
		case AutomaticIndex :
		{
			m_finalString.append("automatic_index");
			break;
		}
		case BusyTimeout :
		{
			m_finalString.append("busy_timeout");
			break;
		}
		case CacheSize :
		{
			m_finalString.append("cache_size");
			break;
		}
		case CacheSpill :
		{
			m_finalString.append("cache_spill");
			break;
		}
		case CaseSensitiveLike :
		{
			m_finalString.append("case_sensitive_like");
			break;
		}
		case CellSizeCheck :
		{
			m_finalString.append("cell_size_check");
			break;
		}
		case CheckpointFullfsync :
		{
			m_finalString.append("checkpoint_fullfsync");
			break;
		}
		case CollationList :
		{
			m_finalString.append("collation_list");
			break;
		}
		case CompileOptions :
		{
			m_finalString.append("compile_options");
			break;
		}
		case DataVersion :
		{
			m_finalString.append("data_version");
			break;
		}
		case DatabaseList :
		{
			m_finalString.append("database_list");
			break;
		}
		case DeferForeignKeys :
		{
			m_finalString.append("defer_foreign_keys");
			break;
		}
		case Encoding :
		{
			m_finalString.append("encoding");
			break;
		}
		case ForeignKeyCheck :
		{
			m_finalString.append("foreign_key_check");
			break;
		}
		case ForeignKeyList :
		{
			m_finalString.append("foreign_key_list");
			break;
		}
		case ForeignKeys :
		{
			m_finalString.append("foreign_keys");
			break;
		}
		case FreelistCount :
		{
			m_finalString.append("freelist_count");
			break;
		}
		case Fullfsync :
		{
			m_finalString.append("fullfsync");
			break;
		}
		case IgnoreCheckConstraints :
        {
        	m_finalString.append("ignore_check_constraints");
            break;
        }
		case IncrementalVacuum :
        {
        	m_finalString.append("incremental_vacuum");
            break;
        }
		case IndexInfo :
		{
			m_finalString.append("index_info");
			break;
		}
		case IndexList :
		{
			m_finalString.append("index_list");
			break;
		}
		case IndexXinfo :
		{
			m_finalString.append("index_xinfo");
			break;
		}
		case IntegrityCheck :
        {
        	m_finalString.append("integrity_check");
            break;
        }
		case JournalMode :
		{
			m_finalString.append("journal_mode");
			break;
		}
		case JournalSizeLimit :
        {
        	m_finalString.append("journal_size_limit");
            break;
        }
		case LegacyFileFormat :
		{
			m_finalString.append("legacy_file_format");
			break;
		}
		case LockingMode :
		{
			m_finalString.append("locking_mode");
			break;
		}
		case MaxPageCount :
		{
			m_finalString.append("max_page_count");
			break;
		}
		case MmapSize :
		{
			m_finalString.append("mmap_size");
			break;
		}
		case PageCount :
		{
			m_finalString.append("page_count");
			break;
		}
		case PageSize :
		{
			m_finalString.append("page_size");
			break;
		}
		case ParserTrace :
		{
			m_finalString.append("parser_trace");
			break;
		}
		case QuickCheck :
		{
			m_finalString.append("quick_check");
			break;
		}
		case ReadUncommitted :
		{
			m_finalString.append("read_uncommitted");
			break;
		}
		case RecursiveTriggers :
		{
			m_finalString.append("recursive_triggers");
			break;
		}
		case ReverseUnorderedSelects :
		{
			m_finalString.append("reverse_unordered_selects");
			break;
		}
		case SchemaVersion :
		{
			m_finalString.append("schema_version");
			break;
		}
		case SecureDelete :
		{
			m_finalString.append("secure_delete");
			break;
		}
		case ShrinkMemory :
		{
			m_finalString.append("shrink_memory");
			break;
		}
		case SoftHeapLimit :
		{
			m_finalString.append("soft_heap_limit");
			break;
		}
		case Stats :
		{
			m_finalString.append("stats");
			break;
		}
		case Synchronous :
		{
			m_finalString.append("synchronous");
			break;
		}
        case TableInfo :
        {
        	m_finalString.append("table_info(" + m_pragma + ")");
            break;
        }
		case TempStore :
		{
			m_finalString.append("temp_store");
			break;
		}
		case Threads :
		{
			m_finalString.append("threads");
			break;
		}
		case UserVersion :
		{
			m_finalString.append("user_version");
			break;
		}
		case VdbeAddoptrace :
		{
			m_finalString.append("vdbe_addoptrace");
			break;
		}
		case VdbeDebug :
		{
			m_finalString.append("vdbe_debug");
			break;
		}
		case VdbeListing :
		{
			m_finalString.append("vdbe_listing");
			break;
		}
		case VdbeTrace :
		{
			m_finalString.append("vdbe_trace");
			break;
		}
		case WalAutocheckpoint :
		{
			m_finalString.append("wal_autocheckpoint");
			break;
		}
		case WalCheckpoint :
		{
			m_finalString.append("wal_checkpoint");
			break;
		}
		case WritableSchema :
		{
			m_finalString.append("writable_schema");
			break;
		}
    }

}

void DataBaseQueryBuilder::insertFromListWithSeparator(const vector<string>& whichList, const string& separator)
{
	for(std::vector<string>::const_iterator it = whichList.begin() ; it != whichList.end(); it++)
	{
		m_finalString.append(*it);
		if (*it != whichList.at(whichList.size() - 1))
		{
			m_finalString.append(separator);
		}

	}
}

void DataBaseQueryBuilder::insertFromListWithOperatorList(const vector<string>& whichList)
{
	std::vector<string>::iterator it2 = m_operatorList.begin();

    for(std::vector<string>::const_iterator it = whichList.begin(); it != whichList.end(); it++, it2++)
    {
        m_finalString.append(*it);
        if (*it != whichList.at(whichList.size() - 1))
        {
            m_finalString.append(" " + *it2 +" ");
            m_operatorList.erase(it2);
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
    case (PragmaQuery) :
        {
            processPragmaClause();
            break;
        }
	}

    m_finalString.append(TerminationQueryCharacter);

    return m_finalString;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Select(const string& columnToSelect)
{
    m_selectList.push_back(columnToSelect);
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

DataBaseQueryBuilder& DataBaseQueryBuilder::From(const string& fromClause)
{
    m_from = fromClause;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::FromAs(const string& table, const string& alias)
{
    m_fromAsList.push_back(table + " " + AsClause + " " + alias);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::JoinAs(const string& table, const string& alias)
{
    m_fromAsList.push_back(table + " " + AsClause + " " + alias);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::OnEqual(const string& column, const string& alias1, const string& alias2)
{
    m_OnList.push_back(alias1 + "." + column +  " = " + alias2 + "." + column);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::NaturalJoin(const string& table)
{
	m_join = NaturalClause + " "  + JoinClause + " " + table;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::CrossJoin(const string& table)
{
	m_join = CrossClause + " " + JoinClause + " " + table;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::NaturalLeftOuterJoin(const string& table)
{
	m_join = NaturalClause + " " + LeftClause + " " + OuterClause + " " + JoinClause + " " + table;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Delete()
{
    m_delete = true;
    m_queryType = DeleteQuery;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::InsertInto(const string& table)
{
    m_insertInto = table;
    m_queryType = InsertQuery;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Update(const string& table)
{
    m_update = table;
    m_queryType = UpdateQuery;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Create(const string& table)
{
    m_createTable = table;
    m_queryType = CreateQuery;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::AddColumn(const string& fieldName, const string& fieldType, const bool& primaryKey, const bool& notNull)
{
    m_addColumn = fieldName + " " + fieldType + " " + (primaryKey? PrimaryKeyClause + " " : "") + (notNull? NotNullClause : "");
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Field(const string& fieldName, const string& fieldType, const bool& primaryKey, const bool& notNull)
{
    m_fieldsList.push_back(fieldName + " " + fieldType + " " + (primaryKey? PrimaryKeyClause + " " : "") + (notNull? NotNullClause : ""));
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Drop(const string& table)
{
    m_dropTable = table;
    m_queryType = DropQuery;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Alter(const string& table)
{
    m_alterTable = table;
    m_queryType = AlterQuery;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::RenameTo(const string& table)
{
    m_renameTable = table;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Values(const string& value)
{
    m_valuesList.push_back("\'" + value + "\'");
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Values(const int& value)
{
    ostringstream ss;
    ss << value;
    m_valuesList.push_back(ss.str());
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Set(const string& setField, const string& value)
{
    m_setList.push_back(setField + " " + EqualClause + " \'" + value + "\'");
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Set(const string& setField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_setList.push_back(setField + " " + EqualClause + " " + ss.str());
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqual(const string& filterField, const string& value)
{
    m_whereList.push_back(filterField + " " + EqualClause + " \'" + value + "\'");
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereLessThan(const string& filterField, const string& value)
{
    m_whereList.push_back(filterField + " " + LessClause + " \'" + value + "\'");
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereGreaterThan(const string& filterField, const string& value)
{
    m_whereList.push_back(filterField + " " + GreaterClause + " \'" + value + "\'");
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqualOrLessThan(const string& filterField, const string& value)
{
    m_whereList.push_back(filterField + " " + LessOrEqualClause + " \'" + value + "\'");
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqualOrGreaterThan(const string& filterField, const string& value)
{
    m_whereList.push_back(filterField + " " + GreaterOrEqualClause + " \'" + value + "\'");
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqual(const string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_whereList.push_back(filterField + " " + EqualClause + " " + ss.str());
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereLessThan(const string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_whereList.push_back(filterField + " " + LessClause + " " + ss.str());
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereGreaterThan(const string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_whereList.push_back(filterField + " " + GreaterClause + " " + ss.str());
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqualOrLessThan(const string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_whereList.push_back(filterField + " " + LessOrEqualClause + " " + ss.str());
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereEqualOrGreaterThan(const string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_whereList.push_back(filterField + " " + GreaterOrEqualClause + " " + ss.str());
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereLike(const string& filterField, const string& value)
{
    m_whereList.push_back(filterField + " " + LikeClause + " \'" + value + "\'");
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereLike(const string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_whereList.push_back(filterField + " " + LikeClause + " " + ss.str());
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereNotLike(const string& filterField, const string& value)
{
    m_whereList.push_back(filterField + " " + NotClause + " " + LikeClause + " \'" + value + "\'");
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereNotLike(const string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_whereList.push_back(filterField + " " + NotClause + " " + LikeClause + " " + ss.str());
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

DataBaseQueryBuilder& DataBaseQueryBuilder::GroupBy(const string& column)
{
	m_groupbyList.push_back(column);
	return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::OrderBy(const string& column)
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

DataBaseQueryBuilder& DataBaseQueryBuilder::Having(const string& filterField, const string& value)
{
    m_havingList.push_back(filterField + " = \'" + value + "\'");
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::Having(const string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_havingList.push_back(filterField + " = " + ss.str());
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereInQuery(const string& filterField, const string& value)
{
	string temp1 = value;
	size_t start_pos = temp1.find(TerminationQueryCharacter);
	if(start_pos != std::string::npos)
	{
	    temp1.replace(start_pos, TerminationQueryCharacter.length(), "");
	}
	temp1 = filterField + " " + InClause + " (" + temp1 + ")";
    m_whereList.push_back(temp1);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereIn(const string& filterField, const int& numberOfArguments, ... )
{
	string temp = filterField + " " + InClause + " (";
    va_list arguments;
    va_start (arguments, numberOfArguments);
    ostringstream ss;
    for (int x = 0; x < numberOfArguments; x++)
    {
        int value = va_arg (arguments, int);
        x == numberOfArguments-1 ? (ss << value) : (ss << value << ",");
	}

	va_end (arguments);

	temp.append(ss.str()+")");
    m_whereList.push_back(temp);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereBetween(const string& filterField, const int& min, const int& max)
{
    ostringstream ss, ss1;
    ss << min;
    ss1 << max;
    m_whereList.push_back(filterField + " " + BetweenClause + " " + ss.str() + " " + AndClause + " " + ss1.str());
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereBetween(const string& filterField, const string& min, const string& max)
{
    m_whereList.push_back(filterField + " " + BetweenClause + " " + min + " " + AndClause + " " + max);
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereNotBetween(const string& filterField, const int& min, const int& max)
{
    ostringstream ss, ss1;
    ss << min;
    ss1 << max;
    m_whereList.push_back(filterField + " " + NotClause + " " + BetweenClause + " " + ss.str() + " " + AndClause + " " + ss1.str());
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::WhereNotBetween(const string& filterField, const string& min, const string& max)
{
    m_whereList.push_back(filterField + " " + NotClause + " " + BetweenClause + " " + min + " " + AndClause + " " + max);
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

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaApplicationId()
{
    m_queryType = PragmaQuery;
    m_pragmaType = ApplicationId;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaAutoVacuum()
{
    m_queryType = PragmaQuery;
    m_pragmaType = AutoVacuum;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaAutomaticIndex()
{
    m_queryType = PragmaQuery;
    m_pragmaType = AutomaticIndex;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaBusyTimeout()
{
    m_queryType = PragmaQuery;
    m_pragmaType = BusyTimeout;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaCacheSize()
{
    m_queryType = PragmaQuery;
    m_pragmaType = CacheSize;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaCacheSpill()
{
    m_queryType = PragmaQuery;
    m_pragmaType = CacheSpill;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaCaseSensitiveLike()
{
    m_queryType = PragmaQuery;
    m_pragmaType = CaseSensitiveLike;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaCellSizeCheck()
{
    m_queryType = PragmaQuery;
    m_pragmaType = CellSizeCheck;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaCheckpointFullfsync()
{
    m_queryType = PragmaQuery;
    m_pragmaType = CheckpointFullfsync;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaCollationList()
{
    m_queryType = PragmaQuery;
    m_pragmaType = CollationList;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaCompileOptions()
{
    m_queryType = PragmaQuery;
    m_pragmaType = CompileOptions;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaDataVersion()
{
    m_queryType = PragmaQuery;
    m_pragmaType = DataVersion;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaDatabaseList()
{
    m_queryType = PragmaQuery;
    m_pragmaType = DatabaseList;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaDeferForeignKeys()
{
    m_queryType = PragmaQuery;
    m_pragmaType = DeferForeignKeys;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaEncoding()
{
    m_queryType = PragmaQuery;
    m_pragmaType = Encoding;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaForeignKeyCheck()
{
    m_queryType = PragmaQuery;
    m_pragmaType = ForeignKeyCheck;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaForeignKeyList()
{
    m_queryType = PragmaQuery;
    m_pragmaType = ForeignKeyList;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaForeignKeys()
{
    m_queryType = PragmaQuery;
    m_pragmaType = ForeignKeys;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaFreelistCount()
{
    m_queryType = PragmaQuery;
    m_pragmaType = FreelistCount;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaFullfsync()
{
    m_queryType = PragmaQuery;
    m_pragmaType = Fullfsync;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaIgnoreCheckConstraints()
{
    m_queryType = PragmaQuery;
    m_pragmaType = IgnoreCheckConstraints;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaIncrementalVacuum()
{
    m_queryType = PragmaQuery;
    m_pragmaType = IncrementalVacuum;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaIndexInfo()
{
    m_queryType = PragmaQuery;
    m_pragmaType = IndexInfo;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaIndexList()
{
    m_queryType = PragmaQuery;
    m_pragmaType = IndexList;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaIndexXinfo()
{
    m_queryType = PragmaQuery;
    m_pragmaType = IndexXinfo;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaIntegrityCheck()
{
    m_queryType = PragmaQuery;
    m_pragmaType = IntegrityCheck;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaJournalMode()
{
    m_queryType = PragmaQuery;
    m_pragmaType = JournalMode;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaJournalSizeLimit()
{
    m_queryType = PragmaQuery;
    m_pragmaType = JournalSizeLimit;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaLegacyFileFormat()
{
    m_queryType = PragmaQuery;
    m_pragmaType = LegacyFileFormat;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaLockingMode()
{
    m_queryType = PragmaQuery;
    m_pragmaType = LockingMode;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaMaxPageCount()
{
    m_queryType = PragmaQuery;
    m_pragmaType = MaxPageCount;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaMmapSize()
{
    m_queryType = PragmaQuery;
    m_pragmaType = MmapSize;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaPageCount()
{
    m_queryType = PragmaQuery;
    m_pragmaType = PageCount;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaPageSize()
{
    m_queryType = PragmaQuery;
    m_pragmaType = PageSize;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaParserTrace()
{
    m_queryType = PragmaQuery;
    m_pragmaType = ParserTrace;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaQuickCheck()
{
    m_queryType = PragmaQuery;
    m_pragmaType = QuickCheck;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaReadUncommitted()
{
    m_queryType = PragmaQuery;
    m_pragmaType = ReadUncommitted;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaRecursiveTriggers()
{
    m_queryType = PragmaQuery;
    m_pragmaType = RecursiveTriggers;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaReverseUnorderedSelects()
{
    m_queryType = PragmaQuery;
    m_pragmaType = ReverseUnorderedSelects;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaSchemaVersion()
{
    m_queryType = PragmaQuery;
    m_pragmaType = SchemaVersion;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaSecureDelete()
{
    m_queryType = PragmaQuery;
    m_pragmaType = SecureDelete;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaShrinkMemory()
{
    m_queryType = PragmaQuery;
    m_pragmaType = ShrinkMemory;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaSoftHeapLimit()
{
    m_queryType = PragmaQuery;
    m_pragmaType = SoftHeapLimit;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaStats()
{
    m_queryType = PragmaQuery;
    m_pragmaType = Stats;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaSynchronous()
{
    m_queryType = PragmaQuery;
    m_pragmaType = Synchronous;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaTableInfo(const string& table)
{
    m_queryType = PragmaQuery;
    m_pragmaType = TableInfo;
    m_pragma = table;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaTempStore()
{
    m_queryType = PragmaQuery;
    m_pragmaType = TempStore;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaThreads()
{
    m_queryType = PragmaQuery;
    m_pragmaType = Threads;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaUserVersion()
{
    m_queryType = PragmaQuery;
    m_pragmaType = UserVersion;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaVdbeAddoptrace()
{
    m_queryType = PragmaQuery;
    m_pragmaType = VdbeAddoptrace;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaVdbeDebug()
{
    m_queryType = PragmaQuery;
    m_pragmaType = VdbeDebug;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaVdbeListing()
{
    m_queryType = PragmaQuery;
    m_pragmaType = VdbeListing;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaVdbeTrace()
{
    m_queryType = PragmaQuery;
    m_pragmaType = VdbeTrace;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaWalAutocheckpoint()
{
    m_queryType = PragmaQuery;
    m_pragmaType = WalAutocheckpoint;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaWalCheckpoint()
{
    m_queryType = PragmaQuery;
    m_pragmaType = WalCheckpoint;
    return *this;
}

DataBaseQueryBuilder& DataBaseQueryBuilder::PragmaWritableSchema()
{
    m_queryType = PragmaQuery;
    m_pragmaType = WritableSchema;
    return *this;
}
