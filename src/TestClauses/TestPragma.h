#include "gtest/gtest.h"
#include "../DataBaseQueryBuilder.h"

TEST(PragmaClause, TEST_PRAGMA_APPLICATION_ID)
{
    string query = DataBaseQueryBuilder().
    		PragmaApplicationId().
            Build();

    ASSERT_EQ("PRAGMA application_id;", query);
}

TEST(PragmaClause, TEST_PRAGMA_AUTO_VACUUM)
{
    string query = DataBaseQueryBuilder().
    		PragmaAutoVacuum().
            Build();

    ASSERT_EQ("PRAGMA auto_vacuum;", query);
}

TEST(PragmaClause, TEST_PRAGMA_AUTO_INDEX)
{
    string query = DataBaseQueryBuilder().
            PragmaAutomaticIndex().
            Build();

    ASSERT_EQ("PRAGMA automatic_index;", query);
}

TEST(PragmaClause, TEST_PRAGMA_BUSY_TIMEOUT)
{
    string query = DataBaseQueryBuilder().
            PragmaBusyTimeout().
            Build();

    ASSERT_EQ("PRAGMA busy_timeout;", query);
}

TEST(PragmaClause, TEST_PRAGMA_CACHE_SIZE)
{
    string query = DataBaseQueryBuilder().
            PragmaCacheSize().
            Build();

    ASSERT_EQ("PRAGMA cache_size;", query);
}

TEST(PragmaClause, TEST_PRAGMA_CACHE_SPILL)
{
    string query = DataBaseQueryBuilder().
            PragmaCacheSpill().
            Build();

    ASSERT_EQ("PRAGMA cache_spill;", query);
}

TEST(PragmaClause, TEST_PRAGMA_CASE_SENTITIVE_LIKE)
{
    string query = DataBaseQueryBuilder().
            PragmaCaseSensitiveLike().
            Build();

    ASSERT_EQ("PRAGMA case_sensitive_like;", query);
}

TEST(PragmaClause, TEST_PRAGMA_CELL_SIZE_CHECK)
{
    string query = DataBaseQueryBuilder().
            PragmaCellSizeCheck().
            Build();

    ASSERT_EQ("PRAGMA cell_size_check;", query);
}

TEST(PragmaClause, TEST_PRAGMA_CHECKPOINT_FULLFSYNC)
{
    string query = DataBaseQueryBuilder().
            PragmaCheckpointFullfsync().
            Build();

    ASSERT_EQ("PRAGMA checkpoint_fullfsync;", query);
}

TEST(PragmaClause, TEST_PRAGMA_COLLATION_LIST)
{
    string query = DataBaseQueryBuilder().
            PragmaCollationList().
            Build();

    ASSERT_EQ("PRAGMA collation_list;", query);
}

TEST(PragmaClause, TEST_PRAGMA_COMPILE_OPTIONS)
{
    string query = DataBaseQueryBuilder().
            PragmaCompileOptions().
            Build();

    ASSERT_EQ("PRAGMA compile_options;", query);
}

TEST(PragmaClause, TEST_PRAGMA_DATA_VERSION)
{
    string query = DataBaseQueryBuilder().
            PragmaDataVersion().
            Build();

    ASSERT_EQ("PRAGMA data_version;", query);
}

TEST(PragmaClause, TEST_PRAGMA_DATABASE_LIST)
{
    string query = DataBaseQueryBuilder().
            PragmaDatabaseList().
            Build();

    ASSERT_EQ("PRAGMA database_list;", query);
}

TEST(PragmaClause, TEST_PRAGMA_DEFER_FOREIGN_KEYS)
{
    string query = DataBaseQueryBuilder().
            PragmaDeferForeignKeys().
            Build();

    ASSERT_EQ("PRAGMA defer_foreign_keys;", query);
}

TEST(PragmaClause, TEST_PRAGMA_ENCODING)
{
    string query = DataBaseQueryBuilder().
            PragmaEncoding().
            Build();

    ASSERT_EQ("PRAGMA encoding;", query);
}

TEST(PragmaClause, TEST_PRAGMA_FOREIGN_KEY_CHECK)
{
    string query = DataBaseQueryBuilder().
            PragmaForeignKeyCheck().
            Build();

    ASSERT_EQ("PRAGMA foreign_key_check;", query);
}

TEST(PragmaClause, TEST_PRAGMA_FOREIGN_KEY_LIST)
{
    string query = DataBaseQueryBuilder().
            PragmaForeignKeyList().
            Build();

    ASSERT_EQ("PRAGMA foreign_key_list;", query);
}

TEST(PragmaClause, TEST_PRAGMA_FOREIGN_KEYS)
{
    string query = DataBaseQueryBuilder().
            PragmaForeignKeys().
            Build();

    ASSERT_EQ("PRAGMA foreign_keys;", query);
}

TEST(PragmaClause, TEST_PRAGMA_INTEGRITY_CHECK)
{
    string query = DataBaseQueryBuilder().
            PragmaIntegrityCheck().
            Build();

    ASSERT_EQ("PRAGMA integrity_check;", query);
}

TEST(PragmaClause, TEST_PRAGMA_TABLE_INFO)
{
    string query = DataBaseQueryBuilder().
            PragmaTableInfo("Table").
            Build();

    ASSERT_EQ("PRAGMA table_info(Table);", query);
}
