NAME	:= Shrubbery

CC		:= c++
FLAGS	:= -Wextra -Wall -Werror

OBJ_DIR := Objects

SRCS	:= main.cpp Bureaucrat.cpp GradeTooHighException.cpp GradeTooLowException.cpp AForm.cpp ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
		
OBJS	:= $(addprefix $(OBJ_DIR)/, ${SRCS:.cpp=.o})

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) -o $@ -c $< $(FLAGS) && printf "Compiling: $(notdir $<)\n"
			
$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re