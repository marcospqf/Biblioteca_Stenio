typedef struct sPoint {
  double x, y;
  sPoint() {}
  sPoint(double _x, double _y) { x = _x, y = _y; }
} point;
typedef point vec;
// 6.1- Distancia de dois ponts (ao quadrado)
double sqDistPoints(point a, point b)
{
  point p(a.x - b.x, a.y - b.y);
  return p.x * p.x + p.y * p.y;
}
// 6.2- Distancia Ponto a Segmento (ao quadrado)
double sqDistPointLine(point a, point b, point c)
{
  vec ab(b.x - a.x, b.y - a.y), ac(c.x - a.x, c.y - a.y);
  double prod = cross(ab, ac);
  prod = (prod * prod) / (ab.x * ab.x + ab.y * ab.y);
  vec bc(c.x - b.x, c.y - b.y), ba(a.x - b.x, a.y - b.y);
  if (dot(ab, bc) > 1e-8) return sqDistPoints(c, b);
  if (dot(ba, ac) > 1e-8) return sqDistPoints(c, a);
  return prod;
}
// 6.3- Produto Vetorial
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
// 6.4- Produto Escalar
double dot(vec a, vec b) { return a.x * b.x + a.y * b.y; }
