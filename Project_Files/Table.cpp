#include "stdafx.h"
#include "Table.h"


PieceInfo::PieceInfo(int _type , bool _color)
		{
			type=_type;
			color=_color;
		}

PieceInfo::operator int () const
		{
			return type;
		}

PieceInfo::operator bool() const
		{
			return type==nnul;
		}

PieceInfo& PieceInfo::operator=(const PieceInfo arg)
		{
			this->type=arg.type;
			this->color=arg.color;
			return *this;
		}

bool PieceInfo::operator==(const PieceInfo& arg)
		{
			return color==arg.color;
		}

bool PieceInfo::operator!=(const PieceInfo& arg)
		{
			return color!=arg.color;
		}

void PieceInfo::Set(int _type , bool _color)
		{
			type=_type;
			color=_color;
		}

Location::Location(int x,int y)
	{
		if(-1<x && x<8)
		{
			column=x;
		}
		else
		{
			column=-1;
		}

		if(-1<y && y<8)
		{
			row=y;
		}
		else
		{
			row=-1;
		}
	}

Location Location::L_NE1() const
	{
		Location temp(column+1,row+2);
		return temp;
	}
Location Location::L_NE2() const
	{
		Location temp(column+2,row+1);
		return temp;
	}
Location Location::L_SE1() const
	{
		Location temp(column-1,row+2);
		return temp;
	}
Location Location::L_SE2() const
	{
		Location temp(column-2,row+1);
		return temp;
	}
Location Location::L_NW1() const
	{
		Location temp(column+1,row-2);
		return temp;
	}
Location Location::L_NW2() const
	{
		Location temp(column+2,row-1);
		return temp;
	}
Location Location::L_SW1() const
	{
		Location temp(column-1,row-2);
		return temp;
	}
Location Location::L_SW2() const
	{
		Location temp(column-2,row-1);
		return temp;
	}

int Location::Get_X() const
	{
		return column;
	}
int Location::Get_Y() const
	{
		return row;
	}

Location Location::Oribp     (int i) const
	{
		Location temp(column+i,row+i);
		return temp;
	}
Location Location::Oribm     (int i) const
	{
		Location temp(column-i,row+i);
		return temp;
	}
Location Location::Vertical  (int i) const
	{
		Location temp(column,row+i);
		return temp;
	}
Location Location::Horizontal(int i) const
	{
		Location temp(column+i,row);
		return temp;
	}

int  Location::OribpStartIndex() const
	{
        return (-1)*min(column,row);
	}
int  Location::OribpEndIndex() const
	{
        return min((7-column),(7-row));
	}
int  Location::OribmStartIndex() const
    {
        return (-1)*min(7-column,row);
    }
int  Location::OribmEndIndex() const
    {
        return min(7-row,column);
    }
int  Location::VerticalStartIndex() const
	{
        return (-1)*row;
	}
int  Location::VerticalEndIndex() const
	{
        return (7-row);
	}
int  Location::HorizontalStartIndex() const
	{
        return (-1)*column;
	}
int  Location::HorizontalEndIndex() const
	{
        return (7-column);
	}

Location Location::operator=(const Location& arg)
	{
		column=(arg).Get_X();
		row=(arg).Get_Y();
		return *this;
	}
bool Location::operator!=(const Location& arg)
	{
        return !(column==arg.column && row==(arg).row);
	}
bool Location::operator==(const Location& arg)
	{
        return column==(arg).column && row==(arg).row;
	}
bool Location::IsValid() const
	{
		if(-1<column && column<8 && -1<row && row<8)
		{
			return true;
		}

		return false;
	}

void Location::Set(int x,int y)
	{
		column=x;
		row=y;
	}

void Location::Load(ifstream &arg)
{
	arg>>column>>row;
}


Table::Table(const Table &arg )
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
					_table[i][j]=arg._table[i][j];
			}
		}
	}

