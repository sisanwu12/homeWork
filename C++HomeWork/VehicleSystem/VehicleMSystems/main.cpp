#include "Task.h"


int main() {
ADMININ:
	Parking& parking = Task::Init();
	if (parking.getPark().empty()) return 0;
	Task::Star(parking);
	goto ADMININ;
	return 0;
}