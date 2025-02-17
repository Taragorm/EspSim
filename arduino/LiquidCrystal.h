// Class automatically generated by Dev-C++ New Class wizard
#include <Arduino.h>
#include <windows.h>

#ifndef LIQUIDCRYSTAL_H
#define LIQUIDCRYSTAL_H

/**
 * No description
 */
class LiquidCrystal
{
	public:
           
		// class constructor
		LiquidCrystal(byte RS, byte EN, byte D4, byte D5, byte D6, byte D7);
		void begin(byte c, byte r);
		byte initialized;                                                         //< The display is initialized or not.
		byte col;                                                                 //< Number of columns
		byte row;                                                                 //< Number of rows
		byte x;                                                                   ///< This is the x location of the cursor
		byte y;                                                                   ///< This is the y location of the cursor
		byte x_offset;                                                            //< X location of the top left corner of the display
		byte y_offset;                                                            //< Y location of the top left corner of the display
		
		byte * display_buffer;                                                    //< This stores the display buffer
		HANDLE hStdout;                                                           //< Display handle as stdout
        CONSOLE_SCREEN_BUFFER_INFO csbiInfo;                                      //< Console screen buffer info

		void clear();                                                             ///< Clear the display
		/*
        void home();                                                              ///< Moves the cursor to top left corner without clearing the display
        
        void noDisplay();                                                         ///< Turns off the display
        void display();                                                           ///< Turn on the display
        void noBlink();                                                           //< Turn off blinking cursor
        void blink();                                                             //< Turn on blinking cursnr
        void noCursor();                                                          //< Hide cursor
        void cursor();                                                            //< Show cursor
        void scrollDisplayLeft();
        void scrollDisplayRight();
        void leftToRight();
        void rightToLeft();
        void autoscroll();
        void noAutoscroll();
        
        void createChar(uint8_t, uint8_t[]);
        
        virtual size_t write(uint8_t);                                            //< Write to display
        void print(char c);                                                       //< Prints the content to the display buffer and updates the display
        void print(int i);                                                        //< Prints the content to the display buffer and updates the display
//        void print(unsigned char* buffer);                                        //< Prints the content to the display buffer and updates the display
//        void print(unsigned char c);                                              //< Prints the content to the display buffer and updates the display
//        void print(unsigned int i);                                               //< Prints the content to the display buffer and updates the display
*/
        void print(char* buffer);                                                 //< Prints the content to the display buffer and updates the display
        void print(byte c);                                                       //< Prints the content to the display buffer and updates the display
        void setCursor(uint8_t, uint8_t);                                         //< Set cursor to location col,row
        void set_screen_location(uint8_t, uint8_t);                               //< Sets the console cursor for updating the console.
        void update_console();                                                    //< This does the actual console screen update with the hStdout and csbiInfo
        byte translate_char(byte c);                                              //< This translates the character so the look is like HD44780 display
		// class destructor
		~LiquidCrystal();
};

#endif // LIQUIDCRYSTAL_H
