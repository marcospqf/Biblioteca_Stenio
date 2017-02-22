typedef struct sPoint {
	int x, y;
	sPoint(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
} point;
bool comp(point a, point b)
{
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
int cross(point a, point b, point c)  // AB x BC
{
	a.x -= b.x;
	a.y -= b.y;
	b.x -= c.x;
	b.y -= c.y;
	return a.x * b.y - a.y * b.x;
}

bool isCw(point a, point b, point c)  // Clockwise
{
	return cross(a, b, c) < 0;
}

// >= if you want to put collinear points on the convex hull
bool isCcw(point a, point b, point c)  // Counter Clockwise
{
	return cross(a, b, c) > 0;
}

vector<point> convexHull(vector<point> p)
{
	vector<point> u, l;  // Upper and Lower hulls

	sort(p.begin(), p.end(), comp);
	for (unsigned int i = 0; i < p.size(); i++) {
		while (l.size() > 1 && !isCcw(l[l.size() - 1], l[l.size() - 2], p[i]))
			l.pop_back();
		l.push_back(p[i]);
	}

	for (int i = p.size() - 1; i >= 0; i--) {
		while (u.size() > 1 && !isCcw(u[u.size() - 1], u[u.size() - 2], p[i]))
			u.pop_back();
		u.push_back(p[i]);
	}
	u.pop_back();
	l.pop_back();
	l.insert(l.end(), u.begin(), u.end());
	return l;
}

