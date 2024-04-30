#include "Count.h"

vector<Piece>& Count::getBlack() {
	return this->black;
}
vector<Piece>& Count::getWhite() {
	return this->white;
}
void Count::pushBlack(Piece& piece) {
	black.push_back(piece);
}
void Count::pushWhite(Piece& piece) {
	white.push_back(piece);
}