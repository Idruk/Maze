#wo
all:
	make -C generator
	make -C solver

clean:
	make -C generator clean
	make -C solver clean

fclean: clean
	make -C generator fclean
	make -C solver fclean

re: fclean all
