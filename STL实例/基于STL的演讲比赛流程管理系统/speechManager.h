#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "sperker.h"
using namespace std;

class SpeechManager
{
public:
    // 构造函数
    SpeechManager();

    // 目录
    void Menu();

    // 初始化
    void initSpeakers();

    // 析构函数
    ~SpeechManager();

    vector<int> v1;
    vector<int> v2;
    vector<int> v;

    map<int, Sperker> speakers;
};