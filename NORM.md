# NORM cub3d

## Structure:  
>./Makefile  
./libft  
./minlibx  
./maps/*.cub  
./img/*.xpm  
./inc/cub.h  
./src/cub_main.c  
./src/parser/cub_map_parsing.c  
  
## Functions names:  
>**ft_function_name**: utils, libft  
**cub_function_name**: global functions (add to cub.h)  
**fs_function_name**: static function (same file)  
**dg_function_name**: debug function (add to debug.h)
  
## Structures names:  
>**t_cub \*cub**: main structure  
**cub->map_data**: images path ? 
**cub->map**: char ** (map[y][x])  
**cub->player**: direction, position (x, y), player info  
  
## Variable names:  
>**ind, i/j**: incrementer  
**count, c**: counter value  
**len**: length  
**x, y**: map coordinates  