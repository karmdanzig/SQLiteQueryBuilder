#include "gtest/gtest.h"
#include "../Builders/PragmaBuilder.h"

TEST(PragmaClause, TEST_PRAGMA_APPLICATION_ID)
{
    string query = PragmaBuilder().
    		PragmaApplicationId().
            Build();

    ASSERT_EQ("PRAGMA application_id;", query);
}

TEST(PragmaClause, TEST_PRAGMA_AUTO_VACUUM)
{
    string query = PragmaBuilder().
    		PragmaAutoVacuum().
            Build();

    ASSERT_EQ("PRAGMA auto_vacuum;", query);
}

TEST(PragmaClause, TEST_PRAGMA_AUTO_INDEX)
{
    string query = PragmaBuilder().
            PragmaAutomaticIndex().
            Build();

    ASSERT_EQ("PRAGMA automatic_index;", query);
}

TEST(PragmaClause, TEST_PRAGMA_BUSY_TIMEOUT)
{
    string query = PragmaBuilder().
            PragmaBusyTimeout().
            Build();

    ASSERT_EQ("PRAGMA busy_timeout;", query);
}

TEST(PragmaClause, TEST_PRAGMA_CACHE_SIZE)
{
    string query = PragmaBuilder().
            PragmaCacheSize().
            Build();

    ASSERT_EQ("PRAGMA cache_size;", query);
}

TEST(PragmaClause, TEST_PRAGMA_CACHE_SPILL)
{
    string query = PragmaBuilder().
            PragmaCacheSpill().
            Build();

    ASSERT_EQ("PRAGMA cache_spill;", query);
}

TEST(PragmaClause, TEST_PRAGMA_CASE_SENTITIVE_LIKE)
{
    string query = PragmaBuilder().
            PragmaCaseSensitiveLike().
            Build();

    ASSERT_EQ("PRAGMA case_sensitive_like;", query);
}

TEST(PragmaClause, TEST_PRAGMA_CELL_SIZE_CHECK)
{
    string query = PragmaBuilder().
            PragmaCellSizeCheck().
            Build();

    ASSERT_EQ("PRAGMA cell_size_check;", query);
}

TEST(PragmaClause, TEST_PRAGMA_CHECKPOINT_FULLFSYNC)
{
    string query = PragmaBuilder().
            PragmaCheckpointFullfsync().
            Build();

    ASSERT_EQ("PRAGMA checkpoint_fullfsync;", query);
}

TEST(PragmaClause, TEST_PRAGMA_COLLATION_LIST)
{
    string query = PragmaBuilder().
            PragmaCollationList().
            Build();

    ASSERT_EQ("PRAGMA collation_list;", query);
}

TEST(PragmaClause, TEST_PRAGMA_COMPILE_OPTIONS)
{
    string query = PragmaBuilder().
            PragmaCompileOptions().
            Build();

    ASSERT_EQ("PRAGMA compile_options;", query);
}

TEST(PragmaClause, TEST_PRAGMA_DATA_VERSION)
{
    string query = PragmaBuilder().
            PragmaDataVersion().
            Build();

    ASSERT_EQ("PRAGMA data_version;", query);
}

TEST(PragmaClause, TEST_PRAGMA_DATABASE_LIST)
{
    string query = PragmaBuilder().
            PragmaDatabaseList().
            Build();

    ASSERT_EQ("PRAGMA database_list;", query);
}

TEST(PragmaClause, TEST_PRAGMA_DEFER_FOREIGN_KEYS)
{
    string query = PragmaBuilder().
            PragmaDeferForeignKeys().
            Build();

    ASSERT_EQ("PRAGMA defer_foreign_keys;", query);
}

TEST(PragmaClause, TEST_PRAGMA_ENCODING)
{
    string query = PragmaBuilder().
            PragmaEncoding().
            Build();

    ASSERT_EQ("PRAGMA encoding;", query);
}

TEST(PragmaClause, TEST_PRAGMA_FOREIGN_KEY_CHECK)
{
    string query = PragmaBuilder().
            PragmaForeignKeyCheck().
            Build();

    ASSERT_EQ("PRAGMA foreign_key_check;", query);
}

TEST(PragmaClause, TEST_PRAGMA_FOREIGN_KEY_LIST)
{
    string query = PragmaBuilder().
            PragmaForeignKeyList().
            Build();

    ASSERT_EQ("PRAGMA foreign_key_list;", query);
}

TEST(PragmaClause, TEST_PRAGMA_FOREIGN_KEYS)
{
    string query = PragmaBuilder().
            PragmaForeignKeys().
            Build();

    ASSERT_EQ("PRAGMA foreign_keys;", query);
}

