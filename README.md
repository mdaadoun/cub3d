# CUB3D

-> DEBUGGER

## Init program
* malloc main structure cub3d
	* [x] main structure cub
		* [x] structure cub->data (for parsing), to free before game start
		* [ ] structure cub->game
		* [ ] structure cub->game->player (direction)

## Get data from file
* [x] check if file exist and correct format: .cub
* [x] get file data (get next line)

## Data errors
* [ ] error gestion (error enum code error with msg error)
	* [ ] file/data format invalid
	* [ ] data missing (need: NO SO WE EA F C map)
	* [ ] invalid or missing images files

## Map init and error
* [ ] build map char**
	* [ ] check errors map if valid

## Init minilibx window and loading images
* [x] display window
* [ ] loading image

## Events
* [x] gestion minilibx event
	* [x] exit red cross (check valgrind)
	* [x] exit ESC
	* [x] arrow keys
	* [x] A W S F keys

## RUN GAME LOOP
(NEED RESEARCH) https://lodev.org/cgtutor/raycasting.html
### **1** UPDATE DATA
### **2** UPDATE DISPLAY

## Free and exit program
* [x] free and display error if any, then exit
