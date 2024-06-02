#include "Task.h"


int main() {
ADMININ:
	Parking* parking = Task::Init();
	if (parking == nullptr) return 0;
	Task::Star(parking);
	goto ADMININ;
	return 0;
}