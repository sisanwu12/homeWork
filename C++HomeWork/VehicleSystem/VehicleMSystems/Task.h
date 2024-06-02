#pragma once
#include "Print.h"
#include "Analy.h"
#include "Parking.h"
#include "CarOrder.h"

class Task:public System {
public:
	static Parking* Init();
	static void Star(Parking* parking);
	static void End(Parking* parking);
};