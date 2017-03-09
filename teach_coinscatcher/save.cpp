#define _CRT_SECURE_NO_WARNINGS
#include "save.h"
#include <stdio.h>

const char * savingFileName = "game.sav";

void SaveGame(const GameSave& save)
{
	FILE * f = fopen(savingFileName, "wb");
	if (f == NULL)
	{
		return;
	}
	fwrite(&save, sizeof(GameSave), 1, f);
	fclose(f);
}

bool LoadGame(GameSave* sg)
{
	FILE * f = fopen(savingFileName, "rb");
	if (f == NULL)
	{
		return false;
	}
	size_t blocksReaded = fread(sg, sizeof(GameSave), 1, f);
	fclose(f);
	remove(savingFileName);
	if (blocksReaded == 1)
	{
		return true;
	}
	return false;
}

bool GameLoadAvailable()
{
	FILE * f = fopen(savingFileName, "r");
	if (f == NULL) {
		return false;
	}
	fclose(f);
	return true;
}
