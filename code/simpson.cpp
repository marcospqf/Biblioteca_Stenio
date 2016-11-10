
const int NPASSOS = 100000;
const int W=1000000;
//W= tamanho do intervalo que eu estou integrando
double integral1()
{
  double h = W / (NPASSOS);
  double a = 0;
  double b = W;
  double s = f(a) + f(b);
  for (double i = 1; i <= NPASSOS; i += 2) s += f(a + i * h) * 4.0;
  for (double i = 2; i <= (NPASSOS - 1); i += 2) s += f(a + i * h) * 2.0;
  return s * h / 3.0;
}
