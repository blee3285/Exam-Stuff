#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int is_op(char c)
{
	char op[] = "+-*/%";
	int i = 0;

	while (op[i])
	{
		if (c == op[i])
			return (1);
		i++;
	}
	return (0);
}

int do_math(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	else if (op == '-')
		return (a - b);
	else if (op == '*')
		return (a * b);
	else if (op == '/')
		return (a / b);
	else if (op == '%')
		return (a % b);
	return (0);
}

void  print_stack(int *stack, int len)
{
	int i = 0;

	while (i < len)
	{
		printf("%d, ", stack[i]);
		i++;
	}
	printf("\n");
}

int rpn_calc(char *str, int *check)
{
	int *stack;
	int i = 0;

	stack = (int*)malloc(sizeof(int) * ft_strlen(str));
	while (*str)
	{
		if (is_op(*str) && atoi(str) == 0)
		{
			i -= 2;
			if ((stack[i + 1] == 0) && ((*str == '/') || (*str == '%')))
				return (stack[0]);
			else
				stack[i] = do_math(stack[i], stack[i + 1], *str);
			i++;
		}
		else
		{
			stack[i] = atoi(str);
			i++;
		}
		while (*str != ' ' && *str)
			str++;
		while (*str == ' ')
			str++;
	}
	if (i == 1)
		*check = 42;
	return (stack[0]);
}

int main(int ac, char **av)
{
	int calc;
	int i;

	i = 0;
	if (ac == 2)
	{
		calc = rpn_calc(av[1], &i);
		if (i == 42)
			printf("%d", calc);
		else
			printf("Error");
	}
	else
	{
		printf("Error");
	}
	printf("\n");
	return (0);
}
