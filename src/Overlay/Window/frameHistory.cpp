#include "frameHistory.h"
#include <cstddef>

PlayerState stateFrom(CharData &player) {
  PlayerState state = PlayerState::Idle;

  if (!isIdle(player)) {
    state = PlayerState::NonIdle;
  }

  return state;
}

StatePair FrameHistory::getPlayerStates(CharData &player1, CharData &player2) {
  return {stateFrom(player1), stateFrom(player2)};
}

void FrameHistory::updateHistory(CharData &player1, CharData &player2) {

  StatePair states = getPlayerStates(player1, player2);

  if (states == BOTH_IDLE) {
    // for the first case, keep the queue as it is. There is nothing of note
    // to write Signal to later calls that we have had both players be idle
    // before.
    is_old = true;
  } else {
    // if something is happening, push the info. But not before clearing out
    if (is_old) {
      // clear the queue
      size_t length = queue.size();
      for (size_t i = 0; i < length; i++) {
        queue.pop_front();
      }
    }

    if (queue.size() == HISTORY_DEPTH) {
      queue.pop_front();
    }
    queue.push_back(states);
    is_old = false;
  }
}

StatePairQueue &FrameHistory::read() { return queue; }

void FrameHistory::clear() {
    queue.clear();
}

FrameHistory::FrameHistory() {
  queue = std::deque<StatePair>();
  is_old = false;
}

FrameHistory::~FrameHistory() {}
