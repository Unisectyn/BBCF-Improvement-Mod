#pragma once

#include "framedata.h"
#include <array>
#include <cstddef>
#include <deque>

// maximum number of frames to be kept track of in the history
const size_t HISTORY_DEPTH = 100;

enum PlayerState {
  NonIdle = 0,
  Idle = 1,
};

// TODO: Change this name
typedef std::array<PlayerState, 2> StatePair;
typedef std::deque<StatePair> StatePairQueue;

const StatePair BOTH_IDLE = {PlayerState::Idle, PlayerState::Idle};

struct FrameHistory {
public:
  FrameHistory();
  ~FrameHistory();

  // Update history with new data
  // Overwrites old history if both players have been previously idle
  void updateHistory(CharData &player1, CharData &player2);
  StatePairQueue &read();

private:
  StatePairQueue queue;
  bool is_old;

  StatePair getPlayerStates(CharData &player1, CharData &player2);
};
