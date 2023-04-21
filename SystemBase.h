#pragma once

#include "common.h"

class SystemBase {
public:
	SystemBase(int admin);
	ResposeData BanUser(int sender, int user);
	ResposeData UnBanUser(int sender, int user);
	ResposeData RegisterNewUser(int sender, int newUser);
	ResposeData GrantModeratorRole(int sender, int user);
	ResposeData GrantAdminRole(int sender, int user);
	ResposeData StopChat(int sender);
	ResposeData ResumeChat(int sender);
};
