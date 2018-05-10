#include <unistd.h>

#define OK "OK"
#define ERR "Error"

size_t ft_strlen(char *s)
{
	size_t len;
	
	len = 0;
	while (s[len])
		++len;
	return (len);
}

void ft_putstr(char *s)
{
	write (1, s, ft_strlen(s));
}

int ft_isopenbracket(char c)
{
	return (c == '(' || c == '{' || c == '[');
}

int ft_isclosebracket(char c)
{
	return (c == ')' || c == '}' || c == ']');
}

int ft_issame(char c1, char c2)
{
	return ( (c1 == '(' && c2 == ')')
			 ||(c1 == '{' && c2 == '}')
			 ||(c1 == '[' && c2 == ']'));
}

int ft_brackets(char *s)
{
	char c[4096];
	int top;

	top = 0;
	while (*s)
	{
		if (ft_isopenbracket(*s))
		{
			c[top] = *s;
			++top;
		}
		else if (ft_isclosebracket(*s))
		{
			if (top == 0 || !ft_issame(c[--top], *s))
				return (0);
		}
		++s;
	}
	if (top != 0)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	int i;

	++argv;
	--argc;
	i = 0;
	while (i < argc)
	{
		if (ft_brackets(argv[i]))
			ft_putstr(OK);
		else
			ft_putstr(ERR);
		if (i < argc - 1)
			ft_putstr("\n");
		++i;
	}
	ft_putstr("\n");
	
	return (0);
}
