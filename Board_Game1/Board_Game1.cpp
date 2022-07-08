#include<iostream>
#include<iomanip>
#include<conio.h>
#include<Windows.h>

//1> X Defines Width of Coordinates of forbidden places
//2> Y Defines Height of Coordinates of forbidden places 
//
//
//WIDTH IS VERTICAL LINE
//
//HEIGHT IS HORIZANTAL LINE
//
//               9999  9999
//               9999  9999
//                 7        8
//                 14      15
//                  21     22
// 
//      then coordinates of 22 is on NUM_Position_X is 3 and Y is 1
//
//



//Board--GAME--Varibles

const int Height = 7;
const int Width = 7;
const int Forbidden_Place = 16;
const int Forbidden_Place_X[Forbidden_Place] = { 0,1,5,6,0,1,5,6,0,1,5,6,0,1,5,6 };
const int Forbidden_Place_Y[Forbidden_Place] = { 0,0,0,0,1,1,1,1,5,5,5,5,6,6,6,6 };
const int Forbidden_Space_Num =9999 ;    //MUST BE GREATER THAN 50 (see find coordinate section)
const int Empty_Place = 1;
const int Empty_Space_Xcoordinate[Empty_Place] = { 3 };
const int Empty_Space_Ycoordinate[Empty_Place] = { 3 };


//Setw---Numbers
const int Screen_Offset = 20;
const int Cell_Offset = 15;
const int Border_Cell_Offset = 7;
const int Screen_Cursor_Offset = 10;

//Border---Values
const char Border = '|';

// STORAGE ---DATA--

int Forbidden_Space[Forbidden_Place];
int Board[Height][Width];









int main()
{

	bool Game_On = true;
	int Number = 0;
	int Num_X_Position = 0, Num_Y_Position = 0;
	int Temp_Num = 0;
	char Direction;
	int Remaing_Space = 32;
	



	//FILL--FORBIDDEN--SPACE--ARRAY
	for (int i = 0;i < Forbidden_Place;i++)
	{
		Forbidden_Space[i] = Forbidden_Place_X[i] + (Forbidden_Place_Y[i] * Width);
	}




	//INITIALIZE--BOARD--ARRAY
	int Filling = 0;
	for (int i = 0;i < Height;i++)
	{
		for (int j = 0;j < Width;j++)
		{
			Board[i][j] = Filling;
			Filling++;
		}

	}

	for (int i = 0;i < Height;i++)
	{
		for (int j = 0;j < Width;j++)
		{
			for (int k = 0;k < Forbidden_Place;k++)
			{
				if (Board[i][j] == Forbidden_Space[k])
					Board[i][j] = Forbidden_Space_Num;
			}
		}
	}



	//INATIALIZE EMPTY SPACE  
	//NUMBER WHICH IS ZERO CALCULATE USING {NUM=(Xcoordinate)+(Ycoordinate*Width)}
	for (int i = 0;i < Empty_Place;i++)
	{
		Board[Empty_Space_Xcoordinate[i]][Empty_Space_Ycoordinate[i]] = 0;
	}


	//Game-----Loop----

	while (Game_On)
	{
		
		//GAME--UPDATE----
		
		system("CLS");


		//Exit::
		std::cout << "Press Any Key in the direction  (option) to exit anytime  :: " << std::endl;

			


		// DISPLAY --- BOARD---
		std::cout << "\n\n\n\n\n";
		for (int i = 0;i < Height;i++)
		{
			std::cout << std::setw(Screen_Offset);
			std::cout << Border << std::setw(Border_Cell_Offset);
			for (int j = 0;j < Width;j++)
			{
				if (j < Width - 1)
					std::cout << Board[i][j] << std::setw(Cell_Offset);
				else
					std::cout << Board[i][j];

			}
			std::cout << std::setw(Border_Cell_Offset) << Border;
			std::cout << "\n\n\n\n" << std::endl;
		}
		std::cout <<"\n\n"<< std::setw(Screen_Cursor_Offset) << "\n\nREMAINING  ::  " << Remaing_Space << std::endl;



		//Get--NUMBER--From --- USER
		std::cout << "\n\n";
		std::cout << "Enter the Choosen Number  :::    ";
		std::cin >> Number;



	
		//A>.....  Find Coordinates of Number
		for (int i = 0;i < Height;i++)
		{
			for (int j = 0;j < Width;j++)
			{
				Temp_Num = i + (j * Width);
				if (Number == Temp_Num)
				{
					Num_X_Position = j;
					Num_Y_Position = i;
					//std::cout << Num_X_Position << "  ,  " << Num_Y_Position << "\n";
					break;
				}
			}
		}



	
		//B>.....Get --Direction from Player---
		std::cout << "\n\n";
		std::cout << "Enter the direction   ::  ";
		Direction = _getch();
		//std::cin >> Direction;




		//b.1>...Check for Valid Direction And if Valid Do Opreation
		switch (Direction)
		{
		case 'w':
		{
			if (Num_X_Position - 2 >-1)
			{
				
				if (Board[Num_X_Position - 1][Num_Y_Position] != 0 && Board[Num_X_Position - 2][Num_Y_Position] == 0)
				{
					Board[Num_X_Position][Num_Y_Position] = 0;
					Board[Num_X_Position - 1][Num_Y_Position] = 0;
					Temp_Num = Num_Y_Position + ((Num_X_Position - 2) * Width);
					Board[Num_X_Position - 2][Num_Y_Position] = Temp_Num;
					Remaing_Space -= 1;
				}

			}

			break;
		}


		case 's':
		{
			if (Num_X_Position + 2 < 7)
			{
					

				if (Board[Num_X_Position + 1][Num_Y_Position] != 0 && Board[Num_X_Position + 2][Num_Y_Position] == 0)
				{
					Board[Num_X_Position][Num_Y_Position] = 0;
					Board[Num_X_Position + 1][Num_Y_Position] = 0;
					Temp_Num = Num_Y_Position + ((Num_X_Position + 2) * Width);
					Board[Num_X_Position + 2][Num_Y_Position] = Temp_Num;
					Remaing_Space -= 1;
				}

			}

			break;
		}


		case 'd':
		{
			if (Num_Y_Position + 2 < 7)
			{
				
				if (Board[Num_X_Position][Num_Y_Position + 1] != 0 && Board[Num_X_Position][Num_Y_Position + 2] == 0)
				{
					Board[Num_X_Position][Num_Y_Position] = 0;
					Board[Num_X_Position][Num_Y_Position + 1] = 0;
					Temp_Num = (Num_Y_Position + 2) + ((Num_X_Position)*Width);
					Board[Num_X_Position][Num_Y_Position + 2] = Temp_Num;
					Remaing_Space -= 1;
				}


			}

			break;
		}


		case 'a':
		{
			if (Num_Y_Position - 2 > -1)
			{
				if (Board[Num_X_Position][Num_Y_Position - 1] != 0 && Board[Num_X_Position][Num_Y_Position - 2] == 0)
				{
					Board[Num_X_Position][Num_Y_Position] = 0;
					Board[Num_X_Position][Num_Y_Position - 1] = 0;
					Temp_Num = (Num_Y_Position - 2) + ((Num_X_Position)*Width);
					Board[Num_X_Position][Num_Y_Position - 2] = Temp_Num;
					Remaing_Space -= 1;
				}


			}

			break;
		}


		default:
		{
			Game_On = false;
		}

		}
	}

	return 0;
}