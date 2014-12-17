/*
  MeggyJr_Stacker.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Moves three dots from side to side for a Stacker type game.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */
 
 /* 
 My idea for Stacker is to create a single array of ints, with each index corresponding to one row.
 We'll designate one of the dots (probably the center dot of the three-dot segments) 
 to be the reference point and draw the dots to either side of that dot when we 
 draw the segment. The boundaries for the reference point will be set so that 
 it won't go over. When we draw the array we'll just read the value of the index then draw each one and update
 it accordingly even if it's blank.
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

int rows[8]; // The numbers in this array correspond to the column where the reference point starts

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
  rows[0] = [random(6)+1]; //picks a random column in the array to be between 1-6
}

void loop()                     // run over and over again
{
  
}

void DrawArray() // This draws three-dot segments and then two-dot segments.
{
  for (int i = 0; i < 3; i++) // First three rows are three-dot segments
  {
    if (rows[i] > 0) // If there is something in the row
    {
      DrawPx(rows[i]-1,i,1); // Dot to left
      DrawPx(rows[i],i,1); // Reference dot
      DrawPx(rows[i]+1,i,1); // Dot to right
    }
  }
  
  for (int i = 3; i < 8; i++) // Upper rows are two-dot segments
  {
    if (rows[i] > 0) // if there is something in the row
    {
      DrawPx(rows[i],i,1); // Reference dot
      DrawPx(rows[i]+1,i,1); // Dot to right
    }
  }
}

