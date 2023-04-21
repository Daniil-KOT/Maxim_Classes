#pragma once

#include "common.h"

class AccessControl
{
public:

    ResposeData AssignRole(int id, ROLE role);
	ResposeData BanUser(int sender, int user);
	ResposeData UnBanUser(int sender, int user);
	ResposeData RegisterNewUser(int sender, int newUser);
	ResposeData GrantModeratorRole(int sender, int user);
	ResposeData GrantAdminRole(int sender, int user);
    AccessControl();
};
