#include <string>

#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_

using namespace std;

typedef enum
{
    NonePragma = 0,
	ApplicationId,
	AutoVacuum,
	AutomaticIndex,
	BusyTimeout,
	CacheSize,
	CacheSpill,
	CaseSensitiveLike,
	CellSizeCheck,
	CheckpointFullfsync,
	CollationList,
	CompileOptions,
	DataVersion,
	DatabaseList,
	DeferForeignKeys,
	Encoding,
	ForeignKeyCheck,
	ForeignKeyList,
	ForeignKeys,
	FreelistCount,
	Fullfsync,
	IgnoreCheckConstraints,
	IndexInfo,
	IndexList,
	IndexXinfo,
	IncrementalVacuum,
    IntegrityCheck,
	JournalMode,
	JournalSizeLimit,
	LegacyFileFormat,
	LockingMode,
	MaxPageCount,
	MmapSize,
	PageCount,
	PageSize,
	ParserTrace,
	QuickCheck,
	ReadUncommitted,
	RecursiveTriggers,
	ReverseUnorderedSelects,
	SchemaVersion,
	SecureDelete,
	ShrinkMemory,
	SoftHeapLimit,
	Stats,
	Synchronous,
    TableInfo,
	TempStore,
	Threads,
	UserVersion,
	VdbeAddoptrace,
	VdbeDebug,
	VdbeListing,
	VdbeTrace,
	WalAutocheckpoint,
	WalCheckpoint,
	WritableSchema
} PragmaType;

typedef enum
{
    NoneAlterType = 0,
    RenameTo,
    AddColumn
} AlterType;

typedef enum
{
    NoneType_DropType = 0,
    Index_DropType,
    Table_DropType,
    Trigger_DropType,
    View_DropType
} DropType;

const string TerminationQueryCharacter = ";";
const string TableClause = "TABLE";
const string ViewClause = "VIEW";
const string TriggerClause = "TRIGGER";
const string IndexClause = "INDEX";
const string SelectClause = "SELECT";
const string DeleteClause = "DELETE";
const string InsertIntoClause = "INSERT INTO";
const string UpdateClause = "UPDATE";
const string DropClause = "DROP";
const string CreateClause = "CREATE";
const string AlterClause = "ALTER";
const string FromClause = "FROM";
const string JoinClause = "JOIN";
const string NaturalClause = "NATURAL";
const string OuterClause = "OUTER";
const string LeftClause = "LEFT";
const string CrossClause = "CROSS";
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
const string GroupByClause = "GROUP BY";
const string HavingClause = "HAVING";
const string OrderByClause = "ORDER BY";
const string AscClause = "ASC";
const string DescClause = "DESC";
const string DistinctClause = "DISTINCT";
const string InClause = "IN";
const string AsClause = "AS";
const string OnClause = "ON";
const string NotClause = "NOT";
const string BetweenClause = "BETWEEN";
const string IfExistsClause = "IF EXISTS";
const string IfNotExistsClause = "IF NOT EXISTS";
const string TemporaryClause = "TEMPORARY";
const string RenameToClause = "RENAME TO";
const string AddColumnClause = "ADD COLUMN";
const string PragmaClause = "PRAGMA";
const string UniqueClause = "UNIQUE";
const string BeginClause = "BEGIN";
const string EndClause = "END";
const string CommitClause = "COMMIT";
const string RollbackClause = "ROLLBACK";

#endif /* SRC_CONSTANTS_H_ */
