#include "music.h"
void  play_music(const string& archiuMusica)
{
    PlaySound(archiuMusica.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}