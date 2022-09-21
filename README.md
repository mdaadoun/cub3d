# CUB3D

-> DEBUGGER

## Init program
* malloc main structure cub3d
	* structure player (direction)
	* structure data

## Get data from file
* check if file exist and correct format: .cub
	* if not error
* get file data (get next line see solong)

## Data errors
* error gestion (error enum code error with msg error)
	* file/data format invalid
	* data missing (need: NO SO WE EA F C map)
	* invalid or missing images files

## Map init and error
* build map char**
	* check errors map if valid

## Init minilibx window and loading images
* loading image and display window

## Events
* gestion minilibx event
	* exit red cross (check valgrind)
	* exit ESC
	* arrow keys
	* A W S F keys

## GAME LOOP
(NEED RESEARCH) https://lodev.org/cgtutor/raycasting.html
### **1** UPDATE DATA
### **2** UPDATE DISPLAY

## Free and exit program
* free and display error if any, then exit
