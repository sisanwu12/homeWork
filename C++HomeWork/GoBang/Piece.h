#pragma once
class Piece {
private:
	int x;
	int y;
	char style;
public:
	Piece(int x, int y,char style);
	Piece() {};
	int getX(int j);
	int getX();
	int getY(int i);
	int getY();
	char getStyle();
	void setPiece(int x, int y, char style);
	void setStyle(char style);
};