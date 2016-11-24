#ifndef  TABLE_H
#define  TABLE_H

#include "stdafx.h"
#include <fstream>
#include <algorithm>

using namespace std;

//----------------------------------------->
#define P_Pawn			  2000
#define P_Rook			  2001
#define P_Knight		  2002
#define P_Bishop		  2003
#define P_Queen			  2004
#define P_King			  2005

#define nnul              0
#define Selected          100
#define Selected_Attack   200
#define Selected_Maintain 300
#define Selected_Castle   400

#define White    true
#define Black    false
//----------------------------------------->

class PieceInfo
{
	public:

		int  type;
		bool color;

		operator int () const;
		operator bool() const;

		PieceInfo(int _type=nnul , bool _color=White);
		PieceInfo& operator= (const PieceInfo);
		bool       operator==(const PieceInfo&);
		bool       operator!=(const PieceInfo&);
		void       Set( int , bool );
};

class Location
{
	friend class Table;

	private:

	int column;
	int row;

	public:

	Location(int x=-1,int y=-1);
	Location L_NE1() const;
	Location L_NE2() const;
	Location L_SE1() const;
	Location L_SE2() const;
	Location L_NW1() const;
	Location L_NW2() const;
	Location L_SW1() const;
	Location L_SW2() const;

	int Get_X() const;
	int Get_Y() const;

	Location Oribp     (int) const;
	Location Oribm     (int) const;
	Location Vertical  (int) const;
	Location Horizontal(int) const;

	int  OribpStartIndex()     const;
	int  OribpEndIndex()       const;
	int  OribmStartIndex()     const;
	int  OribmEndIndex()       const;
	int  VerticalStartIndex()  const;
	int  VerticalEndIndex()    const;
	int  HorizontalStartIndex()const;
	int  HorizontalEndIndex()  const;

	bool operator!=(const Location&);
	bool operator==(const Location&);

	Location operator=(const Location&);

	bool IsValid() const;

	void Set(int ,int );
	void Load(ifstream&);
};

class Table
{
	public:

	PieceInfo _table[8][8];

	bool IsOribpSafe     (const Location & , bool ) const;
	bool IsOribmSafe     (const Location & , bool ) const;
	bool IsVerticalSafe  (const Location & , bool ) const;
	bool IsHorizontalSafe(const Location & , bool ) const;
	bool IsLSafe		 (const Location & , bool ) const;
	bool IsPawnSafe	     (const Location & , bool ) const;

	public:

	Table();
	Table(const Table&);

	PieceInfo At(int , int );
	PieceInfo operator[] (const Location &)  const;

	void Set             (int , int , const PieceInfo& );
	void Select_Maintain (const Location & );
	void Select			 (const Location & );
	void Select_Attack   (const Location & );
	void MoveFromTo      (const Location & , int , int );

	bool IsNull          (int , int )               const;
	bool IsNull          (const Location & )	    const;
	bool IsSafe          (const Location & , bool ) const;

	bool operator==(const Table&);
	bool operator!=(const Table&);
};

#endif
