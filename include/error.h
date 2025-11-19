#ifndef ERROR_H
# define ERROR_H

# define BAD_ALLOC "\033[1;31mError: Unable to allocate memory !\033[0m"
# define BAD_ARGC "\033[1;31mError: Unvalid argument count !\033[0m"
# define BAD_FEMPTY "\033[1;31mError: Scene description file is mandatory !\033[0m"
# define BAD_FILE "\033[1;31mError: Unvalid config file !\033[0m"
# define BAD_MAP "\033[1;31mError: Unvalid map !\033[0m"
# define EMPTY_MAP "\033[1;31mError: Unvalid empty map !\033[0m"
# define EMPTY_CONF "\033[1;31mError: Unvalid empty config !\033[0m"
# define ERROR_GENERAL "\033[1;31mError: $MSG !\033[0m"
# define ERROR_EXTA "\033[1;31mError: Unvalid file extension !\033[0m"
# define ERROR_FORMAT "\033[1;31mUnvalid texture format support : {path, #hex, argb(,,,) '0-256,0-256,0-256'} !\033[0m"
# define ERROR_HEXA "Unvalid hexa color, it shoud be #RRGGBB !"
# define ERROR_RGBA "\033[1;31mUnvalid rgba color, it shoud be rgba (xxx,xxx,xxx) !\033[0m"
# define ERROR_TXT "\033[1;31mError: $MSG texture was not set !\033[0m"
#endif
