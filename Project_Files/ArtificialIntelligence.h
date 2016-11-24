#ifndef ARTIFICIALINTELLIGENCE_H
#define ARTIFICIALINTELLIGENCE_H

//----------------------------------------->
#define P_Pawn     2000
#define P_Rook     2001
#define P_Knight   2002
#define P_Bishop   2003
#define P_Queen    2004
#define P_King     2005

#define Selected          100
#define Selected_Attack   200
#define Selected_Maintain 300

#define White    true
#define Black    false
//----------------------------------------->

class ArtificialIntelligence
{
public:
	static void AI_MOVER(Table , Location & , Location &);
	static int Finished_Checker(Table , bool, int);
	static bool Is_Checked_Cheker(Table & , bool);
private:
	static void Mover(Table &, Location & , Location & );
	static double Evaluate_Material(Table);
	static double Evaluate_Movability(Table);
	static int Evaluate_Isolated(Table);
	static int Evaluate_Doubled(Table);
	static int Evaluate_Backward(Table);
	static double Evaluate_Table(Table);
	static int Evaluate_number_possible_moves(Table,bool);
};
double ArtificialIntelligence::Evaluate_Material(Table in_table)
{
	int k=0,kp=0,q=0,qp=0,r=0,rp=0,b=0,bp=0,n=0,np=0,p=0,pp=0;
	
	for(int i=0 ; i<8 ; i++)
	{
		for(int j=0 ; j<8 ; j++)
		{
			if ( in_table.At(i,j).type == P_Pawn)
			{
				if( in_table.At(i,j).color==0 )
				p++;
				else pp++;
			}
			if ( in_table.At(i,j).type == P_Rook)
			{
				if( in_table.At(i,j).color==0 )
				r++;
				else rp++;
			}
			if ( in_table.At(i,j).type == P_Knight)
			{
				if( in_table.At(i,j).color==0 )
				n++;
				else np++;
			}
			if ( in_table.At(i,j).type == P_Bishop)
			{
				if( in_table.At(i,j).color==0 )
				b++;
				else bp++;
			}
			if ( in_table.At(i,j).type == P_Queen)
			{
				if( in_table.At(i,j).color==0 )
				q++;
				else qp++;
			}
			if ( in_table.At(i,j).type == P_King)
			{
				if( in_table.At(i,j).color==0 )
				k++;
				else kp++;
			}
		}
	}
	double material;
	material = 200*(k-kp)+9*(q-qp)+5*(r-rp)+3*(b-bp+n-np)+(p-pp);
	return material;
}
double ArtificialIntelligence::Evaluate_Movability(Table in_table)
{
	int b_movability=0;
	int w_movability=0;
	for(int i=0 ; i<8 ; i++)
	{
		for(int j=0 ; j<8 ; j++)
		{
			if(in_table.At(i,j).color==0)
			{
				if(in_table.At(i,j).type==P_Pawn)
				{
					
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}

					Pawn temp_pawn(i,j,0,Black);
					temp_pawn.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) b_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==1)
			{
				if(in_table.At(i,j).type==P_Pawn)
				{
					
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}

					Pawn temp_pawn(i,j,0,White);
					temp_pawn.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) w_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==0)
			{
				if(in_table.At(i,j).type==P_Rook)
				{
					
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}

					Rook temp_rook(i,j,0,Black);
					temp_rook.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) b_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==1)
			{
				if(in_table.At(i,j).type==P_Rook)
				{
					
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}

					Rook temp_rook(i,j,0,White);
					temp_rook.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) w_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==0)
			{
				if(in_table.At(i,j).type==P_Knight)
				{
					
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}

					Knight temp_knight(i,j,0,Black);
					temp_knight.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) b_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==1)
			{
				if(in_table.At(i,j).type==P_Knight)
				{
					
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}

					Knight temp_knight(i,j,0,White);
					temp_knight.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) w_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==0)
			{
				if(in_table.At(i,j).type==P_Bishop)
				{
					
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}

					Bishop temp_bishop(i,j,0,Black);
					temp_bishop.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) b_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==1)
			{
				if(in_table.At(i,j).type==P_Knight)
				{
					
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}

					Bishop temp_bishop(i,j,0,White);
					temp_bishop.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) w_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==0)
			{
				if(in_table.At(i,j).type==P_Queen)
				{
					
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}

					Queen temp_queen(i,j,0,Black);
					temp_queen.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) b_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==1)
			{
				if(in_table.At(i,j).type==P_Queen)
				{
					
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}

					Queen temp_queen(i,j,0,White);
					temp_queen.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) w_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==0)
			{
				if(in_table.At(i,j).type==P_King)
				{
					
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}

					King temp_king(i,j,0,Black);
					temp_king.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) b_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==1)
			{
				if(in_table.At(i,j).type==P_King)
				{
					
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}

					King temp_king(i,j,0,White);
					temp_king.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) w_movability++;
						}
					}
				}
			}
		}
	}
	double move_value=0 ;
	move_value = (b_movability-w_movability)*0.1;
	return move_value;
}
int ArtificialIntelligence::Evaluate_Isolated(Table in_table)
{
	int isolated_value=0;
	int isolated_b_value=0;
	int isolated_w_value=0;
	for(int i=0 ; i<8 ; i++)
	{
		for(int j=0 ; j<8 ; j++)
		{
			if(in_table.At(i,j).type==P_Pawn)
			{	
				if(in_table.At(i,j).color==Black)
				{
					if (!(in_table.At(i-1,j-1).type==P_Pawn && in_table.At(i-1,j-1).color==Black) &&
						!(in_table.At(i-1,j+1).type==P_Pawn && in_table.At(i-1,j-1).color==Black) &&
						!(in_table.At(i+1,j-1).type==P_Pawn && in_table.At(i-1,j-1).color==Black) &&
						!(in_table.At(i+1,j+1).type==P_Pawn && in_table.At(i-1,j-1).color==Black)  )
					isolated_b_value ++;
				}
			}
			if(in_table.At(i,j).type==P_Pawn)
			{	
				if(in_table.At(i,j).color==White)
				{
					if (!(in_table.At(i-1,j-1).type==P_Pawn && in_table.At(i-1,j-1).color==White) &&
						!(in_table.At(i-1,j+1).type==P_Pawn && in_table.At(i-1,j-1).color==White) &&
						!(in_table.At(i+1,j-1).type==P_Pawn && in_table.At(i-1,j-1).color==White) &&
						!(in_table.At(i+1,j+1).type==P_Pawn && in_table.At(i-1,j-1).color==White)  )
					isolated_w_value ++;
				}
			}
		}
	}
	isolated_value = isolated_b_value - isolated_w_value ; 
	return isolated_value;
}
int ArtificialIntelligence::Evaluate_Backward(Table in_table)
{
	int backward_value=0;
	int backward_b_value=0;
	int backward_w_value=0;
	for(int i=0 ; i<8 ; i++)
	{
		for(int j=0 ; j<8 ; j++)
		{
			if(in_table.At(i,j).type==P_Pawn)
			{	
				if(in_table.At(i,j).color==Black)
				{
					if(in_table.At(i-1,j-1).type==P_Pawn && in_table.At(i-1,j-1).color==Black)
					backward_b_value ++;
					if(in_table.At(i+1,j-1).type==P_Pawn && in_table.At(i+1,j-1).color==Black)
					backward_b_value ++;
				}
				if(in_table.At(i,j).color==White)
				{
					if(in_table.At(i-1,j-1).type==P_Pawn && in_table.At(i-1,j-1).color==White)
					backward_w_value ++;
					if(in_table.At(i+1,j-1).type==P_Pawn && in_table.At(i+1,j-1).color==White)
					backward_w_value ++;
				}
			}
		}
	}
	backward_value = backward_b_value - backward_w_value ; 
	return backward_value;	
}
int ArtificialIntelligence::Evaluate_Doubled(Table in_table)
{
	int double_value=0;
	int double_b_value=0;
	int double_w_value=0;
	for(int i=0 ; i<8 ; i++)
	{
		for(int j=0 ; j<8 ; j++)
		{
			if(in_table.At(i,j).type==P_Pawn)
			{	
				if(in_table.At(i,j).color==Black)
				{
					if(in_table.At(i,j-1).type==P_Pawn && in_table.At(i,j-1).color==Black)
					double_b_value ++;
				}
				if(in_table.At(i,j).color==White)
				{
					if(in_table.At(i,j-1).type==P_Pawn && in_table.At(i,j-1).color==White)
					double_w_value ++;
				}
			}
		}
	}
	double_value = double_b_value - double_w_value ; 
	return double_value;
}
double ArtificialIntelligence::Evaluate_Table(Table in_table)
{
	double value=0 ;
	double material=ArtificialIntelligence::Evaluate_Material(in_table);
	double movability=ArtificialIntelligence::Evaluate_Movability(in_table);
	int isolated=ArtificialIntelligence::Evaluate_Isolated(in_table);
	int backward= ArtificialIntelligence::Evaluate_Backward(in_table);
	int doubled=ArtificialIntelligence::Evaluate_Doubled(in_table);
	value = material+movability-(0.5)*( isolated+backward+doubled );
	return value;
}
int ArtificialIntelligence::Evaluate_number_possible_moves(Table in_table,bool color)
{
	int b_movability=0;
	for(int i=0 ; i<8 ; i++)
	{
		for(int j=0 ; j<8 ; j++)
		{
			if(in_table.At(i,j).color==color)
			{
				if(in_table.At(i,j).type==P_Pawn)
				{
					
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}

					Pawn temp_pawn(i,j,0,color);
					temp_pawn.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) b_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==color)
			{
				if(in_table.At(i,j).type==P_Rook)
				{
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}
					Rook temp_rook(i,j,0,color);
					temp_rook.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) b_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==color)
			{
				if(in_table.At(i,j).type==P_Knight)
				{
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}
					Knight temp_knight(i,j,0,color);
					temp_knight.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) b_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==color)
			{
				if(in_table.At(i,j).type==P_Bishop)
				{
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}
					Bishop temp_bishop(i,j,0,color);
					temp_bishop.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) b_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==color)
			{
				if(in_table.At(i,j).type==P_Queen)
				{
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}
					Queen temp_queen(i,j,0,color);
					temp_queen.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) b_movability++;
						}
					}
				}
			}
			if(in_table.At(i,j).color==color)
			{
				if(in_table.At(i,j).type==P_King)
				{
					int **temp_table;
					temp_table=new int*[8];
					for(int i=0;i<8;i++)
					{
					temp_table[i]=new int[8];
					}
					King temp_king(i,j,0,color);
					temp_king.Get_Pos_Loc(in_table , temp_table);
					for(int k=0 ; k<8 ; k++)
					{
						for(int m=0 ; m<8 ; m++)
						{
							if(temp_table[k][m]!=0) b_movability++;
						}
					}
				}
			}
		}
	}
	return b_movability;
}
void ArtificialIntelligence::Mover(Table &in_table, Location &in_location , Location &out_location )
{
	PieceInfo in_piece_info=in_table.At(in_location.Get_X(),in_location.Get_Y());
	in_table.At(out_location.Get_X(),out_location.Get_Y())=in_piece_info;
	PieceInfo new_piece_info ; 
	in_table.At(in_location.Get_X(),in_location.Get_Y())= new_piece_info ;
}
void ArtificialIntelligence::AI_MOVER(Table in_table , Location &in_location , Location &out_location)
{
	int value_of_moves = ArtificialIntelligence::Evaluate_number_possible_moves(in_table,Black);
	double *values = new double[value_of_moves];
	int counter=0;
	for(int i=0 ; i<8 ; i++)
	{
		for(int j=0 ; j<8 ; j++)
		{
			if(in_table.At(i,j).color==Black)
			{
				Piece *temp_piece_pointer;
				if(in_table.At(i,j).type==P_Pawn)
				{
					temp_piece_pointer=new Pawn(i,j,0,Black);
				}
				if(in_table.At(i,j).type==P_Rook)
				{
					temp_piece_pointer=new Rook(i,j,0,Black);
				}
				if(in_table.At(i,j).type==P_Knight)
				{
					temp_piece_pointer=new Knight(i,j,0,Black);
				}
				if(in_table.At(i,j).type==P_Bishop)
				{
					temp_piece_pointer=new Bishop(i,j,0,Black);
				}
				if(in_table.At(i,j).type==P_Queen)
				{
					temp_piece_pointer=new Queen(i,j,0,Black);
				}
				if(in_table.At(i,j).type==P_King)
				{
					temp_piece_pointer=new King(i,j,0,Black);
				}

				int **temp_table;
				temp_table=new int*[8];
				for(int w=0;w<8;w++)
				{
				temp_table[w]=new int[8];
				}
				
				temp_piece_pointer->Get_Pos_Loc(in_table,temp_table);
				for(int m=0 ; m<8 ; m++ )
				{
					for(int k=0 ; k<8 ; k++)
					{
						if(temp_table[m][k]==100)
						{
							Table temporary_table=in_table;
							Location in_func_location(i,j);
							Location out_func_location(m,k);
							////
							PieceInfo in_piece_info=temporary_table.At(i,j);
							temporary_table._table[m][k]=in_piece_info;
							PieceInfo new_piece_info ; 
							temporary_table._table[i][j]=new_piece_info;
							////
							values[counter]=ArtificialIntelligence::Evaluate_Table(temporary_table);
							double a=values[counter];
							bool goodflag=1;
							for(int l=0 ; l<(counter-1) ; l++)
							{
								if(values[counter]<values[l])
								{
									goodflag=0;
								}
							}
							if(goodflag)
								{
									in_location=in_func_location;
									out_location=out_func_location;
								}
							counter++;
						}
					}
				}
			}
		}
	}
}
bool ArtificialIntelligence::Is_Checked_Cheker(Table &in_table, bool player_color)
{
	bool checked = 0 ;
	for(int i=0 ; i<8 ; i++)
	{
		for(int j=0 ; j<8 ; j++)
		{
			if(in_table.At(i,j).type==P_King && in_table.At(i,j).color==player_color)
			{
				const Location king_location(i,j);
				if(!(in_table.IsHorizontalSafe(king_location,player_color)))
					checked=1;
				if(!(in_table.IsLSafe(king_location,player_color)))
					checked=1;
				if(!(in_table.IsOribmSafe(king_location,player_color)))
					checked=1;
				if(!(in_table.IsOribpSafe(king_location,player_color)))
					checked=1;
				if(!(in_table.IsPawnSafe(king_location,player_color)))
					checked=1;
				if(!(in_table.IsVerticalSafe(king_location,player_color)))
					checked=1;
			}
		}
	}
	return checked;
}
int ArtificialIntelligence::Finished_Checker(Table in_table, bool color, int no_pawn_moves)
{
	bool White_Uncheck=0;
	bool Black_Uncheck=0;
	for(int i=0 ; i<8 ; i++)
	{
		for(int j=0 ; j<8 ; j++)
		{
			if(in_table.At(i,j).color==White)
			{
				Piece *temp_piece_pointer ;
				int **temp_table={0};
				temp_piece_pointer->Get_Pos_Loc(in_table,temp_table);
				for(int m=0 ; m<8 ; m++ )
				{
					for(int k=0 ; k<8 ; k++)
					{
						if(temp_table[m][k]==100)
						{
							Table temporary_table=in_table;
							Location in_func_location(i,j);
							Location out_func_location(i,j);
							ArtificialIntelligence::Mover(temporary_table,in_func_location,out_func_location);
							if(ArtificialIntelligence::Is_Checked_Cheker(temporary_table,White)==0)
								White_Uncheck=1;
						}
					}
				}
			}
		}
	}
	if(White_Uncheck==0) return 3;
	for(int i=0 ; i<8 ; i++)
	{
		for(int j=0 ; j<8 ; j++)
		{
			if(in_table.At(i,j).color==Black)
			{
				Piece *temp_piece_pointer ;
				int **temp_table={0};
				temp_piece_pointer->Get_Pos_Loc(in_table,temp_table);
				for(int m=0 ; m<8 ; m++ )
				{
					for(int k=0 ; k<8 ; k++)
					{
						if(temp_table[m][k]==100)
						{
							Table temporary_table=in_table;
							Location in_func_location(i,j);
							Location out_func_location(i,j);
							ArtificialIntelligence::Mover(temporary_table,in_func_location,out_func_location);
							if(ArtificialIntelligence::Is_Checked_Cheker(temporary_table,Black)==0)
								Black_Uncheck=1;
						}
					}
				}
			}
		}
	}
	if(Black_Uncheck==0) return 4;
	
	if(ArtificialIntelligence::Evaluate_number_possible_moves(in_table,color)==0)
		return 1;

	if(no_pawn_moves>50)
		return 1;

	return 0;
}
#endif ARTIFICIALINTELLIGENCE_H