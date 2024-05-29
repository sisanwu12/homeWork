#pragma once
#include "Print.h"
#include "Analy.h"
#include "Parking.h"
#include "CarOrder.h"

class Task:public System {
public:
	static void Init();
	static void Star();
	static void End();
};