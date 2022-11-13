#pragma once

#include "testconf.h"

namespace janus {

#ifdef RAFT_TEST_CORO

class KvServer;
class ShardMasterServiceImpl;
class RaftLabTest {
 public:
  KvServer* kv_svr_{nullptr};
  ShardMasterServiceImpl* sm_svr_{nullptr};
 private:
  RaftTestConfig *config_;
  uint64_t index_;
  uint64_t init_rpcs_;
  // int32_t kv_test_cnt_{0};

 public:
  RaftLabTest(RaftTestConfig *config) : config_(config), index_(1) {}
  int Run(void);
  int RunShard(void);
  int RunKv(void);
  int RunRaft(void);
  int GenericKvTest(int n_cli, bool unreliable, uint64_t timeout=3000000, int leader = 0);
  void Cleanup(void);

 private:

  int testInitialElection(void);
  int testReElection(void);

  int testBasicAgree(void);
  int testFailAgree(void);
  int testFailNoAgree(void);
  int testRejoin(void);
  int testConcurrentStarts(void);
  int testBackup(void);
  int testCount(void);

  int testUnreliableAgree(void);
  int testFigure8(void);

  int testKvBasic(void);
  int testKvConcurrent(void);
  int testKvMajority(void);
  int testKvMajorityConcurrent(void);
  int testKvMajorityConcurrentSameKey(void);
  int testKvMajorityConcurrentLinear(void);
  int testKvMinority(void);
  int testKvReElection(void);
  int testKvUnreliable(void);

  int testShardBasic(void);
  int testShardConcurrent(void);
  int testShardMinimalTransferJoin(void);
  int testShardMinimalTransferLeave(void);

  void checkShardBasic(const map<uint32_t, vector<uint32_t>>& group_servers={});

  void wait(uint64_t microseconds);

};

#endif

} // namespace janus
