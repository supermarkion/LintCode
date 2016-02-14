void DrawEighthOfCircle(int radius)
{
	int x, y;
	x = 0;
	y = radius;
	while (y <= x) {
		y = sqrt((radius * radius) - (x * x)) + 0.5;
		SetPixel(x, y);
		x++;
	}
}