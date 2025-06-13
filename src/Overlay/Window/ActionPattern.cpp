#include "ActionPattern.h"
#include <cstdio>

#define MIN(x, y) (x < y ? x : y)

Action::Action(std::string action, bool is_new) {
  this->action = action;
  this->is_new = is_new;

}

const std::string ActionPattern::IDLE = std::string("IDLE");

Action Action::get_next_player_action(CharData* player) {
    // TODO: Change this to account for how many frames this action has been on. How many hits it got in, etc...
    std::string currentAction = std::string(player->currentAction);
    // Check if the action is new
    bool new_action = 0 == player->actionTime - 1;

    return Action(currentAction, new_action);
}


ActionPattern::ActionPattern(std::vector<std::string> pattern) {
  this->pattern = pattern;
  this->progress_index = 0;
}
ActionPattern::~ActionPattern() {}

/// Returns number of matched patterns
size_t ActionPattern::match_next(Action next_action) {
  if (pattern.size() <= progress_index) {
    if (next_action.action == ActionPattern::IDLE || !next_action.is_new) {
      return pattern.size();
    } else {
      progress_index = 0;
    }
  }
  if (next_action.is_new && next_action.action != ActionPattern::IDLE) {
    if (pattern[progress_index] == next_action.action) {
      progress_index += 1;
    } else {
      progress_index = 0;
    }
  } else {
  }
      return progress_index;
}

