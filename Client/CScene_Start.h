#pragma once
#include "CScene.h"
class CScene_Start : public CScene
{
public:
	CScene_Start();
	~CScene_Start();
public:
	virtual void update();
	void Enter() override;
	void Exit() override;
};