Table::Table()
	{
		_table[0][0].Set(P_Rook   , White);   //filling 1A
		_table[1][0].Set(P_Knight , White);   //filling 1B
		_table[2][0].Set(P_Bishop , White);   //filling 1C
		_table[3][0].Set(P_Queen  , White);   //filling 1D
		_table[4][0].Set(P_King   , White);   //filling 1E
		_table[5][0].Set(P_Bishop , White);   //filling 1F
		_table[6][0].Set(P_Knight , White);   //filling 1G
		_table[7][0].Set(P_Rook   , White);   //filling 1H

		for(int i=0;i<8;i++)                //filling 2A-2H
		{
			_table[i][1].Set(P_Pawn , White);
		}

		_table[0][7].Set(P_Rook   , Black);   //filling 8A
		_table[1][7].Set(P_Knight , Black);   //filling 8B
		_table[2][7].Set(P_Bishop , Black);   //filling 8C
		_table[3][7].Set(P_Queen  , Black);   //filling 8D
		_table[4][7].Set(P_King   , Black);   //filling 8E
		_table[5][7].Set(P_Bishop , Black);   //filling 8F
		_table[6][7].Set(P_Knight , Black);   //filling 8G
		_table[7][7].Set(P_Rook   , Black);   //filling 8H

		for(int i=0;i<8;i++)                //filling 7A-7H
		{
			_table[i][6].Set(P_Pawn , Black);
		}

		//----------------------------------------nnul

	}

PieceInfo Table::operator[] (const Location &arg)  const
	{
		return _table[(arg).Get_X()][(arg).Get_Y()];
	}

PieceInfo Table::At(int column , int row)
	{
		return _table[column][row];
	}

bool Table::IsOribpSafe     (const Location &arg , bool color) const
	{
		for(int i=-1;i>=arg.OribpStartIndex();i--)
		{
			if(!IsNull(arg.Oribp(i)))
			{
				if((*this)[arg.Oribp(i)].color!=color && ( (*this)[arg.Oribp(i)].type==P_Bishop || (*this)[arg.Oribp(i)].type==P_Queen))
				{
					return false;
				}
				else 
				{
					break;
				}
			}
		}

		for(int i=1;i<=arg.OribpEndIndex();i++)
		{
			if(!IsNull(arg.Oribp(i)))
			{
				if((*this)[arg.Oribp(i)].color!=color && ( (*this)[arg.Oribp(i)].type==P_Bishop || (*this)[arg.Oribp(i)].type==P_Queen))
				{
					return false;
				}
				else
				{
					break;
				}
			}
		}

		return true;
	}

bool Table::IsOribmSafe     (const Location &arg , bool color) const
	{
		for(int i=-1;i>=arg.OribmStartIndex();i--)
		{
			if(!IsNull(arg.Oribm(i)))
			{
				if((*this)[arg.Oribm(i)].color!=color && ( (*this)[arg.Oribm(i)].type==P_Bishop || (*this)[arg.Oribm(i)].type==P_Queen))
				{
					return false;
				}
				else
				{
					break;
				}
			}
		}

		for(int i=1;i<=arg.OribmEndIndex();i++)
		{
			if(!IsNull(arg.Oribm(i)))
			{
				if((*this)[arg.Oribm(i)].color!=color && ( (*this)[arg.Oribm(i)].type==P_Bishop || (*this)[arg.Oribm(i)].type==P_Queen))
				{
					return false;
				}
				else
				{
					break;
				}
			}
		}

		return true;
	}

bool Table::IsVerticalSafe  (const Location &arg , bool color) const
	{
		for(int i=-1;i>=arg.VerticalStartIndex();i--)
		{
			if(!IsNull(arg.Vertical(i)))
			{
				if((*this)[arg.Vertical(i)].color!=color && ( (*this)[arg.Vertical(i)].type==P_Rook || (*this)[arg.Vertical(i)].type==P_Queen))
				{
					return false;
				}
				else
				{
					break;
				}
			}
		}

		for(int i=1;i<=arg.VerticalEndIndex();i++)
		{
			if(!IsNull(arg.Vertical(i)))
			{
				if((*this)[arg.Vertical(i)].color!=color && ( (*this)[arg.Vertical(i)].type==P_Rook || (*this)[arg.Vertical(i)].type==P_Queen))
				{
					return false;
				}
				else
				{
					break;
				}
			}
		}

		return true;
	}

bool Table::IsHorizontalSafe(const Location &arg , bool color) const
	{
		for(int i=-1;i>=arg.HorizontalStartIndex();i--)
		{
			if(!IsNull(arg.Horizontal(i)))
			{
				if((*this)[arg.Horizontal(i)].color!=color && ( (*this)[arg.Horizontal(i)].type==P_Rook || (*this)[arg.Horizontal(i)].type==P_Queen))
				{
					return false;
				}
				else
				{
					break;
				}
			}
		}

		for(int i=1;i<=arg.HorizontalEndIndex();i++)
		{
			if(!IsNull(arg.Horizontal(i)))
			{
				if((*this)[arg.Horizontal(i)].color!=color && ( (*this)[arg.Horizontal(i)].type==P_Rook || (*this)[arg.Horizontal(i)].type==P_Queen))
				{
					return false;
				}
				else
				{
					break;
				}
			}
		}

		return true;
	}

