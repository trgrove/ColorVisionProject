# Colors Visible to Three Types of Colorblindness
## Description

**version 1.0**

This code allows you to test for either Protanopia, Tritanopia or Deuteranopia. You chose one of the three as the first step. you then select the number of colors in your palette, up to 5 are allowed. One color at a time, you input your colors in RGB color form. "color 1:"  000 000 000. It will, one at a time, tell you whether your color is visible to people with the type of colorblindness chosen at the beginning of the run. If you input to large or small of a number, or select an option that is not available, the run will end and give a message explaining why.

**version 2.0 updates**

This code is similar to the last however, the palette size now only allows for three colors max at a time. It will compare colors using the Euclidian equation for RGB colors to tell the distance between two colors. Once that distance is determined, the program checks if the distance is larger than a set number of my choosing. Additionally it'll tell you whether the color is too dark to see as well and will return "not visible" for colors too dark to be able to see in general as some types of colorblindness can make one color appear darker than it should be. However, the program runs the same in many ways asking for colors in RGB form where you input in this format: 000 000 000. If the color is out of range of 0-255, the program will now simply ask for the color again rather than quitting the whole program and the same goes for if the available types of color blindness are misspelled in any way.

## Developer

Tatum Grove

## Example

To run the program simply press compile and run and it will begin prompting you with the first question.

Here is an example of the program running:

```
browser.cpp:~$ Compilation successful.
browser.cpp:~$ 
input type of colorblindess: Tritanopia A, Protanopia B or Deuteranopia C.
A
Tritanopia
enter number of colors in your palette: 
4
enter color 1 in RGB number form
132 44 56
color 1 is visible to people with Tritanopia!
enter color 2 in RGB number form
76 32 1
color 2 is visible to people with Tritanopia!
enter color 3 in RGB number form
122 55 0
color 3 is visible to people with Tritanopia!
enter color 4 in RGB number form
000 000 000
color 4 is neutral(grey/black/white)
browser.cpp:~$

```

Here is an example of version 2.0 running:

```
Hello! Please enter type of colorblindness below:
 (protanopia, deuteranopia, tritanopia)
protanopija
it's not that hard to spell bruh lock in...
protanopia
Evaluating color palette visibility for protanopia
Pick three colors in a color palette.
Please enter color 1 keeping the values within rgb range, 0-255:
59 130 246
Color within range. storing in color palette..
Please enter color 2 keeping the values within rgb range, 0-255:
60 125 444
Colors out of range...re-enter please.
Please enter color 2 keeping the values within rgb range, 0-255:
60 125 250
Color within range. storing in color palette..
Please enter color 3 keeping the values within rgb range, 0-255:
34 12 99
Color within range. storing in color palette..
Color 1: Visible
Color 2: Visible
Color 3: Visible
Color 1 and color 2 are too close in color for someone with protanopia to distinct between.
Color 1 and color 3 are visible and not too close in color.
Color 2 and color 3 are visible and not too close in color.

```
