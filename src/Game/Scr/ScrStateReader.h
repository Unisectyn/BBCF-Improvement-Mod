#pragma once

#include <vector>
#include <string>

#include "ScrStateEntry.h"


std::vector<scrState*> parse_scr(char* bbcf_base_addr, int player_num);
int parse_state(char* addr, std::vector<scrState*>& states_parsed);
void override_state(char* addr, char* new_state);