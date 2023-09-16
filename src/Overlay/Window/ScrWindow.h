#pragma once
#include "IWindow.h"
#include <vector>
#include "Game/Scr/ScrStateReader.h"
#include "Game/Playbacks/PlaybackManager.h"
class ScrWindow : public IWindow
{
public:
	ScrWindow(const std::string& windowTitle, bool windowClosable,
		ImGuiWindowFlags windowFlags = 0)
		: IWindow(windowTitle, windowClosable, windowFlags) {}
	~ScrWindow() override = default;

protected:
	void Draw() override;

	void swap_character_coordinates();

private:
	void DrawGenericOptionsSection();
	void DrawStatesSection();
	void draw_playback_slot_section(int slot);
	void DrawPlaybackSection();
	void DrawReplayTheaterSection();
	void DrawReplayRewind();
	void DrawVeryExperimentalSection2();
	void DrawRoomSection();
	PlaybackManager playback_manager;
	bool m_showDemoWindow = false;
	void* p2_old_char_data = NULL;
	std::vector<scrState*> gap_register{};
	std::vector<int> gap_register_delays{};
	std::vector<scrState*> wakeup_register{};
	std::vector<int> wakeup_register_delays{};
	std::vector<scrState*> onhit_register{};
	std::vector<int> onhit_register_delays{};
	std::vector<scrState*> throwtech_register{};
	std::vector<int> throwtech_register_delays{};
	scrState* burst_action;
	scrState* air_burst_action;



	int states_wakeup_random_pos = 0;
	int states_gap_random_pos = 0;
	int states_onhit_random_pos = 0;
	int states_throwtech_random_pos = 0;


	int frame_to_burst_onhit;
	int states_wakeup_frame_to_do_action = 0;
	int states_gap_frame_to_do_action = 0;
	int states_throwtech_frame_to_do_action = 0;


	char fpath_s1[1200] = "fpath";
	char fpath_s2[1200] = "fpath";
	char fpath_s3[1200] = "fpath";
	char fpath_s4[1200] = "fpath";
	int slot_gap = 0; //0 for disabled, 1 for slot 1, 2 for slot 2, etc
	int slot_wakeup = 0; //0 for disabled, 1 for slot 1, 2 for slot 2, etc
	int slot_onblock = 0; //0 for disabled, 1 for slot 1, 2 for slot 2, etc
	int slot_onhit = 0; //0 for disabled, 1 for slot 1, 2 for slot 2, etc
	int slot_throwtech = 0; //0 for disabled, 1 for slot 1, 2 for slot 2, etc
	
	bool random_gap_slot1 = false;
	bool random_gap_slot2 = false;
	bool random_gap_slot3 = false;
	bool random_gap_slot4 = false;

	bool random_wakeup_slot1 = false;
	bool random_wakeup_slot2 = false;
	bool random_wakeup_slot3 = false;
	bool random_wakeup_slot4 = false;
	std::vector<int> slot_buffer{ 0,0,0,0 }; //holds the amount of frames each slot should buffer their actions for before coming out of hitstun(not implemented) or being able to act after waking up
	std::vector<int> random_gap{}; //holds the slots to be random for gap
	std::vector<int> random_wakeup{}; //holds the slots to be random for wakeup

	std::string prev_action;
};