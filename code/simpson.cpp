
const int NPASSOS = 100000;
double integral1(double altura)
{
  double h = W / (NPASSOS);
  double a = 0;
  double b = W;
  double s = f(a, -altura) + f(b, -altura);
  for (double i = 1; i <= n; i += 2) s += f(a + i * h, -altura) * 4.0;
  for (double i = 2; i <= (n - 1); i += 2) s += f(a + i * h, -altura) * 2.0;
  return s * h / 3.0;
}
