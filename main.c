#include "minishell.h"

void	noflag(int argc, char **argv)
{
	argc++;
	argv += 1;
}
int 	main(int argc, char **argv, char **en)
{
	t_hash 	**table;
	int 	size;

	noflag(argc, argv);
	table = create_hashtable(en, &size);
	ft_putendl(fhash(table, "LS_COLORS", size));
	hash_free(table, size);
	return (0);
}
