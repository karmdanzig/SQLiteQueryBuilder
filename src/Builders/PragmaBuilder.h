/*
 * PragmaBuilder.h
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_PRAGMABUILDER_H_
#define SRC_BUILDERS_PRAGMABUILDER_H_

#include "QueryBuilder.h"
#include "../Keywords/Pragma.h"

class PragmaBuilder : public QueryBuilder
{
private:

    PragmaType m_pragmaType;
    std::string m_pragmaValue;

public:

    PragmaBuilder();
    ~PragmaBuilder();

    PragmaBuilder& PragmaApplicationId();

    PragmaBuilder& PragmaAutoVacuum();

    PragmaBuilder& PragmaAutomaticIndex();

    PragmaBuilder& PragmaBusyTimeout();

    PragmaBuilder& PragmaCacheSize();

    PragmaBuilder& PragmaCacheSpill();

    PragmaBuilder& PragmaCaseSensitiveLike();

    PragmaBuilder& PragmaCellSizeCheck();

    PragmaBuilder& PragmaCheckpointFullfsync();

    PragmaBuilder& PragmaCollationList();

    PragmaBuilder& PragmaCompileOptions();

    PragmaBuilder& PragmaDataVersion();

    PragmaBuilder& PragmaDatabaseList();

    PragmaBuilder& PragmaDeferForeignKeys();

    PragmaBuilder& PragmaEncoding();

    PragmaBuilder& PragmaForeignKeyCheck();

    PragmaBuilder& PragmaForeignKeyList();

    PragmaBuilder& PragmaForeignKeys();

    PragmaBuilder& PragmaFreelistCount();

    PragmaBuilder& PragmaFullfsync();

    PragmaBuilder& PragmaIgnoreCheckConstraints();

    PragmaBuilder& PragmaIncrementalVacuum();

    PragmaBuilder& PragmaIndexInfo();

    PragmaBuilder& PragmaIndexList();

    PragmaBuilder& PragmaIndexXinfo();

    PragmaBuilder& PragmaIntegrityCheck();

    PragmaBuilder& PragmaJournalMode();

    PragmaBuilder& PragmaJournalSizeLimit();

    PragmaBuilder& PragmaLegacyFileFormat();

    PragmaBuilder& PragmaLockingMode();

    PragmaBuilder& PragmaMaxPageCount();

    PragmaBuilder& PragmaMmapSize();

    PragmaBuilder& PragmaPageCount();

    PragmaBuilder& PragmaPageSize();

    PragmaBuilder& PragmaParserTrace();

    PragmaBuilder& PragmaQuickCheck();

    PragmaBuilder& PragmaReadUncommitted();

    PragmaBuilder& PragmaRecursiveTriggers();

    PragmaBuilder& PragmaReverseUnorderedSelects();

    PragmaBuilder& PragmaSchemaVersion();

    PragmaBuilder& PragmaSecureDelete();

    PragmaBuilder& PragmaShrinkMemory();

    PragmaBuilder& PragmaSoftHeapLimit();

    PragmaBuilder& PragmaStats();

    PragmaBuilder& PragmaSynchronous();

    PragmaBuilder& PragmaTableInfo(const string& table);

    PragmaBuilder& PragmaTempStore();

    PragmaBuilder& PragmaThreads();

    PragmaBuilder& PragmaUserVersion();

    PragmaBuilder& PragmaVdbeAddoptrace();

    PragmaBuilder& PragmaVdbeDebug();

    PragmaBuilder& PragmaVdbeListing();

    PragmaBuilder& PragmaVdbeTrace();

    PragmaBuilder& PragmaWalAutocheckpoint();

    PragmaBuilder& PragmaWalCheckpoint();

    PragmaBuilder& PragmaWritableSchema();

    std::string Build();

};



#endif /* SRC_BUILDERS_PRAGMABUILDER_H_ */
