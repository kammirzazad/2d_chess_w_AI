#ifndef OTHERPIECES_H
#define OTHERPIECES_H

#include "Piece.h"

#define P_Pawn     2000
#define P_Rook     2001
#define P_Knight   2002
#define P_Bishop   2003
#define P_Queen    2004
#define P_King     2005

#define Selected          100
#define Selected_Attack   200
#define Selected_Maintain 300
#define Selected_Castle   400

#define White    true
#define Black    false

class Pawn: public Piece
{
    friend class Game;

	public:

	Pawn(int x, int y , int ID , bool color ) 
	:Piece(x,y,ID,color,P_Pawn)
	{

	}

	void Get_Pos_Loc(const Table &_table , int** temp)
	{
		temp[GetLoc().Get_X()][GetLoc().Get_Y()]=Selected_Maintain;

		if(_table.IsNull(GetLoc().Vertical(_info.color?1:-1)))
		{
			temp[GetLoc().Vertical(_info.color?1:-1).Get_X()][GetLoc().Vertical(_info.color?1:-1).Get_Y()]=Selected;

			if(_table.IsNull(GetLoc().Vertical(_info.color?2:-2)) && !_moved)
			{
				temp[GetLoc().Vertical(_info.color?2:-2).Get_X()][GetLoc().Vertical(_info.color?2:-2).Get_Y()]=Selected;
			}
		}

		if((!_table.IsNull(GetLoc().Oribp(_info.color?1:-1))) && GetLoc().Oribp(_info.color?1:-1).IsValid())
		{
			if(_table[GetLoc().Oribp(_info.color?1:-1)]!=GetInfo())
			{
				temp[GetLoc().Oribp(_info.color?1:-1).Get_X()][GetLoc().Oribp(_info.color?1:-1).Get_Y()]=Selected_Attack;
			}
		}

		if((!_table.IsNull(GetLoc().Oribm(_info.color?1:-1))) && GetLoc().Oribm(_info.color?1:-1).IsValid())
		{
			if(_table[GetLoc().Oribm(_info.color?1:-1)]!=GetInfo())
			{
				temp[GetLoc().Oribm(_info.color?1:-1).Get_X()][GetLoc().Oribm(_info.color?1:-1).Get_Y()]=Selected_Attack;
			}
		}
	}

};

class Rook: public Piece
{
    friend class Game;

	public:

	Rook(int x, int y , int ID , bool color)
	:Piece(x,y,ID,color,P_Rook)
	{

	}

	void Get_Pos_Loc(const Table &_table , int** temp)
	{
		temp[GetLoc().Get_X()][GetLoc().Get_Y()]=Selected_Maintain;

		for(int i=1 ;i<=GetLoc().HorizontalEndIndex() ;i++)
		{
	       if(_table.IsNull( GetLoc().Horizontal( i)))
		   {
			   temp[GetLoc().Horizontal(i).Get_X()][GetLoc().Horizontal(i).Get_Y()]=Selected;
		   }
		   else 
		   {
			   if(GetLoc().Horizontal(i).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Horizontal( i)])
					{
						temp[GetLoc().Horizontal(i).Get_X()][GetLoc().Horizontal(i).Get_Y()]=Selected_Attack;
					}
			   }
			   
			   break;
		   }
		}

		for(int i=-1 ; i>=GetLoc().HorizontalStartIndex() ;i--)
		{
	       if(_table.IsNull( GetLoc().Horizontal( i)))
		   {
			   temp[GetLoc().Horizontal(i).Get_X()][GetLoc().Horizontal(i).Get_Y()]=Selected;
		   }
		   else 
		   {
			   if(GetLoc().Horizontal(i).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Horizontal( i)])
					{
						temp[GetLoc().Horizontal(i).Get_X()][GetLoc().Horizontal(i).Get_Y()]=Selected_Attack;
					}
			   }
			   
			   break;
		   }
		}

		for(int j=1 ;j<=GetLoc().VerticalEndIndex() ;j++)
		{
	       if(_table.IsNull(GetLoc().Vertical( j)))
		   {
			   temp[GetLoc().Vertical(j).Get_X()][GetLoc().Vertical(j).Get_Y()]=Selected;
		   }
		   else
		   {
			   if(_loc.Vertical( j).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Vertical( j)])
					{
						 temp[GetLoc().Vertical(j).Get_X()][GetLoc().Vertical(j).Get_Y()]=Selected_Attack;
					}
			   }

			   break;
		   }
		}

		for(int j=-1;j>=GetLoc().VerticalStartIndex() ;j--)
		{
	       if(_table.IsNull(GetLoc().Vertical( j)))
		   {
			   temp[GetLoc().Vertical(j).Get_X()][GetLoc().Vertical(j).Get_Y()]=Selected;
		   }
		   else
		   {
			   if(_loc.Vertical( j).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Vertical( j)])
					{
						 temp[GetLoc().Vertical(j).Get_X()][GetLoc().Vertical(j).Get_Y()]=Selected_Attack;
					}
			   }

			   break;
		   }
		}
	}
};

