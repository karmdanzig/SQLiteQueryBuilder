/*
 * Pragma.cpp
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#include "Pragma.h"

namespace Keys
{

Pragma::Pragma(const PragmaType& command)
: command(command)
{
    processKeyword();
}

Pragma::Pragma(const PragmaType& command, std::string pragmaValue)
: command(command), m_pragmaValue(pragmaValue)
{
    processKeyword();
}

Pragma::~Pragma()
{
}

void Pragma::processKeyword()
{
    m_completeKeyword = PragmaClause + " ";

    switch(command)
    {
        case NonePragma :
        {
            m_completeKeyword.append("");
            break;
        }
        case ApplicationId :
        {
            m_completeKeyword.append("application_id");
            break;
        }
        case AutoVacuum :
        {
            m_completeKeyword.append("auto_vacuum");
            break;
        }
        case AutomaticIndex :
        {
            m_completeKeyword.append("automatic_index");
            break;
        }
        case BusyTimeout :
        {
            m_completeKeyword.append("busy_timeout");
            break;
        }
        case CacheSize :
        {
            m_completeKeyword.append("cache_size");
            break;
        }
        case CacheSpill :
        {
            m_completeKeyword.append("cache_spill");
            break;
        }
        case CaseSensitiveLike :
        {
            m_completeKeyword.append("case_sensitive_like");
            break;
        }
        case CellSizeCheck :
        {
            m_completeKeyword.append("cell_size_check");
            break;
        }
        case CheckpointFullfsync :
        {
            m_completeKeyword.append("checkpoint_fullfsync");
            break;
        }
        case CollationList :
        {
            m_completeKeyword.append("collation_list");
            break;
        }
        case CompileOptions :
        {
            m_completeKeyword.append("compile_options");
            break;
        }
        case DataVersion :
        {
            m_completeKeyword.append("data_version");
            break;
        }
        case DatabaseList :
        {
            m_completeKeyword.append("database_list");
            break;
        }
        case DeferForeignKeys :
        {
            m_completeKeyword.append("defer_foreign_keys");
            break;
        }
        case Encoding :
        {
            m_completeKeyword.append("encoding");
            break;
        }
        case ForeignKeyCheck :
        {
            m_completeKeyword.append("foreign_key_check");
            break;
        }
        case ForeignKeyList :
        {
            m_completeKeyword.append("foreign_key_list");
            break;
        }
        case ForeignKeys :
        {
            m_completeKeyword.append("foreign_keys");
            break;
        }
        case FreelistCount :
        {
            m_completeKeyword.append("freelist_count");
            break;
        }
        case Fullfsync :
        {
            m_completeKeyword.append("fullfsync");
            break;
        }
        case IgnoreCheckConstraints :
        {
            m_completeKeyword.append("ignore_check_constraints");
            break;
        }
        case IncrementalVacuum :
        {
            m_completeKeyword.append("incremental_vacuum");
            break;
        }
        case IndexInfo :
        {
            m_completeKeyword.append("index_info");
            break;
        }
        case IndexList :
        {
            m_completeKeyword.append("index_list");
            break;
        }
        case IndexXinfo :
        {
            m_completeKeyword.append("index_xinfo");
            break;
        }
        case IntegrityCheck :
        {
            m_completeKeyword.append("integrity_check");
            break;
        }
        case JournalMode :
        {
            m_completeKeyword.append("journal_mode");
            break;
        }
        case JournalSizeLimit :
        {
            m_completeKeyword.append("journal_size_limit");
            break;
        }
        case LegacyFileFormat :
        {
            m_completeKeyword.append("legacy_file_format");
            break;
        }
        case LockingMode :
        {
            m_completeKeyword.append("locking_mode");
            break;
        }
        case MaxPageCount :
        {
            m_completeKeyword.append("max_page_count");
            break;
        }
        case MmapSize :
        {
            m_completeKeyword.append("mmap_size");
            break;
        }
        case PageCount :
        {
            m_completeKeyword.append("page_count");
            break;
        }
        case PageSize :
        {
            m_completeKeyword.append("page_size");
            break;
        }
        case ParserTrace :
        {
            m_completeKeyword.append("parser_trace");
            break;
        }
        case QuickCheck :
        {
            m_completeKeyword.append("quick_check");
            break;
        }
        case ReadUncommitted :
        {
            m_completeKeyword.append("read_uncommitted");
            break;
        }
        case RecursiveTriggers :
        {
            m_completeKeyword.append("recursive_triggers");
            break;
        }
        case ReverseUnorderedSelects :
        {
            m_completeKeyword.append("reverse_unordered_selects");
            break;
        }
        case SchemaVersion :
        {
            m_completeKeyword.append("schema_version");
            break;
        }
        case SecureDelete :
        {
            m_completeKeyword.append("secure_delete");
            break;
        }
        case ShrinkMemory :
        {
            m_completeKeyword.append("shrink_memory");
            break;
        }
        case SoftHeapLimit :
        {
            m_completeKeyword.append("soft_heap_limit");
            break;
        }
        case Stats :
        {
            m_completeKeyword.append("stats");
            break;
        }
        case Synchronous :
        {
            m_completeKeyword.append("synchronous");
            break;
        }
        case TableInfo :
        {
            m_completeKeyword.append("table_info(" + m_pragmaValue + ")");
            break;
        }
        case TempStore :
        {
            m_completeKeyword.append("temp_store");
            break;
        }
        case Threads :
        {
            m_completeKeyword.append("threads");
            break;
        }
        case UserVersion :
        {
            m_completeKeyword.append("user_version");
            break;
        }
        case VdbeAddoptrace :
        {
            m_completeKeyword.append("vdbe_addoptrace");
            break;
        }
        case VdbeDebug :
        {
            m_completeKeyword.append("vdbe_debug");
            break;
        }
        case VdbeListing :
        {
            m_completeKeyword.append("vdbe_listing");
            break;
        }
        case VdbeTrace :
        {
            m_completeKeyword.append("vdbe_trace");
            break;
        }
        case WalAutocheckpoint :
        {
            m_completeKeyword.append("wal_autocheckpoint");
            break;
        }
        case WalCheckpoint :
        {
            m_completeKeyword.append("wal_checkpoint");
            break;
        }
        case WritableSchema :
        {
            m_completeKeyword.append("writable_schema");
            break;
        }
    }

}

}
