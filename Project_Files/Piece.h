#ifndef  PIECE_H
#define  PIECE_H

#include "Table.h"
#include <fstream>
#include <sstream>

#define P_Pawn     2000
#define P_Rook     2001
#define P_Knight   2002
#define P_Bishop   2003
#define P_Queen    2004
#define P_King     2005

#define nnul              0
#define Selected          100
#define Selected_Attack   200
#define Selected_Maintain 300
#define Selected_Castle   400

#define White    true
#define Black    false

class Piece
{
    friend class Game;

    public:

    PieceInfo  _info;
	Location   _loc;
	bool       _moved;
	bool       _available;
	const int  _ID;

	Piece(int , int , int , bool , int );

	bool Match(int);

	bool MatchLocation(const Location &);

	void Move(int,int);

	Location GetLoc();

	PieceInfo& GetInfo();

	void Save(ofstream&);
	void Load(ifstream&);

	virtual void Get_Pos_Loc(const Table& , int** )   = 0;
};


#endif PIECE_H