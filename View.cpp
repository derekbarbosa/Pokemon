#include "View.h"

View::View()
{
	origin = Point2D();
	size = 11;
	scale = 2;
}

void View::Clear() //GRID OF 11x11 dots
{
	for(int i = 0; i < size; i++) // 0-10 (11 entries)
	{
		for(int j = 0; j < size; j++)
		{
			grid[i][j][0] = '.'; //print a dot
			grid[i][j][1] = ' '; //print an empty space
		}
	}
}

bool View::GetSubscripts(int &out_x, int &out_y, Point2D location)
{
	Vector2D subscripts; 
	subscripts.x = int(location.x) - int(origin.x);
	subscripts.y = int(location.y) - int(origin.y);

	subscripts = subscripts/scale;

	subscripts.x = int(subscripts.x);
	subscripts.y = int(subscripts.y);

	out_x = int(subscripts.x);
	out_y = int(subscripts.y);

	if(subscripts.x < size*scale && subscripts.y < size*scale)
	{
		return true;
	}
	else
	{
		cout << "an object is out of bounds!!" << endl;
		return false;
	}

}

void View::Plot(GameObject *ptr) { //copied from PA3 solution
    int ix, iy;
    bool valid;
    valid = GetSubscripts(ix, iy, ptr->GetLocation());
    if (valid && grid[ix][iy][0] == '.') {
        ptr->DrawSelf(grid[ix][iy]);
    }
    else if (valid) {
        grid[ix][iy][0] = '*';
        grid[ix][iy][1] = ' ';
    }
}

void View::Draw() //SOLUTION FOR VIEW::DRAW() WAS REACHED WITH THE ASSISTANCE OF CLASSMATES 
{
    for (int i = size - 1; i >= 0; i--) //LOOP from top to bottom
	{
        for (int j = -1; j < size; j++) 
		{
            if (j == -1) 
			{
				//values are ONLY printed on even values of the axis, SO to compensate for nothing printed, see "else"
                if (i % 2 == 0)
				{
                    if (i * scale < 10) //if the number is less than 10, j.E single digit, then it needs to print a whitespace afterward to keep the grid "balanced"
					{
                        cout << i * scale << " ";
                    } 
					else 
					{
                        cout << i * scale; //however, if the number is greater than 10, no whitespace needs to be printed to compensate
                    }
                } 
				else 
				{
                    cout << "  "; //NO VALUE SO ADD A WHITESPACE TO KEEP BALANCE
                }
            } 
			else 
			{
                // Print grid values
                cout << grid[j][i][0] << grid[j][i][1];
            }
        }

        cout << " " << endl; //WHITESPACE AND NEW LINE DONT TOUCH
    }

    cout << " "; //WHITESPACE DONT TOUCH
	
    for (int j = -1; j < size; j++) //SAME AS ABOVE FOR Y-AXIS, BUT INVERTED!
	{
        //values are ONLY printed on even values of the axis, SO to compensate for nothing printed, see "else"
        if (j % 2 == 0) 
		{
            if (j * scale < 10) //if the number is less than 10, j.E single digit, then it needs to print a whitespace afterward to keep the grid "balanced"
			{
                cout << j * scale << " ";
            } 
			else  //however, if the number is greater than 10, no whitespace needs to be printed to compensate
			{
                cout << j * scale; 
            }
        } 
		else //NO VALUE SO ADD A WHITESPACE TO KEEP BALANCE
		{
            cout << "  ";
        }
    }
}