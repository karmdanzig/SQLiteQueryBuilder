/*
 * TestCommit.h
 *
 *  Created on: 4 Nov 2016
 *      Author: porcellic
 */

#ifndef SRC_UNITTESTS_TESTCOMMIT_H_
#define SRC_UNITTESTS_TESTCOMMIT_H_

#include "gtest/gtest.h"
#include "../Builders/CommitBuilder.h"

TEST(Commit, TEST_COMMIT)
{
    string query = CommitBuilder().
            Commit().
            Build();

    ASSERT_EQ("COMMIT;", query);
}




#endif /* SRC_UNITTESTS_TESTCOMMIT_H_ */