TEST(PragmaClause, TEST_PRAGMA_FREELIST_COUNT)
{
    string query = PragmaBuilder().
            PragmaFreelistCount().
            Build();

    ASSERT_EQ("PRAGMA freelist_count;", query);
}

TEST(PragmaClause, TEST_PRAGMA_FULLFSYNC)
{
    string query = PragmaBuilder().
            PragmaFullfsync().
            Build();

    ASSERT_EQ("PRAGMA fullfsync;", query);
}

TEST(PragmaClause, TEST_PRAGMA_IGNORE_CHECK_CONSTRAINTS)
{
    string query = PragmaBuilder().
            PragmaIgnoreCheckConstraints().
            Build();

    ASSERT_EQ("PRAGMA ignore_check_constraints;", query);
}

TEST(PragmaClause, TEST_PRAGMA_INCREMENTAL_VACUUM)
{
    string query = PragmaBuilder().
            PragmaIncrementalVacuum().
            Build();

    ASSERT_EQ("PRAGMA incremental_vacuum;", query);
}

TEST(PragmaClause, TEST_PRAGMA_INDEX_INFO)
{
    string query = PragmaBuilder().
            PragmaIndexInfo().
            Build();

    ASSERT_EQ("PRAGMA index_info;", query);
}

TEST(PragmaClause, TEST_PRAGMA_INDEX_LIST)
{
    string query = PragmaBuilder().
            PragmaIndexList().
            Build();

    ASSERT_EQ("PRAGMA index_list;", query);
}

TEST(PragmaClause, TEST_PRAGMA_INDEX_XINFO)
{
    string query = PragmaBuilder().
            PragmaIndexXinfo().
            Build();

    ASSERT_EQ("PRAGMA index_xinfo;", query);
}

TEST(PragmaClause, TEST_PRAGMA_INTEGRITY_CHECK)
{
    string query = PragmaBuilder().
            PragmaIntegrityCheck().
            Build();

    ASSERT_EQ("PRAGMA integrity_check;", query);
}

TEST(PragmaClause, TEST_PRAGMA_JOURNAL_MODE)
{
    string query = PragmaBuilder().
            PragmaJournalMode().
            Build();

    ASSERT_EQ("PRAGMA journal_mode;", query);
}

TEST(PragmaClause, TEST_PRAGMA_JOURNAL_SIZE_LIMIT)
{
    string query = PragmaBuilder().
            PragmaJournalSizeLimit().
            Build();

    ASSERT_EQ("PRAGMA journal_size_limit;", query);
}

TEST(PragmaClause, TEST_PRAGMA_LEGACY_FILE_FORMAT)
{
    string query = PragmaBuilder().
            PragmaLegacyFileFormat().
            Build();

    ASSERT_EQ("PRAGMA legacy_file_format;", query);
}

TEST(PragmaClause, TEST_PRAGMA_LOCKING_MODE)
{
    string query = PragmaBuilder().
            PragmaLockingMode().
            Build();

    ASSERT_EQ("PRAGMA locking_mode;", query);
}

TEST(PragmaClause, TEST_PRAGMA_MAX_PAGE_COUNT)
{
    string query = PragmaBuilder().
            PragmaMaxPageCount().
            Build();

    ASSERT_EQ("PRAGMA max_page_count;", query);
}

TEST(PragmaClause, TEST_PRAGMA_MMAP_SIZE)
{
    string query = PragmaBuilder().
            PragmaMmapSize().
            Build();

    ASSERT_EQ("PRAGMA mmap_size;", query);
}

TEST(PragmaClause, TEST_PRAGMA_PAGE_COUNT)
{
    string query = PragmaBuilder().
            PragmaPageCount().
            Build();

    ASSERT_EQ("PRAGMA page_count;", query);
}

TEST(PragmaClause, TEST_PRAGMA_PAGE_SIZE)
{
    string query = PragmaBuilder().
            PragmaPageSize().
            Build();

    ASSERT_EQ("PRAGMA page_size;", query);
}

TEST(PragmaClause, TEST_PRAGMA_PARSER_TRACE)
{
    string query = PragmaBuilder().
            PragmaParserTrace().
            Build();

    ASSERT_EQ("PRAGMA parser_trace;", query);
}

TEST(PragmaClause, TEST_PRAGMA_QUICK_CHECK)
{
    string query = PragmaBuilder().
            PragmaQuickCheck().
            Build();

    ASSERT_EQ("PRAGMA quick_check;", query);
}

TEST(PragmaClause, TEST_PRAGMA_READ_UNCOMMITTED)
{
    string query = PragmaBuilder().
            PragmaReadUncommitted().
            Build();

    ASSERT_EQ("PRAGMA read_uncommitted;", query);
}

