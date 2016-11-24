#include "stdafx.h"
#include "Piece.h"

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
#define Attack_King       400
#define Attack_Queen      500

#define White    true
#define Black    false


	Piece::Piece(int x , int y , int ID , bool color , int type)
	:_loc(x,y),_ID(ID),_info(type,color),_moved(false),_available(true)
	{

	}

	bool Piece::Match(int selected_ID)
	{
        if(selected_ID==_ID && _info.type!=nnul)
        {
            return true;
        }
        else
        {
            return false;
        }
	}

	bool Piece::MatchLocation(const Location &arg)
	{
		return ( this->GetLoc().Get_X()==arg.Get_X() && this->GetLoc().Get_Y()==arg.Get_Y() );
	}


	void Piece::Move(int X_Des , int Y_Des)
	{
	    _loc.Set(X_Des,Y_Des);
		_moved=true;
	}

	Location Piece::GetLoc()
	{
		return _loc;
	}

	PieceInfo& Piece::GetInfo()
	{
		return _info;
	}
	
	void Piece::Save(ofstream &stream)
	{
		stream<<_info.type<<"  "<<GetLoc().Get_X()<<"  "<<GetLoc().Get_Y()<<"   "<<_moved<<" "<<_available<<endl;
	}

	void Piece::Load(ifstream &stream)
	{
		stream>>_info.type;
		_loc.Load(stream);
		stream>>_moved;
		stream>>_available;
	}

	