class Knight: public Piece
{
    friend class Game;

	public:

	Knight(int x, int y , int ID , bool color)
	:Piece(x,y,ID,color,P_Knight)
	{

	}

	void Get_Pos_Loc(const Table &_table , int** temp)
	{
		temp[GetLoc().Get_X()][GetLoc().Get_Y()]=Selected_Maintain;

		//****************************************************************

		if(_table.IsNull(GetLoc().L_NE1()))
		{
			temp[GetLoc().L_NE1().Get_X()][GetLoc().L_NE1().Get_Y()]=Selected;
		}
		else if(GetLoc().L_NE1().IsValid())
		{
			if(GetInfo()!=_table[GetLoc().L_NE1()])
			{
				temp[GetLoc().L_NE1().Get_X()][GetLoc().L_NE1().Get_Y()]=Selected_Attack;
			}
		}

		//****************************************************************

		if(_table.IsNull(GetLoc().L_NE2()))
		{
			temp[GetLoc().L_NE2().Get_X()][GetLoc().L_NE2().Get_Y()]=Selected;
		}
		else if(GetLoc().L_NE2().IsValid())
		{
			if(GetInfo()!=_table[GetLoc().L_NE2()])
			{
				temp[GetLoc().L_NE2().Get_X()][GetLoc().L_NE2().Get_Y()]=Selected_Attack;
			}
		}

		//****************************************************************

		if(_table.IsNull(GetLoc().L_SE1()))
		{
			temp[GetLoc().L_SE1().Get_X()][GetLoc().L_SE1().Get_Y()]=Selected;
		}
		else if(GetLoc().L_SE1().IsValid())
		{
			if(GetInfo()!=_table[GetLoc().L_SE1()])
			{
				temp[GetLoc().L_SE1().Get_X()][GetLoc().L_SE1().Get_Y()]=Selected_Attack;
			}
		}

		//****************************************************************

		if(_table.IsNull(GetLoc().L_SE2()))
		{
			temp[GetLoc().L_SE2().Get_X()][GetLoc().L_SE2().Get_Y()]=Selected;
		}
		else if(GetLoc().L_SE2().IsValid())
		{
			if(GetInfo()!=_table[GetLoc().L_SE2()])
			{
				temp[GetLoc().L_SE2().Get_X()][GetLoc().L_SE2().Get_Y()]=Selected_Attack;
			}
		}

		//****************************************************************

		if(_table.IsNull(GetLoc().L_NW1()))
		{
			temp[GetLoc().L_NW1().Get_X()][GetLoc().L_NW1().Get_Y()]=Selected;
		}
		else if(GetLoc().L_NW1().IsValid())
		{
			if(GetInfo()!=_table[GetLoc().L_NW1()])
			{
				temp[GetLoc().L_NW1().Get_X()][GetLoc().L_NW1().Get_Y()]=Selected_Attack;
			}
		}

		//****************************************************************

		if(_table.IsNull(GetLoc().L_NW2()))
		{
			temp[GetLoc().L_NW2().Get_X()][GetLoc().L_NW2().Get_Y()]=Selected;
		}
		else if(GetLoc().L_NW2().IsValid())
		{
			if(GetInfo()!=_table[GetLoc().L_NW2()])
			{
				temp[GetLoc().L_NW2().Get_X()][GetLoc().L_NW2().Get_Y()]=Selected_Attack;
			}
		}
		
		//****************************************************************

		if(_table.IsNull(GetLoc().L_SW1()))
		{
			temp[GetLoc().L_SW1().Get_X()][GetLoc().L_SW1().Get_Y()]=Selected;
		}
		else if(GetLoc().L_SW1().IsValid())
		{
			if(GetInfo()!=_table[GetLoc().L_SW1()])
			{
				temp[GetLoc().L_SW1().Get_X()][GetLoc().L_SW1().Get_Y()]=Selected_Attack;
			}
		}

		//****************************************************************

		if(_table.IsNull(GetLoc().L_SW2()))
		{
			temp[GetLoc().L_SW2().Get_X()][GetLoc().L_SW2().Get_Y()]=Selected;
		}
		else if(GetLoc().L_SW2().IsValid())
		{
			if(GetInfo()!=_table[GetLoc().L_SW2()])
			{
				temp[GetLoc().L_SW2().Get_X()][GetLoc().L_SW2().Get_Y()]=Selected_Attack;
			}
		}

		//****************************************************************
	}
};