TEST(PragmaClause, TEST_PRAGMA_RECURSIVE_TRIGGERS)
{
    string query = PragmaBuilder().
            PragmaRecursiveTriggers().
            Build();

    ASSERT_EQ("PRAGMA recursive_triggers;", query);
}

TEST(PragmaClause, TEST_PRAGMA_REVERSE_UNORDERED_SELECTS)
{
    string query = PragmaBuilder().
            PragmaReverseUnorderedSelects().
            Build();

    ASSERT_EQ("PRAGMA reverse_unordered_selects;", query);
}

TEST(PragmaClause, TEST_PRAGMA_SCHEMA_VERSION)
{
    string query = PragmaBuilder().
            PragmaSchemaVersion().
            Build();

    ASSERT_EQ("PRAGMA schema_version;", query);
}

TEST(PragmaClause, TEST_PRAGMA_SECURE_DELETE)
{
    string query = PragmaBuilder().
            PragmaSecureDelete().
            Build();

    ASSERT_EQ("PRAGMA secure_delete;", query);
}

TEST(PragmaClause, TEST_PRAGMA_SHRINK_MEMORY)
{
    string query = PragmaBuilder().
            PragmaShrinkMemory().
            Build();

    ASSERT_EQ("PRAGMA shrink_memory;", query);
}

TEST(PragmaClause, TEST_PRAGMA_SOFT_HEAP_LIMIT)
{
    string query = PragmaBuilder().
            PragmaSoftHeapLimit().
            Build();

    ASSERT_EQ("PRAGMA soft_heap_limit;", query);
}

TEST(PragmaClause, TEST_PRAGMA_STATS)
{
    string query = PragmaBuilder().
            PragmaStats().
            Build();

    ASSERT_EQ("PRAGMA stats;", query);
}

TEST(PragmaClause, TEST_PRAGMA_SYNCHRONOUS)
{
    string query = PragmaBuilder().
            PragmaSynchronous().
            Build();

    ASSERT_EQ("PRAGMA synchronous;", query);
}

TEST(PragmaClause, TEST_PRAGMA_TABLE_INFO)
{
    string query = PragmaBuilder().
            PragmaTableInfo("Table").
            Build();

    ASSERT_EQ("PRAGMA table_info(Table);", query);
}

TEST(PragmaClause, TEST_PRAGMA_TEMP_STORE)
{
    string query = PragmaBuilder().
            PragmaTempStore().
            Build();

    ASSERT_EQ("PRAGMA temp_store;", query);
}

TEST(PragmaClause, TEST_PRAGMA_THREADS)
{
    string query = PragmaBuilder().
            PragmaThreads().
            Build();

    ASSERT_EQ("PRAGMA threads;", query);
}

TEST(PragmaClause, TEST_PRAGMA_USER_VERSION)
{
    string query = PragmaBuilder().
            PragmaUserVersion().
            Build();

    ASSERT_EQ("PRAGMA user_version;", query);
}

TEST(PragmaClause, TEST_PRAGMA_VDBE_ADDOPTRACE)
{
    string query = PragmaBuilder().
            PragmaVdbeAddoptrace().
            Build();

    ASSERT_EQ("PRAGMA vdbe_addoptrace;", query);
}

TEST(PragmaClause, TEST_PRAGMA_VDBE_DEBUG)
{
    string query = PragmaBuilder().
            PragmaVdbeDebug().
            Build();

    ASSERT_EQ("PRAGMA vdbe_debug;", query);
}

TEST(PragmaClause, TEST_PRAGMA_VDBE_LISTING)
{
    string query = PragmaBuilder().
            PragmaVdbeListing().
            Build();

    ASSERT_EQ("PRAGMA vdbe_listing;", query);
}

TEST(PragmaClause, TEST_PRAGMA_VDBE_TRACE)
{
    string query = PragmaBuilder().
            PragmaVdbeTrace().
            Build();

    ASSERT_EQ("PRAGMA vdbe_trace;", query);
}

TEST(PragmaClause, TEST_PRAGMA_WAL_AUTOCHECKPOINT)
{
    string query = PragmaBuilder().
            PragmaWalAutocheckpoint().
            Build();

    ASSERT_EQ("PRAGMA wal_autocheckpoint;", query);
}

TEST(PragmaClause, TEST_PRAGMA_WAL_CHECKPOINT)
{
    string query = PragmaBuilder().
            PragmaWalCheckpoint().
            Build();

    ASSERT_EQ("PRAGMA wal_checkpoint;", query);
}

TEST(PragmaClause, TEST_PRAGMA_WRITABLE_SCHEMA)
{
    string query = PragmaBuilder().
            PragmaWritableSchema().
            Build();

    ASSERT_EQ("PRAGMA writable_schema;", query);
}
