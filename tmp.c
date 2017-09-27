#include "wolf.h"

void	rotation(t_all *data, char sense, char change)
{
	//origine vecteur
	data->map.player = (t_point){18, 8};

	// limite max de mon repere (min = 0)
	data->map.limitx = 20;
	data->map.limity = 10;

	data->map.view = (t_point){-3, -2};

//	changer vecteur pour qu'il touche un bord de la map

	if (fabs(data->map.view.y) < fabs(data->map.view.x))
	{
		if (0 < data->map.view.x)
			data->map.view = (t_point){(data->map.limitx - data->map.player.x), data->map.view.y * (data->map.limitx - data->map.player.x) / data->map.view.x};
		else
			data->map.view = (t_point){-data->map.player.x, data->map.view.y * -data->map.player.x / data->map.view.x};
	}
	else
	{
		if (0 < data->map.view.x)
			data->map.view = (t_point){data->map.view.x * (data->map.limity - data->map.player.y) / data->map.view.y, (data->map.limity - data->map.player.y)};
		else
			data->map.view = (t_point){data->map.view.x * -data->map.player.y / data->map.view.y, -data->map.player.y};
	}
	printf("x = %f\ty = %f\n", data->map.view.x, data->map.view.y);
}

int main()
{
	t_all data;

	rotation(&data, 'a', 'b');
	return (0);
}
