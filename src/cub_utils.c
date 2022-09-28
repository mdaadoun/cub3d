#include "../inc/cub.h"

void	*cub_alloc(t_cub *cub, size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(nmemb, size);
	if (!ptr)
		cub_free_before_exit(cub, ERROR_MALLOC);
	return (ptr);
}
