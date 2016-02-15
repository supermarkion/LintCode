struct point {
	int x;
	int y;
};

struct rect {
	struct point UL;
	struct point LR;
};

int Overlap(struct rect A, struct rect B)
{
	return ((A.UL.x <= B.LR.x) &&
			(A.UL.y >= B.LR.y) &&
			(A.LR.x >= B.UL.x) &&
			(A.LR.y <= B.UR.y));
}