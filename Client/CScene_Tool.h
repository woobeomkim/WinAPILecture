#pragma once
#include "CScene.h"
class CScene_Tool :
    public CScene
{
public:

private:
    virtual void update();
    virtual void Enter();
    virtual void Exit();

public:
    CScene_Tool();
    ~CScene_Tool();
};

