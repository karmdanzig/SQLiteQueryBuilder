/*
 * PragmaBuilder.cpp
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#include "PragmaBuilder.h"

PragmaBuilder& PragmaBuilder::PragmaApplicationId()
{
    m_pragmaType = ApplicationId;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaAutoVacuum()
{
    m_pragmaType = AutoVacuum;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaAutomaticIndex()
{
    m_pragmaType = AutomaticIndex;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaBusyTimeout()
{
    m_pragmaType = BusyTimeout;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaCacheSize()
{
    m_pragmaType = CacheSize;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaCacheSpill()
{
    m_pragmaType = CacheSpill;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaCaseSensitiveLike()
{
    m_pragmaType = CaseSensitiveLike;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaCellSizeCheck()
{
    m_pragmaType = CellSizeCheck;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaCheckpointFullfsync()
{
    m_pragmaType = CheckpointFullfsync;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaCollationList()
{
    m_pragmaType = CollationList;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaCompileOptions()
{
    m_pragmaType = CompileOptions;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaDataVersion()
{
    m_pragmaType = DataVersion;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaDatabaseList()
{
    m_pragmaType = DatabaseList;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaDeferForeignKeys()
{
    m_pragmaType = DeferForeignKeys;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaEncoding()
{
    m_pragmaType = Encoding;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaForeignKeyCheck()
{
    m_pragmaType = ForeignKeyCheck;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaForeignKeyList()
{
    m_pragmaType = ForeignKeyList;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaForeignKeys()
{
    m_pragmaType = ForeignKeys;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaFreelistCount()
{
    m_pragmaType = FreelistCount;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaFullfsync()
{
    m_pragmaType = Fullfsync;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaIgnoreCheckConstraints()
{
    m_pragmaType = IgnoreCheckConstraints;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaIncrementalVacuum()
{
    m_pragmaType = IncrementalVacuum;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaIndexInfo()
{
    m_pragmaType = IndexInfo;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaIndexList()
{
    m_pragmaType = IndexList;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaIndexXinfo()
{
    m_pragmaType = IndexXinfo;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaIntegrityCheck()
{
    m_pragmaType = IntegrityCheck;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaJournalMode()
{
    m_pragmaType = JournalMode;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaJournalSizeLimit()
{
    m_pragmaType = JournalSizeLimit;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaLegacyFileFormat()
{
    m_pragmaType = LegacyFileFormat;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaLockingMode()
{
    m_pragmaType = LockingMode;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaMaxPageCount()
{
    m_pragmaType = MaxPageCount;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaMmapSize()
{
    m_pragmaType = MmapSize;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaPageCount()
{
    m_pragmaType = PageCount;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaPageSize()
{
    m_pragmaType = PageSize;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaParserTrace()
{
    m_pragmaType = ParserTrace;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaQuickCheck()
{
    m_pragmaType = QuickCheck;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaReadUncommitted()
{
    m_pragmaType = ReadUncommitted;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaRecursiveTriggers()
{
    m_pragmaType = RecursiveTriggers;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaReverseUnorderedSelects()
{
    m_pragmaType = ReverseUnorderedSelects;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaSchemaVersion()
{
    m_pragmaType = SchemaVersion;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaSecureDelete()
{
    m_pragmaType = SecureDelete;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaShrinkMemory()
{
    m_pragmaType = ShrinkMemory;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaSoftHeapLimit()
{
    m_pragmaType = SoftHeapLimit;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaStats()
{
    m_pragmaType = Stats;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaSynchronous()
{
    m_pragmaType = Synchronous;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaTableInfo(const string& table)
{
    m_pragmaType = TableInfo;
    //m_pragma = table;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaTempStore()
{
    m_pragmaType = TempStore;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaThreads()
{
    m_pragmaType = Threads;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaUserVersion()
{
    m_pragmaType = UserVersion;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaVdbeAddoptrace()
{
    m_pragmaType = VdbeAddoptrace;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaVdbeDebug()
{
    m_pragmaType = VdbeDebug;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaVdbeListing()
{
    m_pragmaType = VdbeListing;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaVdbeTrace()
{
    m_pragmaType = VdbeTrace;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaWalAutocheckpoint()
{
    m_pragmaType = WalAutocheckpoint;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaWalCheckpoint()
{
    m_pragmaType = WalCheckpoint;
    return *this;
}

PragmaBuilder& PragmaBuilder::PragmaWritableSchema()
{
    m_pragmaType = WritableSchema;
    return *this;
}
