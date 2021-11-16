NAME	=	libftprintf.a

SRCS	=	ft_atoi.c \
			ft_check_flag_prec.c \
			ft_check_flag_type.c \
			ft_check_flag_width.c \
			ft_check_flags_1.c \
			ft_hexlen.c \
			ft_init_flags.c \
			ft_neg_int.c \
			ft_pos_int.c \
			ft_pos_int_sub.c \
			ft_printf.c \
			ft_pros_char.c \
			ft_pros_int.c \
			ft_pros_p.c \
			ft_pros_perc.c \
			ft_pros_str.c \
			ft_pros_u.c \
			ft_pros_x.c \
			ft_pros_x_sub.c \
			ft_prosessor.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_putnbr_u.c \
			ft_putstr.c \
			ft_putx.c \
			ft_strchr.c \
			ft_strlen.c \
			ft_ulen.c \
			ft_dlen.c \
			ft_check_x.c \
			ft_zero_int.c \
			ft_zero_int_sub.c

OBJS	=	$(SRCS:.c=.o)

LIBH	=	ft_printf.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

all:		${NAME}

${NAME}: ${OBJS}
			$(MAKE) -C ./libft
			ar rc ${NAME} ${OBJS} ./libft/libft.a
			ranlib ${NAME}

%.o:	%.c ${LIBH}
			${CC} ${FLAGS} -c $< -o $@ 

bonus:	$(OBJS) $(OBJ_BONUS)
			ar rc $(NAME) $(OBJS) $(OBJ_BONUS)
			ranlib $(NAME)
clean:
		${RM} ${OBJS} ${OBJSB}

fclean:	clean
		${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re bonus