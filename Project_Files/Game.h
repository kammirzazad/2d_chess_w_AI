#ifndef GAME_H
#define GAME_H

#include "stdafx.h"

#include "Table.h" 
#include "OtherPieces.h"
#include "ArtificialIntelligence.h"

#include <vector>
#include <fstream>
#include <iostream>

#define White    true
#define Black    false

#define Left     true
#define Right    false

using namespace System;

void MarshalString(String ^ s,string & os)
{
		using namespace Runtime::InteropServices;
		const char* chars=(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os=chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
}

class Game
{
	private:

		int    NumberOfMoves;
		int    currentsave;
        bool   current_player;
		bool   AI_state;

		//********************************************>Castling Information
        int  W_King_ID;
        int  W_Rook_L_ID;
        int  W_Rook_R_ID;
		//---------------//
        int  B_King_ID;
        int  B_Rook_L_ID;
        int  B_Rook_R_ID;

		//********************************************
        Table  game_table;//running default-contructor
        int**  temp_table;

		Piece** White_Pieces;
		Piece** Black_Pieces;
		vector <Table> table_save;
		//*******************************************

	public:

		Game()
		{
			currentsave=0;
			current_player=true;
			AI_state = false;

			temp_table=new int*[8];

			for(int u=0;u<8;u++)
			{
				temp_table[u]=new int[8];
			}

			int base_ID=200;//----------->choose default value

			White_Pieces=new Piece*[16];
			Black_Pieces=new Piece*[16];

			for(int i=0;i<8;i++)
			{
			   White_Pieces[i]=new Pawn(i,1,base_ID++,White);
			}

            W_Rook_L_ID=base_ID;
			White_Pieces[8] =new Rook  (0,0,base_ID++,White);//White Left Rook
			White_Pieces[9] =new Knight(1,0,base_ID++,White);
			White_Pieces[10]=new Bishop(2,0,base_ID++,White);
			White_Pieces[11]=new Queen (3,0,base_ID++,White);
			W_King_ID=base_ID;
			White_Pieces[12]=new King  (4,0,base_ID++,White);//White King
			White_Pieces[13]=new Bishop(5,0,base_ID++,White);
			White_Pieces[14]=new Knight(6,0,base_ID++,White);
			W_Rook_R_ID=base_ID;
			White_Pieces[15]=new Rook  (7,0,base_ID++,White);//White Right Rook

			for(int i=0;i<8;i++)
			{
			   this->Black_Pieces[i]=new Pawn(i,6,base_ID++,Black);
			}

			B_Rook_L_ID=base_ID;
			Black_Pieces[8] =new Rook  (0,7,base_ID++,Black);//Black Left Rook
			Black_Pieces[9] =new Knight(1,7,base_ID++,Black);
			Black_Pieces[10]=new Bishop(2,7,base_ID++,Black);
			Black_Pieces[11]=new Queen (3,7,base_ID++,Black);
			B_King_ID=base_ID;
			Black_Pieces[12]=new King  (4,7,base_ID++,Black);//Black King
			Black_Pieces[13]=new Bishop(5,7,base_ID++,Black);
			Black_Pieces[14]=new Knight(6,7,base_ID++,Black);
			B_Rook_R_ID=base_ID;
			Black_Pieces[15]=new Rook  (7,7,base_ID++,Black);//Black Right Rook
		}

		int** Get_Pos_Loc(int selected_ID)
		{
			//Initialize

			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					temp_table[i][j]=0;
				}
			}

			//Detect Piece Type 
			for(int i=0;i<16;i++)
			{
				     if(White_Pieces[i]->_ID == selected_ID)
				{
					White_Pieces[i]->Get_Pos_Loc(game_table,temp_table);
					break;

				}
				else if(Black_Pieces[i]->_ID == selected_ID)
				{
					Black_Pieces[i]->Get_Pos_Loc(game_table,temp_table);
					break;
				}
			}

			CheckCastling(selected_ID);

			return temp_table;
		}

		bool GetCurrent()
		{
			return current_player;
		}

		bool IsKingSafe()
		{
			if(current_player)
			{
				return game_table.IsSafe(White_Pieces[12]->GetLoc(),current_player);
			}
			else
			{
				return game_table.IsSafe(Black_Pieces[12]->GetLoc(),current_player);
			}
		}

		bool MoveByID(int ID , int Des_X , int Des_Y)
		{
			for(int i=0;i<16;i++)
			{
				if(current_player)
				{
				    if(White_Pieces[i]->_ID == ID)
					{
						Table temp(game_table);
						temp.MoveFromTo(White_Pieces[i]->GetLoc(),Des_X,Des_Y);

						bool result=temp.IsSafe(White_Pieces[12]->GetLoc(),White);

						if(result)
						{
							game_table.MoveFromTo(White_Pieces[i]->GetLoc(),Des_X,Des_Y);
							SaveInformation();

							if(SearchAttackByLocation(Des_X,Des_Y,White) || White_Pieces[i]->GetInfo().type==P_Pawn )
							{
								NumberOfMoves=0;
							}
							else
							{
								NumberOfMoves++;
							}

							White_Pieces[i]->Move(Des_X,Des_Y);
							current_player=!current_player;
						}
						
						return result;
					}
				}
				else
				{
					if(Black_Pieces[i]->_ID == ID)
					{
						Table temp(game_table);
						temp.MoveFromTo(Black_Pieces[i]->GetLoc(),Des_X,Des_Y);

						bool result=temp.IsSafe(Black_Pieces[12]->GetLoc(),Black);

						if(result)
						{
							game_table.MoveFromTo(Black_Pieces[i]->GetLoc(),Des_X,Des_Y);
							SaveInformation();

							if(SearchAttackByLocation(Des_X,Des_Y,Black) || Black_Pieces[i]->GetInfo().type==P_Pawn )
							{
								NumberOfMoves=0;
							}
							else
							{
								NumberOfMoves++;
							}

							Black_Pieces[i]->Move(Des_X,Des_Y);
							current_player=!current_player;
						}
						
						return result;
					}
				}
			}
		}

		void ChangeAIState()
		{
			AI_state=!AI_state;
		}

		void Castle(bool color, bool leftright )
		{
			SaveInformation();

			if(color)
			{
				if(leftright)
				{
					White_Pieces[ 8]->Move(3,0);
					White_Pieces[12]->Move(2,0);
				}
				else
				{
					White_Pieces[12]->Move(6,0);
					White_Pieces[15]->Move(5,0);
				}
			}
			else
			{
				if(leftright)
				{
					Black_Pieces[ 8]->Move(3,0);
					Black_Pieces[12]->Move(2,0);
				}
				else
				{
					Black_Pieces[12]->Move(6,0);
					Black_Pieces[15]->Move(5,0);
				}
			}

			current_player=!current_player;
		}

		void Promote(Location arg_promote , int type)
		{
			for(int i=0;i<8;i++)
			{
				if(White_Pieces[i]->GetLoc()==arg_promote)
				{
					int selected_ID=White_Pieces[i]->_ID;
					delete White_Pieces[i];

					if(type==P_Rook)
					{
						White_Pieces[i]=new Rook(arg_promote.Get_X()  ,arg_promote.Get_Y(),selected_ID,White);
					}
					else if(type==P_Knight)
					{
						White_Pieces[i]=new Knight(arg_promote.Get_X(),arg_promote.Get_Y(),selected_ID,White);
					}
					else if(type==P_Bishop)
					{
						White_Pieces[i]=new Bishop(arg_promote.Get_X(),arg_promote.Get_Y(),selected_ID,White);
					}
					else //Queen
					{
						White_Pieces[i]=new Queen (arg_promote.Get_X(),arg_promote.Get_Y(),selected_ID,White);
					}

					return;
				}
				
				if(Black_Pieces[i]->GetLoc()==arg_promote)
				{
					int selected_ID=Black_Pieces[i]->_ID;
					delete Black_Pieces[i];

					if(type==P_Rook)
					{
						Black_Pieces[i]=new Rook(arg_promote.Get_X(),arg_promote.Get_Y(),selected_ID,Black);
					}
					else if(type==P_Knight)
					{
						Black_Pieces[i]=new Knight(arg_promote.Get_X(),arg_promote.Get_Y(),selected_ID,Black);
					}
					else if(type==P_Bishop)
					{
						Black_Pieces[i]=new Bishop(arg_promote.Get_X(),arg_promote.Get_Y(),selected_ID,Black);
					}
					else //Queen
					{
						Black_Pieces[i]=new Queen (arg_promote.Get_X(),arg_promote.Get_Y(),selected_ID,Black);
					}

					return;
				}
			}
		}

		void Save(string arg)
		{
			ofstream saveChess(arg);

			for(int i=0;i<16;i++)
			{
				White_Pieces[i]->Save(saveChess);
			}

			for(int i=0;i<16;i++)
			{
				Black_Pieces[i]->Save(saveChess);
			}

			saveChess.close();
		}

		void Load(string arg)
		{
			ifstream loadChess(arg);

			for(int i=0;i<16;i++)
			{
				White_Pieces[i]->Load(loadChess);
			}

			for(int i=0;i<16;i++)
			{
				Black_Pieces[i]->Load(loadChess);
			}

			loadChess.close();
		}

		bool LoadInformation(int i)
		{
			if(i==-1 && currentsave==0)
			{
				return false;
			}

			current_player=!current_player;
			currentsave+=i;
			String^ name="2dCHESS"+currentsave.ToString()+".chess";
			string  name2;
			MarshalString(name,name2);
			ifstream new_info(name2);

			if(!new_info)//
			{
				currentsave-=i;
				return false;
			}

			for(int i=0;i<16;i++)
			{
				White_Pieces[i]->Load(new_info);
			}

			for(int i=0;i<16;i++)
			{
				Black_Pieces[i]->Load(new_info);
			}

			new_info.close();
			return true;
		}

		PieceInfo  SearchTypeByID(int selected_ID)
		{
			for(int i=0;i<16;i++)
			{
				if(White_Pieces[i]->_ID==selected_ID)
				{
					return White_Pieces[i]->GetInfo();
				}
				
				if(Black_Pieces[i]->_ID==selected_ID)
				{
					return Black_Pieces[i]->GetInfo();
				}
			}
		}

		void GetArgFrom(int table[8][8] , int Pieces[8][8] , bool Colors[8][8] , int* White_Lost  , int* Black_Lost , int &WhiteCount , int &BlackCount )
		{
			for(int k=0;k<16;k++)
			{
						if(White_Pieces[k]->_available)
						{
							table[White_Pieces[k]->GetLoc().Get_X()][White_Pieces[k]->GetLoc().Get_Y()]=White_Pieces[k]->_ID;
							Pieces[White_Pieces[k]->GetLoc().Get_X()][White_Pieces[k]->GetLoc().Get_Y()]=White_Pieces[k]->GetInfo().type;
							Colors [White_Pieces[k]->GetLoc().Get_X()][White_Pieces[k]->GetLoc().Get_Y()]=White_Pieces[k]->GetInfo().color;
							game_table.Set(White_Pieces[k]->GetLoc().Get_X(), White_Pieces[k]->GetLoc().Get_Y() , White_Pieces[k]->GetInfo()); 
						}
						else
						{
							White_Lost[WhiteCount++]=White_Pieces[k]->GetInfo().type;
						}
				
						if(Black_Pieces[k]->_available)
						{
							table[Black_Pieces[k]->GetLoc().Get_X()][Black_Pieces[k]->GetLoc().Get_Y()]=Black_Pieces[k]->_ID;
							Pieces[Black_Pieces[k]->GetLoc().Get_X()][Black_Pieces[k]->GetLoc().Get_Y()]=Black_Pieces[k]->GetInfo().type;
							Colors[Black_Pieces[k]->GetLoc().Get_X()][Black_Pieces[k]->GetLoc().Get_Y()]=Black_Pieces[k]->GetInfo().color;
							game_table.Set(Black_Pieces[k]->GetLoc().Get_X(), Black_Pieces[k]->GetLoc().Get_Y() , Black_Pieces[k]->GetInfo()); 
						}
						else
						{
							Black_Lost[BlackCount++]=Black_Pieces[k]->GetInfo().type;
						}
			}

		}

		void AIconvertor(int &Origin_X , int &Origin_Y, int &Des_X , int &Des_Y)
		{
			Location temp_from;
			Location temp_to;
			ArtificialIntelligence::AI_MOVER(game_table,temp_from,temp_to);
			Origin_X=temp_from.Get_X();
			Origin_Y=temp_from.Get_Y();
			Des_X=temp_to.Get_X();
			Des_Y=temp_to.Get_Y();
		}
	private:

		void SaveInformation()
		{
			String^ name="2dCHESS"+currentsave.ToString()+".chess";
			string  name2;
			MarshalString(name,name2);
			ofstream new_info(name2);

			for(int i=0;i<16;i++)
			{
				White_Pieces[i]->Save(new_info);
			}

			for(int i=0;i<16;i++)
			{
				Black_Pieces[i]->Save(new_info);
			}

			new_info.close();

			currentsave++;
		}

		bool CheckMove(bool color , bool leftright)//true for left , false for right
		{
			if(color)
			{
				if(White_Pieces[12]->_moved)
				{
					return false;
				}
				else
				{
					if(leftright)
					{
						return !White_Pieces[8]->_moved;
					}
					else
					{
						return !White_Pieces[15]->_moved;
					}
				}
			}
			else
			{
				if(Black_Pieces[12]->_moved)
				{
					return false;
				}
				else
				{
					if(leftright)
					{
						return !Black_Pieces[8]->_moved;
					}
					else
					{
						return !Black_Pieces[15]->_moved;
					}
				}
			}
		}
	
		bool SearchAttackByLocation(int x, int y , bool color)
		{
			if(!color)
			{
				for(int i=0;i<16;i++)
				{
					if(White_Pieces[i]->GetLoc().Get_X()==x && White_Pieces[i]->GetLoc().Get_Y()==y)
					{
						White_Pieces[i]->_available=false;
						return true;
					}
				}

				return false;
			}
			else
			{
				for(int i=0;i<16;i++)
				{
					if(Black_Pieces[i]->GetLoc().Get_X()==x && Black_Pieces[i]->GetLoc().Get_Y()==y)
					{
						Black_Pieces[i]->_available=false;
						return true;
					}
				}

				return false;
			}
		}

		int  CheckEndOfGame(int id , bool color)
		{
			if(NumberOfMoves==50)
			{
				return 5;//game resulted in draw
			}

			int count=0;

			for(int i=0;i<table_save.size();i++)
			{
				if(table_save[i]==game_table)
				{
					count++;
				}
			}

			if(count>=3)
			{
				return 5;
			}
			else
			{
				table_save.push_back(game_table);
			}

			Black_Pieces[12]->Get_Pos_Loc(game_table,temp_table);

			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					if(temp_table[i][j]!=0)
					{
						return 1;//1st player won
					}
				}
			}

			White_Pieces[12]->Get_Pos_Loc(game_table,temp_table);

			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					if(temp_table[i][j]!=0)
					{
						return -1;//2nd player won
					}
				}
			}

			return 0;//game is not ended
		}

		void CheckCastling(int ID)
		{
			Location base_loc(0,0);

			     if(ID==W_King_ID  )
			{
				base_loc=White_Pieces[12]->_loc;

				if(CheckMove(White , Left  ))
				{
					if(game_table.IsNull(base_loc.Horizontal(-1)) && game_table.IsNull(base_loc.Horizontal(-2)) && game_table.IsNull(base_loc.Horizontal(-3)))
					{
						if(game_table.IsSafe(base_loc,White) && game_table.IsSafe(base_loc.Horizontal(-1),White) && game_table.IsSafe(base_loc.Horizontal(-2),White))
						{
							temp_table[2][0]=Selected_Castle;
						}
					}	
				}

				if(CheckMove(White , Right ))
				{
					if(game_table.IsNull(base_loc.Horizontal(1)) && game_table.IsNull(base_loc.Horizontal(2)) )
					{
						if(game_table.IsSafe(base_loc,White) && game_table.IsSafe(base_loc.Horizontal(1),White) && game_table.IsSafe(base_loc.Horizontal(2),White))
						{
							temp_table[6][0]=Selected_Castle;
						}
					}
					
				}
			}
			else if(ID==W_Rook_L_ID)
			{
				base_loc=White_Pieces[12]->_loc;

				if(CheckMove(White , Left  ))
				{
					if(game_table.IsNull(base_loc.Horizontal(-1)) && game_table.IsNull(base_loc.Horizontal(-2)) && game_table.IsNull(base_loc.Horizontal(-3)))
					{
						if(game_table.IsSafe(base_loc,White) && game_table.IsSafe(base_loc.Horizontal(-1),White) && game_table.IsSafe(base_loc.Horizontal(-2),White))
						{
							temp_table[3][0]=Selected_Castle;
						}
					}	
				}
			}
			else if(ID==W_Rook_R_ID)
			{
				base_loc=White_Pieces[12]->_loc;

				if(CheckMove(White , Right ))
				{
					if(game_table.IsNull(base_loc.Horizontal(1)) && game_table.IsNull(base_loc.Horizontal(2)) )
					{
						if(game_table.IsSafe(base_loc,White) && game_table.IsSafe(base_loc.Horizontal(1),White) && game_table.IsSafe(base_loc.Horizontal(2),White))
						{
							temp_table[5][0]=Selected_Castle;
						}
					}
				}
			}
			else if(ID==B_King_ID  )
			{
				base_loc=Black_Pieces[12]->_loc;

				if(CheckMove(Black , Left  ))
				{
					if(game_table.IsNull(base_loc.Horizontal(-1)) && game_table.IsNull(base_loc.Horizontal(-2)) && game_table.IsNull(base_loc.Horizontal(-3)))
					{
						if(game_table.IsSafe(base_loc,Black) && game_table.IsSafe(base_loc.Horizontal(-1),Black) && game_table.IsSafe(base_loc.Horizontal(-2),Black))
						{
							temp_table[2][8]=Selected_Castle;
						}
					}	
				}

				if(CheckMove(Black , Right ))
				{
					if(game_table.IsNull(base_loc.Horizontal(1)) && game_table.IsNull(base_loc.Horizontal(2)) )
					{
						if(game_table.IsSafe(base_loc,Black) && game_table.IsSafe(base_loc.Horizontal(1),Black) && game_table.IsSafe(base_loc.Horizontal(2),Black))
						{
							temp_table[6][8]=Selected_Castle;
						}
					}
				}
			}
			else if(ID==B_Rook_L_ID)
			{
				base_loc=Black_Pieces[12]->_loc;

				if(CheckMove(Black , Left  ))
				{
					if(game_table.IsNull(base_loc.Horizontal(-1)) && game_table.IsNull(base_loc.Horizontal(-2)) && game_table.IsNull(base_loc.Horizontal(-3)))
					{
						if(game_table.IsSafe(base_loc,Black) && game_table.IsSafe(base_loc.Horizontal(-1),Black) && game_table.IsSafe(base_loc.Horizontal(-2),Black))
						{
							temp_table[3][8]=Selected_Castle;
						}
					}	
				}
			}
			else if(ID==B_Rook_R_ID)
			{
				base_loc=Black_Pieces[12]->_loc;

				if(CheckMove(Black , Right ))
				{
					if(game_table.IsNull(base_loc.Horizontal(1)) && game_table.IsNull(base_loc.Horizontal(2)) )
					{
						if(game_table.IsSafe(base_loc,Black) && game_table.IsSafe(base_loc.Horizontal(1),Black) && game_table.IsSafe(base_loc.Horizontal(2),Black))
						{
							temp_table[5][8]=Selected_Castle;
						}
					}
				}

			}

		}
		 
};

#endif GAME_H


