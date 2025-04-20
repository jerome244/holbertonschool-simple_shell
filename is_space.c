/**
 * is_space - check inputted character.
 * @c: input char.
 * Return: 0 true, 1 false.
 */
int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\f' || c == '\r');
}