class Bishop: public Piece
{
    friend class Game;

	public:

	Bishop(int x, int y , int ID , bool color)
	:Piece(x,y,ID,color,P_Bishop)
	{

	}

	void Get_Pos_Loc(const Table &_table , int** temp)
	{
		temp[GetLoc().Get_X()][GetLoc().Get_Y()]=Selected_Maintain;

		for(int i=1 ; i<=GetLoc().OribpEndIndex() ;i++)
		{
	       if(_table.IsNull(GetLoc().Oribp( i)))
		   {
				temp[GetLoc().Oribp(i).Get_X()][GetLoc().Oribp(i).Get_Y()]=Selected;
		   }
		   else 
		   {
			   if(GetLoc().Oribp(i).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Oribp( i)])
					{
						temp[GetLoc().Oribp(i).Get_X()][GetLoc().Oribp(i).Get_Y()]=Selected_Attack;
					}
			   }

			   break;
		   }
		}

		for(int i=-1 ; i>=GetLoc().OribpStartIndex() ;i--)
		{
	       if(_table.IsNull(GetLoc().Oribp( i)))
		   {
				temp[GetLoc().Oribp(i).Get_X()][GetLoc().Oribp(i).Get_Y()]=Selected;
		   }
		   else 
		   {
			   if(GetLoc().Oribp( i).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Oribp( i)])
					{
						temp[GetLoc().Oribp(i).Get_X()][GetLoc().Oribp(i).Get_Y()]=Selected_Attack;
					}
			   }

			   break;
		   }
		}

		for(int i=1 ; i<=GetLoc().OribmEndIndex() ;i++)
		{
	       if(_table.IsNull(GetLoc().Oribm( i)))
		   {
				temp[GetLoc().Oribm(i).Get_X()][GetLoc().Oribm(i).Get_Y()]=Selected;
		   }
		   else 
		   {
			   if(GetLoc().Oribm( i).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Oribm( i)])
					{
						temp[GetLoc().Oribm(i).Get_X()][GetLoc().Oribm(i).Get_Y()]=Selected_Attack;
					}
			   }

			   break;
		   }
		}

		for(int i=-1 ; i>=GetLoc().OribmStartIndex() ; i--)
		{
	       if(_table.IsNull(GetLoc().Oribm( i)))
		   {
				temp[GetLoc().Oribm(i).Get_X()][GetLoc().Oribm(i).Get_Y()]=Selected;
		   }
		   else 
		   {
			   if(GetLoc().Oribm( i).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Oribm( i)])
					{
						temp[GetLoc().Oribm(i).Get_X()][GetLoc().Oribm(i).Get_Y()]=Selected_Attack;
					}
			   }

			   break;
		   }
		}

		
	}

};

class Queen: public Piece
{
    friend class Game;

	public:

	Queen(int x, int y , int ID , bool color)
	:Piece(x,y,ID,color,P_Queen)
	{

	}

