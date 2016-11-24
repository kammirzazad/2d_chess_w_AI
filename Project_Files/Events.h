#include "stdafx.h"
#include "Form1.h"

#include "Table.h"
#include "Game.h"
#include <string>

#define Left     true
#define Right    false

extern Game mygame;

int   base_ID     = 200;//----------->choose default value
int   selected_ID = 0;
int   ID_Table[8][8];
int** Saved_Pos;

int white_lost=0;
int black_lost=0;

bool  state=true;
bool  except=false;

Location selected_Loc;
Location promoted_Loc;

namespace FINALPROJECT
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	void InitializeIDTable()
	{

	for(int i=0;i<8;i++)//White_Pawns
	{
		ID_Table[i][1]=base_ID++;
	}

	for(int i=0;i<8;i++)//White_Pieces
	{
		ID_Table[i][0]=base_ID++;
	}

	for(int i=0;i<8;i++)//Black_Pawns
	{
		ID_Table[i][6]=base_ID++;
	}

	for(int i=0;i<8;i++)//Black_Pieces
	{
		ID_Table[i][7]=base_ID++;
	}

	Saved_Pos=new int*[8];

	for(int i=0;i<8;i++)
	{
		Saved_Pos[i]=new int[8];
	}

	}

	void SavePos(int** arg)
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				Saved_Pos[i][j]=arg[i][j];
			}
		}
	}

	bool CheckTurn(int x, int y)
	{
		if(ID_Table[x][y]<216)//White_Pieces
		{
			return state;
		}
		else
		{
			return !state;
		}
	}

    void Form1::H8_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp =mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[7][7]);

			if(Saved_Pos[7][7]==Selected || Saved_Pos[7][7]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,7,7))
				{
					if(Saved_Pos[7][7]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[7][7]=selected_ID;
					ChangeBackGround(7,7,temp.type,temp.color);

					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(7,7);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}

			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(7,7))
		{
			selected_ID=ID_Table[7][7];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(7,7);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::H7_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[7][6]);

			if(Saved_Pos[7][6]==Selected || Saved_Pos[7][6]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,7,6))
				{
					if(Saved_Pos[7][6]==Selected_Attack)
					{						
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[7][6]=selected_ID;
					ChangeBackGround(7,6,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(7,6))
		{
			selected_ID=ID_Table[7][6];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(7,6);
			SavePos(mytable);
			Select(mytable);
		}
		
    }

	void Form1::H6_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[7][5]);

			if(Saved_Pos[7][5]==Selected || Saved_Pos[7][5]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,7,5))
				{
					if(Saved_Pos[7][5]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[7][5]=selected_ID;
					ChangeBackGround(7,5,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(7,5))
		{
			selected_ID=ID_Table[7][5];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(7,5);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::H5_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[7][4]);

			if(Saved_Pos[7][4]==Selected || Saved_Pos[7][4]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,7,4))
				{
					if(Saved_Pos[7][4]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[7][4]=selected_ID;
					ChangeBackGround(7,4,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(7,4))
		{
			selected_ID=ID_Table[7][4];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(7,4);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::H4_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[7][3]);

			if(Saved_Pos[7][3]==Selected || Saved_Pos[7][3]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,7,3))
				{
					if(Saved_Pos[7][3]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[7][3]=selected_ID;
					ChangeBackGround(7,3,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(7,3))
		{
			selected_ID=ID_Table[7][3];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(7,3);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::H3_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[7][2]);

			if(Saved_Pos[7][2]==Selected || Saved_Pos[7][2]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,7,2))
				{
					if(Saved_Pos[7][2]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[7][2]=selected_ID;
					ChangeBackGround(7,2,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(7,2))
		{
			selected_ID=ID_Table[7][2];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(7,2);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::H2_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[7][1]);

			if(Saved_Pos[7][1]==Selected || Saved_Pos[7][1]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,7,1))
				{
					if(Saved_Pos[7][1]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[7][1]=selected_ID;
					ChangeBackGround(7,1,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(7,1))
		{
			selected_ID=ID_Table[7][1];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(7,1);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::H1_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[7][0]);

			if(Saved_Pos[7][0]==Selected || Saved_Pos[7][0]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,7,0))
				{
					if(Saved_Pos[7][0]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[7][0]=selected_ID;
					ChangeBackGround(7,0,temp.type,temp.color);

					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(7,0);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(7,0))
		{
			selected_ID=ID_Table[7][0];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(7,0);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::G8_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[6][7]);

			if(Saved_Pos[6][7]==Selected || Saved_Pos[6][7]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,6,7))
				{
					if(Saved_Pos[6][7]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[6][7]=selected_ID;
					ChangeBackGround(6,7,temp.type,temp.color);

					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(6,7);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else if(Saved_Pos[6][7]==Selected_Castle)
			{
				mygame.Castle(Black,Left);

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[6][7]=selected_ID;
				ChangeBackGround(6,7,P_King,Black);

				selected_Loc.Set(7,7);//Setting location so that ClearBackGround can find selected cell 
				int id=ID_Table[7][7];

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[5][7]=id;//ID of King
				ChangeBackGround(5,7,P_Rook,Black);

				selected_ID=0;
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(6,7))
		{
			selected_ID=ID_Table[6][7];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(6,7);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::G7_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp =mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[6][6]);

			if(Saved_Pos[6][6]==Selected || Saved_Pos[6][6]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,6,6))
				{
					if(Saved_Pos[6][6]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[6][6]=selected_ID;
					ChangeBackGround(6,6,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(6,6))
		{
			selected_ID=ID_Table[6][6];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(6,6);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::G6_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[6][5]);

			if(Saved_Pos[6][5]==Selected || Saved_Pos[6][5]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,6,5))
				{
					if(Saved_Pos[6][5]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[6][5]=selected_ID;
					ChangeBackGround(6,5,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}

			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(6,5))
		{
			selected_ID=ID_Table[6][5];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(6,5);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::G5_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[6][4]);

			if(Saved_Pos[6][4]==Selected || Saved_Pos[6][4]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,6,4))
				{
					if(Saved_Pos[6][4]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[6][4]=selected_ID;
					ChangeBackGround(6,4,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}

			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(6,4))
		{
			selected_ID=ID_Table[6][4];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(6,4);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::G4_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[6][3]);

			if(Saved_Pos[6][3]==Selected || Saved_Pos[6][3]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,6,3))
				{
					if(Saved_Pos[6][3]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[6][3]=selected_ID;
					ChangeBackGround(6,3,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(6,3))
		{
			selected_ID=ID_Table[6][3];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(6,3);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::G3_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[6][2]);

			if(Saved_Pos[6][2]==Selected || Saved_Pos[6][2]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,6,2))
				{
					if(Saved_Pos[6][2]==Selected_Attack)
					{	
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[6][2]=selected_ID;
					ChangeBackGround(6,2,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(6,2))
		{
			selected_ID=ID_Table[6][2];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(6,2);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::G2_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[6][1]);

			if(Saved_Pos[6][1]==Selected | Saved_Pos[6][1]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,6,1))
				{
					if(Saved_Pos[6][1]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[6][1]=selected_ID;
					ChangeBackGround(6,1,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}

			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(6,1))
		{
			selected_ID=ID_Table[6][1];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(6,1);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::G1_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[6][0]);

			if(Saved_Pos[6][0]==Selected || Saved_Pos[6][0]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,6,0))
				{
					if(Saved_Pos[6][0]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[6][0]=selected_ID;
					ChangeBackGround(6,0,temp.type,temp.color);

					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(6,0);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else if(Saved_Pos[6][0]==Selected_Castle)
			{
				mygame.Castle(White,Right);

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[6][0]=selected_ID;
				ChangeBackGround(6,0,P_King,White);

				selected_Loc.Set(7,0);//Setting location so that ClearBackGround can find selected cell 
				int id=ID_Table[7][0];

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[5][0]=id;//ID of King
				ChangeBackGround(5,0,P_Rook,White);

				selected_ID=0;
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(6,0))
		{
			selected_ID=ID_Table[6][0];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(6,0);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::F8_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[5][7]);

			if(Saved_Pos[5][7]==Selected || Saved_Pos[5][7]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,5,7))
				{
					if(Saved_Pos[5][7]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[5][7]=selected_ID;
					ChangeBackGround(5,7,temp.type,temp.color);

					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(5,7);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else if(Saved_Pos[5][7]==Selected_Castle)
			{
				mygame.Castle(Black,Right);

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[5][7]=selected_ID;
				ChangeBackGround(5,7,P_Rook,Black);

				selected_Loc.Set(4,7);//Setting location so that ClearBackGround can find selected cell 
				int id=ID_Table[4][7];

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[6][7]=id;//ID of King
				ChangeBackGround(6,7,P_King,Black);

				selected_ID=0;
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(5,7))
		{
			selected_ID=ID_Table[5][7];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(5,7);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::F7_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[5][6]);

			if(Saved_Pos[5][6]==Selected || Saved_Pos[5][6]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,5,6))
				{
					if(Saved_Pos[5][6]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[5][6]=selected_ID;
					ChangeBackGround(5,6,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(5,6))
		{
			selected_ID=ID_Table[5][6];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(5,6);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::F6_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[5][5]);

			if(Saved_Pos[5][5]==Selected || Saved_Pos[5][5]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,5,5))
				{
					if(Saved_Pos[5][5]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[5][5]=selected_ID;
					ChangeBackGround(5,5,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(5,5))
		{
			selected_ID=ID_Table[5][5];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(5,5);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::F5_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[5][4]);

			if(Saved_Pos[5][4]==Selected | Saved_Pos[5][4]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,5,4))
				{
					if(Saved_Pos[5][4]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[5][4]=selected_ID;
					ChangeBackGround(5,4,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		} 
		else if(CheckTurn(5,4))
		{
			selected_ID=ID_Table[5][4];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(5,4);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::F4_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[5][3]);

			if(Saved_Pos[5][3]==Selected || Saved_Pos[5][3]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,5,3))
				{
					if(Saved_Pos[5][3]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[5][3]=selected_ID;
					ChangeBackGround(5,3,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(5,3))
		{ 
			selected_ID=ID_Table[5][3];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(5,3);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::F3_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[5][2]);

			if(Saved_Pos[5][2]==Selected || Saved_Pos[5][2]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,5,2))
				{
					if(Saved_Pos[5][2]==Selected_Attack)
					{	
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[5][2]=selected_ID;
					ChangeBackGround(5,2,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(5,2))
		{
			selected_ID=ID_Table[5][2];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(5,2);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::F2_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[5][1]);

			if(Saved_Pos[5][1]==Selected || Saved_Pos[5][1]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,selected_Loc.Get_X(),selected_Loc.Get_Y()))
				{
					if(Saved_Pos[5][1]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[5][1]=selected_ID;
					ChangeBackGround(5,1,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
						textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(5,1))
		{
			selected_ID=ID_Table[5][1];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(5,1);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::F1_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[5][0]);

			if(Saved_Pos[5][0]==Selected || Saved_Pos[5][0]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,5,0))
				{
					if(Saved_Pos[5][0]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[5][0]=selected_ID;
					ChangeBackGround(5,0,temp.type,temp.color);

					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(5,0);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else if(Saved_Pos[5][0]==Selected_Castle)
			{
				mygame.Castle(White,Right);

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[5][0]=selected_ID;
				ChangeBackGround(5,0,P_Rook,White);

				selected_Loc.Set(4,0);//Setting location so that ClearBackGround can find selected cell 
				int id=ID_Table[4][0];

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[6][0]=id;//ID of King
				ChangeBackGround(6,0,P_King,White);

				selected_ID=0;
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(5,0))
		{
			selected_ID=ID_Table[5][0];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(5,0);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::E8_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[4][7]);

			if(Saved_Pos[4][7]==Selected || Saved_Pos[4][7]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,4,7))
				{
					if(Saved_Pos[4][7]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[4][7]=selected_ID;
					ChangeBackGround(4,7,temp.type,temp.color);

					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(4,7);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
						textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(4,7))
		{
			selected_ID=ID_Table[4][7];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(4,7);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::E7_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[4][6]);

			if(Saved_Pos[4][6]==Selected || Saved_Pos[4][6]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,4,6))
				{
					if(Saved_Pos[4][6]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[4][6]=selected_ID;
					ChangeBackGround(4,6,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(4,6))
		{
			selected_ID=ID_Table[4][6];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(4,6);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::E6_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[4][5]);

			if(Saved_Pos[4][5]==Selected || Saved_Pos[4][5]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,4,5))
				{
					if(Saved_Pos[4][5]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[4][5]=selected_ID;
					ChangeBackGround(4,5,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
						textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(4,5))
		{
			selected_ID=ID_Table[4][5];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(4,5);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::E5_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[4][4]);

			if(Saved_Pos[4][4]==Selected || Saved_Pos[4][4]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,4,4))
				{
					if(Saved_Pos[4][4]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[4][4]=selected_ID;
					ChangeBackGround(4,4,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
						textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(4,4))
		{
			selected_ID=ID_Table[4][4];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(4,4);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::E4_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[4][3]);

			if(Saved_Pos[4][3]==Selected || Saved_Pos[4][3]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,4,3))
				{
					if(Saved_Pos[4][3]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[4][3]=selected_ID;
					ChangeBackGround(4,3,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		} 
		else if(CheckTurn(4,3))
		{
			selected_ID=ID_Table[4][3];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(4,3);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::E3_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[4][2]);

			if(Saved_Pos[4][2]==Selected || Saved_Pos[4][2]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,4,2))
				{
					if(Saved_Pos[4][2]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[4][2]=selected_ID;
					ChangeBackGround(4,2,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
						textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(4,2))
		{
			selected_ID=ID_Table[4][2];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(4,2);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::E2_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[4][1]);

			if(Saved_Pos[4][1]==Selected || Saved_Pos[4][1]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,4,1))
				{
					if(Saved_Pos[4][1]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[4][1]=selected_ID;
					ChangeBackGround(4,1,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(4,1))
		{
			selected_ID=ID_Table[4][1];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(4,1);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::E1_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[4][0]);

			if(Saved_Pos[4][0]==Selected || Saved_Pos[4][0]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,4,0))
				{
					if(Saved_Pos[4][0]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[4][0]=selected_ID;
					ChangeBackGround(4,0,temp.type,temp.color);

					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(4,0);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(4,0))
		{
			selected_ID=ID_Table[4][0];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(4,0);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::D8_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[3][7]);

			if(Saved_Pos[3][7]==Selected | Saved_Pos[3][7]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,3,7))
				{
					if(Saved_Pos[3][7]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[3][7]=selected_ID;
					ChangeBackGround(3,7,temp.type,temp.color);

					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(3,7);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else if(Saved_Pos[3][7]==Selected_Castle)
			{
				mygame.Castle(Black,Left);

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[3][7]=selected_ID;
				ChangeBackGround(3,7,P_Rook,Black);

				selected_Loc.Set(4,7);//Setting location so that ClearBackGround can find selected cell 
				int id=ID_Table[4][7];

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[2][7]=id;//ID of King
				ChangeBackGround(2,7,P_King,Black);

				selected_ID=0;
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(3,7))
		{
			selected_ID=ID_Table[3][7];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(3,7);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::D7_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[3][6]);

			if(Saved_Pos[3][6]==Selected | Saved_Pos[3][6]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,3,6))
				{
					if(Saved_Pos[3][6]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[3][6]=selected_ID;
					ChangeBackGround(3,6,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(3,6))
		{
			selected_ID=ID_Table[3][6];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(3,6);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::D6_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[3][5]);

			if(Saved_Pos[3][5]==Selected || Saved_Pos[3][5]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,3,5))
				{
					if(Saved_Pos[3][5]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[3][5]=selected_ID;
					ChangeBackGround(3,5,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(3,5))
		{
			selected_ID=ID_Table[3][5];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(3,5);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::D5_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[3][4]);

			if(Saved_Pos[3][4]==Selected || Saved_Pos[3][4]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,3,4))
				{
					if(Saved_Pos[3][4]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[3][4]=selected_ID;
					ChangeBackGround(3,4,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(3,4))
		{
			selected_ID=ID_Table[3][4];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(3,4);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::D4_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[3][3]);

			if(Saved_Pos[3][3]==Selected || Saved_Pos[3][3]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,3,3))
				{
					if(Saved_Pos[3][3]==Selected_Attack)
					{	
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[3][3]=selected_ID;
					ChangeBackGround(3,3,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(3,3))
		{
			selected_ID=ID_Table[3][3];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(3,3);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::D3_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[3][2]);

			if(Saved_Pos[3][2]==Selected || Saved_Pos[3][2]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,3,2))
				{
					if(Saved_Pos[3][2]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[3][2]=selected_ID;
					ChangeBackGround(3,2,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(3,2))
		{
			selected_ID=ID_Table[3][2];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(3,2);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::D2_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[3][1]);

			if(Saved_Pos[3][1]==Selected | Saved_Pos[3][1]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,3,1))
				{
					if(Saved_Pos[3][1]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[3][1]=selected_ID;
					ChangeBackGround(3,1,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(3,1))
		{
			selected_ID=ID_Table[3][1];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(3,1);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::D1_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[3][0]);

			if(Saved_Pos[3][0]==Selected || Saved_Pos[3][0]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,3,0))
				{
					if(Saved_Pos[3][0]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[3][0]=selected_ID;
					ChangeBackGround(3,0,temp.type,temp.color);

					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(3,0);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else if(Saved_Pos[3][0]==Selected_Castle)
			{
				mygame.Castle(White,Left);

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[3][0]=selected_ID;
				ChangeBackGround(3,0,P_Rook,White);

				selected_Loc.Set(4,0);//Setting location so that ClearBackGround can find selected cell 
				int id=ID_Table[4][0];

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[2][0]=id;//ID of Left Rook
				ChangeBackGround(2,0,P_King,White);

				selected_ID=0;
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(3,0))
		{
			selected_ID=ID_Table[3][0];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(3,0);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::C8_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[2][7]);

			if(Saved_Pos[2][7]==Selected || Saved_Pos[2][7]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,2,7))
				{
					if(Saved_Pos[2][7]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[2][7]=selected_ID;
					ChangeBackGround(2,7,temp.type,temp.color);

					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(2,7);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}

			}
			else if(Saved_Pos[2][7]==Selected_Castle)
			{
				mygame.Castle(Black,Left);

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[2][7]=selected_ID;
				ChangeBackGround(2,7,P_King,Black);

				selected_Loc.Set(0,7);//Setting location so that ClearBackGround can find selected cell 
				int id=ID_Table[0][7];

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[3][7]=id;//ID of King
				ChangeBackGround(3,7,P_Rook,Black);

				selected_ID=0;
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(2,7))
		{
			selected_ID=ID_Table[2][7];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(2,7);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::C7_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[2][6]);

			if(Saved_Pos[2][6]==Selected || Saved_Pos[2][6]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,2,6))
				{
					if(Saved_Pos[2][6]==Selected_Attack)
					{
						
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[2][6]=selected_ID;
					ChangeBackGround(2,6,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}

			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(2,6))
		{
			selected_ID=ID_Table[2][6];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(2,6);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::C6_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[2][5]);

			if(Saved_Pos[2][5]==Selected || Saved_Pos[2][5]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,2,5))
				{
					if(Saved_Pos[2][5]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[2][5]=selected_ID;
					ChangeBackGround(2,5,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
						textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(2,5))
		{
			selected_ID=ID_Table[2][5];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(2,5);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::C5_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[2][4]);

			if(Saved_Pos[2][4]==Selected || Saved_Pos[2][4]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,2,4))
				{
					if(Saved_Pos[2][4]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[2][4]=selected_ID;
					ChangeBackGround(2,4,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}

			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(2,4))
		{
			selected_ID=ID_Table[2][4];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(2,4);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::C4_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[2][3]);

			if(Saved_Pos[2][3]==Selected || Saved_Pos[2][3]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,2,3))
				{
					if(Saved_Pos[2][3]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[2][3]=selected_ID;
					ChangeBackGround(2,3,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(2,3))
		{
			selected_ID=ID_Table[2][3];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(2,3);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::C3_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[2][2]);

			if(Saved_Pos[2][2]==Selected || Saved_Pos[2][2]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,2,2))
				{
					if(Saved_Pos[2][2]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[2][2]=selected_ID;
					ChangeBackGround(2,2,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(2,2))
		{
			selected_ID=ID_Table[2][2];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(2,2);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::C2_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[2][1]);

			if(Saved_Pos[2][1]==Selected || Saved_Pos[2][1]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,2,1))
				{
					if(Saved_Pos[2][1]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[2][1]=selected_ID;
					ChangeBackGround(2,1,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(2,1))
		{
			selected_ID=ID_Table[2][1];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(2,1);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::C1_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[2][0]);

			if(Saved_Pos[2][0]==Selected || Saved_Pos[2][0]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,2,0))
				{
					if(Saved_Pos[2][0]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[2][0]=selected_ID;
					ChangeBackGround(2,0,temp.type,temp.color);

					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(2,0);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else if(Saved_Pos[2][0]==Selected_Castle)
			{
				mygame.Castle(White,Left);

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[2][0]=selected_ID;
				ChangeBackGround(2,0,P_King,White);

				selected_Loc.Set(0,0);//Setting location so that ClearBackGround can find selected cell 
				int id=ID_Table[0][0];

				ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
				ID_Table[3][0]=id;//ID of Left Rook
				ChangeBackGround(3,0,P_Rook,White);

				selected_ID=0;
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(2,0))
		{
			selected_ID=ID_Table[2][0];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(2,0);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::B8_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[1][7]);

			if(Saved_Pos[1][7]==Selected || Saved_Pos[1][7]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,1,7))
				{
					if(Saved_Pos[1][7]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[1][7]=selected_ID;
					ChangeBackGround(1,7,temp.type,temp.color);

					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(1,7);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(1,7))
		{
			selected_ID=ID_Table[1][7];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(1,7);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::B7_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[1][6]);

			if(Saved_Pos[1][6]==Selected || Saved_Pos[1][6]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,1,6))
				{
					if(Saved_Pos[1][6]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[1][6]=selected_ID;
					ChangeBackGround(1,6,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(1,6))
		{
			selected_ID=ID_Table[1][6];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(1,6);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::B6_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[1][5]);

			if(Saved_Pos[1][5]==Selected || Saved_Pos[1][5]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,1,5))
				{
					if(Saved_Pos[1][5]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[1][5]=selected_ID;
					ChangeBackGround(1,5,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(1,5))
		{
			selected_ID=ID_Table[1][5];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(1,5);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::B5_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[1][4]);

			if(Saved_Pos[1][4]==Selected || Saved_Pos[1][4]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,1,4))
				{
					if(Saved_Pos[1][4]==Selected_Attack)
					{	
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[1][4]=selected_ID;
					ChangeBackGround(1,4,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(1,4))
		{
			selected_ID=ID_Table[1][4];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(1,4);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::B4_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[1][3]);

			if(Saved_Pos[1][3]==Selected || Saved_Pos[1][3]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,1,3))
				{
					if(Saved_Pos[1][3]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[1][3]=selected_ID;
					ChangeBackGround(1,3,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(1,3))
		{
			selected_ID=ID_Table[1][3];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(1,3);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::B3_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[1][2]);

			if(Saved_Pos[1][2]==Selected || Saved_Pos[1][2]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,1,2))
				{
					if(Saved_Pos[1][2]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[1][2]=selected_ID;
					ChangeBackGround(1,2,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		} 
		else if(CheckTurn(1,2))
		{
			selected_ID=ID_Table[1][2];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(1,2);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::B2_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[1][1]);

			if(Saved_Pos[1][1]==Selected || Saved_Pos[1][1]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,1,1))
				{
					if(Saved_Pos[1][1]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[1][1]=selected_ID;
					ChangeBackGround(1,1,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(1,1))
		{
			selected_ID=ID_Table[1][1];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(1,1);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::B1_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[1][0]);

			if(Saved_Pos[1][0]==Selected || Saved_Pos[1][0]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,1,0))
				{
					if(Saved_Pos[1][0]==Selected_Attack)
					{	
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[1][0]=selected_ID;
					ChangeBackGround(1,0,temp.type,temp.color);

					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(1,0);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}

			}
			else 
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(1,0))
		{
			selected_ID=ID_Table[1][0];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(1,0);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::A8_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[0][7]);

			if(Saved_Pos[0][7]==Selected || Saved_Pos[0][7]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,0,7))
				{
					if(Saved_Pos[0][7]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[0][7]=selected_ID;
					ChangeBackGround(0,7,temp.type,temp.color);
					
					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(0,7);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(0,7))
		{
			selected_ID=ID_Table[0][7];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(0,7);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::A7_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[0][6]);

			if(Saved_Pos[0][6]==Selected || Saved_Pos[0][6]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,0,6))
				{
					if(Saved_Pos[0][6]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[0][6]=selected_ID;
					ChangeBackGround(0,6,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(0,6))
		{
			selected_ID=ID_Table[0][6];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(0,6);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::A6_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[0][5]);

			if(Saved_Pos[0][5]==Selected || Saved_Pos[0][5]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,0,5))
				{
					if(Saved_Pos[0][5]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[0][5]=selected_ID;
					ChangeBackGround(0,5,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(0,5))
		{
			selected_ID=ID_Table[0][5];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(0,5);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::A5_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[0][4]);

			if(Saved_Pos[0][4]==Selected || Saved_Pos[0][4]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,0,4))
				{
					if(Saved_Pos[0][4]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[0][4]=selected_ID;
					ChangeBackGround(0,4,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(0,4))
		{
			selected_ID=ID_Table[0][4];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(0,4);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::A4_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[0][3]);

			if(Saved_Pos[0][3]==Selected || Saved_Pos[0][3]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,0,3))
				{
					if(Saved_Pos[0][3]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[0][3]=selected_ID;
					ChangeBackGround(0,3,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(0,3))
		{
			selected_ID=ID_Table[0][3];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(0,3);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::A3_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[0][2]);

			if(Saved_Pos[0][2]==Selected || Saved_Pos[0][2]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,0,2))
				{
					if(Saved_Pos[0][2]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[0][2]=selected_ID;
					ChangeBackGround(0,2,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}
			
			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(0,2))
		{
			selected_ID=ID_Table[0][2];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(0,2);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::A2_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[0][1]);

			if(Saved_Pos[0][1]==Selected || Saved_Pos[0][1]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,0,1))
				{
					if(Saved_Pos[0][1]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[0][1]=selected_ID;
					ChangeBackGround(0,1,temp.type,temp.color);

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}

			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(0,1))
		{
			selected_ID=ID_Table[0][1];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(0,1);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::A1_Click(System::Object^  sender, System::EventArgs^  e)
    {
		if(selected_ID!=0 )
		{
			PieceInfo temp=mygame.SearchTypeByID(selected_ID);
			PieceInfo temp2=mygame.SearchTypeByID(ID_Table[0][0]);

			if(Saved_Pos[0][0]==Selected || Saved_Pos[0][0]==Selected_Attack)
			{
				if(mygame.MoveByID(selected_ID,0,0))
				{
					if(Saved_Pos[0][0]==Selected_Attack)
					{
						AddLost(temp2.color,temp2.type);
					}

					ID_Table[selected_Loc.Get_X()][selected_Loc.Get_Y()]=0;
					ID_Table[1][0]=selected_ID;
					ChangeBackGround(0,0,temp.type,temp.color);

					if(temp.type==P_Pawn)
					{
						ChangeState(false);
						promoted_Loc.Set(0,0);
					}

					if(!mygame.IsKingSafe())
					{
						textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					    textBox1->ForeColor=System::Drawing::Color::Red;
					}
					else
					{
						textBox1->Text="";
					}
				}
				else//can not move piece because king is in check  
				{
					textBox1->Text=(mygame.GetCurrent()?"1st":"2nd")+" is in check";
					textBox1->ForeColor=System::Drawing::Color::Red;
					state=!state;
				}
			}
			else
			{
				state=!state;
			}

			selected_ID=0;
			DeSelect(Saved_Pos);
		}
		else if(CheckTurn(0,0))
		{
			selected_ID=ID_Table[0][0];
			int** mytable=mygame.Get_Pos_Loc(selected_ID);
			selected_Loc.Set(0,0);
			SavePos(mytable);
			Select(mytable);
		}
    }

	void Form1::Select(int**  arg )
		{
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					if(arg[i][j] == Selected)
					{
						Colorize(i,j,System::Drawing::Color::Orange);
					}
					else if(arg[i][j] == Selected_Attack)
					{
						Colorize(i,j,System::Drawing::Color::Pink);
					}
					else if(arg[i][j] == Selected_Maintain)
					{
						Colorize(i,j,System::Drawing::Color::LightGreen);
					}
					else if(arg[i][j] == Selected_Castle)
					{
						Colorize(i,j,System::Drawing::Color::DarkOrange);
					}
				}
			}
		}

	void Form1::DeSelect(int** arg)
		{
			Color mycolor;

			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					if((i+j)%2==0)
					{
						Colorize(i,j,mycolor.FromArgb(192,64,0));
					}
					else
					{
						Colorize(i,j,mycolor.FromName("White"));
					}
				}
			}

			state=!state;
		}

	void Form1::ChangeState(bool my_state)
	{
		Form1::A1->Enabled=my_state;
		Form1::A2->Enabled=my_state;
		Form1::A3->Enabled=my_state;
		Form1::A4->Enabled=my_state;
		Form1::A5->Enabled=my_state;
		Form1::A6->Enabled=my_state;
		Form1::A7->Enabled=my_state;
		Form1::A8->Enabled=my_state;
		//---------------------->
		Form1::B1->Enabled=my_state;
		Form1::B2->Enabled=my_state;
		Form1::B3->Enabled=my_state;
		Form1::B4->Enabled=my_state;
		Form1::B5->Enabled=my_state;
		Form1::B6->Enabled=my_state;
		Form1::B7->Enabled=my_state;
		Form1::B8->Enabled=my_state;
		//---------------------->
		Form1::C1->Enabled=my_state;
		Form1::C2->Enabled=my_state;
		Form1::C3->Enabled=my_state;
		Form1::C4->Enabled=my_state;
		Form1::C5->Enabled=my_state;
		Form1::C6->Enabled=my_state;
		Form1::C7->Enabled=my_state;
		Form1::C8->Enabled=my_state;
		//---------------------->
		Form1::D1->Enabled=my_state;
		Form1::D2->Enabled=my_state;
		Form1::D3->Enabled=my_state;
		Form1::D4->Enabled=my_state;
		Form1::D5->Enabled=my_state;
		Form1::D6->Enabled=my_state;
		Form1::D7->Enabled=my_state;
		Form1::D8->Enabled=my_state;
		//---------------------->
		Form1::E1->Enabled=my_state;
		Form1::E2->Enabled=my_state;
		Form1::E3->Enabled=my_state;
		Form1::E4->Enabled=my_state;
		Form1::E5->Enabled=my_state;
		Form1::E6->Enabled=my_state;
		Form1::E7->Enabled=my_state;
		Form1::E8->Enabled=my_state;
		//---------------------->
		Form1::F1->Enabled=my_state;
		Form1::F2->Enabled=my_state;
		Form1::F3->Enabled=my_state;
		Form1::F4->Enabled=my_state;
		Form1::F5->Enabled=my_state;
		Form1::F6->Enabled=my_state;
		Form1::F7->Enabled=my_state;
		Form1::F8->Enabled=my_state;
		//---------------------->
		Form1::G1->Enabled=my_state;
		Form1::G2->Enabled=my_state;
		Form1::G3->Enabled=my_state;
		Form1::G4->Enabled=my_state;
		Form1::G5->Enabled=my_state;
		Form1::G6->Enabled=my_state;
		Form1::G7->Enabled=my_state;
		Form1::G8->Enabled=my_state;
		//---------------------->
		Form1::H1->Enabled=my_state;
		Form1::H2->Enabled=my_state;
		Form1::H3->Enabled=my_state;
		Form1::H4->Enabled=my_state;
		Form1::H5->Enabled=my_state;
		Form1::H6->Enabled=my_state;
		Form1::H7->Enabled=my_state;
		Form1::H8->Enabled=my_state;

		Form1::B_Bishop->Visible=!my_state;
		Form1::B_Knight->Visible=!my_state;
		Form1::B_Rook  ->Visible=!my_state;
		Form1::B_Queen ->Visible=!my_state;

		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));

		if(!my_state)
		{
			if(state)
			{
				Form1::B_Bishop->BackgroundImage=(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
				Form1::B_Rook  ->BackgroundImage=(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
				Form1::B_Queen ->BackgroundImage=(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
				Form1::B_Knight->BackgroundImage=(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
			}
			else
			{
				Form1::B_Bishop->BackgroundImage=(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
				Form1::B_Rook  ->BackgroundImage=(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
				Form1::B_Queen ->BackgroundImage=(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
				Form1::B_Knight->BackgroundImage=(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
			}
		}
	}

	void Form1::ChangeState(int x , int y , bool state)
	{
		Color mycolor;

		switch(x)
		{
			case 0:
			{
				switch(y)
				{
					case 0:
					{
						Form1::A1->Enabled=state;
						break;
					}

					case 1:
					{
						Form1::A2->Enabled=state;
						break;
					}

					case 2:
					{
						Form1::A3->Enabled=state;
						break;
					}

					case 3:
					{
						Form1::A4->Enabled=state;
						break;
					}

					case 4:
					{
						Form1::A5->Enabled=state;
						break;
					}

					case 5:
					{
						Form1::A6->Enabled=state;
						break;
					}

					case 6:
					{
						Form1::A7->Enabled=state;
						break;
					}

					case 7:
					{
						Form1::A8->Enabled=state;
						break;
					}
				}

				break;
			}

			case 1:
			{
				switch(y)
				{
					case 0:
					{
						Form1::B1->Enabled=state;
						break;
					}

					case 1:
					{
						Form1::B2->Enabled=state;
						break;
					}

					case 2:
					{
						Form1::B3->Enabled=state;
						break;
					}

					case 3:
					{
						Form1::B4->Enabled=state;
						break;
					}

					case 4:
					{
						Form1::B5->Enabled=state;
						break;
					}

					case 5:
					{
						Form1::B6->Enabled=state;
						break;
					}

					case 6:
					{
						Form1::B7->Enabled=state;
						break;
					}

					case 7:
					{
						Form1::B8->Enabled=state;
						break;
					}
				}

				break;
			}

			case 2:
			{
				switch(y)
				{
					case 0:
					{
						Form1::C1->Enabled=state;
						break;
					}

					case 1:
					{
						Form1::C2->Enabled=state;
						break;
					}

					case 2:
					{
						Form1::C3->Enabled=state;
						break;
					}

					case 3:
					{
						Form1::C4->Enabled=state;
						break;
					}

					case 4:
					{
						Form1::C5->Enabled=state;
						break;
					}

					case 5:
					{
						Form1::C6->Enabled=state;
						break;
					}

					case 6:
					{
						Form1::C7->Enabled=state;
						break;
					}

					case 7:
					{
						Form1::C8->Enabled=state;
						break;
					}
				}

				break;
			}

			case 3:
			{
				switch(y)
				{
					case 0:
					{
						Form1::D1->Enabled=state;
						break;
					}

					case 1:
					{
						Form1::D2->Enabled=state;
						break;
					}

					case 2:
					{
						Form1::D3->Enabled=state;
						break;
					}

					case 3:
					{
						Form1::D4->Enabled=state;
						break;
					}

					case 4:
					{
						Form1::D5->Enabled=state;
						break;
					}

					case 5:
					{
						Form1::D6->Enabled=state;
						break;
					}

					case 6:
					{
						Form1::D7->Enabled=state;
						break;
					}

					case 7:
					{
						Form1::D8->Enabled=state;
						break;
					}
				}

				break;
			}

			case 4:
			{
				switch(y)
				{
					case 0:
					{
						Form1::E1->Enabled=state;
						break;
					}

					case 1:
					{
						Form1::E2->Enabled=state;
						break;
					}

					case 2:
					{
						Form1::E3->Enabled=state;
						break;
					}

					case 3:
					{
						Form1::E4->Enabled=state;
						break;
					}

					case 4:
					{
						Form1::E5->Enabled=state;
						break;
					}

					case 5:
					{
						Form1::E6->Enabled=state;
						break;
					}

					case 6:
					{
						Form1::E7->Enabled=state;
						break;
					}

					case 7:
					{
						Form1::E8->Enabled=state;
						break;
					}
				}

				break;
			}

			case 5:
			{
				switch(y)
				{
					case 0:
					{
						Form1::F1->Enabled=state;
						break;
					}

					case 1:
					{
						Form1::F2->Enabled=state;
						break;
					}

					case 2:
					{
						Form1::F3->Enabled=state;
						break;
					}

					case 3:
					{
						Form1::F4->Enabled=state;
						break;
					}

					case 4:
					{
						Form1::F5->Enabled=state;
						break;
					}

					case 5:
					{
						Form1::F6->Enabled=state;
						break;
					}

					case 6:
					{
						Form1::F7->Enabled=state;
						break;
					}

					case 7:
					{
						Form1::F8->Enabled=state;
						break;
					}
				}

				break;
			}

			case 6:
			{
				switch(y)
				{
					case 0:
					{
						Form1::G1->Enabled=state;
						break;
					}

					case 1:
					{
						Form1::G2->Enabled=state;
						break;
					}

					case 2:
					{
						Form1::G3->Enabled=state;
						break;
					}

					case 3:
					{
						Form1::G4->Enabled=state;
						break;
					}

					case 4:
					{
						Form1::G5->Enabled=state;
						break;
					}

					case 5:
					{
						Form1::G6->Enabled=state;
						break;
					}

					case 6:
					{
						Form1::G7->Enabled=state;
						break;
					}

					case 7:
					{
						Form1::G8->Enabled=state;
						break;
					}
				}

				break;
			}

			case 7:
			{
				switch(y)
				{
					case 0:
					{
						Form1::H1->Enabled=state;
						break;
					}

					case 1:
					{
						Form1::H2->Enabled=state;
						break;
					}

					case 2:
					{
						Form1::H3->Enabled=state;
						break;
					}

					case 3:
					{
						Form1::H4->Enabled=state;;
						break;
					}

					case 4:
					{
						Form1::H5->Enabled=state;;
						break;
					}

					case 5:
					{
						Form1::H6->Enabled=state;;
						break;
					}

					case 6:
					{
						H7->Enabled=state;;
						break;
					}

					case 7:
					{
						H8->Enabled=state;
						break;
					}
				}

				break;
			}
		}
	}

	void Form1::Colorize(int x , int y , System::Drawing::Color color)
	{
		Color mycolor;

		switch(x)
		{
			case 0:
			{
				switch(y)
				{
					case 0:
					{
						Form1::A1->BackColor=color;
						break;
					}

					case 1:
					{
						Form1::A2->BackColor=color;
						break;
					}

					case 2:
					{
						Form1::A3->BackColor=color;
						break;
					}

					case 3:
					{
						Form1::A4->BackColor=color;
						break;
					}

					case 4:
					{
						Form1::A5->BackColor=color;
						break;
					}

					case 5:
					{
						Form1::A6->BackColor=color;
						break;
					}

					case 6:
					{
						Form1::A7->BackColor=color;
						break;
					}

					case 7:
					{
						Form1::A8->BackColor=color;
						break;
					}
				}

				break;
			}

			case 1:
			{
				switch(y)
				{
					case 0:
					{
						Form1::B1->BackColor=color;
						break;
					}

					case 1:
					{
						Form1::B2->BackColor=color;
						break;
					}

					case 2:
					{
						Form1::B3->BackColor=color;
						break;
					}

					case 3:
					{
						Form1::B4->BackColor=color;
						break;
					}

					case 4:
					{
						Form1::B5->BackColor=color;
						break;
					}

					case 5:
					{
						Form1::B6->BackColor=color;
						break;
					}

					case 6:
					{
						Form1::B7->BackColor=color;
						break;
					}

					case 7:
					{
						Form1::B8->BackColor=color;
						break;
					}
				}

				break;
			}

			case 2:
			{
				switch(y)
				{
					case 0:
					{
						Form1::C1->BackColor=color;
						break;
					}

					case 1:
					{
						Form1::C2->BackColor=color;
						break;
					}

					case 2:
					{
						Form1::C3->BackColor=color;
						break;
					}

					case 3:
					{
						Form1::C4->BackColor=color;
						break;
					}

					case 4:
					{
						Form1::C5->BackColor=color;
						break;
					}

					case 5:
					{
						Form1::C6->BackColor=color;
						break;
					}

					case 6:
					{
						Form1::C7->BackColor=color;
						break;
					}

					case 7:
					{
						Form1::C8->BackColor=color;
						break;
					}
				}

				break;
			}

			case 3:
			{
				switch(y)
				{
					case 0:
					{
						Form1::D1->BackColor=color;
						break;
					}

					case 1:
					{
						Form1::D2->BackColor=color;
						break;
					}

					case 2:
					{
						Form1::D3->BackColor=color;
						break;
					}

					case 3:
					{
						Form1::D4->BackColor=color;
						break;
					}

					case 4:
					{
						Form1::D5->BackColor=color;
						break;
					}

					case 5:
					{
						Form1::D6->BackColor=color;
						break;
					}

					case 6:
					{
						Form1::D7->BackColor=color;
						break;
					}

					case 7:
					{
						Form1::D8->BackColor=color;
						break;
					}
				}

				break;
			}

			case 4:
			{
				switch(y)
				{
					case 0:
					{
						Form1::E1->BackColor=color;
						break;
					}

					case 1:
					{
						Form1::E2->BackColor=color;
						break;
					}

					case 2:
					{
						Form1::E3->BackColor=color;
						break;
					}

					case 3:
					{
						Form1::E4->BackColor=color;
						break;
					}

					case 4:
					{
						Form1::E5->BackColor=color;
						break;
					}

					case 5:
					{
						Form1::E6->BackColor=color;
						break;
					}

					case 6:
					{
						Form1::E7->BackColor=color;
						break;
					}

					case 7:
					{
						Form1::E8->BackColor=color;
						break;
					}
				}

				break;
			}

			case 5:
			{
				switch(y)
				{
					case 0:
					{
						Form1::F1->BackColor=color;
						break;
					}

					case 1:
					{
						Form1::F2->BackColor=color;
						break;
					}

					case 2:
					{
						Form1::F3->BackColor=color;
						break;
					}

					case 3:
					{
						Form1::F4->BackColor=color;
						break;
					}

					case 4:
					{
						Form1::F5->BackColor=color;
						break;
					}

					case 5:
					{
						Form1::F6->BackColor=color;
						break;
					}

					case 6:
					{
						Form1::F7->BackColor=color;
						break;
					}

					case 7:
					{
						Form1::F8->BackColor=color;
						break;
					}
				}

				break;
			}

			case 6:
			{
				switch(y)
				{
					case 0:
					{
						Form1::G1->BackColor=color;
						break;
					}

					case 1:
					{
						Form1::G2->BackColor=color;
						break;
					}

					case 2:
					{
						Form1::G3->BackColor=color;
						break;
					}

					case 3:
					{
						Form1::G4->BackColor=color;
						break;
					}

					case 4:
					{
						Form1::G5->BackColor=color;
						break;
					}

					case 5:
					{
						Form1::G6->BackColor=color;
						break;
					}

					case 6:
					{
						Form1::G7->BackColor=color;
						break;
					}

					case 7:
					{
						Form1::G8->BackColor=color;
						break;
					}
				}

				break;
			}

			case 7:
			{
				switch(y)
				{
					case 0:
					{
						Form1::H1->BackColor=color;
						break;
					}

					case 1:
					{
						Form1::H2->BackColor=color;
						break;
					}

					case 2:
					{
						Form1::H3->BackColor=color;
						break;
					}

					case 3:
					{
						Form1::H4->BackColor=color;;
						break;
					}

					case 4:
					{
						Form1::H5->BackColor=color;;
						break;
					}

					case 5:
					{
						Form1::H6->BackColor=color;;
						break;
					}

					case 6:
					{
						H7->BackColor=color;;
						break;
					}

					case 7:
					{
						H8->BackColor=color;
						break;
					}
				}

				break;
			}
		}
	}

	void Form1::ClearBackGround(int x, int y)
	{
		switch(x)
		{
			case 0:
			{
				switch(y)
				{
					case 0:
					{
						Form1::A1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 1:
					{
						Form1::A2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 2:
					{
						Form1::A3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 3:
					{
						Form1::A4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 4:
					{
						Form1::A5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 5:
					{
						Form1::A6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 6:
					{
						Form1::A7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 7:
					{
						Form1::A8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}
				}

				break;
			}

			case 1:
			{
				switch(y)
				{
					case 0:
					{
						Form1::B1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 1:
					{
						Form1::B2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 2:
					{
						Form1::B3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 3:
					{
						Form1::B4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 4:
					{
						Form1::B5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 5:
					{
						Form1::B6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 6:
					{
						Form1::B7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 7:
					{
						Form1::B8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}
				}

				break;
			}

			case 2:
			{
				switch(y)
				{
					case 0:
					{
						Form1::C1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 1:
					{
						Form1::C2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 2:
					{
						Form1::C3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 3:
					{
						Form1::C4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 4:
					{
						Form1::C5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 5:
					{
						Form1::C6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 6:
					{
						Form1::C7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 7:
					{
						Form1::C8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}
				}

				break;
			}

			case 3:
			{
				switch(y)
				{
					case 0:
					{
						Form1::D1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 1:
					{
						Form1::D2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 2:
					{
						Form1::D3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 3:
					{
						Form1::D4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 4:
					{
						Form1::D5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 5:
					{
						Form1::D6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 6:
					{
						Form1::D7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 7:
					{
						Form1::D8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}
				}

				break;
			}

			case 4:
			{
				switch(y)
				{
					case 0:
					{
						Form1::E1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 1:
					{
						Form1::E2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 2:
					{
						Form1::E3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 3:
					{
						Form1::E4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 4:
					{
						Form1::E5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 5:
					{
						Form1::E6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 6:
					{
						Form1::E7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 7:
					{
						Form1::E8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}
				}

				break;
			}

			case 5:
			{
				switch(y)
				{
					case 0:
					{
						Form1::F1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 1:
					{
						Form1::F2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 2:
					{
						Form1::F3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 3:
					{
						Form1::F4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 4:
					{
						Form1::F5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 5:
					{
						Form1::F6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 6:
					{
						Form1::F7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 7:
					{
						Form1::F8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}
				}

				break;
			}

			case 6:
			{
				switch(y)
				{
					case 0:
					{
						Form1::G1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 1:
					{
						Form1::G2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 2:
					{
						Form1::G3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 3:
					{
						Form1::G4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 4:
					{
						Form1::G5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 5:
					{
						Form1::G6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 6:
					{
						Form1::G7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 7:
					{
						Form1::G8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}
				}

				break;
			}

			case 7:
			{
				switch(y)
				{
					case 0:
					{
						Form1::H1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 1:
					{
						Form1::H2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 2:
					{
						Form1::H3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 3:
					{
						Form1::H4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 4:
					{
						Form1::H5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 5:
					{
						Form1::H6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 6:
					{
						H7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}

					case 7:
					{
						H8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
						break;
					}
				}

				break;
			}
		}



	}

	void Form1::ChangeBackGround(int x , int y , int temp , bool color)
	{
		if(!except)
		{
			ClearBackGround(selected_Loc.Get_X(),selected_Loc.Get_Y());
		}

		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));

		switch(x)
		{
			case 0:
			{
				switch(y)
				{
					case 0://A1
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									Form1::A1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									A1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										A1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										A1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										A1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										A1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										A1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										A1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										A1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										A1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										A1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										A1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
						}
                        break;
					}//END OF A1

					case 1://A2
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									A2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									A2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										A2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										A2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										A2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										A2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										A2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										A2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										A2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										A2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										A2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										A2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}
						break;
					}//END OF A2

					case 2://A3
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									A3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									A3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										A3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										A3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										A3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										A3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										A3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										A3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										A3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										A3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										A3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										A3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A3

					case 3://A4
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									A4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									A4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										A4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										A4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										A4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										A4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										A4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										A4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										A4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										A4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										A4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										A4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
					}
                        break;
                    }//END OF A4

                    case 4://A5
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									A5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									A5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										A5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										A5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										A5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										A5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										A5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										A5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										A5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										A5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										A5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										A5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}
						break;
					}//END OF CASE A5

					case 5://A6
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									A6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									A6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										A6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										A6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										A6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										A6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										A6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										A6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										A6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										A6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										A6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										A6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A6

					case 6://A7
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									A7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									A7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										A7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										A7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										A7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										A7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										A7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										A7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										A7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										A7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										A7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										A7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A7

					case 7://A8
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									A8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									A8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										A8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										A8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										A8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										A8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										A8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										A8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										A8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										A8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										A8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										A8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
						}
						break;
					}
                }//END OF SWITCH 0
                break;
			}

                case 1://second column
                {
                    switch(y)
                    {

			        case 0://B1
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									B1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									B1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										B1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										B1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										B1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										B1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										B1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										B1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										B1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										B1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										B1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										B1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
                        }//END OF A1
                        break;
					}

					case 1://B2
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									B2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									B2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										B2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										B2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										B2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										B2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										B2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										B2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										B2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										B2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										B2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										B2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}

						break;
					}//END OF A2

					case 2://B3
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									B3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									B3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										B3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										B3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										B3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										B3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										B3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										B3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										B3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										B3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										B3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										B3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF B3

					case 3://B4
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									B4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									B4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										B4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										B4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										B4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										B4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										B4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										B4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										B4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										B4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										B4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										B4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
                        }
                        break;
                    }//END OF B4

                    case 4://B5
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									B5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									B5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										B5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										B5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										B5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										B5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										B5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										B5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										B5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										B5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										B5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										B5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}

						break;
					}//END OF CASE B5

					case 5://B6
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									B6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									B6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										B6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										B6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										B6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										B6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										B6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										B6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										B6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										B6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										B6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										B6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF B6

					case 6://B7
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									B7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									B7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										B7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										B7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										B7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										B7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										B7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										B7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										B7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										B7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										B7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										B7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A7

					case 7://B8
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									B8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									B8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										B8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										B8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										B8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										B8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										B8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										B8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										B8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										B8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										B8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										B8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}
                    }//END OF SWITCH 1
                    break;
                }

                    case 2://**********************************
                    {
                        switch(y)
                        {
                    case 0://C1
                    {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									C1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									C1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										C1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										C1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										C1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										C1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										C1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										C1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										C1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										C1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										C1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										C1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
                        }//END OF A1
                        break;
                    }

					case 1://C2
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									C2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									C2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										C2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										C2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										C2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										C2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										C2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										C2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										C2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										C2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										C2->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										C2->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}

						break;
					}//END OF A2

					case 2://C3
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									C3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									C3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										C3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										C3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										C3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										C3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										C3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										C3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										C3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										C3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										C3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										C3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A3

					case 3://C4
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									C4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									C4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										C4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										C4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										C4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										C4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										C4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										C4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										C4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										C4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										C4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										C4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
					}
					break;
				}//END OF A4

                    case 4://C5
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									C5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									C5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										C5->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										C5->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										C5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										C5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										C5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										C5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										C5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										C5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										C5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										C5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}

						break;
					}//END OF CASE A5

					case 5://C6
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									C6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									C6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										C6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										C6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										C6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										C6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										C6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										C6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										C6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										C6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										C6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										C6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A6

					case 6://C7
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									C7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									C7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										C7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										C7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										C7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										C7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										C7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										C7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										C7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										C7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										C7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										C7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A7

					case 7://C8
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									C8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									C8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										C8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										C8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										C8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										C8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										C8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										C8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										C8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										C8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										C8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										C8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}
                        }//END OF SWITCH 2
                        break;
                    }

                    case 3://D1
                    {
                        switch(y)
                        {

                    case 0:
                    {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									D1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									D1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										D1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										D1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										D1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										D1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										D1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										D1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										D1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										D1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										D1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										D1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
                        }//END OF A1
                        break;
                    }

					case 1://D2
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									D2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									D2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										D2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										D2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										D2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										D2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										D2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										D2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										D2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										D2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										D2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										D2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}
						break;
					}//END OF A2

					case 2://D3
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									D3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									D3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										D3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										D3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										D3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										D3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										D3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										D3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										D3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										D3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										D3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										D3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A3

					case 3://D4
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									D4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									D4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										D4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										D4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										D4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										D4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										D4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										D4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										D4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										D4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										D4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										D4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
                        }
                        break;
                    }//END OF A4

                    case 4://D5
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									D5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									D5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										D5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										D5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										D5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										D5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										D5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										D5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										D5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										D5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										D5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										D5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}

						break;
					}//END OF CASE A5

					case 5://D6
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									D6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									D6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										D6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										D6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										D6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										D6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										D6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										D6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										D6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										D6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										D6->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										D6->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A6

					case 6://D7
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									D7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									D7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										D7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										D7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										D7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										D7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										D7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										D7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										D7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										D7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										D7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										D7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A7

					case 7://D8
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									D8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									D8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										D8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										D8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										D8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										D8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										D8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										D8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										D8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										D8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										D8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										D8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}
                        }//END OF SWITCH 3
                        break;
                    }

                    case 4://E1
					{
					    switch(y)
					    {

					    case 0:
					    {

						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									E1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									E1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										E1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										E1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										E1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										E1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										E1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										E1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										E1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										E1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										E1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										E1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
                        }//END OF A1
                            break;
					    }


                        case 1://E2
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									E2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									E2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										E2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										E2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										E2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										E2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										E2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										E2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										E2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										E2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										E2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										E2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}

						break;
					}//END OF A2

                        case 2://E3
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									E3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									E3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										E3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										E3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										E3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										E3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										E3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										E3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										E3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										E3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										E3->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										E3->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A3

                        case 3://E4
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									E4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									E4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										E4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										E4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										E4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										E4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										E4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										E4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										E4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										E4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										E4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										E4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
					}
					break;
				}//END OF A4

                        case 4://E5
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									E5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									E5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										E5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										E5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										E5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										E5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										E5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										E5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										E5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										E5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										E5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										E5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}

						break;
					}//END OF CASE A5

                        case 5://E6
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									E6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									E6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										E6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										E6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										E6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										E6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										E6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										E6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										E6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										E6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										E6->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										E6->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A6

                        case 6://E7
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									E7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									E7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										E7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										E7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										E7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										E7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										E7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										E7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										E7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										E7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										E7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										E7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A7

                        case 7://E8
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									E8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									E8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										E8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										E8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										E8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										E8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										E8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										E8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										E8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										E8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										E8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										E8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
						}
						break;
                        }
                        }//END OF SWITCH 4
                        break;
					}

                    case 5://*************************************************
                    {
                        switch(y)
                        {

                        case 0://F1
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									F1->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									F1->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										F1->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										F1->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										F1->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										F1->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										F1->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										F1->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										F1->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										F1->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										F1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										F1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
                        }//END OF A1
                        break;
                    }

                        case 1://F2
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									F2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									F2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										F2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										F2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										F2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										F2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										F2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										F2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										F2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										F2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										F2->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										F2->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}

						break;
					}//END OF A2

                        case 2://F3
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									F3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									F3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										F3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										F3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										F3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										F3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										F3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										F3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										F3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										F3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										F3->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										F3->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A3

                        case 3://F4
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									F4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									F4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										F4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										F4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										F4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										F4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										F4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										F4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										F4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										F4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										F4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										F4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
					}
					break;
				}//END OF A4

                        case 4://F5
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									F5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									F5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										F5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										F5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										F5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										F5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										F5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										F5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										F5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										F5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										F5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										F5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}

						break;
					}//END OF CASE A5

                        case 5://F6
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									F6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									F6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										F6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										F6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										F6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										F6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										F6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										F6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										F6->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										F6->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										F6->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										F6->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A6

                        case 6://F7
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									F7->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									F7->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										F7->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										F7->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										F7->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										F7->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										F7->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										F7->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										F7->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										F7->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										F7->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										F7->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A7

                        case 7://F8
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									F8->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									F8->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										F8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										F8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										F8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										F8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										F8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										F8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										F8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										F8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										F8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										F8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
						}
						break;
                        }
                        }  //END OF SWITCH 5
                        break;
                    }

                case 6://*************************************************
                {
                    switch(y)
                    {
                    case 0://G1
                    {

						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									G1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									G1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										G1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										G1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										G1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										G1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										G1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										G1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										G1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										G1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										G1->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										G1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}
									break;
							}
                                    break;
                                    }//END OF A1
                    break;
                    }

					case 1://G2
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									G2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									G2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										G2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										G2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										G2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										G2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										G2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										G2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										G2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										G2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										G2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										G2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}

						break;
					}//END OF A2

					case 2://G3
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									G3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									G3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										G3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										G3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										G3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										G3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										G3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										G3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										G3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										G3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										G3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										G3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A3

					case 3://G4
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									G4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									G4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										G4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										G4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										G4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										G4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										G4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										G4->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										G4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										G4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										G4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										G4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
					}
                        break;
                    }//END OF A4

                    case 4://G5
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									G5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									G5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										G5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										G5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										G5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										G5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										G5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										G5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										G5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										G5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										G5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										G5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}

						break;
					}//END OF CASE A5

					case 5://G6
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									G6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									G6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										G6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										G6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										G6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										G6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										G6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										G6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										G6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										G6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										G6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										G6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A6

					case 6://G7
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									G7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									G7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										G7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										G7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										G7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										G7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										G7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										G7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										G7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										G7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										G7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										G7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}//END OF A7

					case 7://G8
					{
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									G8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									G8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										G8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										G8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										G8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										G8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										G8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										G8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										G8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										G8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										G8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										G8->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
					}
                    }//END OF SWITCH 6
                    break;
                }

                case 7://H's
                {
                    switch(y)
                    {
                        case 0://H1
                        {
                            switch(temp)
                            {
                                        case P_Pawn:
                                        {
                                            if(color)
                                            {
                                                H1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
                                            }
                                            else
                                            {
                                                H1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
                                            }

                                            break;
                                        }

                                    case P_Rook:
                                    {
                                        if(color)
                                        {
                                            H1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
                                        }
                                        else
                                        {
                                            H1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
                                        }

                                        break;
                                    }

                                    case P_Knight:
                                    {
                                        if(color)
                                        {
                                            H1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
                                        }
                                        else
                                        {
                                            H1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
                                        }

                                        break;
                                    }

                                    case P_Bishop:
                                    {
                                        if(color)
                                        {
                                            H1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
                                        }
                                        else
                                        {
                                            H1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
                                        }

                                        break;
                                    }

                                    case P_Queen:
                                    {
                                        if(color)
                                        {
                                            H1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
                                        }
                                        else
                                        {
                                            H1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
                                        }

                                        break;
                                    }

                                    case P_King:
                                    {
                                        if(color)
                                        {
                                            H1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
                                        }
                                        else
                                        {
                                            H1->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
                                        }

                                        break;
                                    }

                                    break;
                            }
                            break;
                            }//END OF A1

                        case 1://H2
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									H2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									H2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										H2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										H2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										H2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										H2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										H2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										H2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										H2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										H2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										H2->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										H2->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}

						break;
                            }//END OF A2

                        case 2://H3
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									H3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									H3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										H3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										H3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										H3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										H3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										H3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										H3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										H3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										H3->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										H3->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										H3->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
                            }//END OF A3

                        case 3://H4
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									H4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									H4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										H4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										H4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										H4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										H4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										H4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										H4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										H4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										H4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										H4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										H4->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
					}
                        break;
                            }//END OF A4

                        case 4://H5
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									H5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									H5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										H5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										H5->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										H5->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										H5->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										H5->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										H5->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										H5->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										H5->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										H5->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										H5->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}

							break;
						}

						break;
                            }//END OF CASE A5

                        case 5://H6
                        {
                        switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									H6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									H6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										H6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										H6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										H6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										H6->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										H6->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										H6->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										H6->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										H6->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										H6->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										H6->BackgroundImage =(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
                            }//END OF A6

                        case 6://H7
                        {
						switch(temp)
						{
							case P_Pawn:
							{
								if(color)
								{
									H7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									H7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										H7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										H7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										H7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										H7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										H7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										H7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										H7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										H7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										H7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										H7->BackgroundImage =

(cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
							break;
						}
						break;
                        }//END OF A7

                        case 7://H8
                        {
                            switch(temp)
                            {
							case P_Pawn:
							{
								if(color)
								{
									H8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
								}
								else
								{
									H8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
								}

								break;
							}

							case P_Rook:
							{
									if(color)
									{
										H8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
									}
									else
									{
										H8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
									}

									break;
							}

							case P_Knight:
							{
									if(color)
									{
										H8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
									}
									else
									{
										H8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
									}

									break;
							}

							case P_Bishop:
							{
									if(color)
									{
										H8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
									}
									else
									{
										H8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
									}

									break;
							}

							case P_Queen:
							{
									if(color)
									{
										H8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
									}
									else
									{
										H8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
									}

									break;
							}

							case P_King:
							{
									if(color)
									{
										H8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
									}
									else
									{
										H8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
									}

									break;
							}
                            }
                            break;
                        }
                    }//END OF SWITCH 7
                    break;
                }
		}
		}

	void Form1::B_Knight_Click(System::Object^  sender, System::EventArgs^  e)
	{
		except=true;
		ChangeBackGround(promoted_Loc.Get_X(),promoted_Loc.Get_Y(),P_Knight,promoted_Loc.Get_Y()==7);
		mygame.Promote(promoted_Loc , P_Knight);
		ChangeState(true);
		except=false;
	}

	void Form1::B_Rook_Click(System::Object^  sender, System::EventArgs^  e)
	{
		except=true;
		ChangeBackGround(promoted_Loc.Get_X(),promoted_Loc.Get_Y(),P_Rook,promoted_Loc.Get_Y()==7);
		mygame.Promote(promoted_Loc , P_Rook);
		ChangeState(true);
		except=false;
	}

	void Form1::B_Queen_Click(System::Object^  sender, System::EventArgs^  e)
	{
		except=true;
		ChangeBackGround(promoted_Loc.Get_X(),promoted_Loc.Get_Y(),P_Queen,promoted_Loc.Get_Y()==7);
		mygame.Promote(promoted_Loc , P_Queen);
		ChangeState(true);
		except=false;
	}

	void Form1::B_Bishop_Click(System::Object^  sender, System::EventArgs^  e)
	{
		except=true;
		ChangeBackGround(promoted_Loc.Get_X(),promoted_Loc.Get_Y(),P_Bishop,promoted_Loc.Get_Y()==7);
		mygame.Promote(promoted_Loc , P_Bishop);
		ChangeState(true);
		except=false;
	}

	void Form1::AddLost(bool color , int type)
	{
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));

		if(color){white_lost++;}else{black_lost++;}
		if( color && white_lost==16){return;}
		if(!color && black_lost==16){return;}

			switch(color?white_lost:black_lost)
			{
				case 1:
					{
						switch(type)
		{
				case P_Pawn:
					{
						if(color)
						{
							Form1::White_Lost_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage" )));
						}
						
						break;
					}

				case P_Rook:
					{
						if(color)
						{
							Form1::White_Lost_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage" )));
						}

						break;
					}

				case P_Knight:
					{
						if(color)
						{
							Form1::White_Lost_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage" )));
						}

						break;
					}

				case P_Bishop:
					{
						if(color)
						{
							Form1::White_Lost_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
						}
						else
						{
							Form1::Black_Lost_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage" )));
						}
						
						break;
					}

				case P_Queen:
					{
						if(color)
						{
							Form1::White_Lost_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage" )));
						}

						break;
					}
		}
						break;
					}

				case 2:
					{
						switch(type)
		{
				case P_Pawn:
					{
						if(color)
						{
							Form1::White_Lost_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage" )));
						}
						
						break;
					}

				case P_Rook:
					{
						if(color)
						{
							Form1::White_Lost_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage" )));
						}

						break;
					}

				case P_Knight:
					{
						if(color)
						{
							Form1::White_Lost_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage" )));
						}

						break;
					}

				case P_Bishop:
					{
						if(color)
						{
							Form1::White_Lost_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
						}
						else
						{
							Form1::Black_Lost_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage" )));
						}
						
						break;
					}

				case P_Queen:
					{
						if(color)
						{
							Form1::White_Lost_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage" )));
						}

						break;
					}
		}
						break;
					}

				case 3:
					{
						switch(type)
		{
				case P_Pawn:
					{
						if(color)
						{
							Form1::White_Lost_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage" )));
						}
						
						break;
					}

				case P_Rook:
					{
						if(color)
						{
							Form1::White_Lost_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage" )));
						}

						break;
					}

				case P_Knight:
					{
						if(color)
						{
							Form1::White_Lost_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage" )));
						}

						break;
					}

				case P_Bishop:
					{
						if(color)
						{
							Form1::White_Lost_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
						}
						else
						{
							Form1::Black_Lost_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage" )));
						}
						
						break;
					}

				case P_Queen:
					{
						if(color)
						{
							Form1::White_Lost_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage" )));
						}

						break;
					}
		}
						break;
					}

				case 4:
					{
						switch(type)
							{
				case P_Pawn:
					{
						if(color)
						{
							Form1::White_Lost_4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage" )));
						}
						
						break;
					}

				case P_Rook:
					{
						if(color)
						{
							Form1::White_Lost_4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage" )));
						}

						break;
					}

				case P_Knight:
					{
						if(color)
						{
							Form1::White_Lost_4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage" )));
						}

						break;
					}

				case P_Bishop:
					{
						if(color)
						{
							Form1::White_Lost_4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
						}
						else
						{
							Form1::Black_Lost_4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage" )));
						}
						
						break;
					}

				case P_Queen:
					{
						if(color)
						{
							Form1::White_Lost_4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage" )));
						}

						break;
					}
		}
		
						break;
					}

				case 5:
					{
						switch(type)
		{
				case P_Pawn:
					{
						if(color)
						{
							Form1::White_Lost_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage" )));
						}
						
						break;
					}

				case P_Rook:
					{
						if(color)
						{
							Form1::White_Lost_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage" )));
						}

						break;
					}

				case P_Knight:
					{
						if(color)
						{
							Form1::White_Lost_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage" )));
						}

						break;
					}

				case P_Bishop:
					{
						if(color)
						{
							Form1::White_Lost_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
						}
						else
						{
							Form1::Black_Lost_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage" )));
						}
						
						break;
					}

				case P_Queen:
					{
						if(color)
						{
							Form1::White_Lost_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage" )));
						}

						break;
					}
		}
						break;
					}
					
				case 6:
					{
						switch(type)
		{
				case P_Pawn:
					{
						if(color)
						{
							Form1::White_Lost_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage" )));
						}
						
						break;
					}

				case P_Rook:
					{
						if(color)
						{
							Form1::White_Lost_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage" )));
						}

						break;
					}

				case P_Knight:
					{
						if(color)
						{
							Form1::White_Lost_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage" )));
						}

						break;
					}

				case P_Bishop:
					{
						if(color)
						{
							Form1::White_Lost_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
						}
						else
						{
							Form1::Black_Lost_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage" )));
						}
						
						break;
					}

				case P_Queen:
					{
						if(color)
						{
							Form1::White_Lost_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage" )));
						}

						break;
					}
		}
						break;
					}

				case 7:
					{
						switch(type)
		{
				case P_Pawn:
					{
						if(color)
						{
							Form1::White_Lost_7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage" )));
						}
						
						break;
					}

				case P_Rook:
					{
						if(color)
						{
							Form1::White_Lost_7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage" )));
						}

						break;
					}

				case P_Knight:
					{
						if(color)
						{
							Form1::White_Lost_7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage" )));
						}

						break;
					}

				case P_Bishop:
					{
						if(color)
						{
							Form1::White_Lost_7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
						}
						else
						{
							Form1::Black_Lost_7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage" )));
						}
						
						break;
					}

				case P_Queen:
					{
						if(color)
						{
							Form1::White_Lost_7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage" )));
						}

						break;
					}
		}
						break;
					}

				case 8:
					{
						switch(type)
		{
				case P_Pawn:
					{
						if(color)
						{
							Form1::White_Lost_8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage" )));
						}
						
						break;
					}

				case P_Rook:
					{
						if(color)
						{
							Form1::White_Lost_8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage" )));
						}

						break;
					}

				case P_Knight:
					{
						if(color)
						{
							Form1::White_Lost_8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage" )));
						}

						break;
					}

				case P_Bishop:
					{
						if(color)
						{
							Form1::White_Lost_8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
						}
						else
						{
							Form1::Black_Lost_8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage" )));
						}
						
						break;
					}

				case P_Queen:
					{
						if(color)
						{
							Form1::White_Lost_8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage" )));
						}

						break;
					}
		}
						break;
					}

				case 9:
					{
						switch(type)
		{
				case P_Pawn:
					{
						if(color)
						{
							Form1::White_Lost_9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage" )));
						}
						
						break;
					}

				case P_Rook:
					{
						if(color)
						{
							Form1::White_Lost_9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage" )));
						}

						break;
					}

				case P_Knight:
					{
						if(color)
						{
							Form1::White_Lost_9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage" )));
						}

						break;
					}

				case P_Bishop:
					{
						if(color)
						{
							Form1::White_Lost_9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
						}
						else
						{
							Form1::Black_Lost_9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage" )));
						}
						
						break;
					}

				case P_Queen:
					{
						if(color)
						{
							Form1::White_Lost_9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage" )));
						}

						break;
					}
		}
						break;
					}

				case 10:
					{
						switch(type)
		{
				case P_Pawn:
					{
						if(color)
						{
							Form1::White_Lost_10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage" )));
						}
						
						break;
					}

				case P_Rook:
					{
						if(color)
						{
							Form1::White_Lost_10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage" )));
						}

						break;
					}

				case P_Knight:
					{
						if(color)
						{
							Form1::White_Lost_10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage" )));
						}

						break;
					}

				case P_Bishop:
					{
						if(color)
						{
							Form1::White_Lost_10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
						}
						else
						{
							Form1::Black_Lost_10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage" )));
						}
						
						break;
					}

				case P_Queen:
					{
						if(color)
						{
							Form1::White_Lost_10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage" )));
						}

						break;
					}
		}
						break;
					}

				case 11:
					{
						switch(type)
		{
				case P_Pawn:
					{
						if(color)
						{
							Form1::White_Lost_11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage" )));
						}
						
						break;
					}

				case P_Rook:
					{
						if(color)
						{
							Form1::White_Lost_11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage" )));
						}

						break;
					}

				case P_Knight:
					{
						if(color)
						{
							Form1::White_Lost_11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage" )));
						}

						break;
					}

				case P_Bishop:
					{
						if(color)
						{
							Form1::White_Lost_11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
						}
						else
						{
							Form1::Black_Lost_11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage" )));
						}
						
						break;
					}

				case P_Queen:
					{
						if(color)
						{
							Form1::White_Lost_11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage" )));
						}

						break;
					}
		}
						break;
					}

				case 12:
					{
						switch(type)
		{
				case P_Pawn:
					{
						if(color)
						{
							Form1::White_Lost_12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage" )));
						}
						
						break;
					}

				case P_Rook:
					{
						if(color)
						{
							Form1::White_Lost_12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage" )));
						}

						break;
					}

				case P_Knight:
					{
						if(color)
						{
							Form1::White_Lost_12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage" )));
						}

						break;
					}

				case P_Bishop:
					{
						if(color)
						{
							Form1::White_Lost_12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
						}
						else
						{
							Form1::Black_Lost_12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage" )));
						}
						
						break;
					}

				case P_Queen:
					{
						if(color)
						{
							Form1::White_Lost_12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage" )));
						}

						break;
					}
		}
						break;
					}

				case 13:
					{
						switch(type)
		{
				case P_Pawn:
					{
						if(color)
						{
							Form1::White_Lost_13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage" )));
						}
						
						break;
					}

				case P_Rook:
					{
						if(color)
						{
							Form1::White_Lost_13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage" )));
						}

						break;
					}

				case P_Knight:
					{
						if(color)
						{
							Form1::White_Lost_13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage" )));
						}

						break;
					}

				case P_Bishop:
					{
						if(color)
						{
							Form1::White_Lost_13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
						}
						else
						{
							Form1::Black_Lost_13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage" )));
						}
						
						break;
					}

				case P_Queen:
					{
						if(color)
						{
							Form1::White_Lost_13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage" )));
						}

						break;
					}
		}
						break;
					}

				case 14:
					{
						switch(type)
		{
				case P_Pawn:
					{
						if(color)
						{
							Form1::White_Lost_14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage" )));
						}
						
						break;
					}

				case P_Rook:
					{
						if(color)
						{
							Form1::White_Lost_14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage" )));
						}

						break;
					}

				case P_Knight:
					{
						if(color)
						{
							Form1::White_Lost_14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage" )));
						}

						break;
					}

				case P_Bishop:
					{
						if(color)
						{
							Form1::White_Lost_14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
						}
						else
						{
							Form1::Black_Lost_14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage" )));
						}
						
						break;
					}

				case P_Queen:
					{
						if(color)
						{
							Form1::White_Lost_14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage" )));
						}

						break;
					}
		}
						break;
					}

				case 15:
					{
						switch(type)
		{
				case P_Pawn:
					{
						if(color)
						{
							Form1::White_Lost_15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage" )));
						}
						
						break;
					}

				case P_Rook:
					{
						if(color)
						{
							Form1::White_Lost_15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage" )));
						}

						break;
					}

				case P_Knight:
					{
						if(color)
						{
							Form1::White_Lost_15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage" )));
						}

						break;
					}

				case P_Bishop:
					{
						if(color)
						{
							Form1::White_Lost_15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
						}
						else
						{
							Form1::Black_Lost_15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage" )));
						}
						
						break;
					}

				case P_Queen:
					{
						if(color)
						{
							Form1::White_Lost_15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage" )));
						}
						else
						{
							Form1::Black_Lost_15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage" )));
						}

						break;
					}
						}
						break;
					}
			}
			}

	void Form1::ClearLost()
	{
		white_lost=0;
		black_lost=0;
		Form1::White_Lost_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::White_Lost_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::White_Lost_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::White_Lost_4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::White_Lost_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::White_Lost_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::White_Lost_7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::White_Lost_8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::White_Lost_9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::White_Lost_10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::White_Lost_11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::White_Lost_12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::White_Lost_13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::White_Lost_14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::White_Lost_15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::Black_Lost_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::Black_Lost_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::Black_Lost_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::Black_Lost_4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::Black_Lost_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::Black_Lost_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::Black_Lost_7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::Black_Lost_8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::Black_Lost_9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::Black_Lost_10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::Black_Lost_11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::Black_Lost_12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::Black_Lost_13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::Black_Lost_14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
		Form1::Black_Lost_15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(nullptr));
	}

	void Form1::toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SaveFile->ShowDialog();
		string name;
		MarshalString(SaveFile->FileName,name);
		mygame.Save(name);
	}

	void Form1::toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFile->ShowDialog();
		string name;
		MarshalString(SaveFile->FileName,name);
		mygame.Load(name);
		RefreshTable();
	}

	void Form1::toolStripButton3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if(mygame.LoadInformation(-1))
		{
			state=!state;
			RefreshTable();
		}
	}

	void Form1::toolStripButton4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if(mygame.LoadInformation(1))
		{
			state=!state;
			RefreshTable();
		}
	}

	void Form1::RefreshTable()
	{
		except=true;

		int WhiteCount=0;
		int BlackCount=0;

		int  table [8][8]={0};
		int  Pieces[8][8]={0};
		bool Colors[8][8];
		
		int* White_Lost=new int[16];
		int* Black_Lost=new int[16];

		mygame.GetArgFrom(table , Pieces , Colors , White_Lost , Black_Lost , WhiteCount , BlackCount );

		ClearLost();

		for(int i=0;i<8;i++)//i for column
		{
			for(int j=0;j<8;j++)//j for row
			{
				if(Pieces[i][j]!=0)
				{
					ChangeBackGround(i,j,Pieces[i][j],Colors[i][j]);
				}
				else
				{
					ClearBackGround(i,j);
				}
			}
		}

		for(int i=0;i<WhiteCount;i++)
		{
			AddLost(White,White_Lost[i]);
		}

		for(int i=0;i<BlackCount;i++)
		{
			AddLost(Black,Black_Lost[i]);
		}

		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				ID_Table[i][i]=table[i][j];
			}
		}

		except=false;
	}

	void Form1::checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if(checkBox1->Checked)
		{
			checkBox1->Text="Disable Artificial Intelligence";
			mygame.ChangeAIState();
		}
		else
		{
			checkBox1->Text="Enable Artificial Intelligence";
			mygame.ChangeAIState();
		}
	}
	
	void Form1::Artificial_Move()	
	{
		int I_X ;
		int I_Y ;
		int O_X ; 
		int O_Y ;
		mygame.AIconvertor(I_X,I_Y,O_X ,O_Y);
		int Temp_ID=ID_Table[I_X][I_Y];
		PieceInfo temp =mygame.SearchTypeByID(Temp_ID);
		PieceInfo temp2=mygame.SearchTypeByID(ID_Table[O_X][O_Y]);

		if(mygame.MoveByID(Temp_ID,O_X,O_Y))
		{

			ID_Table[I_X][I_Y]=0;
			ID_Table[O_X][O_Y]=Temp_ID;
			ChangeBackGround(O_X,O_Y,temp.type,temp.color);
			ClearBackGround(I_X,I_Y);
		}
		DeSelect(Saved_Pos);
	}

};//end of namespace

