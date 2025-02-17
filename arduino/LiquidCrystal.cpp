// Class automatically generated by Dev-C++ New Class wizard

#include "LiquidCrystal.h" // class's header file
using namespace std;

// class constructor
LiquidCrystal::LiquidCrystal(byte RS, byte EN, byte D4, byte D5, byte D6, byte D7)
{
	// insert your code here
	initialized=0;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
}

// class destructor
LiquidCrystal::~LiquidCrystal()
{
	// insert your code here
	free((void*)display_buffer);
}

void LiquidCrystal::begin(byte c, byte r)
{
    if (initialized) free((void*)display_buffer);
    col=c;
    row=r;
    display_buffer=(byte*)malloc(col*row+1);

    x_offset=0;
    y_offset=2;
    x=0;
    y=0;
    
    GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
    csbiInfo.dwCursorPosition.X=x_offset;
    csbiInfo.dwCursorPosition.Y=y_offset;
    SetConsoleCursorPosition(hStdout,csbiInfo.dwCursorPosition);

    initialized=1;                                         //< Now the display is initialized
    clear();
}

void LiquidCrystal::clear()
{
    if (initialized)
    {      
        for (byte i=0;i<row*col;i++) {display_buffer[i]=' ';}  //< Fill buffer with space.
        display_buffer[col*row]='\0';                          //< Terminate the string.
        update_console(); 
    }
}                                     //< Updates the consold display

void LiquidCrystal::print(char * buffer)
{
    int location,remaining_length,i=0;
    if (initialized)
    {      
        location=(x)+(y)*col;
        remaining_length=col*row-location;
        while(remaining_length>0)
        {   if (buffer[i]!='\0')
            {
                display_buffer[location]=buffer[i];
                i++;
                location++;
                remaining_length--;
            }
            else
            {
                update_console();
                return;
            }
        }
        
    }
}

void LiquidCrystal::print(byte c)
{
    int location;
    if (initialized)
    {      
        location=(x)+(y)*col;
        if (location<col*row)
        {
            display_buffer[location]=c;
            x++;
            if (x==col)
            {
                x=0;
                y++;
                if (y==row) y=0; //< Wrap around
            }
        }
        update_console();
    }
}
void LiquidCrystal::update_console()
{
    if (initialized)
    {
        for (byte i=0;i<row;i++)
        {
            set_screen_location(x_offset,i+y_offset);
            for (byte j=0;j<col;j++)
            {
                putchar(translate_char(display_buffer[i*col+j]));
            }
        }
        set_screen_location(x_offset,row+y_offset);
    }
}

void LiquidCrystal::set_screen_location(byte _x, byte _y)
{
    if (initialized)
    {      
        GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
        csbiInfo.dwCursorPosition.X = _x;
        csbiInfo.dwCursorPosition.Y = _y;
        SetConsoleCursorPosition(hStdout,csbiInfo.dwCursorPosition);
    }
}
    
void LiquidCrystal::setCursor(byte _x, byte _y)
{
    if (initialized)
    {      
        x=_x;
        y=_y;
    }
}
                                        

byte LiquidCrystal::translate_char(byte c)
{
    if (c<' ') c%=8; //< Restrict c between 0-7 if below ' '.
    switch (c)
    {      
        case 126: //< Right arrow
        return 175; //< somewhat like right arrow
        break;

        case 127: //< Left arrow
        return 174; //< somewhat like left arrow
        break;
        
        case 165: //< Big dot
        return 254; //< somewhat like big dot
        break;
        
        case 254: //< Space
        return ' '; //< Space
        break;
        
        case 255: //< Black block
        return 219; //< Black box
        break;

        case 0: //< Up triangle with block
        return 223; //< somewhat like that
        break;

        case 1: //< Up triangle
        return ' '; //< somewhat like that
        break;
        
        case 2: //< Top block
        return 223; //< somewhat like that
        break;
        
        case 3: //< Bottom block
        return 220; //< Space
        break;
        
        case 4: //< Down triangle
        return ' '; //< Black box
        break;
        
        case 5: //< Down triangle with block
        return 220; //< somewhat like that
        break;

        case 6: //< 
        return 176; //< 
        break;
        
        case 7: //< 
        return 177; //< 
        break;
        
        default:
        return c;
        break;
    }
}