	void Get_Pos_Loc(const Table &_table , int** temp)
	{
        temp[GetLoc().Get_X()][GetLoc().Get_Y()]=Selected_Maintain;

		for(int i=1 ;i<=GetLoc().HorizontalEndIndex() ;i++)
		{
	       if(_table.IsNull( GetLoc().Horizontal( i)))
		   {
			   temp[GetLoc().Horizontal(i).Get_X()][GetLoc().Horizontal(i).Get_Y()]=Selected;
		   }
		   else 
		   {
			   if(GetLoc().Horizontal(i).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Horizontal( i)])
					{
						temp[GetLoc().Horizontal(i).Get_X()][GetLoc().Horizontal(i).Get_Y()]=Selected_Attack;
					}
			   }
			   
			   break;
		   }
		}

		for(int i=-1 ; i>=GetLoc().HorizontalStartIndex() ;i--)
		{
	       if(_table.IsNull( GetLoc().Horizontal( i)))
		   {
			   temp[GetLoc().Horizontal(i).Get_X()][GetLoc().Horizontal(i).Get_Y()]=Selected;
		   }
		   else 
		   {
			   if(GetLoc().Horizontal(i).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Horizontal( i)])
					{
						temp[GetLoc().Horizontal(i).Get_X()][GetLoc().Horizontal(i).Get_Y()]=Selected_Attack;
					}
			   }
			   
			   break;
		   }
		}

		for(int j=1 ;j<=GetLoc().VerticalEndIndex() ;j++)
		{
	       if(_table.IsNull(GetLoc().Vertical( j)))
		   {
			   temp[GetLoc().Vertical(j).Get_X()][GetLoc().Vertical(j).Get_Y()]=Selected;
		   }
		   else
		   {
			   if(_loc.Vertical( j).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Vertical( j)])
					{
						 temp[GetLoc().Vertical(j).Get_X()][GetLoc().Vertical(j).Get_Y()]=Selected_Attack;
					}
			   }

			   break;
		   }
		}

		for(int j=-1;j>=GetLoc().VerticalStartIndex() ;j--)
		{
	       if(_table.IsNull(GetLoc().Vertical( j)))
		   {
			   temp[GetLoc().Vertical(j).Get_X()][GetLoc().Vertical(j).Get_Y()]=Selected;
		   }
		   else
		   {
			   if(_loc.Vertical( j).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Vertical( j)])
					{
						 temp[GetLoc().Vertical(j).Get_X()][GetLoc().Vertical(j).Get_Y()]=Selected_Attack;
					}
			   }

			   break;
		   }
		}

		for(int i=1 ; i<=GetLoc().OribpEndIndex() ;i++)
		{
	       if(_table.IsNull(GetLoc().Oribp( i)))
		   {
				temp[GetLoc().Oribp(i).Get_X()][GetLoc().Oribp(i).Get_Y()]=Selected;
		   }
		   else 
		   {
			   if(GetLoc().Oribp(i).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Oribp( i)])
					{
						temp[GetLoc().Oribp(i).Get_X()][GetLoc().Oribp(i).Get_Y()]=Selected_Attack;
					}
			   }

			   break;
		   }
		}

		for(int i=-1 ; i>=GetLoc().OribpStartIndex() ;i--)
		{
	       if(_table.IsNull(GetLoc().Oribp( i)))
		   {
				temp[GetLoc().Oribp(i).Get_X()][GetLoc().Oribp(i).Get_Y()]=Selected;
		   }
		   else 
		   {
			   if(GetLoc().Oribp( i).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Oribp( i)])
					{
						temp[GetLoc().Oribp(i).Get_X()][GetLoc().Oribp(i).Get_Y()]=Selected_Attack;
					}
			   }

			   break;
		   }
		}

		for(int i=1 ; i<=GetLoc().OribmEndIndex() ;i++)
		{
	       if(_table.IsNull(GetLoc().Oribm( i)))
		   {
				temp[GetLoc().Oribm(i).Get_X()][GetLoc().Oribm(i).Get_Y()]=Selected;
		   }
		   else 
		   {
			   if(GetLoc().Oribm( i).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Oribm( i)])
					{
						temp[GetLoc().Oribm(i).Get_X()][GetLoc().Oribm(i).Get_Y()]=Selected_Attack;
					}
			   }

			   break;
		   }
		}

		for(int i=-1 ; i>=GetLoc().OribmStartIndex() ; i--)
		{
	       if(_table.IsNull(GetLoc().Oribm( i)))
		   {
				temp[GetLoc().Oribm(i).Get_X()][GetLoc().Oribm(i).Get_Y()]=Selected;
		   }
		   else 
		   {
			   if(GetLoc().Oribm( i).IsValid())
			   {
					if(GetInfo()!=_table[GetLoc().Oribm( i)])
					{
						temp[GetLoc().Oribm(i).Get_X()][GetLoc().Oribm(i).Get_Y()]=Selected_Attack;
					}
			   }

			   break;
		   }
		}
	}
};

class King: public Piece
{
    friend class Game;

	public:

	King(int x, int y , int ID , bool color)
	:Piece(x,y,ID,color,P_King)
	{

	}

