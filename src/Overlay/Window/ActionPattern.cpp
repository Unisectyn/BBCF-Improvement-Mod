#include "ActionPattern.h"
#include <cstdio>

#define MIN(x, y) (x < y ? x : y)

// for patterns
Action::Action(std::string action, std::string display_name, ActionResult result=ActionResult::Hit, bool is_new=true) {
  this->action = action;
  this->is_new = is_new;
  this->display_name = display_name;
  this->result = result;
}

// for input
Action::Action(std::string action, bool is_new, ActionResult result) {
  this->action = action;
  this->is_new = is_new;
  this->display_name = std::string();
  this->result = result;
}

const std::string ActionPattern::IDLE = std::string("IDLE");

Action Action::get_next_player_action(CharData* player) {
    // TODO: Change this to account for how many frames this action has been on. How many hits it got in, etc...
    std::string currentAction = std::string(player->currentAction);
    // Check if the action is new
    bool new_action = 0 == player->actionTime - 1;

    return Action(currentAction, new_action);
}


ActionPattern::ActionPattern(std::string name, std::vector<Action> pattern) {
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
    Action action_to_check = pattern[progress_index];
    if (action_to_check.action == next_action.action && action_to_check.is_new == next_action.is_new) {
      progress_index += 1;
    } else {
      progress_index = 0;
    }
  } else {
  }
      return progress_index;
}

