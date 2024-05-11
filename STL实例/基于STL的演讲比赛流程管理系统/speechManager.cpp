#include "speechManager.h"

SpeechManager::SpeechManager()
{
    initSpeakers();
}

SpeechManager::~SpeechManager()
{
    
}

void SpeechManager::initSpeakers()
{
    this->v1.clear();
    this->v2.clear();
    this->v.clear();
    this->speakers.clear();
}