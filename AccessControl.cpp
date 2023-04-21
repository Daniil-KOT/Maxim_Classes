#include "AccessControl.h"

AccessControl::AccessControl()
{}

ResposeData AccessControl::BanUser(int sender, int user)
{
	ResposeData response;
	response.Response = "";
	response.Success = false;

	auto Sender = Database.find(sender);
	auto User = Database.find(user);

	if (Sender == Database.end() || User == Database.end())
	{
		response.Response = "ERROR: No such sender or user!";
		return response;
	}

	if (Sender->second != ROLE::Admin || Sender->second != ROLE::Moderator)
	{
		response.Response = "ERROR: Sender is not admin or moderator!";
		return response;
	}

	if (User->second == ROLE::Admin || User->second == ROLE::Moderator)
	{
		response.Response = "ERROR: User is admin or moderator!";
		return response;
	}

	User->second = ROLE::Banned;
	response.Response = "User " + std::to_string(user) + " banned.";
	response.Success = true;
	return response;
}

ResposeData AccessControl::UnBanUser(int sender, int user)
{
	ResposeData response;
	response.Response = "";
	response.Success = false;

	auto Sender = Database.find(sender);
	auto User = Database.find(user);

	if (Sender == Database.end() || User == Database.end())
	{
		response.Response = "ERROR: No such sender or user!";
		return response;
	}

	if (Sender->second != ROLE::Admin || Sender->second != ROLE::Moderator)
	{
		response.Response = "ERROR: Sender is not admin or moderator!";
		return response;
	}

	if (User->second != ROLE::Banned)
	{
		response.Response = "ERROR: User is not banned!";
		return response;
	}

	User->second = ROLE::User;
	response.Response = "User " + std::to_string(user) + " unbanned.";
	response.Success = true;
	return response;
}

ResposeData AccessControl::RegisterNewUser(int sender, int newUser)
{
	ResposeData response;
	response.Response = "";
	response.Success = false;

	return response;
}

ResposeData AccessControl::GrantModeratorRole(int sender, int user)
{
	ResposeData response;
	response.Response = "";
	response.Success = false;

	return response;
}

ResposeData AccessControl::GrantAdminRole(int sender, int user)
{
	ResposeData response;
	response.Response = "";
	response.Success = false;

	return response;
}

ResposeData AccessControl::AssignRole(int id, ROLE role)
{
	ResposeData response;
	response.Response = "";
	response.Success = false;

	auto Val = Database.find(id);

	if (Val == Database.end())
	{
		response.Success = Database.emplace(id, role).second;
	}
	else if (Val->second != role)
	{
		Val->second = role;
		response.Success = true;
	}

	if (response.Success == false)
		response.Response = "Unable to assign role! User not found or it has the same role.";

	return response;
}