bool Table::IsLSafe		    (const Location &arg , bool color) const
	{
		if((arg).L_NE1().IsValid())
		{
			if((*this)[(arg).L_NE1()].color!=color && (*this)[(arg).L_NE1()].type==P_Knight)
			{
				return false;
			}
		}
		if((arg).L_NE2().IsValid())
		{
			if((*this)[(arg).L_NE2()].color!=color && (*this)[(arg).L_NE2()].type==P_Knight)
			{
				return false;
			}
		}

		if((arg).L_SE1().IsValid())
		{
			if((*this)[(arg).L_SE1()].color!=color && (*this)[(arg).L_SE1()].type==P_Knight)
			{
				return false;
			}
		}
		if((arg).L_SE2().IsValid())
		{
			if((*this)[(arg).L_SE2()].color!=color && (*this)[(arg).L_SE2()].type==P_Knight)
			{
				return false;
			}
		}
		if((arg).L_NW1().IsValid())
		{
			if((*this)[(arg).L_NW1()].color!=color && (*this)[(arg).L_NW1()].type==P_Knight)
			{
				return false;
			}
		}
		if((arg).L_NW2().IsValid())
		{
			if((*this)[(arg).L_NW2()].color!=color && (*this)[(arg).L_NW2()].type==P_Knight)
			{
				return false;
			}
		}
		if((arg).L_SW1().IsValid())
		{
			if((*this)[(arg).L_SW1()].color!=color && (*this)[(arg).L_SW1()].type==P_Knight)
			{
				return false;
			}
		}
		if((arg).L_SW2().IsValid())
		{
			if((*this)[(arg).L_SW2()].color!=color && (*this)[(arg).L_SW2()].type==P_Knight)
			{
				return false;
			}
		}
		return true;
	}

bool Table::IsPawnSafe	    (const Location &arg , bool color) const
	{
		if((arg).Oribp(-1).IsValid())
		{
			if((*this)[(arg).Oribp(-1)].color!=color && (*this)[(arg).Oribp(-1)].type==P_Pawn)
			{
				return false;
			}
		}

		if((arg).Oribm(-1).IsValid())
		{
			if((*this)[(arg).Oribm(-1)].color!=color && (*this)[(arg).Oribm(-1)].type==P_Pawn)
			{
				return false;
			}
		}

		return true;
	}

bool Table::IsSafe          (const Location &arg , bool color) const
{
	return IsOribpSafe(arg,color) && IsOribmSafe(arg,color) && IsVerticalSafe(arg,color) && IsHorizontalSafe(arg,color) && IsLSafe(arg,color) && IsPawnSafe(arg,color) ;
}

bool Table::IsNull          (int x , int y)        const
{
	if( x<0 | x>7 | y<0 | y>7)
	{
		return false;
	}
	else
	{
		return (bool)_table[x][y];
	}
}

bool Table::IsNull          (const Location &arg)  const
	{
		if(!arg.IsValid())
		{
			return false;
		}
		else
		{
			return (bool)(*this)[arg];
		}
	}

void Table::Select_Maintain (const Location &arg)
	{
		_table[arg.Get_X()][arg.Get_Y()].Set(Selected_Maintain,White);
	}

void Table::Select			(const Location &arg)
	{
		(*this)[arg].Set(Selected,White);
	}

void Table::Select_Attack   (const Location &arg)
	{
		(*this)[arg].Set(Selected_Attack,White);
	}

void Table::MoveFromTo      (const Location &src , int x_des , int y_des)
	{
		_table[x_des][y_des].type=(*this)[src].type;
		_table[x_des][y_des].color=(*this)[src].color;
		_table[src.Get_X()][src.Get_Y()].type=nnul;
	}

bool Table::operator==(const Table& arg)
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(_table[i][j]!=arg._table[i][j])
			{
				return false;
			}
		}

	}

	return true;
}

bool Table::operator!=(const Table& arg)
{
	return !((*this)==arg);
}

void Table::Set(int x , int y , const PieceInfo &arg)
{
	_table[x][y]=arg;
}