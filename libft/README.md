# LIBFT
By nifromon (Nicolas Fromont), student at 42 perpignan, France.
> ---
>
> ## DESCRIPTION
>
> This project's goal was for us to create in C our own library of generic functions that we could use in our future projects at 42. Coding in C is quite laborious, imagine how hard it would be if we didn't have access to all those small but extremely pratical functions. That's why we must begin our cursus at 42 by creating our own library - Which we will be free to enrich as we go trough the cursus as long as we respect the rules.
>
> ---
> ## INSTRUCTIONS
> - Program name : libft.a .
> - Files to return : Makefile, libft.h, ft_*.c.
> - Makefile rules : NAME, all, clean, fclean, re.
> - Allowed external functions : See details below.
> - Libft allowed : n/a.
> ---
> - ### Part 1 - Libc functions
>	In this first part, we must recode a group of functions of the "libc" library as described in there respective manual pages. Our functions must have the exact same prototype, the same behavior and the same return values as the originals. The only difference will be that they must be prefixed by "ft_" and will be coded our way.
>	#### Functions :
>	##### Character classification functions :
>	- **[ft_isalpha](libft/src/ft_isalpha.c)** :
>		- Prototype : `int	ft_isalpha(int c);`
>		- Description : Checks for an alphabetic character.
>		- Allowed external functions : None.
>		- Return Value : The values returned are non-zero if the character falls into the tested class, and zero if not.
>	- **[ft_isdigit](libft/src/ft_isdigit.c)** :
>		- Prototype : `int	ft_isdigit(int c);`
>		- Description : Checks for a digital character (0 - 9).
>		- Allowed external functions : None.
>		- Return Value : The values returned are non-zero if the character falls into the tested class, and zero if not.
>	- **[ft_isalnum](libft/src/ft_isalnum.c)** :
>		- Prototype : `int	ft_isalnum(int c);`
>		- Description : Checks for an alphanumeric character.
>		- Allowed external functions : None.
>		- Return Value : The values returned are non-zero if the character falls into the tested class, and zero if not.
>	- **[ft_isascii](libft/src/ft_isascii.c)** :
>		- Prototype : `int	ft_isascii(int c);`
>		- Description : Checks whether 'c' is a 7-bit unsigned char value that fits into the ascii table of characters.
>		- Allowed external functions : None.
>		- Return Value : The values returned are non-zero if the character falls into the tested class, and zero if not.
>	- **[ft_isprint](libft/src/ft_isprint.c)** :
>		- Prototype : `int	ft_isprint(int c);`
>		- Description : Checks for any printable character.
>		- Allowed external functions : None.
>		- Return Value : The values returned are non-zero if the character falls into the tested class, and zero if not.
>	##### Convertion functions :
>	- **[ft_toupper](libft/src/ft_toupper.c)** :
>		- Prototype : `int	ft_toupper(int c);`
>		- Description : It converts a lower_case letter top the corresponding upper_case letter. The argument must be representable as an unsigned char or the value of EOF.
>		- Allowed external functions : None.
>		- Return Value : If the argument is a lower_case letter, the ft_toupper function return the corresponding upper_case letter if there is one, otherwise it returns the given character unchanged.
>	- **[ft_tolower](libft/src/ft_tolower.c)** :
>		- Prototype : `int	ft_tolower(int c);`
>		- Description : It converts a upper_case letter top the corresponding lower_case letter. The argument must be representable as an unsigned char or the value of EOF.
>		- Allowed external functions : None.
>		- Return Value : If the argument is a upper_case letter, the ft_tolower function return the corresponding lower_case letter if there is one, otherwise it returns the given character unchanged.
>	- **[ft_atoi](libft/src/ft_atoi.c)** :
>		- Prototype : `int	ft_atoi(const char *nptr);`
>		- Description : It converts the initial portion of the string pointed to by nptr to it's int representation (atoi : ascii to int).
>		- Allowed external functions : None.
>		- Return Value : if the string pointed to by 'nptr' contains only digits and that it can fit in a int after convertion then it returns an int corresponding to the given argument.
>	##### String Manipulation functions :
>	- **[ft_strlen](libft/src/ft_strlen.c)** :
>		- Prototype : `size_t	ft_strlen(const char *str);`
>		- Description : Calculate the lenght of a string pointed by 'str', excluding the terminating null byte ('\0').
>		- Allowed external functions : None.
>		- Return Value : It returns the number of bytes in the string pointed to by 'str'.
>	- **[ft_strlcpy](libft/src/ft_strlcpy.c)** :
>		- Prototype : `size_t	ft_strlcpy(char *dst, const char *src, size_t size);`
>		- Description : Copy the input string into a destination string. If the destination buffer, limited by it's size isn't large enough to hold the copy, the resulting string is truncated (but is guaranteed to be null terminated).
>		- Allowed external functions : None.
>		- Return Value : It return the lenght of the total string they tried to create.
>	- **[ft_strlcat](libft/src/ft_strlcat.c)** :
>		- Prototype : `size_t	ft_strlcat(char *dst, const char *src, size_t size);`
>		- Description : Concatenate the input string into a destination string. If the destination buffer, limited by it's size isn't large enough to hold the copy, the resulting string is truncated (but is guaranteed to be null terminated).
>		- Allowed external functions : None.
>		- Return Value : It return the lenght of the total string they tried to create.
>	- **[ft_strncmp](libft/src/ft_strncmp.c)** :
>		- Prototype : `int	ft_strncmp(const char *s1, const char *s2, size_t n);`
>		- Description : It compare not more than 'n' bytes from the array pointed to by 's1' to the array pointed to by 's2'.
>		- Allowed external functions : None.
>		- Return Value : Upon successfull completion, it shall return an integer greater than, equal to, or less than 0 if the array pointed by 's1' is greater than, equal to, or less than the array pointed to by 's2', it return the value of the first difference he find.
>	- **[ft_strnstr](libft/src/ft_strnstr.c)** :
>		- Prototype : `char	*ft_strnstr(const char *big, const char *little, size_t len);`
>		- Description : It locate the first occurence of the null-terminated string 'little' in the string 'big', where not more than 'len' characters are searched.
>		- Allowed external functions : None.
>		- Return Value : if little is an empty string, then big is returned. if little occurs nowhere in big, NULL is returned. Otherwise a pointer to the first character of the first occurence of 'little' in 'big' is returned.
>	- **[ft_strchr](libft/src/ft_strchr.c)** :
>		- Prototype : `char	*ft_strchr(const char *s, int c);`
>		- Description : It locates the first occurence of c (converted to a char) in the string pointed to by 's'. The terminating null character is considered part of the string; therefore if 'c' is '\0', the functions locate the terminating '\0'.
>		- Allowed external functions : None.
>		- Return Value : It returns a pointer to the located character in the string, or NULL if the character searched is not found in the string.
>	- **[ft_strrchr](libft/src/ft_strrchr.c)** :
>		- Prototype : `char	*ft_strrchr(const char *s, int c);`
>		- Description : It locates the last occurence of c (converted to a char) in the string pointed to by 's'. The terminating null character is considered part of the string; therefore if 'c' is '\0', the functions locate the terminating '\0'.
>		- Allowed external functions : None.
>		- Return Value : It returns a pointer to the located character in the string, or NULL if the character searched is not found in the string.
>	##### Memory manipulation functions :
>	- **[ft_memset](libft/src/ft_memset.c)** :
>		- Prototype : `void	*ft_memset(void *s, int c, size_t n);`
>		- Description : It fills the first 'n' bytes of memory area pointed to by 's' with the constant byte 'c'.
>		- Allowed external functions : None.
>		- Return Value : it returns a pointer to the memory area of 's'.
>	- **[ft_bzero](libft/src/ft_bzero.c)** :
>		- Prototype : `void	ft_bzero(void *s, size_t n);`
>		- Description : It erases the data in the 'n' bytes of the memory area startig at the location pointed to by 's', by writing zeros ('\0') to that area.
>		- Allowed external functions : None.
>		- Return Value : None.
>	- **[ft_memmove](libft/src/ft_memmove.c)** :
>		- Prototype : `void	*ft_memmove(void *dest, const void *src, size_t n);`
>		- Description : It copies 'n' bytes from memory area 'src' to memory area 'dest'. The memory areas may overlap: copying takes place as though the bytes in src are first copied into a temporary array that does not overlap 'src' or 'dest', and the bytes are then copied from the temporary array to 'dest'.
>		- Allowed external functions : None.
>		- Return Value : It returns a pointer to 'dest'.
>	- **[ft_memcpy](libft/src/ft_memcpy.c)** :
>		- Prototype : `void	*ft_memcpy(void *dest, const void *src, size_t n);`
>		- Description : It copies 'n' bytes from memory area 'src' to memory area 'dest'. The memory areas must not overlap.
>		- Allowed external functions : None.
>		- Return Value : It returns a pointer to 'dest'.
>	- **[ft_memchr](libft/src/ft_memchr.c)** :
>		- Prototype : `void	*ft_memchr(const void *s, int c, size_t n);`
>		- Description : It scans the initial 'n' bytes of memory area pointed to by 's' for the first instance of 'c'. Both 'c' and the bytes of memory area pointed to by 's' are interpreted as unsigned char.
>		- Allowed external functions : None.
>		- Return Value : It returns a pointer to the matching byte or NULL if the character does not occure in the given memory area.
>	- **[ft_memcmp](libft/src/ft_memcmp.c)** :
>		- Prototype : `int	ft_memcmp(const void *s1, const void *s2, size_t n);`
>		- Description : It compares the first 'n' bytes (each interpreted as unsigned char) of the memory areas 's1' and 's2'.
>		- Allowed external functions : None.
>		- Return Value : It returns an integer less than, equal to, or greater than zero if the first n bytes of s1 is found, respectively, to be less than, to match, or be greater than the first n bytes of s2. For a nonzero return value, the sign is determined by the sign of the difference between the first pair of bytes (interpreted as unsigned char) that differ in s1 and s2. If n is zero, the return value is zero.
>	- **[ft_calloc](libft/src/ft_calloc.c)** :
>		- Prototype : `void	*ft_calloc(size_t nmemb, size_t size);`
>		- Description : It shall allocate unused space for an array of nmemb elements each of whose size in bytes is size.  The space shall be initialized to all bits 0.
>		- Allowed external functions : malloc() {stdlib.h}.
>		- Return Value : Upon successfull completion with both nmemb and size non-zero, shall return a pointer to the allocated space. If either nmemb or size is 0, then either : A null pointer shall be returned and errno may be set to an implementation defined value or A pointer to the allocated space shall be returned. The application shall ensure that the pointer is not used to access an object. Otherwise it shall return a null pointer and set errno to indicate an error.
>	- **[ft_strdup](libft/src/ft_strdup.c)** :
>		- Prototype : `char	*ft_strdup(const char *s);`
>		- Description : It shall duplicate the string 's', memory for the new string is obtained with malloc() and can be freed with free().
>		- Allowed external functions : malloc() {stdlib.h}.
>		- Return Value : Upon succes, it shall returns a pointer to the duplicated string. It returns NULL if insufficient memory was avaible, with errno set to indicate an error.
>
> ---
>
>  - ### Part 2 - Additional functions
>	 In this second part, we must recode a group of functions that is not necessarily part of the libc library.
>	 #### Functions :
>	 ##### String Manipulation functions :
>	 - **[ft_substr](libft/src/ft_substr.c)** :
>		 - Prototype : `char *ft_substr(char const *s, unsigned int start, size_t len);`
>		 - Description : Extract a sub_string from the string pointed to by 's' which start at the 'start' index with a maximum size of 'len'.
>		 - Allowed external functions : malloc() {stdlib.h}
>		 - Return Value : The new string extracted from 's' or NULL if the allocation fails.
>	 - **[ft_strjoin](libft/src/ft_strjoin.c)** :
>		 - Prototype : `char *ft_strjoin(char const *s1, char const *s2);`
>		 - Description : Concatenate the two string 's1' and 's2' in new string allocated with malloc().
>		 - Allowed external functions : malloc() {stdlib.h}
>		 - Return Value : The new string created from the concatenation of 's1' and 's2' or NULL if the allocation fails.
>	 - **[ft_strtrim](libft/src/ft_strtrim.c)** :
>		 - Prototype : `char *ft_strtrim(char const *s1, char const *set);`
>		 - Description : Trim the specified 'set' of characters from the 's1' string at the start and the end of the string. And allocate with malloc() to create the new string
>		 - Allowed external functions : malloc() {stdlib.h}
>		 - Return Value : The new string created from trimming 's1' from the characters found in 'set' at the start and end. Or NULL if the allocation failed.
>	 - **[ft_split](libft/src/ft_split.c)** :
>		 - Prototype : `char **ft_split(char const *s, char c);`
>		 - Description : It split the string 's' at the location specified from 'c' to create new strings.
>		 - Allowed external functions : malloc(), free() {stdlib.h}
>		 - Return Value : An array of string containing each string created from spliting the string 's' with 'c'. Or NULL if the allocation failed
>	 ##### Convertion functions :
>	 - **[ft_itoa](libft/src/ft_itoa.c)** :
>		 - Prototype : `char *ft_itoa(int n);`
>		 - Description : It converts the 'n' number to a string corresponding to 'n'. (itoa : int to ascii).
>		 - Allowed external functions : malloc() {stdlib.h}
>		 - Return Value : It returns a string corresponding to int 'n'. or NULL if the memory allocation failed.
>	 ##### Function pointer functions :
>	 - **[ft_strmapi](libft/src/ft_strmapi.c)** :
>		 - Prototype : `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));`
>		 - Description : Apply the 'f' function to each character of the string pointed to by 's', passing it's index as first argument and the character itself as second argument. Which creates a new string resulting from the successive application of 'f'.
>		 - Allowed external functions : malloc() {stdlib.h}
>		 - Return Value : It returns the string created from successively applying 'f' to each character of string 's'. Or NULL if the memory allocation failed.
>	 - **[ft_striteri](libft/src/ft_striteri.c)** :
>		 - Prototype : `void ft_striteri(char *s, void (*f)(unsigned int, char*));`
>		 - Description : Apply the 'f' function to each character of the string pointed to by 's', passing it's index as first argument and the pointer to the character itself as second argument.
>		 - Allowed external functions : None
>		 - Return Value : None
>	 ##### Print on file descriptor functions :
>	 - **[ft_putchar_fd](libft/src/ft_putchar_fd.c)** :
>		 - Prototype : `void ft_putchar_fd(char c, int fd);`
>		 - Description : Print the 'c' character on the 'fd' file descriptor.
>		 - Allowed external functions : write(), {unistd.h}
>		 - Return Value : None
>	 - **[ft_putstr_fd](libft/src/ft_putstr_fd.c)** :
>		 - Prototype : `void ft_putstr_fd(char *s, int fd);`
>		 - Description : Print the 's' string on the 'fd' file descriptor.
>		 - Allowed external functions : write(), {unistd.h}
>		 - Return Value : None
>	 - **[ft_putendl_fd](libft/src/ft_putendl_fd.c)** :
>		 - Prototype : `void ft_putendl_fd(char *s, int fd);`
>		 - Description : Print the 's' string on the 'fd' file descriptor followed by a newline.
>		 - Allowed external functions : write(), {unistd.h}
>		 - Return Value : None
>	 - **[ft_putnbr_fd](libft/src/ft_putnbr_fd.c)** :
>		 - Prototype : `void ft_putnbr_fd(int n, int fd);`
>		 - Description : Print the 'n' integer on the 'fd' file descriptor.
>		 - Allowed external functions : write(), {unistd.h}
>		 - Return Value : None
>
> ---
>
> - ### Bonus part - Linked list functions :
>	 We will use the following structure to represent the nodes of our list, it's declaration is to add to your libft.h file.
>	 The members of the t_list structure are :
>
>    `void *content` : Allow us to stock any kind of data inside our nodes.
>
>    `struct s_list *next` : The adress to the next node of the linked list, can be put to NULL if it's the last element of the linked list.
>    #### Functions :
>    ##### Linked list manipulation functions :
>    - **[ft_lstnew](libft/src/ft_lstnew.c)** :
>        - Prototype : `t_list	*ft_lstnew(void *content);`
>        - Description : It creates a new node which put content to the value of the 'content' variable with a malloc(), and then put the pointer to the next node to NULL.
>        - Allowed external functions : malloc(), {stdlib.h}.
>        - Return Value : The new node.
>    - **[ft_lstadd_front](libft/src/ft_lstadd_front.c)** :
>        - Prototype : `void	ft_lstadd_front(t_list **lst, t_list *new);`
>        - Description : Add the 'new' element at the start of the linked list pointed to by 'lst'.
>        - Allowed external functions : None.
>        - Return Value : None.
>    - **[ft_lstsize](libft/src/ft_lstsize.c)** :
>        - Prototype : `int	ft_lstsize(t_list *lst);`
>        - Description : Calculate the number of elements in the list pointed to by 'lst'.
>        - Allowed external functions : None.
>        - Return Value : The size of the list.
>    - **[ft_lstlast](libft/src/ft_lstlast.c)** :
>        - Prototype : `t_list	*ft_lstlast(t_list *lst);`
>        - Description : Find the last element of the linked list pointed to by 'lst'.
>        - Allowed external functions : None.
>        - Return Value : The last element of the linked list.
>    - **[ft_lstadd_back](libft/src/ft_lstadd_back.c)** :
>        - Prototype : `void	ft_lstadd_back(t_list **lst, t_list *new);`
>        - Description : Add the 'new' element at the end of the linked list pointed to by 'lst'.
>        - Allowed external functions : None.
>        - Return Value : None.
>    ##### Linked list manipulation functions with function pointer :
>    - **[ft_lstdelone](libft/src/ft_lstdelone.c)** :
>        - Prototype : `void	ft_lstdelone(t_list *lst, void (*del)(void *));`
>        - Description : Delete and free the memory of the element pointed to by 'lst' with the help of 'del' function pointer and free(). Then the pointer is put to NULL.
>        - Allowed external functions : free(), {stdlib.h}.
>        - Return Value : None.
>    - **[ft_lstclear](libft/src/ft_lstclear.c)** :
>        - Prototype : `void	ft_lstclear(t_list **lst, void (*del)(void *));`
>        - Description : Delete and free the memory of the element pointed to by 'lst' and all the following elements with the help of 'del' function pointer and free(). Then the pointer is put to NULL.
>        - Allowed external functions : free(), {stdlib.h}.
>        - Return Value : None.
>    - **[ft_lstiter](libft/src/ft_lstiter.c)** :
>        - Prototype : `void	ft_lstiter(t_list *lst, void (*f)(void *));`
>        - Description : Iterate on the linked list pointed to by 'lst' and apply the pointer of function 'f' on the content of each node of the list.
>        - Allowed external functions : None.
>        - Return Value : None.
>    - **[ft_lstmap](libft/src/ft_lstmap.c)** :
>        - Prototype : `t_list	*ft_lstmap(t_list *lst, void (*f)(void *), void (*del)(void *));`
>        - Description : Iterate on the linked list pointed to by 'lst' and apply the function pointer 'f' to the content of each node, and then creates a new list based on the result of the successive application of the function 'f'. The 'del' function pointer is here in case deleting an element become necessary.
>        - Allowed external functions : malloc(), free(), {stdlib.h}.
>        - Return Value : The new list, or NULL if the memory allocation failed.
> ---