

struct GameSave
{
	int Px, Py, Cx, Cy;
	int Timer, Coins;
};


void SaveGame(const GameSave& save);
bool LoadGame(GameSave* sg);
bool GameLoadAvailable();
