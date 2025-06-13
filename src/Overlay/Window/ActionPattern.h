#pragma once

#include "Core/interfaces.h"
#include "Core/utils.h"
#include "Game/CharData.h"
#include "Game/Jonb/JonbDBReader.h"
#include "Game/Scr/ScrStateReader.h"
#include "imgui.h"
#include <array>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <string>
#include <vector>


struct Action {
    std::string action;
    bool is_new;
    Action(std::string, bool);
    static Action get_next_player_action(CharData* player);
};


struct ActionPattern {
public:
    const static std::string IDLE;
    ActionPattern(std::vector<std::string> pattern);
    ~ActionPattern();


    size_t match_next(Action action);
    // pattern
    // Think about adding duration to the pattern,
    // or something to encode number of hits
    std::vector<std::string> pattern;
    
    size_t progress_index;
};
