#pragma once

#include <string>

//Entities which will contain varius states. In this case, a red & blue ghost

enum { ent_Red_Ghost, ent_Blue_Ghost};

inline std::string GetEntityName(int n)
{
	switch (n) {
	case ent_Red_Ghost:
		return "Red Ghost";
		break;

	case ent_Blue_Ghost:
		return "Blue Ghost";
		break;

	default:
		return "Unknown";
	}
}
