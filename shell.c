#include "main.h"

/**
 * cd_shell - changes current directory
 *
 * @datash_mogale: data relevant
 * Return: 1 on success
 */
int cd_shell(data_shell_15 *datash_mogale)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = datash_mogale->args15[1];

	if (dir != NULL)
	{
		ishome = strcm_p("$HOME", dir);
		ishome2 = strcm_p("~", dir);
		isddash = strcm_p("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(datash_mogale);
		return (1);
	}

	if (strcm_p("-", dir) == 0)
	{
		cd_previous(datash_mogale);
		return (1);
	}

	if (strcm_p(".", dir) == 0 || strcm_p("..", dir) == 0)
	{
		cd_dot(datash_mogale);
		return (1);
	}

	cd_to(datash_mogale);

	return (1);
}
