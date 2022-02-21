# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 16:52:51 by wismith           #+#    #+#              #
#    Updated: 2022/02/21 16:52:55 by wismith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Modified version of my libft + bonus to include ft_printf and get_next_line

Interactions:
1)
	$ make 			or 			$ make all

	Will make all projects within the library including ft_printf and get_next_line by
invoking each respective Makefile. The way we do this is by including the following within
our Parent Makefile:
								EXAMPLE = directory of child projects
								
								NameOfProject.a :
									make -C $(EXAMPLE) 

2)
	$ make clean

	Will clean all object files including those produced by child projects by 
invoking their Makefiles to clean as well; as can be seen by the following lines of code 
embedded in libft Makefile:
								clean :
									make clean -C $(FT_PRINTF)
									make clean -C $(GNL)
									make clean -C $(GNLB)

3)
	$ make fclean

	Will invoke clean in all Makefiles to remove object files and will remove the archive libraries too.

General info:

	For convenience the libft source (*.c) files are stored in the src directory, and the Header (*.h) files
from all projects are stored in the include directory. 
	Once make is invoked, each Makefile will create an Objects directory in which object files will be stored
within their respective directories. Only the Makefile within the libft (parent) directory will create two directories,
one for the mandatory part, and one for the bonus.
	For convenience the get_next_line project has been seperated into two parts as well: the mandatory and the bonus.
Instead of having mandatory and bonus compile into the same archive library, I've made them seperate, e.g. :
							
							'libft.a' , 'libftbonus.a', and 'gnl_m.a', 'gnl_b.a'

The following archive libraries are generated in from this library:

				Library/
						gnl_b.a
						gnl_m.a
						libft.a
						libftbonus.a
						libftprintf.a

In order to use them do the following:

	$ gcc *.c .../Library/*.a

	Remember to include the respective Header (*.h) file within your project wherever you use a particular function. 
The Header files can be found in the child directory: ./include
	It is recommended that only one archive file is used at a time in order to avoid multiple function declarations. 
This problem will be addressed in the future of this project.