	void Get_Pos_Loc(const Table &_table , int** temp_table)
	{
		if(_table.IsSafe(GetLoc(),GetInfo().color))
        {
			temp_table[GetLoc().Get_X()][GetLoc().Get_Y()]=Selected_Maintain;
        }

		if(_table.IsSafe(GetLoc().Oribp(1),_info.color) )
		{
			if(_table.IsNull(GetLoc().Oribp(1)))
			{
				temp_table[GetLoc().Oribp(1).Get_X()][GetLoc().Oribp(1).Get_Y()]=Selected;
			}
			else if(_table[GetLoc().Oribp(1)]!=GetInfo())
			{
				temp_table[GetLoc().Oribp(1).Get_X()][GetLoc().Oribp(1).Get_Y()]=Selected_Attack;
			}
		}

	 	if(_table.IsSafe(GetLoc().Oribp(-1),_info.color) )
		{
			if(_table.IsNull(GetLoc().Oribp(-1)))
			{
				temp_table[GetLoc().Oribp(-1).Get_X()][GetLoc().Oribp(-1).Get_Y()]=Selected;
			}
			else if(_table[GetLoc().Oribp(-1)]!=GetInfo())
			{
				temp_table[GetLoc().Oribp(-1).Get_X()][GetLoc().Oribp(-1).Get_Y()]=Selected_Attack;
			}
		}

		if(_table.IsSafe(GetLoc().Oribm(1),_info.color) )
		{
			if(_table.IsNull(GetLoc().Oribm(1)))
			{
				temp_table[GetLoc().Oribm(1).Get_X()][GetLoc().Oribm(1).Get_Y()]=Selected;
			}
			else if(_table[GetLoc().Oribm(1)]!=GetInfo())
			{
				temp_table[GetLoc().Oribm(1).Get_X()][GetLoc().Oribm(1).Get_Y()]=Selected_Attack;
			}
		}

		if(_table.IsSafe(GetLoc().Oribm(-1),_info.color) )
		{
			if(_table.IsNull(GetLoc().Oribm(-1)))
			{
				temp_table[GetLoc().Oribm(-1).Get_X()][GetLoc().Oribm(-1).Get_Y()]=Selected;
			}
			else if(_table[GetLoc().Oribm(-1)]!=GetInfo())
			{
				temp_table[GetLoc().Oribm(-1).Get_X()][GetLoc().Oribm(-1).Get_Y()]=Selected_Attack;
			}
		}

		if(_table.IsSafe(GetLoc().Vertical(1),_info.color) )
		{
			if(_table.IsNull(GetLoc().Vertical(1)))
			{
				temp_table[GetLoc().Vertical(1).Get_X()][GetLoc().Vertical(1).Get_Y()]=Selected;
			}
			else if(_table[GetLoc().Vertical(1)]!=GetInfo())
			{
				temp_table[GetLoc().Vertical(1).Get_X()][GetLoc().Vertical(1).Get_Y()]=Selected_Attack;
			}
		}

		if(_table.IsSafe(GetLoc().Vertical(-1),_info.color) )
		{
			if(_table.IsNull(GetLoc().Vertical(-1)))
			{
				temp_table[GetLoc().Vertical(-1).Get_X()][GetLoc().Vertical(-1).Get_Y()]=Selected;
			}
			else if(_table[GetLoc().Vertical(-1)]!=GetInfo())
			{
				temp_table[GetLoc().Vertical(-1).Get_X()][GetLoc().Vertical(-1).Get_Y()]=Selected_Attack;
			}
		}

		if(_table.IsSafe(GetLoc().Horizontal(1),_info.color) )
		{
			if(_table.IsNull(GetLoc().Horizontal(1)))
			{
				temp_table[GetLoc().Horizontal(1).Get_X()][GetLoc().Horizontal(1).Get_Y()]=Selected;
			}
			else if(_table[GetLoc().Horizontal(1)]!=GetInfo())
			{
				temp_table[GetLoc().Horizontal(1).Get_X()][GetLoc().Horizontal(1).Get_Y()]=Selected_Attack;
			}
		}

		if(_table.IsSafe(GetLoc().Horizontal(-1),_info.color) )
		{
			if(_table.IsNull(GetLoc().Horizontal(-1)))
			{
				temp_table[GetLoc().Horizontal(-1).Get_X()][GetLoc().Horizontal(-1).Get_Y()]=Selected;
			}
			else if(_table[GetLoc().Horizontal(-1)]!=GetInfo())
			{
				temp_table[GetLoc().Horizontal(-1).Get_X()][GetLoc().Horizontal(-1).Get_Y()]=Selected_Attack;
			}
		}
	}
};

#endif OTHERPIECES_H
