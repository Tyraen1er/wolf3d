#include "wolf.h"
#include <math.h>

void    raycasting(t_all *dta)
{
	double  length;
	double  dxy[2];
	double  xy[2];

	length = fabs(dta->map.view.y - dta->map.player.x) <= fabs(dta->map.view.x - dta->map.player.x)
	? fabs(dta->map.view.x - dta->map.player.x) : fabs(dta->map.view.y - dta->map.player.x);
	dxy[0] = (dta->map.view.x - dta->map.player.x) / length;
	dxy[1] = (dta->map.view.y - dta->map.player.y) / length;
	xy[0] = dta->map.player.x;
	xy[1] = dta->map.player.y;
	printf("length = %f\ndxy[0] = %f\ndxy[1] = %f\nxy[0] = %f\nxy[1] = %f\nlimitx = %d\nlimity = %d\nwhile (0 < xy[0] && xy[0] < dta->map.limitx && 0 < xy[1] && xy[1] < dta->map.limity)\n", length, dxy[0], dxy[1], xy[0], xy[1], dta->map.limitx, dta->map.limity);

	// dta->map.limity sont faux
	while (0 < xy[0] && xy[0] < dta->map.limitx && 0 < xy[1] && xy[1] < dta->map.limity)
	{
		if (dta->map.map[(int)xy[0]] || dta->map.map[(int)xy[1]])
			break ;
		xy[0] += dxy[0];
		xy[1] += dxy[1];
	}
	printf("%f\n", sqrt(pow(dta->map.player.x - xy[0], 2) + pow(dta->map.player.y - xy[1], 2)));
}

int main()
{
	t_all	data;
	double	*carte[1];
	double	suite[10];

	suite[0] = 0;
	suite[1] = 0;
	suite[2] = 0;
	suite[3] = 0;
	suite[4] = 0;
	suite[5] = 0;
	suite[6] = 0;
	suite[7] = 0;
	suite[8] = 0;
	suite[9] = 1;
	data.map.view.y = 0;
	data.map.view.x = 1;
	data.map.limitx = 10;
	data.map.limity = 1;
	carte[0] = suite;
	data.map.map = carte;
	data.map.player.x = 1.0f;
	data.map.player.y = 1.0f;
	raycasting(&data);
	return (0);
}
